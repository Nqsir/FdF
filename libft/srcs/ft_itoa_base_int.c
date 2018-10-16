/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_int.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 16:02:11 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:27:10 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_digitlen_base(int n, int baselen)
{
	int	ret;

	ret = 0;
	if (n < 0 && baselen == 10)
	{
		ret++;
		n = -n;
	}
	else if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base_int(int n, int baselen, char *base)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_digitlen_base(n, baselen);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	str[len] = '\0';
	if (n < 0 && baselen == 10)
	{
		n = -n;
		str[i++] = '-';
	}
	else if (n < 0)
		n = -n;
	while (len > i)
	{
		str[--len] = base[n % baselen];
		n = n / baselen;
	}
	return (str);
}
