/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:35:21 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:22:29 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

static int		ft_check_free(char *s1, char *s2)
{
	if (!s1)
	{
		if (s2)
		{
			free(s2);
			s2 = NULL;
		}
		return (0);
	}
	else if (!s2)
	{
		if (s1)
		{
			free(s1);
			s1 = NULL;
		}
		return (0);
	}
	return (1);
}

void			ft_strjoinfree(char *s1, char *s2, t_struct *strt, int n)
{
	int		len;

	if (!ft_check_free(s1, s2))
		return ;
	if (strt->s_arg)
		free(strt->s_arg);
	strt->s_arg = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(strt->s_arg = (char *)(malloc(sizeof(char) * (len + 2)))))
		return ;
	if (n == 0)
	{
		ft_strcpy(strt->s_arg, s1);
		ft_strcat(strt->s_arg, s2);
	}
	else
	{
		ft_strcpy(strt->s_arg, s2);
		ft_strcat(strt->s_arg, s1);
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
