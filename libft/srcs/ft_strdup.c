/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:56:23 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/09 10:58:16 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(char *src)
{
	char	*tab;

	if (!(tab = (malloc(ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(tab, src);
	return (tab);
}
