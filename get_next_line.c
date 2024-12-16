/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:07:55 by syanak            #+#    #+#             */
/*   Updated: 2024/12/16 17:18:06 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*add_stash(char *buff, char *stash)
{
	char	*ret;

	ret = 0;
	if (!stash && buff)
	{
		ret = ft_strdup(buff);
		if (!ret)
			return (NULL);
		return (ret);
	}
	ret = ft_strjoin(buff, stash);
	ft_free_stash(&stash, 0);
	return (ret);
}

static int	find_nl(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
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
	{
		temp[j] = stash[j];
		j++;
	}
	temp[j] = 0;
	return (temp);
}

static char	*ft_recreate_stash(char *stash)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	tmp = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!tmp)
		return (ft_free_stash(&stash, 0), NULL);
	ft_free_stash(&stash, 0);
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
	line = NULL;
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1 || (readed <= 0 && !stash))
			return (ft_free_stash(&stash, 0));
		buff[readed] = 0;
		stash = add_stash(buff, stash);
		if (find_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}
