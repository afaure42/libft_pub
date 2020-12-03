/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:55:26 by afaure            #+#    #+#             */
/*   Updated: 2020/11/30 00:15:01 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*ptr_new;
	t_list	*ptr;

	if (!lst || !(new = malloc(sizeof(t_list))))
		return (NULL);
	ptr_new = new;
	ptr = lst;
	while (ptr)
	{
		ptr_new->content = (*f)(ptr->content);
		if (ptr->next)
		{
			if (!(ptr_new->next = malloc(sizeof(t_list))))
			{
				ft_lstclear(&new, (*del));
				return (NULL);
			}
			ptr_new = ptr_new->next;
		}
		ptr = ptr->next;
	}
	ptr_new->next = NULL;
	return (new);
}
