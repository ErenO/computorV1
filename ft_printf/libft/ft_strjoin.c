/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:54:41 by eozdek            #+#    #+#             */
/*   Updated: 2016/01/07 16:02:22 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*ret1;
	char	*s3;
	char	*s4;

	s3 = (char *)s1;
	s4 = (char *)s2;
	if (!s2 || !s3)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen((s3) + ft_strlen(s4) + 1)));
	if (ret == NULL)
		return (NULL);
	ret1 = ret;
	while (*s1 != '\0')
		*ret1++ = *s1++;
	while (*s2 != '\0')
		*ret1++ = *s2++;
	*ret1 = '\0';
	return (ret);
}
