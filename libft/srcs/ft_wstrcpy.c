/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 18:08:28 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:42:18 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

wchar_t	*ft_wstrcpy(wchar_t *wdst, wchar_t *wsrc)
{
	int i;

	i = 0;
	while (wsrc[i] != '\0')
	{
		wdst[i] = wsrc[i];
		i++;
	}
	wdst[i] = '\0';
	return (wdst);
}
