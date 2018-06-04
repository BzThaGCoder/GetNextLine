/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:54:58 by sjona             #+#    #+#             */
/*   Updated: 2018/05/30 04:50:13 by sjona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*str;

	length = 0;
	while (s1[length])
		length++;
	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
