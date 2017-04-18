/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:50:30 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/04/02 17:31:27 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

int    ft_atoi_plus(t_list *list, char *str)
{
    int i;
    double nb;

    i = 0;
    nb = 0.0;
    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            i++;
            nb = ft_atoi(str + i);
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            break ;
        }
        i++;
    }
    nb /= ft_power(10, ft_numb_size(nb));
    list->i += list->i > 0 ? nb : (-nb);
    return (i);
}

void print_term(t_poly *p)
{
    int i;
    int size;

    i = 0;
    size = ft_list_size(p->list);
    if (p->list)
    {
        while (i < size)
        {
            ft_putnbr(i);
            ft_putstr(": i ");
            ft_print_double(p->list->i);
            ft_putstr("; e ");
            ft_putnbr(p->list->e);
            ft_putchar('\n');
            p->list = p->list->next;
            i++;
        }
    }
}

int    ft_end_term(char *str)
{
    int i;

    i = 0;
    // ft_putchar('s');
    // ft_putstr(str);
    // ft_putchar('\n');
    if (str[i] == '=' || str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != 0 && str[i] != '=' && str[i] != '+' && str[i] != '-')
        i++;
    return (i);
}

void ft_split_to_term(t_poly *p, char *str)
{
    int i;
    int nb;
    int neg;
    int deg;
    char *s;

    i = 0;
    nb = 1;
    neg = 1;
    deg = 0;
    s = NULL;
    p->degrees = 0;
    p->natural = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=' || i == 0)
        {
            if (str[i] == '=')
                i++;
            // ft_putstr(str + i);
            // ft_putchar('\n');
            // ft_putchar('e');
            // ft_putstr(str + i + ft_end_term(str + i));
            // i = ft_end_term(str + i);
            // i++;
            // ft_putchar('\n');
            s = ft_strsub(str, i, ft_end_term(str + i));
            i = ft_end_term(str + i);
            // ft_putstr("apres sub |");
            // ft_putstr(s);
            // ft_putchar('|');
            // ft_putchar('\n');
            // ft_putchar('a');
            // ft_putnbr(is_natural_exp_0(s));
            // ft_putchar('\n');
            // ft_putchar('b');
            // ft_putnbr(is_natural_exp_1(s));
            // ft_putchar('\n');
            // ft_putchar('c');
            // ft_putnbr(is_natural_exp_sup(s));
            // ft_putchar('\n');
            // begin = i - size;
            deg = natural_check(p, s);
            if (deg == -2)
                nb = 1;
            else
                nb = ft_atoi(s) * neg;
                ft_putchar('b');
            if (deg == 0)
                deg = ft_atoi(ft_strchr(s, '^'));
            ft_list_push_front(p, nb, deg);
            ft_atoi_plus(p->list, s);
            if (p->degrees < p->list->e)
                p->degrees = p->list->e;
            // ft_putnbr(i);
            ft_putchar('a');
            free(s);
            s = NULL;
        }
        if (str[i] == '=')
            neg = -1;
        i++;
    }
    // print_term(p);
    if ((p->tab = ft_memalloc(sizeof(p->tab) * (p->degrees + 1))) == NULL)
        ft_error(0);
    ft_bzero(p->tab, p->degrees);
}
