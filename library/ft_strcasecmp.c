/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:11:52 by sjona             #+#    #+#             */
/*   Updated: 2018/06/04 14:10:42 by sjona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_str_tolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}

int					ft_strcasecmp(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	char	*tmp1;
	char	*tmp2;
	int		ret;

	str1 = ft_strdup(s1);
	str2 = ft_strdup(s2);
	ft_str_tolower(str1);
	ft_str_tolower(str2);
	tmp1 = str1;
	tmp2 = str2;
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	ret = (unsigned char)*str1 - (unsigned char)*str2;
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (ret);
}
