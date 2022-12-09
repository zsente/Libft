/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:38:24 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:41:07 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	if (lst)
	{
		while (*lst)
		{
			lst_temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_temp;
		}
		*lst = NULL;
	}
}
