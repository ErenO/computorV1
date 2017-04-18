/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:13:18 by eozdek            #+#    #+#             */
/*   Updated: 2016/02/22 14:20:46 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		aux_dix(unsigned long long n, char *ans, int *p)
{
	if (9 < n)
		aux_dix(n / 10, ans, p);
	ans[(*p)++] = '0' + (n % 10);
}

static void		aux(t_ull n, t_ull b, char *ans, int *p)
{
	char const base[] = "0123456789ABCDEF";

	if (n >= b)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

char			*ft_ulltoa_base(t_ull value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || base > 16
		|| !(ans = (char *)malloc(sizeof(char) * (sizeof(t_ull) * 8 + 1))))
		return (NULL);
	p = 0;
	if (base == 10)
		aux_dix(value, ans, &p);
	else
		aux(value, (t_ull)base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
