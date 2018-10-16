/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:51:47 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:29:55 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpd;
	char	*tmps;

	tmpd = (char*)dst;
	tmps = (char*)src;
	if (tmps < tmpd)
	{
		while (len--)
			tmpd[len] = tmps[len];
	}
	else
		ft_memcpy(tmpd, tmps, len);
	return (tmpd);
}
