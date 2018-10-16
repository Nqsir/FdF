/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:50:03 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:28:36 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newcontent;

	if (!(newcontent = (malloc(sizeof(t_list)))))
		return (NULL);
	if (!content)
	{
		newcontent->content = NULL;
		newcontent->content_size = 0;
	}
	else
	{
		if (!(newcontent->content = (malloc(sizeof(content_size)))))
			return (NULL);
		ft_memcpy(newcontent->content, content, content_size);
		newcontent->content_size = content_size;
	}
	newcontent->next = NULL;
	return (newcontent);
}
