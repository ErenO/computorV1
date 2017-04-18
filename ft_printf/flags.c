/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 21:37:30 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 11:33:59 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_p *p, char *str, int i)
{
	p->h = 0;
	p->l = 0;
	p->point = 0;
	p->previous = 0;
	p->after = 0;
	p->j = 0;
	p->positif = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->diese = 0;
	p->pointer = 0;
	p->z = 0;
	p->q = 0;
	p->t = 0;
	flags_premier(p, str, i);
	flags_second(p, str, i);
}

int		flags_premier(t_p *p, char *str, int i)
{
	int j;

	j = ft_letters(str, i);
	while (i < j)
	{
		if (str[i] == '#')
			p->diese = 1;
		if (str[i] == '0' && !(str[i - 1] >= '1' && str[i - 1] <= '9')
			&& p->point == 0)
			p->zero = 1;
		if (str[i] == '-')
			p->minus = 1;
		if (str[i] == '+')
			p->plus = 1;
		if (str[i] == 32)
			p->space = 1;
		if (str[i] == 'q')
			p->q = 1;
		if (str[i] == 't')
			p->t = 1;
		i++;
	}
	p->zero = p->minus == 1 ? 0 : p->zero;
	return (0);
}

int		flags_second(t_p *p, char *str, int i)
{
	int j;

	j = ft_letters(str, i);
	while (i < j)
	{
		if (str[i] == 'h')
			p->h++;
		if (str[i] == 'l')
			p->l++;
		if (str[i] == 'j')
			p->j = 1;
		if (str[i] == 'z')
			p->z = 1;
		if (str[i] == ' ')
			p->space = 1;
		if (str[i] == '.')
			p->point = 1;
		i++;
	}
	return (0);
}
