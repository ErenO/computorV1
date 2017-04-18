/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:29:03 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/19 14:29:21 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

double square_root(double num)
{
  double x1;
  double x2;

  x1 = (num * 1.0) / 2;
  x2 = (x1 + (num / x1)) / 2;
  while (ABS(x1 - x2) >= 0.0000001)
  {
    x1 = x2;
    x2 = (x1 + (num / x1)) / 2;
  }
  return (x2);
}
