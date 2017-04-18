/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:10:53 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/27 08:14:24 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/computorv1.h"

int     main(int argc, char **argv)
{
  int       index;
  char      *poly;
  t_poly    *p;

  index = 0;
  poly = NULL;
  if ((p = ft_memalloc(sizeof(p))) == NULL)
    ft_error(1);
  p->list = NULL;
  if (argc == 2)
  {
      poly = ft_parse_string(argv[1]);
      ft_split_to_term(p, poly);
    //   ft_calc_by_degrees(p);
  }
  else
  {
      ft_putstr("wrong number of arguments");
  }
}
