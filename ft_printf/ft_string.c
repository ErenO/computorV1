/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 20:11:17 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 14:27:52 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_space(t_p *p, char *str)
{
	int i;
	int j;
	int q;

	j = p->previous;
	i = 0;
	q = ft_strlen(str);
	j -= (p->after < q && p->after > 0) ? p->after : ft_strlen(str);
	if (p->minus == 1)
	{
		if (p->after < (int)ft_strlen(str) && p->after > 0)
			i += ft_putstr_nb(str, p->after);
		else
			i += ft_putstr_mod(str);
	}
	while (j-- > 0)
		i += p->zero && !(p->minus) ? ft_putchar_mod('0') : ft_putchar_mod(' ');
	if (p->minus == 0)
	{
		if (p->after < (int)ft_strlen(str) && p->after > 0)
			i += ft_putstr_nb(str, p->after);
		else
			i += ft_putstr_mod(str);
	}
	return (i);
}

int		ft_char(va_list ap, t_p *p)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(ap, int);
	if ((p->point == 1) && (p->after == 0) && (p->previous == 0))
	{
		ft_putstr("");
		return (1);
	}
	if (p->minus == 1)
		i += ft_putchar_mod(c);
	p->previous = p->previous - 1;
	while (p->previous > 0)
	{
		if (p->zero == 1)
			i += ft_putchar_mod('0');
		else
			i += ft_putchar_mod(' ');
		p->previous--;
	}
	if (p->minus == 0)
		i += ft_putchar_mod(c);
	return (i);
}

int		ft_string(va_list ap, t_p *p)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		s = malloc(sizeof(char) * 6 + 1);
		tmp = s;
		ft_strcpy(s, "(null)");
		free(tmp);
	}
	if ((p->point == 1) && (p->after == 0))
	{
		s = ft_strdup("");
	}
	i = ft_space(p, s);
	return (i);
}
