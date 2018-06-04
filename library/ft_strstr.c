/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:43:38 by sjona             #+#    #+#             */
/*   Updated: 2018/05/26 07:43:01 by sjona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	index;

	if (!*little)
	{
		return ((char *)big);
	}
	while (*big)
	{
		index = 0;
		while (big[index] == little[index])
		{
			if (!little[++index])
			{
				return ((char *)big);
			}
		}
		big++;
	}
	return (0);
}
