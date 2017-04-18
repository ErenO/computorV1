/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:28:41 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/04/02 17:26:46 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H
# include <stdio.h>
# include "get_next_line.h"
# define ABS(v) (v < 0 ? (-v) : v)

typedef struct		s_list
{
	struct s_list	*next;
    double          i;
    int             e;
}					t_list;

typedef struct	s_poly
{
  t_list        *list;
  int           *tab;
  int           degrees;
  int           natural;
}				t_poly;

/*
** ft_list
*/
t_list	*ft_create_elem(int i, int e);
void	ft_list_push_front(t_poly *p, int i, int e);
int     ft_list_size(t_list *list);

/*
** parse_arg
*/
int     count_alpha(char *str);
char    *ft_epur(char *str);
char    *ft_parse_string(char *str);

/*
** parse_term
*/
void    ft_split_to_term(t_poly *p, char *str);
int    ft_atoi_plus(t_list *list, char *str);

/*
** print_result
*/
void    ft_print_calc(t_poly *p);
void    upper_degrees();
void    ft_calc_first_degrees(double zero, double one);
void    ft_calc_second_degrees(double a, double b, double c);

/*
** ft_list
*/
void    ft_calc_by_degrees(t_poly *p);
double  square_root(double num);
int     ft_numb_size(double nb);
int     ft_power(int nb, int power);

/*
** ft_double
*/
void    ft_print_double(double nb);
int     ft_number_decimal(double nb);

/*
** ft_error
*/
void    ft_error(int number);

/*
** delta
*/
void    ft_delta_positive(double a, double b, double delta);
void    ft_delta_negative();
void    ft_delta_zero(double a, double b);

/*
** natural_parse
*/
int natural_check(t_poly *p, char *str);
int is_natural_exp_1(char *str);
int is_natural_exp_0(char *str);
int is_natural_exp_sup(char *str);

#endif
