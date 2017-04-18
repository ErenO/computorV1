/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eren_ozd <eren_ozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:29:18 by eren_ozd          #+#    #+#             */
/*   Updated: 2017/03/18 09:54:29 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computorv1.h"

int count_alpha(char *str)
{
  int i;
  int alpha;

  i = 0;
  alpha = 0;
  while (str[i] != '\0')
  {
    if (ft_strchr(" Xx123456789*+=-/", str[i]))
      alpha++;
    i++;
  }
  return (alpha);
}

char    *ft_epur(char *str)
{
  int   i;
  int   alpha;
  int   count;
  char  *s;

  i = 0;
  alpha = 0;
  count = 0;
  if (!(count = count_alpha(str)))
    return (NULL);
  if ((s = (char *)ft_memalloc(sizeof(char) * count)) == NULL)
    return (NULL);
  while (str[i] != '\0')
  {
    if (ft_strchr("Xx0123456789.^*+=-/", str[i]))
    {
        s[alpha] = str[i];
        alpha++;
    }
    i++;
  }
  s[alpha] = '\0';
  return (s);
}

char  *ft_parse_string(char *str)
{
    char *poly;

    poly = ft_epur(str);
    return (poly);
}
