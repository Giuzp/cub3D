/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:42:08 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 22:42:39 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	has_monitor_support(t_xvar *xvar);
static int	select_primary_monitor(XRRMonitorInfo *monitors, int count);

/* Returns 1 on success; on failure, leaves the monitor geometry unchanged. */
int	get_monitor_size(t_mlx *mlx)
{
	t_xvar			*xvar;
	XRRMonitorInfo	*monitors;
	int				count;
	int				selected;

	if (!mlx || !has_monitor_support(mlx->mlx))
		return (0);
	xvar = mlx->mlx;
	monitors = XRRGetMonitors(xvar->display, xvar->root, True, &count);
	if (!monitors)
		return (0);
	selected = select_primary_monitor(monitors, count);
	if (count <= 0 || monitors[selected].width <= 0
		|| monitors[selected].height <= 0)
	{
		XRRFreeMonitors(monitors);
		return (0);
	}
	mlx->screen_x = monitors[selected].x;
	mlx->screen_y = monitors[selected].y;
	mlx->width = monitors[selected].width;
	mlx->height = monitors[selected].height;
	XRRFreeMonitors(monitors);
	return (1);
}

static int	has_monitor_support(t_xvar *xvar)
{
	int	major;
	int	minor;

	if (!xvar || !xvar->display)
		return (0);
	major = 1;
	minor = 5;
	if (!XRRQueryVersion(xvar->display, &major, &minor))
		return (0);
	return (major > 1 || (major == 1 && minor >= 5));
}

static int	select_primary_monitor(XRRMonitorInfo *monitors, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (monitors[i].primary)
			return (i);
		i++;
	}
	return (0);
}
