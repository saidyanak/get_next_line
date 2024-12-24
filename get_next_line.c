/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:28:59 by syanak            #+#    #+#             */
/*   Updated: 2024/12/24 20:27:24 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	recreate_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*buf;
	int		i;
	int		k;

	i = 0;
	k = 0;
	last_node = ft_last_node(*list);
	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!buf || !new_node)
		return ;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i])
	{
		buf[k] = last_node->content[++i];
		k++;
	}
	buf[k] = '\0';
	new_node->content = buf;
	new_node->next = NULL;
	ft_free_linked_list(list, new_node, buf);
}

static char	*ft_extract_line(t_list *list)
{
	char	*line;
	size_t	line_len;

	line_len = ft_len(list);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	copy_line(list, line);
	return (line);
}

static void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

static void	ft_create_list(t_list **list, int fd)
{
	int		readed;
	char	*buf;

	while (!ft_found_nl(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == 0 || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		append(list, buf);
		if (!*list)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	line = ft_extract_line(list);
	if (!line)
		return (NULL);
	recreate_list(&list);
	return (line);
}
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*prt;

	prt = get_next_line(5);
	printf("%s",prt);
}
