/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_revstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 12:21:44 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:33:08 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_revstr(char *str)
{
	int		i;
	int		length;
	char	*tmp;

	i = -1;
	length = ft_strlen(str);
	if (!(tmp = malloc(length + 1)))
		return (NULL);
	while (length >= 0)
	{
		tmp[++i] = str[--length];
	}
	tmp[i] = '\0';
	return (tmp);
}
