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

/**
 * @brief	Stores the selected monitor position and dimensions
 *
 * @param[in,out]	mlx	Mlx struct with the connection and window geometry
 * @return		1 on success, 0 if monitor geometry could not be retrieved
 *
 * The geometry is unchanged on failure
 */
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

/**
 * @brief	Checks if the display supports RandR 1.5 monitor queries
 *
 * @param[in]	xvar	Mlx connection with the X11 display
 * @return		1 if monitor queries are supported, 0 otherwise
 */
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

/**
 * @brief	Finds the primary monitor in the monitor array
 *
 * @param[in]	monitors	Array of monitors returned by RandR
 * @param[in]	count		Number of monitors in the array
 * @return		Index of the primary monitor, or 0 if none is marked primary
 */
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
