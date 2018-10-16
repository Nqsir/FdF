/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:59:07 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:40:49 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmps;
	int			i;

	tmps = s;
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	i = ft_strlen(s);
	while (tmps[i] != (char)c)
		i--;
	return ((char *)s + i);
}
