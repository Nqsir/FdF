/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:54:40 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:33:49 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*tmps;
	int			n;

	i = 0;
	tmps = s;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (tmps[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
