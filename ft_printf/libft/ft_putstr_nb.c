/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:10:40 by eozdek            #+#    #+#             */
/*   Updated: 2016/02/22 19:19:01 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_mod(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr_mod(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_putstr_zero(int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		j += ft_putchar_mod(c);
	}
	return (j);
}

int		ft_putstr_nb(char *str, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		j += ft_putchar_mod(str[j]);
	}
	return (j);
}

int		put_zero(t_p *p, int j)
{
	int i;
	int n;
	int q;

	q = j;
	i = 0;
	n = ft_skip_interval(p);
	if (((p->after >= q && p->after > 0) || p->zero == 1))
	{
		j = p->after > q && p->after > 0 ? p->after - q : p->previous - j - n;
		while (i < j)
			i += ft_putchar_mod('0');
		j = j < 0 ? 0 : j;
		return (j);
	}
	return (0);
}
