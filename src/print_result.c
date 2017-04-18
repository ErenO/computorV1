/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:46:05 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/19 14:34:01 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

void    ft_print_calc(t_poly *p)
{
    int i;

    i = 0;
    while (i <= p->degrees)
    {
        if (i > 0)
        {
            if (p->tab[i] >= 0)
                ft_putstr("+ ");
            else
                ft_putstr("- ");
        }
        ft_print_double(ABS(p->tab[i]));
        ft_putstr(" * X ^ ");
        ft_putnbr(i);
        ft_putchar(' ');
        i++;
    }
    ft_putstr("= 0\n");
    ft_putstr("Polynomial degrees : ");
    ft_putnbr(p->degrees);
    ft_putchar('\n');
}

void    ft_calc_first_degrees(double zero, double one)
{
    double result;

    result = (-zero) / one;
    ft_putstr("\nx = ");
    ft_print_double(result);
}

void    upper_degrees()
{
    ft_putstr("The polynomial degree");
    ft_putstr(" is stricly greater than 2, I can't solve.\n");
}

void    ft_calc_second_degrees(double a, double b, double c)
{
    double delta;

    delta = ABS(b * b) - (4.0 * a * c);
    ft_putstr("a = ");
    ft_print_double(a);
    ft_putchar('\n');
    ft_putstr("b = ");
    ft_print_double(b);
    ft_putchar('\n');
    ft_putstr("c = ");
    ft_print_double(c);
    ft_putchar('\n');
    ft_putstr("Δ = ");
    ft_print_double(delta);
    ft_putchar('\n');
    if (delta > 0.0)
        ft_delta_positive(a, b, delta);
    else if (delta == 0)
        ft_delta_zero(a, b);
    else if (delta < 0)
        ft_delta_negative();
}
