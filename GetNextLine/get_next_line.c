/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:16:06 by sjona             #+#    #+#             */
/*   Updated: 2018/06/26 02:04:23 by sjona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_stock(int const fd, char **info)
{
	char	*buffer;
	int		val;
	char	*tmp;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))))
		return (-1);
	val = read(fd, buffer, BUFF_SIZE);
	if (val > 0)
	{
		buffer[val] = '\0';
		tmp = ft_strjoin(*info, buffer);
		free(*info);
		*info = tmp;
	}
	free(buffer);
	return (val);
}

int			get_next_line(int const fd, char **line)
{
	char		*stri;
	int			value;
	static char	*detai = NULL;

	if ((!detai && (detai = (char *)malloc(sizeof(*detai))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	stri = ft_strchr(detai, '\n');
	while (stri == NULL)
	{
		value = read_to_stock(fd, &detai);
		if (value == 0)
		{
			if (ft_strlen(detai) == 0)
				return (0);
			detai = ft_strjoin(detai, "\n");
		}
		if (value < 0)
			return (-1);
		else
			stri = ft_strchr(detai, '\n');
	}
	*line = ft_strsub(detai, 0, ft_strlen(detai) - ft_strlen(stri));
	detai = ft_strdup(stri + 1);
	return (1);
}
