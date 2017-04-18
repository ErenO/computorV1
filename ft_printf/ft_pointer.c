/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:31:14 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/23 13:13:23 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_choose(t_p *p)
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
	i = i == 0 ? 8 : i;
	return (i);
}

static char		*ft_convert_pointer(t_p *p, char *s, va_list ap)
{
	unsigned long long int	i;
	char					*tmp;

	priority(p);
	i = ft_choose(p);
	tmp = s;
	i = p->point == 1 && p->after == 0 ? 0 : i;
	if (i == 1)
		s = ft_ulltoa_base((unsigned char)va_arg(ap, unsigned int), 16);
	if (i == 2)
		s = ft_ulltoa_base((unsigned short int)va_arg(ap, unsigned int), 16);
	s = i == 3 ? ft_ulltoa_base(va_arg(ap, unsigned long int), 16) : s;
	if (i == 4)
		s = ft_ulltoa_base((unsigned long long int)va_arg(ap, void*), 16);
	if (i == 5)
		s = ft_ulltoa_base((uintmax_t)va_arg(ap, unsigned long long int), 16);
	s = i == 6 ? ft_ulltoa_base(va_arg(ap, size_t), 16) : s;
	if (i == 7)
		s = ft_ulltoa_base((ptrdiff_t)va_arg(ap, unsigned long long int), 16);
	s = i == 8 ? ft_ulltoa_base(va_arg(ap, unsigned long), 16) : s;
	i == 0 ? i : free(tmp);
	return (s);
}

int				ft_pointer(va_list ap, t_p *p)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(0);
	s = ft_convert_pointer(p, s, ap);
	p->positif = 0;
	p->plus = 0;
	p->space = 0;
	p->diese = 0;
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	p->pointer = 1;
	while (s[i++] != '\0')
		s[i] = ft_tolower(s[i]);
	i = ft_space_x(p, s);
	return (i);
}
