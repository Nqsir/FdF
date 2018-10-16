/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:17:23 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:19:46 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_init(t_strt *wdw)
{
	wdw->x = -1;
	wdw->y = -1;
	wdw->line = NULL;
	wdw->zoom = 2;
	wdw->centerx = (2000 - (wdw->coorx * wdw->zoom
				+ wdw->coory * wdw->zoom / 2)) / 2;
	wdw->centery = (1200 - (wdw->coory * wdw->zoom)) / 2;
	wdw->height = wdw->zoom / 12;
}
