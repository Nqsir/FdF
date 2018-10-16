/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:24:21 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:42:41 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_case1(t_fdf *lst, t_strt *wdw)
{
	while (lst->i <= lst->d_x)
	{
		mlx_pixel_put(wdw->mlx_ptr, wdw->win_ptr, lst->x1, lst->y1, 0xFFFFFF);
		lst->i++;
		lst->x1 += lst->x_incr;
		lst->ex -= lst->dy;
		if (lst->ex < 0)
		{
			lst->y1 += lst->y_incr;
			lst->ex += lst->dx;
		}
	}
}

static void		ft_case2(t_fdf *lst, t_strt *wdw)
{
	while (lst->i <= lst->d_y)
	{
		mlx_pixel_put(wdw->mlx_ptr, wdw->win_ptr, lst->x1, lst->y1, 0xFFFFFF);
		lst->i++;
		lst->y1 += lst->y_incr;
		lst->ey -= lst->dx;
		if (lst->ey < 0)
		{
			lst->x1 += lst->x_incr;
			lst->ey += lst->dy;
		}
	}
}

static void		ft_draw2(t_strt *wdw, t_fdf *lst, int i)
{
	lst->x1 = wdw->centerx + wdw->x * wdw->zoom + (wdw->zoom / 2 * i);
	lst->x2 = lst->x1 + wdw->zoom;
	lst->y1 = wdw->centery + wdw->y * wdw->zoom
		- wdw->coor[wdw->y][wdw->x] * wdw->height;
	lst->y2 = wdw->centery + wdw->y * wdw->zoom
		- wdw->coor[wdw->y][wdw->x + 1] * wdw->height;
	ft_init_fdf(lst);
	if (lst->d_x >= lst->d_y)
		ft_case1(lst, wdw);
	if (lst->d_x <= lst->d_y)
		ft_case2(lst, wdw);
}

static void		ft_draw3(t_strt *wdw, t_fdf *lst, int i)
{
	lst->x1 = wdw->centerx + wdw->x * wdw->zoom + (wdw->zoom / 2 * i);
	lst->x2 = lst->x1 + (wdw->zoom / 2);
	lst->y1 = wdw->centery + wdw->y * wdw->zoom
		- wdw->coor[wdw->y][wdw->x] * wdw->height;
	lst->y2 = wdw->centery + wdw->y * wdw->zoom
		+ wdw->zoom - wdw->coor[wdw->y + 1][wdw->x] * wdw->height;
	ft_init_fdf(lst);
	if (lst->d_x >= lst->d_y)
		ft_case1(lst, wdw);
	if (lst->d_x <= lst->d_y)
		ft_case2(lst, wdw);
}

void			ft_draw(t_strt *wdw)
{
	t_fdf	lst;
	int		i;

	wdw->x = -1;
	while (++wdw->x < wdw->coorx)
	{
		wdw->y = -1;
		i = 0;
		while (++wdw->y < wdw->coory)
		{
			if (wdw->x < (wdw->coorx - 1))
				ft_draw2(wdw, &lst, i);
			if (wdw->y < (wdw->coory - 1))
				ft_draw3(wdw, &lst, i);
			i++;
		}
	}
}
