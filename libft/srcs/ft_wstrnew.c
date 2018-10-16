/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 20:07:37 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:42:39 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t	*wtmp;
	size_t	i;

	i = 0;
	if (!(wtmp = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		wtmp[i] = '\0';
		i++;
	}
	return (wtmp);
}
