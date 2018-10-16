/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fdf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:22:07 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:23:22 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_init_fdf(t_fdf *lst)
{
	lst->ex = fabs(lst->x2 - lst->x1);
	lst->ey = fabs(lst->y2 - lst->y1);
	lst->dx = 2 * lst->ex;
	lst->dy = 2 * lst->ey;
	lst->d_x = lst->ex;
	lst->d_y = lst->ey;
	lst->i = 0;
	if (lst->x1 > lst->x2)
		lst->x_incr = -1;
	else
		lst->x_incr = 1;
	if (lst->y1 > lst->y2)
		lst->y_incr = -1;
	else
		lst->y_incr = 1;
}
