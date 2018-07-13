/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 06:07:32 by sjona             #+#    #+#             */
/*   Updated: 2018/06/01 06:13:44 by sjona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisnumber(const char *s)
{
	if ((*s == '-' || *s == '+') && *(s + 1))
	{
		s++;
	}
	while (*s && ft_isdigit(*s))
		s++;
	return (*s ? 0 : 1);
}