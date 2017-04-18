/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:34:16 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/19 14:34:47 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

void    ft_delta_positive(double a, double b, double delta)
{
    double x1;
    double x2;

    x1 = 0;
    x2 = 0;
    if (a != 0)
    {
        x1 = (-b - square_root(delta)) / (2 * a);
        x2 = (-b + square_root(delta)) / (2 * a);
    }
    else
    {
        x1 = 0;
        x2 = 0;
    }
    ft_putstr("\nx1 = ");
    ft_print_double(x1);
    ft_putstr("\nx2 = ");
    ft_print_double(x2);
    ft_putchar('\n');
}

void    ft_delta_negative()
{
    ft_putstr("Δ < 0 alors l'équation ne possède pas de solution réelle mais admet 2 solutions complexes x1 et x2\n");
    ft_putstr("x1 = (−b − i√(-Δ) ) / (2a) et x2 = (−b + i√(-Δ) ) / (2a)\n");
}

void ft_delta_zero(double a, double b)
{
    int x0;

    x0 = (-b) / (2 * a);
    ft_putstr("x0 : ");
    ft_print_double(x0);
}
