/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:47:33 by gwells            #+#    #+#             */
/*   Updated: 2016/02/22 17:13:07 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnwstr(const wchar_t *str, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i += 1;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x1FFFFF)
			i += 4;
		if (i <= len)
			j += ft_putwchar(*str++);
		if (i >= len)
			break ;
	}
	if (i == 0)
		j = 0;
	return (j);
}

int			ft_putwchar(wchar_t chr)
{
	int i;

	i = 0;
	if (chr <= 0x7F)
		i += ft_putchar_mod(chr);
	else if (chr <= 0x7FF)
	{
		i += ft_putchar_mod((chr >> 6) + 0xC0);
		i += ft_putchar_mod((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		i += ft_putchar_mod((chr >> 12) + 0xE0);
		i += ft_putchar_mod(((chr >> 6) & 0x3F) + 0x80);
		i += ft_putchar_mod((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x1FFFFF)
	{
		i += ft_putchar_mod((chr >> 18) + 0xF0);
		i += ft_putchar_mod(((chr >> 12) & 0x3F) + 0x80);
		i += ft_putchar_mod(((chr >> 6) & 0x3F) + 0x80);
		i += ft_putchar_mod((chr & 0x3F) + 0x80);
	}
	return (i);
}

static int	casse_pieds(int j, int i, int n)
{
	i += j > 0 && (i + n <= j) ? n : 0;
	i += j == 0 ? n : 0;
	return (i);
}

size_t		ft_wstrlen(const wchar_t *s, t_p *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = p->after > 0 ? p->after : 0;
	while (*s)
	{
		if (*s <= 0x7F)
			i = casse_pieds(j, i, 1);
		else if (*s <= 0x7FF)
			i = casse_pieds(j, i, 2);
		else if (*s <= 0xFFFF)
			i = casse_pieds(j, i, 3);
		else if (*s <= 0x1FFFFF)
			i = casse_pieds(j, i, 4);
		(s)++;
	}
	return (i);
}

int			ft_wchar_str(va_list ap, t_p *p)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			e;

	i = 0;
	j = 0;
	s = va_arg(ap, wchar_t*);
	if (s == NULL)
		s = ft_wstrdup(L"(null)");
	j = ft_wstrlen(s, p);
	e = (p->point == 1 && p->after == 0) ? 1 : 0;
	if (p->minus == 1 && e == 0)
		i += ft_putnwstr(s, j);
	if (p->after < (int)j && p->after > 0 && e == 0)
		p->previous -= i != 0 ? p->after : 0;
	else
		p->previous -= e == 0 ? j : 0;
	i += ft_wspace(p);
	if (p->minus == 0 && e == 0)
		i += ft_putnwstr(s, j);
	return (i);
}
