/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:34:39 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 15:00:18 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_mod(t_p *p)
{
	int i;

	i = 0;
	p->zero = (p->minus == 1) ? 0 : p->zero;
	if (p->minus > 0)
		i += ft_putchar_mod('%');
	if (p->previous > 0)
	{
		if (p->zero == 1)
			i += ft_putstr_zero(p->previous - 1, '0');
		else
			i += ft_putstr_zero(p->previous - 1, ' ');
	}
	if (p->minus == 0)
		i += ft_putchar_mod('%');
	return (i);
}

int		ft_mod1(t_p *p, char c)
{
	int a;

	a = 0;
	if (p->minus == 1)
		a += ft_putchar_mod(c);
	if (p->previous > 0)
	{
		if (p->zero == 1)
			a += ft_putstr_zero(p->previous - 1, '0');
		else
			a += ft_putstr_zero(p->previous - 1, ' ');
	}
	if (p->minus == 0)
		a += ft_putchar_mod(c);
	return (a);
}
