/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 21:00:51 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:41:02 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_wordslen(const char *s, char c, int i)
{
	int n;

	n = 0;
	while (s[i++] != c && s[i] != '\0')
		n++;
	return (n);
}

static int	ft_countwords(char const *s, char c)
{
	int i;
	int words;
	int	j;

	i = 0;
	words = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && j > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			words++;
			j = 0;
		}
		else if (s[i] != c)
			j++;
		i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		n;
	int		i;
	int		j;

	j = 0;
	i = 0;
	n = 0;
	if (!s || !c)
		return (NULL);
	if (!(split = (char **)(malloc(8 * (ft_countwords(s, c) + 1)))))
		return (NULL);
	while (ft_countwords(s, c) > n)
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (!(split[n] = (char *)(malloc(ft_wordslen(s, c, i) + 2))))
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			split[n][j++] = s[i++];
		split[n++][j] = '\0';
	}
	split[n] = NULL;
	return (split);
}
