/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:31:05 by erenozde          #+#    #+#             */
/*   Updated: 2016/02/26 21:21:46 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_print_bits(unsigned char octet)
{
	int		nbr;
	char	*s;
	int		i;

	i = 0;
	if ((s = malloc(sizeof(char) * 8 + 1)) == NULL)
		return (NULL);
	nbr = 128;
	while (nbr > 0)
	{
		if (nbr <= octet)
		{
			s[i] = '1';
			i++;
			octet = octet - nbr;
		}
		else
		{
			s[i] = '0';
			i++;
		}
		nbr = nbr / 2;
	}
	s[i] = '\0';
	return (s);
}

static char		*ft_convert_binary(t_p *p, char *s, va_list ap)
{
	unsigned long long	i;
	char				*tmp;

	priority(p);
	tmp = s;
	i = va_arg(ap, unsigned long long);
	i = (p->l == 2) || (p->q > 0) ? (unsigned long long int)i : i;
	i = p->l != 2 && (p->l > 0) ? (unsigned long int)i : i;
	i = p->h == 2 ? (unsigned char)i : i;
	i = (p->h != 2) && (p->h > 0) ? (short unsigned int)i : i;
	i = p->j > 0 ? (uintmax_t)i : i;
	i = p->z > 0 ? (size_t)i : i;
	i = p->t > 0 ? (ptrdiff_t)i : i;
	if ((p->l == 0) && (p->h == 0) && (p->j == 0) && (p->t == 0) && (p->z == 0))
		i = (unsigned int)i;
	s = p->point == 1 && p->after == 0 && i == 0 ? s : ft_print_bits(i);
	p->point == 1 && p->after == 0 && i == 0 ? p->point : free(tmp);
	return (s);
}

int				ft_binary(va_list ap, t_p *p)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(0);
	s = ft_convert_binary(p, s, ap);
	p->zero = p->point == 1 && p->after == 0 ? 0 : p->zero;
	i = ft_space_x(p, s);
	return (i);
}
