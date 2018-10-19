/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:21:16 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/16 22:25:54 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data	*add_data(int fd, t_data *data)
{
	t_data *data_new;

	data_new = (t_data *)malloc(sizeof(t_data));
	data_new->fd = fd;
	data_new->pointer = BUFF_SIZE + 1;
	data_new->buffer = malloc(BUFF_SIZE + 1);
	ft_memset(data_new->buffer, '\0', BUFF_SIZE + 1);
	data_new->next = data;
	return (data_new);
}

t_data	*get_data(int fd, t_data *data)
{
	while (data != NULL)
	{
		if (data->fd == fd)
			return (data);
		data = data->next;
	}
	return (NULL);
}

int		read_line(int fd, t_data **dt, char **line, int i)
{
	char tmp[BUFF_SIZE + 1];

	ft_memset(tmp, '\0', BUFF_SIZE + 1);
	if ((*dt)->pointer == BUFF_SIZE + 1)
	{
		if (((*dt)->last_char = read(fd, (*dt)->buffer, BUFF_SIZE)) == -1)
			return (-1);
		(*dt)->buffer[(*dt)->last_char] = '\0';
		(*dt)->pointer = 0;
	}
	while ((*dt)->buffer[(*dt)->pointer])
	{
		if ((*dt)->buffer[(*dt)->pointer++] == '\n' &&
				(*line = ft_strjoin(*line, tmp)))
			return (1);
		tmp[i++] = (*dt)->buffer[(*dt)->pointer - 1];
	}
	if ((*dt)->last_char == 0 && ft_strlen(*line) > 0)
		return (1);
	else if ((*dt)->last_char == 0)
		return (0);
	(*dt)->pointer = BUFF_SIZE + 1;
	*line = ft_strjoin(*line, tmp);
	return (read_line(fd, dt, line, 0));
}

int		get_next_line(const int fd, char **line)
{
	t_data			*tmp;
	static t_data	*data = NULL;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (data == NULL)
		data = add_data(fd, data);
	if ((tmp = get_data(fd, data)) == NULL)
		data = add_data(fd, data);
	tmp = get_data(fd, data);
	*line = ft_strdup("");
	return (read_line(fd, &tmp, line, 0));
}
