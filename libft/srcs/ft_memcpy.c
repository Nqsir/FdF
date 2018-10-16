/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:51:32 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:29:31 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*tmps;
	char		*tmpd;
	size_t		i;

	i = 0;
	tmps = src;
	tmpd = dst;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return (dst);
}
