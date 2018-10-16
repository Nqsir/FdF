/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:50:47 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:29:06 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmps;
	size_t				i;

	i = 0;
	tmps = s;
	while (i < n)
	{
		if (tmps[i] == (const unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
