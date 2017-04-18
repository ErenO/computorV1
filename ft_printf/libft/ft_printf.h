/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:01:37 by eozdek            #+#    #+#             */
/*   Updated: 2016/02/22 20:08:49 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <inttypes.h>
# include <sys/types.h>
# include <wchar.h>
# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef unsigned long long	t_ull;
typedef unsigned short int	t_usi;
typedef	struct	s_p
{
	int pointer;
	int h;
	int l;
	int point;
	int z;
	int diese;
	int previous;
	int after;
	int j;
	int positif;
	int zero;
	int minus;
	int plus;
	int space;
	int neg;
	int q;
	int t;
}				t_p;

int				ft_putstr_nb(char *str, int i);
void			priority(t_p *p);
int				ft_putwchar(wchar_t chr);
int				ft_putnwstr(const wchar_t *str, size_t len);
int				ft_wchar_str(va_list ap, t_p *p);
int				ft_wchar_char(va_list ap, t_p *p);
size_t			ft_wstrlen(const wchar_t *s, t_p *p);
wchar_t			*ft_wstrdup(wchar_t *wstr);
size_t			ft_wcharlen(wchar_t c);
int				ft_mod(t_p *p);
int				ft_mod1(t_p *p, char c);
wchar_t			*ft_cut_wstring(wchar_t *str, t_p *p);
wchar_t			*ft_strwsub(wchar_t const *s, unsigned int start, size_t len);
int				ft_wspace(t_p *p);
char			*char_str(char c);
int				ft_binary(va_list ap, t_p *p);
int				its_true(char c);
int				ft_skip_interval2(int i, char *str);
char			*ft_ulltoa_base(t_ull value, int base);
int				ft_putchar_mod(char c);
void			ft_putchar(char c);
int				ft_pointer(va_list ap, t_p *p);
int				ft_octal(va_list ap, t_p *p, char c);
int				ft_hexa(va_list ap, char c, t_p *p);
int				ft_unsigned(va_list ap, t_p *p, char c);
int				ft_string(va_list ap, t_p *p);
char			*ft_putzero(char *str, t_p *p);
int				ft_putstr_zero(int i, char c);
int				ft_putstr_mod(char *str);
int				ft_letters(char *str, int i);
int				ft_rest(char c, va_list ap, t_p *p);
int				ft_printf(char const *args, ...);
int				ft_number(va_list ap, t_p *p, char c);
void			ft_init(t_p *p, char *str, int i);
char			*ft_cut_string(char *str, t_p *p);
char			*ft_convert(t_p *p, char *s, int base, va_list ap);
int				flags_premier(t_p *p, char *str, int i);
int				flags_second(t_p *p, char *str, int i);
int				ft_char(va_list ap, t_p *p);
int				ft_space_x(t_p *p, char *str);
int				ft_space(t_p *p, char *str);
int				precision(t_p *p, char *str, int i);
int				ft_skip_interval(t_p *p);
int				put_zero(t_p *p, int j);

#endif
