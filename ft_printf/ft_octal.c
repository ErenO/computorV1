/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:31:19 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 14:22:35 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_convert_octal(t_p *p, char *s, va_list ap, char c)
{
	unsigned long long	i;
	char				*tmp;

	priority(p);
	i = va_arg(ap, unsigned long long);
	i = p->h == 2 ? (unsigned char)i : i;
	i = p->h != 2 && (p->h > 0) ? (unsigned short int)i : i;
	i = p->l != 2 && (p->l > 0) ? (unsigned long int)i : i;
	i = (p->l == 2) || (p->q > 0) ? (unsigned long long int)i : i;
	i = p->j > 0 ? (uintmax_t)i : i;
	i = p->z > 0 ? (size_t)i : i;
	i = p->t > 0 ? (ptrdiff_t)i : i;
	if ((p->l == 0) && (p->h == 0) && (p->j == 0) && (p->t == 0) && (p->z == 0))
		i = c == 'o' ? (unsigned int)i : (unsigned long)i;
	tmp = s;
	s = p->point == 1 && p->after == 0 && i == 0 ? s : ft_ulltoa_base(i, 8);
	p->point == 1 && p->after == 0 && i == 0 ? p->point : free(tmp);
	if (p->point == 1 && p->previous == 0 && p->after == 0 && i == 0)
		p->diese = (p->diese == 1) ? 2 : p->diese;
	p->diese = (p->diese == 1) && i != 0 && p->after == 0 ? 2 : p->diese;
	return (s);
}

int					ft_octal(va_list ap, t_p *p, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (c == 'O')
	{
		p->h = 0;
		p->j = 0;
		p->l = 0;
		p->z = 0;
	}
	s = ft_strnew(0);
	p->positif = 1;
	p->neg = 0;
	p->plus = 0;
	p->space = 0;
	s = ft_convert_octal(p, s, ap, c);
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	i = ft_space_x(p, s);
	return (i);
}
