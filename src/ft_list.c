/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:26:01 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/27 07:37:01 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

t_list	*ft_create_elem(int i, int e)
{
	t_list	*list;

	list = NULL;
	if ((list = ft_memalloc(sizeof(t_list))) == NULL)
        return (NULL);
	if (list)
	{
        list->i = i;
        list->e = e;
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_front(t_poly *p, int i, int e)
{
	t_list	*list;

	if (p->list)
	{
        list = ft_create_elem(i, e);
        list->next = p->list;
        p->list = list;
	}
	else
    {
		p->list = ft_create_elem(i, e);
    }
}

int ft_list_size(t_list *list)
{
    int i;

    i = 0;
    while (list->next != NULL)
    {
        list = list->next;
        i++;
    }
    return (i);
}
