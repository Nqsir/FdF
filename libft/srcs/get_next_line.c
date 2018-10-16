/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 18:22:56 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 12:54:51 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"
#include "./get_next_line.h"

static int			ft_lenstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static void			ft_way_too_long(char **line, t_lst *lst_tmp,
		char **tmps, int len)
{
	len = ft_lenstr(*tmps);
	*line = ft_strnew(len);
	*line = ft_strncpy(*line, *tmps, len);
	free(lst_tmp->str);
	lst_tmp->str = ft_strsub(*tmps, len + 1, ft_strlen(*tmps));
	free(*tmps);
}

static t_lst		*ft_lst_search_or_create(t_lst **lst_fd, int fd)
{
	t_lst	*link;
	t_lst	*tmp;

	if (!(link = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	link->fd = fd;
	link->str = NULL;
	link->next = NULL;
	if (*lst_fd == NULL)
	{
		*lst_fd = link;
		return (*lst_fd);
	}
	tmp = *lst_fd;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
		{
			free(link);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (link);
}

static void			ft_readline(t_lst *lst_tmp, int fd, char **tmps, int *ret)
{
	char			*tmpt;
	char			*buf;

	buf = malloc(sizeof(char *) * BUFF_SIZE);
	if (lst_tmp->str && *lst_tmp->str != '\0')
		*tmps = ft_strdup(lst_tmp->str);
	while ((*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		if (!(*tmps))
			*tmps = ft_strdup(buf);
		else
		{
			tmpt = ft_strdup(*tmps);
			free(*tmps);
			*tmps = ft_strjoin(tmpt, buf);
			free(tmpt);
		}
		if (*tmps && ft_strchr(*tmps, '\n'))
		{
			free(buf);
			return ;
		}
	}
	free(buf);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmps;
	static	t_lst	*lst_fd = NULL;
	t_lst			*lst_tmp;
	int				len;

	len = 0;
	tmps = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	lst_tmp = ft_lst_search_or_create(&lst_fd, fd);
	ft_readline(lst_tmp, fd, &tmps, &ret);
	if (ret < 0)
		return (-1);
	if (tmps)
	{
		ft_way_too_long(line, lst_tmp, &tmps, len);
		return (1);
	}
	free(lst_tmp->str);
	free(tmps);
	return (0);
}
