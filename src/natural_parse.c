/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   natural_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 08:20:36 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/04/02 17:28:42 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

int natural_check(t_poly *p, char *str)
{
    int temp;

    temp = 0;
    p->natural = 1;
    if ((temp = is_natural_exp_0(str)))
        return (0);
    else if ((temp = is_natural_exp_1(str)))
    {
        if (temp == 1)
            return (1);
        else
            return (-2);
    }
    else if ((temp = is_natural_exp_sup(str)))
        return (temp);
    else
        return (-1);
}

int is_natural_exp_1(char *str)
{
    int i;
    int simple;

    i = 0;
    simple = 0;
    i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        i++;
        simple = 1;
    }
    i += (str[i] == '*') ? 1 : 0;
    if (str[i] == 'X' && str[i + 1] != '^')
    {
        if (simple)
            return (1);
        else
            return (2);
    }
    else
        return (0);
}

int is_natural_exp_0(char *str)
{
    int i;

    i = 0;
    if (ft_atoi(str))
    {
        i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
        while (str[i] == '+' || str[i] == '-' || str[i] == '=' || str[i] != 0)
        {
            if (!ft_isdigit(str[i]))
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}

int is_natural_exp_sup(char *str)
{
    int i;

    i = 0;
    i += (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (!ft_isdigit(str[i]) && str[i] == 'X')
    {
        i++;
        if (str[i] == '^')
        {
            i++;
            if (ft_isdigit(str[i]))
                return (ft_atoi(str + i));
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (0);
}
