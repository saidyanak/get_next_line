/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:10 by syanak            #+#    #+#             */
/*   Updated: 2024/12/16 17:09:13 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(char *buff)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!buff)
		return (NULL);
	ret = malloc((ft_strlen(buff) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (*buff)
		ret[i++] = *buff++;
	return (ret[i] = 0, ret);
}

char	*ft_strjoin(char *buff, char *stash)
{
	char	*ret;
	size_t	i;

	if (!buff && !stash)
		return (NULL);
	if (!buff)
		return (ft_strdup(stash));
	if (!stash)
		return (ft_strdup(buff));
	ret = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(stash) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*stash)
		ret[i++] = *stash++;
	while (*buff)
		ret[i++] = *buff++;
	return (ret[i] = 0, ret);
}

void	*ft_free_stash(char **stash, int line)
{
	char	*ret;

	ret = 0;
	if (!stash)
		return (NULL);
	if (line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else
	{
		ret = ft_strdup(*stash);
		free(*stash);
		stash = NULL;
		return (ret);
	}
	return (NULL);
}

char	*ft_substr(const char *stash, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	stash_len;

	i = 0;
	if (!stash)
		return (NULL);
	stash_len = ft_strlen((char *)stash);
	if (start >= stash_len)
		return (ft_strdup(""));
	if (len > stash_len - start)
		len = stash_len - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len)
		ret[i++] = stash[start++];
	ret[i] = '\0';
	return (ret);
}

int	ft_strlen(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
		i++;
	return (i);
}
