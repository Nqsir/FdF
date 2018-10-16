/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:35:34 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:37:52 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void		*ft_realloc(void *mem, size_t size)
{
	void	*new;

	new = NULL;
	if (!(new = (void *)malloc(size)))
		return (NULL);
	if (mem)
	{
		ft_memcpy(new, mem, size);
		free(mem);
		mem = NULL;
	}
	return (new);
}
