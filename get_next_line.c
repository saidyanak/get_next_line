/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:07:55 by syanak            #+#    #+#             */
/*   Updated: 2024/12/09 20:05:54 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*add_stash(char *buff, char *stash)
{
	char	*ret;

	ret = 0;
	if (!stash && buff)
	{
		ret = ft_strdub(buff);
		if (!ret)
			return (NULL);
		return (ret);
	}
	ret = ft_strjoin(buff, stash);
	ft_free_stash(&stash);
	return (ret);
}

static int	find_nl(char *stash)
{
	while (*stash++ != '\n')
	{
		if (*stash == '\n')
			return (1);
	}
	return (0);
}
static char	*ft_extract_line(char *stash)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	j = 0;
	while (j < i + 1)
		temp[j++] = stash[i];
	temp[j] = 0;
	return (temp);
}
static char	*ft_recreate_stash(char *stash)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash));
	tmp = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!tmp)
		return (ft_free_stash(&stash), NULL);
	ft_free_stash(&stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = 0;
	readed = 1;
	while (readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (ft_free_stash(&stash), NULL);
		buff[BUFFER_SIZE] = 0;
		stash = add_stash(buff, stash);
		if (find_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash), NULL);
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash), line);
}
int	main(void)
{
	return (0);
}
