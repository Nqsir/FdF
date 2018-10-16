/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 19:39:59 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 17:48:41 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_lst
{
	char			*str;
	int				fd;
	struct s_lst	*next;
	char			*p;
}				t_lst;

int				get_next_line(const int fd, char **line);

#endif
