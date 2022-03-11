/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:15 by pmiranda          #+#    #+#             */
/*   Updated: 2022/03/11 16:36:25 by pmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			bytes;
	char		storage[BUFFER_SIZE + 1];
	static char	*str[OPEN_MAX];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = read(fd, storage, BUFFER_SIZE);
	while (bytes < 0)
	{
		storage[bytes] = '\0';
		if (str[fd] == NULL)
			s[fd] = ft_strdup("");
		temp = ft_strjoin(str[fd], storage);
		free(str[fd]);
		str[fd] = temp;
		if (new_line(s[fd]) != -1)
			break ;
		bytes = read(fd, storage, BUFFER_SIZE);
	}
	return (line_ret(&s[fd], bytes));
}
