/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:49:57 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/27 07:41:42 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

int    ft_numb_size(double nb)
{
    int i;

    i = 1;
    while (nb >= 10)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

int ft_power(int nb, int power)
{
    int num;

    num = 1;
    if (power == 0)
        return (0);
    if (power == 1)
        return (nb);
    while (power > 0)
    {
        num *= nb;
        power--;
    }
    return (num);
}

int    determin_degrees(t_poly *p)
{
    int i;
    int deg;

    i = 0;
    deg = 0;
    while (i <= p->degrees)
    {
        if (p->tab[i])
            deg = i;
        i++;
    }
    return (deg);
}

void    ft_calc_by_degrees(t_poly *p)
{
    while (p->list != NULL)
    {
        p->tab[p->list->e] += p->list->i;
        p->list = p->list->next;
    }
    p->degrees = determin_degrees(p);
    // ft_print_calc(p);
    if (p->degrees == 2)
        ft_calc_second_degrees(p->tab[2], p->tab[1], p->tab[0]);
    else if (p->degrees == 1)
        ft_calc_first_degrees(p->tab[0], p->tab[1]);
    else if (p->degrees == 0)
        ft_putstr("Tous les nombres réels sont solution\n");
    else
        upper_degrees();
}
