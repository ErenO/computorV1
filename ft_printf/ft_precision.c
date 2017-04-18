/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 22:32:30 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/22 20:06:13 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_skip_interval3(int i, char *str)
{
	char const print[] = "sSpdDioOuxXcC%b";

	while (!(ft_strchr(print, str[i])) || str[i] != '\0')
	{
		if (str[i] != 'l' && str[i] != '-' && str[i] != '+' && str[i] != ' '
			&& str[i] != 'z' && str[i] != 't' && str[i] != 'j' && str[i] != '#'
			&& str[i] != 'h' && str[i] != '*' && str[i] != '0'
			&& str[i] != 'q' && str[i] != '.'
			&& !(str[i] >= '1' && str[i] <= '9'))
			break ;
		i++;
	}
	return (i);
}

int				precision(t_p *p, char *str, int i)
{
	i = ft_skip_interval2(i, str);
	if (str[i] >= '1' && str[i] <= '9')
	{
		p->previous = ft_atoi(str + i);
		p->previous < 0 ? p->minus = 1 : p->previous;
		p->previous = p->previous < 0 ? -(p->previous) : p->previous;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '.' && p->point == 1)
	{
		(str[i + 1] != '.') ? i++ : p->zero == 0;
		i = ft_skip_interval2(i, str);
		if (str[i] >= '0' && str[i] <= '9')
		{
			p->after = ft_atoi(str + i);
			p->after < 0 ? p->minus = 1 : p->after;
			p->after = p->after < 0 ? -(p->after) : p->after;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
	}
	i = ft_skip_interval3(i, str);
	return (i);
}

static int		return_j(t_p *p, int j, int n, char *str)
{
	if (p->after > j && !(p->zero))
		j = p->previous - p->after - n;
	else
		j = p->previous - ft_strlen(str) - n;
	return (j);
}

static int		seconde(int j, t_p *p, char *str)
{
	int n;
	int i;
	int q;

	i = 0;
	n = ft_skip_interval(p);
	q = j;
	j = return_j(p, j, n, str);
	if (p->minus == 0 && p->zero == 0)
		while (j-- > 0)
			i += ft_putchar_mod(' ');
	i += (p->space == 1) ? ft_putchar_mod(' ') : 0;
	i += p->pointer == 1 ? ft_putstr_mod("0x") : 0;
	i += p->pointer == 3 ? ft_putstr_mod("0X") : 0;
	i += p->diese == 2 ? ft_putchar_mod('0') : 0;
	i += p->neg == 1 ? ft_putchar_mod('-') : 0;
	i += p->plus == 1 && p->positif > 0 ? ft_putchar_mod('+') : 0;
	i += put_zero(p, q);
	i += ft_putstr_mod(str);
	if (p->minus == 1 && p->zero == 0)
		while (j-- > 0)
			i += ft_putchar_mod(' ');
	return (i);
}

int				ft_space_x(t_p *p, char *str)
{
	int j;
	int i;
	int n;

	i = 0;
	j = ft_strlen(str);
	n = ft_skip_interval(p);
	p->zero = p->minus == 1 ? 0 : p->zero;
	p->zero = p->after > j ? 0 : p->zero;
	p->space = !(p->neg) && !(p->plus) ? p->space : 0;
	p->space = p->previous > j && p->zero == 0 ? 0 : p->space;
	i = seconde(j, p, str);
	free(str);
	return (i);
}
