/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 19:35:49 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:42:29 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (wstr[i] != '\0')
	{
		if (wstr[i] <= 0x7F)
			len += 1;
		else if (wstr[i] <= 0x7FF)
			len += 2;
		else if (wstr[i] <= 0xFFFF)
			len += 3;
		else if (wstr[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}
