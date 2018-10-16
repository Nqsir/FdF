/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:49:15 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:27:39 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		while ((*alst)->next != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
		}
		ft_lstdelone(alst, (*del));
	}
}
