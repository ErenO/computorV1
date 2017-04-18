/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:35:07 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 20:09:32 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_skip_interval(t_p *p)
{
	int i;

	i = 0;
	i += p->plus == 1 && p->positif == 1 ? 1 : 0;
	i += p->neg == 1 ? 1 : 0;
	i += p->space == 1 && p->zero == 1 ? 1 : 0;
	i += p->pointer > 0 ? 2 : 0;
	i += p->diese == 2 ? 1 : 0;
	return (i);
}

int		ft_skip_interval2(int i, char *str)
{
	while ((str[i] == 'l') || (str[i] == '-') || (str[i] == '+')
			|| (str[i] == ' ') || (str[i] == 'z') || (str[i] == 't')
			|| (str[i] == 'j') || (str[i] == '#') || (str[i] == 'h')
			|| (str[i] == '*') || (str[i] == '0') || (str[i] == 'q'))
		i++;
	return (i);
}

int		its_true(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
		|| c == 'D' || c == 'i' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'c'
		|| c == 'C' || c == '%' || c == 'b' || c == 'n')
		return (1);
	return (0);
}

int		ft_wspace(t_p *p)
{
	int i;

	i = 0;
	while (p->previous > 0)
	{
		if (p->zero == 1 && p->minus == 0)
			i += ft_putchar_mod('0');
		else
			i += ft_putchar_mod(' ');
		p->previous--;
	}
	return (i);
}

void	priority(t_p *p)
{
	p->h = !(p->l) && !(p->j) && !(p->z) ? p->h : 0;
	p->l = !(p->j) && !(p->z) ? p->l : 0;
	p->j = !(p->z) ? p->j : 0;
}
