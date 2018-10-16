/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/07 12:04:16 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 19:22:13 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft_printf/include/libft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_strt
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*line;
	float	**coor;
	float	coorx;
	float	coory;
	float	height;
	float	centerx;
	float	centery;
	float	zoom;
	int		x;
	int		y;
	int		len;
	int		ylen;
}				t_strt;

typedef struct	s_fdf
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	ex;
	float	ey;
	float	dx;
	float	dy;
	float	d_x;
	float	d_y;
	float	i;
	float	x_incr;
	float	y_incr;
}				t_fdf;

void			ft_init(t_strt *wdw);
void			ft_free(t_strt *wdw);
void			ft_init_fdf(t_fdf *lst);
void			ft_draw(t_strt *wdw);
int				ft_deal_key(int key, t_strt *wdw);

#endif
