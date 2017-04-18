/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:00:08 by eozdek            #+#    #+#             */
/*   Updated: 2016/02/22 15:27:38 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_choose(t_p *p, char c)
{
	int i;

	i = 0;
	i = p->h == 2 ? 1 : i;
	i = p->h != 2 && p->h > 0 ? 2 : i;
	i = p->l != 2 && p->l > 0 ? 3 : i;
	i = p->l == 2 || p->q > 0 ? 4 : i;
	i = p->j == 1 ? 5 : i;
	i = p->z == 1 ? 6 : i;
	i = p->t == 1 ? 7 : i;
	i = i == 0 && c == 'u' ? 8 : i;
	i = i == 0 && c == 'U' ? 9 : i;
	return (i);
}

static char			*ft_convert_unsigned(t_p *p, char *s, va_list ap, char c)
{
	unsigned long long int	i;
	char					*tmp;

	priority(p);
	i = ft_choose(p, c);
	tmp = s;
	i = p->point == 1 && p->after == 0 ? 0 : i;
	if (i == 1)
		s = ft_ulltoa_base((unsigned char)va_arg(ap, unsigned int), 10);
	if (i == 2)
		s = ft_ulltoa_base((unsigned short int)va_arg(ap, unsigned int), 10);
	s = i == 3 ? ft_ulltoa_base(va_arg(ap, unsigned long int), 10) : s;
	if (i == 4)
		s = ft_ulltoa_base((unsigned long long int)va_arg(ap, void*), 10);
	if (i == 5)
		s = ft_ulltoa_base((uintmax_t)va_arg(ap, unsigned long long int), 10);
	s = i == 6 ? ft_ulltoa_base(va_arg(ap, size_t), 10) : s;
	if (i == 7)
		s = ft_ulltoa_base((ptrdiff_t)va_arg(ap, unsigned long long int), 10);
	if (i == 8)
		s = ft_ulltoa_base(va_arg(ap, unsigned int), 10);
	if (i == 9)
		s = ft_ulltoa_base(va_arg(ap, unsigned long), 10);
	i == 0 ? i : free(tmp);
	return (s);
}

int					ft_unsigned(va_list ap, t_p *p, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (c == 'U')
	{
		p->h = 0;
		p->j = 0;
		p->l = 0;
		p->z = 0;
	}
	s = ft_strnew(0);
	s = ft_convert_unsigned(p, s, ap, c);
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	p->space = 0;
	p->positif = 1;
	p->plus = 0;
	i = ft_space_x(p, s);
	return (i);
}
