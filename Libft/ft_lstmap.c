/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:35:55 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/10 14:53:18 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*content;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		content = ft_lstnew(f(lst->content));
		if (!content)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, content);
		lst = lst->next;
	}
	return (new);
}
