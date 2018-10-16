/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_unsi.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 17:35:44 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:27:20 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_digitlen_base(uintmax_t n, int baselen)
{
	uintmax_t	ret;

	ret = 0;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base_unsi(uintmax_t n, int baselen, char *base)
{
	uintmax_t		len;
	uintmax_t		i;
	char			*str;

	i = 0;
	len = ft_digitlen_base(n, baselen);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	str[len] = '\0';
	while (len > i)
	{
		str[--len] = base[n % baselen];
		n = n / baselen;
	}
	return (str);
}
