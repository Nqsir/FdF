/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_deal_key.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:32:49 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 18:10:23 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_deal_key2(int key, t_strt *wdw)
{
	if (key == 0)
		wdw->centerx -= 50;
	if (key == 2)
		wdw->centerx += 50;
	if (key == 13)
		wdw->centery -= 50;
	if (key == 1)
		wdw->centery += 50;
	if (key == 126)
		wdw->height += 1;
	if (key == 125)
		wdw->height -= 1;
}

int				ft_deal_key(int key, t_strt *wdw)
{
	if (key == 15)
		ft_init(wdw);
	if (key == 53)
	{
		ft_free(wdw);
		exit(EXIT_SUCCESS);
	}
	if (key == 69)
	{
		wdw->zoom += 2;
		wdw->height = wdw->zoom / 12;
	}
	if (key == 78)
	{
		wdw->zoom -= 2;
		wdw->height = wdw->zoom / 12;
	}
	ft_deal_key2(key, wdw);
	mlx_clear_window(wdw->mlx_ptr, wdw->win_ptr);
	wdw->x = -1;
	wdw->y = -1;
	ft_draw(wdw);
	return (key);
}
