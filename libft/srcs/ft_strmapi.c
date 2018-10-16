/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:57:54 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:39:31 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmps;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(tmps = malloc((len + 1) * (sizeof(char)))))
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			tmps[i] = f(i, s[i]);
			i++;
		}
		tmps[i] = '\0';
		return (tmps);
	}
	return (NULL);
}
