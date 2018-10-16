/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 16:54:07 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 15:35:19 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_get_coordinate3(t_strt *wdw, char **tab, int y, int x)
{
	if (x == 0)
		wdw->ylen = y;
	if (y < wdw->ylen)
	{
		while (tab[++x])
			free(tab[x]);
		free(tab);
		ft_printf("map error\n");
		exit(EXIT_FAILURE);
	}
}

static void		ft_get_coordinate2(char **tab, t_strt *wdw, char ***tmpt, int x)
{
	*tmpt = ft_strsplit(tab[x], ' ');
	free(tab[x]);
	if (!(wdw->coor[x] = (float *)malloc(sizeof(float) * wdw->len)))
		return ;
}

static void		ft_get_coordinate(char **tab, t_strt *wdw, int i)
{
	int		x;
	int		y;
	char	**tmpt;

	tmpt = NULL;
	x = -1;
	((int)ft_strlen(tab[0]) > i) ? (wdw->len = (int)ft_strlen(tab[0])) :
		(wdw->len = i);
	if (!(wdw->coor = (float **)malloc(sizeof(float *) * wdw->len)))
		return ;
	while (tab[++x])
	{
		y = -1;
		ft_get_coordinate2(tab, wdw, &tmpt, x);
		while (tmpt[++y])
		{
			wdw->coor[x][y] = ft_atoi(tmpt[y]);
			free(tmpt[y]);
		}
		free(tmpt);
		ft_get_coordinate3(wdw, tab, y, x);
	}
	wdw->coorx = y;
	wdw->coory = x;
}

static void		ft_read(int fd, t_strt *wdw)
{
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_realloc(tab, (9 * (i + 1)));
		tab[i] = line;
		i++;
	}
	tab[i] = NULL;
	close(fd);
	ft_get_coordinate(tab, wdw, i);
	free(tab);
}

int				main(int ac, char **av)
{
	t_strt	wdw;
	int		fd;

	**av = 0;
	fd = 0;
	wdw.coor = 0;
	wdw.ylen = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDWR)) < 0)
			return (ft_printf("wrong file and/or rights\n"));
		wdw.mlx_ptr = mlx_init();
		wdw.win_ptr = mlx_new_window(wdw.mlx_ptr, 2000, 1200, av[1]);
		ft_read(fd, &wdw);
		ft_init(&wdw);
		ft_draw(&wdw);
		mlx_key_hook(wdw.win_ptr, ft_deal_key, &wdw);
		mlx_loop(wdw.mlx_ptr);
	}
	else
		ft_printf("usage ./fdf [file]");
	return (0);
}
