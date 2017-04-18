/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:31:23 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 11:30:59 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_choose(t_p *p, char c)
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
	i = i == 0 && c == 'x' ? 8 : i;
	i = i == 0 && c == 'X' ? 9 : i;
	return (i);
}

static char	*ft_convert_hexa(t_p *p, char *s, va_list ap, char c)
{
	unsigned long long int	i;
	char					*tmp;

	priority(p);
	i = ft_choose(p, c);
	tmp = s;
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
	if (i == 8)
		s = ft_ulltoa_base(va_arg(ap, unsigned int), 16);
	if (i == 9)
		s = ft_ulltoa_base(va_arg(ap, unsigned int), 16);
	i == 0 ? i : free(tmp);
	s[0] = s[0] == '0' && s[1] == 0 && p->point && !(p->after) ? '\0' : s[0];
	return (s);
}

static char	*str_change(char *s, char c)
{
	int n;

	n = 0;
	if (c == 'x')
	{
		while (s[n] != '\0')
		{
			s[n] = ft_tolower(s[n]);
			n++;
		}
	}
	n = 0;
	if (c == 'X')
	{
		while (s[n] != '\0')
		{
			s[n] = ft_toupper(s[n]);
			n++;
		}
	}
	return (s);
}

int			ft_hexa(va_list ap, char c, t_p *p)
{
	int		n;
	int		i;
	char	*s;

	i = 0;
	n = 0;
	s = ft_strnew(0);
	p->positif = 1;
	p->space = 0;
	p->plus = 0;
	s = ft_convert_hexa(p, s, ap, c);
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	str_change(s, c);
	if (p->diese > 0 && p->neg != -1 && c == 'x' && p->neg != -1 && s[0] != '0')
		p->pointer = 1;
	if (p->diese > 0 && p->neg != -1 && c == 'X' && p->neg != -1 && s[0] != '0')
		p->pointer = 3;
	p->pointer = p->point == 1 && p->after == 0 ? 0 : p->pointer;
	p->neg = 0;
	i = ft_space_x(p, s);
	return (i);
}
