/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_monitor_selection_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:52:51 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 11:52:58 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	has_monitor_support(t_xvar *xvar);
static int	select_primary_monitor(XRRMonitorInfo *monitors, int count);
static int	get_pointer_position(t_xvar *xvar, int *pos);
static int	select_pointer_monitor(t_xvar *xvar,
				XRRMonitorInfo *monitors, int count);

/**
 * @brief	Stores the pointer monitor position and dimensions
 *
 * @param[in,out]	mlx	Mlx struct with the connection and window geometry
 * @return		1 on success, 0 if monitor geometry could not be retrieved
 *
 * Uses the primary monitor, or the first monitor, as a fallback.
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
	selected = select_pointer_monitor(xvar, monitors, count);
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

/**
 * @brief	Gets the mouse pointer position in desktop coordinates
 *
 * @param[in]	xvar	Mlx connection with the X11 display
 * @param[out]	pos		Array receiving the desktop x and y coordinates
 * @return		Nonzero on success, 0 if the pointer query fails
 *
 * Use pos only when the query succeeds
 */
static int	get_pointer_position(t_xvar *xvar, int *pos)
{
	Window			windows[2];
	int				local[2];
	unsigned int	mask;

	return (XQueryPointer(xvar->display, xvar->root, &windows[0],
			&windows[1], &pos[0], &pos[1], &local[0], &local[1], &mask));
}

/**
 * @brief	Finds the monitor containing the mouse pointer
 *
 * @param[in]	xvar		Mlx connection with the X11 display
 * @param[in]	monitors	Array of active monitors returned by RandR
 * @param[in]	count		Number of monitors in the array
 * @return		Index of the selected monitor
 *
 * Falls back to the primary monitor if querying or matching fails,
 * or index 0 if no monitor is marked primary. Requires a nonempty array
 */
static int	select_pointer_monitor(t_xvar *xvar,
		XRRMonitorInfo *monitors, int count)
{
	int	pos[2];
	int	i;

	if (!get_pointer_position(xvar, pos))
		return (select_primary_monitor(monitors, count));
	i = 0;
	while (i < count)
	{
		if (pos[0] >= monitors[i].x
			&& pos[0] < monitors[i].x + monitors[i].width
			&& pos[1] >= monitors[i].y
			&& pos[1] < monitors[i].y + monitors[i].height)
			return (i);
		i++;
	}
	return (select_primary_monitor(monitors, count));
}
