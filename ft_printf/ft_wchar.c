/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:32:00 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 14:50:37 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_wchar_char(va_list ap, t_p *p)
{
	wchar_t		c;
	int			i[2];

	i[0] = 0;
	c = va_arg(ap, int);
	i[1] = ft_wcharlen(c);
	if ((p->point == 1) && (p->after == 0) && (p->previous == 0))
	{
		ft_putstr("");
		return (1);
	}
	if (p->minus == 1)
		i[0] += ft_putwchar(c);
	p->previous = p->previous - i[1];
	while (p->previous > 0)
	{
		if (p->zero == 1)
			i[0] += ft_putchar_mod('0');
		else
			i[0] += ft_putchar_mod(' ');
		p->previous--;
	}
	if (p->minus == 0)
		i[0] += ft_putwchar(c);
	return (i[0]);
}

wchar_t				*ft_wstrdup(wchar_t *wstr)
{
	size_t		i;
	size_t		n;
	wchar_t		*ret;
	wchar_t		*tmp;

	i = 0;
	n = 6;
	n = sizeof(wchar_t) * (6 + 1);
	ret = (wchar_t*)malloc(n);
	tmp = ret;
	ft_memcpy(ret, wstr, n);
	free(tmp);
	return (ret);
}

size_t				ft_wcharlen(wchar_t c)
{
	size_t i;

	i = 0;
	if (c <= 0x7F)
		i = 1;
	else if (c <= 0x7FF)
		i = 2;
	else if (c <= 0xFFFF)
		i = 3;
	else if (c <= 0x1FFFFF)
		i = 4;
	return (i);
}
