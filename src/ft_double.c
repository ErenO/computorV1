/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:40:34 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/19 14:33:37 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

int     ft_number_decimal(double nb)
{
    double num;
    int count;
    int dint;
    int i;

    count = 0;
    num = ABS(nb);
    dint = num;
    i = 7;
    num = num - (int)num;
    dint = 0;
    while (ABS(num) >= 0.00000000001 && i > 0)
    {
        num = num * 10;
        count = count + 1;
        dint = num;
        dint += (num - dint) > 0.9999999999 ? 1 : 0;
        num = num - dint;
        i--;
    }
    return (count);
}

void    ft_print_double(double nb)
{
    int     isInt;
    double  num;
    int     decimal;

    isInt = nb == (int)nb;
    num = 0;
    decimal = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = ABS(nb);
    }
    ft_putnbr(ABS((int)nb));
    if (isInt == 0)
    {
        ft_putchar('.');
        num = nb - (int)nb;
        decimal = ABS(num * ft_power(10.0, ft_number_decimal(nb)));
        ft_putnbr(decimal);
    }
}
