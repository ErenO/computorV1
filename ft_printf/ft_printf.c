/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 18:09:20 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 17:05:27 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_letters(char *str, int i)
{
	while ((str[i] != 's') || (str[i] != 'S') || (str[i] != 'p')
		|| (str[i] != 'd') || (str[i] != 'D') || (str[i] != 'i')
		|| (str[i] != 'o') || (str[i] != 'O') || (str[i] != 'u')
		|| (str[i] != 'x') || (str[i] != 'X') || (str[i] != 'c')
		|| (str[i] != 'C') || (str[i] != '%') || (str[i] != 'b')
		|| (str[i] != '\0'))
	{
		if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O'
			|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'c'
			|| str[i] == 'C' || str[i] == '%'
			|| str[i] == '\0' || str[i] == 'b')
			return (i);
		i++;
	}
	return (0);
}

int			ft_rest(char c, va_list ap, t_p *p)
{
	int j;

	j = 0;
	c = (c == 'c' && p->l != 2 && p->l > 0) ? 'C' : c;
	c = (c == 's' && p->l != 2 && (p->l > 0)) ? 'S' : c;
	j += (c == 's') ? ft_string(ap, p) : 0;
	j += (c == 'd') || (c == 'i') || (c == 'D') ? ft_number(ap, p, c) : 0;
	j += (c == 'c') ? ft_char(ap, p) : 0;
	j += (c == 'p') ? ft_pointer(ap, p) : 0;
	j += (c == 'x') || (c == 'X') ? ft_hexa(ap, c, p) : 0;
	j += (c == 'u') || (c == 'U') ? ft_unsigned(ap, p, c) : 0;
	j += (c == 'o') || (c == 'O') ? ft_octal(ap, p, c) : 0;
	j += (c == '%') ? ft_mod(p) : 0;
	j += (c == 'S') ? ft_wchar_str(ap, p) : 0;
	j += (c == 'C') ? ft_wchar_char(ap, p) : 0;
	j += (c == 'b') ? ft_binary(ap, p) : 0;
	if (j == 0 && its_true(c) != 1)
		return (-1);
	return (j);
}

static int	*ft_manage1(char *str, int *i, t_p *p, va_list ap)
{
	if ((i[2] = ft_rest(str[i[0]], ap, p)) != -1)
	{
		i[1] += i[2];
		i[0]++;
	}
	else
	{
		if ((its_true(str[i[0]]) != 1) && (str[i[0]]))
			i[1] += ft_mod1(p, str[i[0]]);
		i[0] += (str[i[0]]) ? 1 : 0;
	}
	return (i);
}

static int	ft_manage(char *str, va_list ap)
{
	int		*i;
	int		j;
	t_p		*p;

	i = malloc(sizeof(int) * 3);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (str[i[0]] != '\0')
	{
		if (str[i[0]] == '%')
		{
			i[0]++;
			p = malloc(sizeof(t_p));
			ft_init(p, (char *)str, i[0]);
			i[0] = precision(p, str, i[0]);
			i = ft_manage1(str, i, p, ap);
			free(p);
		}
		else
			i[1] += ft_putchar_mod(str[i[0]++]);
	}
	j = i[1];
	free(i);
	return (j);
}

int			ft_printf(char const *args, ...)
{
	va_list ap;
	int		j;

	j = 0;
	va_start(ap, args);
	j = ft_manage((char *)args, ap);
	va_end(ap);
	return (j);
}
