/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:32:27 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 14:23:40 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_convert_number(t_p *p, char *s, va_list ap, char c)
{
	signed long long	i;
	char				*tmp;

	priority(p);
	tmp = s;
	i = va_arg(ap, signed long long);
	i = (p->h == 2) ? (char)i : i;
	i = (p->h != 2) && (p->h > 0) ? (signed short int)i : i;
	i = (p->l % 2 != 2) ? (signed long int)i : i;
	i = (p->l % 2 == 2) || (p->q > 0) ? (signed long long int)i : i;
	i = p->j > 0 ? (intmax_t)i : i;
	i = p->z > 0 ? (size_t)i : i;
	i = p->t > 0 ? (ptrdiff_t)i : i;
	if ((p->l == 0) && (p->h == 0) && (p->j == 0) && (p->t == 0) && (p->z == 0))
		i = c == 'D' ? (unsigned long)i : (int)i;
	p->positif = i >= 0 ? 1 : 0;
	p->neg = i < 0 ? 1 : 0;
	i = p->neg == 1 ? ABS(i) : i;
	s = p->point == 1 && p->after == 0 && i == 0 ? s : ft_ulltoa_base(i, 10);
	p->point == 1 && p->after == 0 && i == 0 ? p->point : free(tmp);
	return (s);
}

int					ft_number(va_list ap, t_p *p, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(0);
	if (c == 'D')
	{
		p->h = 0;
		p->l = 0;
		p->j = 0;
		p->z = 0;
	}
	s = ft_convert_number(p, s, ap, c);
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	i = ft_space_x(p, s);
	return (i);
}
