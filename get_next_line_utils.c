/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:10 by syanak            #+#    #+#             */
/*   Updated: 2024/12/09 20:35:38 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdub(char *buff)
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

	if (!buff || !stash)
		return (NULL);
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

void	*ft_free_stash(char **stash)
{
}

char	*ft_substr(const char *stash, unsigned int start, size_t len)
{
	char	*ret;
	int		stash_len;

	stash_len = ft_strlen(stash);
	if (!stash || len <= 0)
		return (NULL);
	if (len > stash_len)
		len = stash_len;
}

int	ft_strlen(char *stash)
{
	if (*stash)
		return (ft_strlen(++stash) + 1);
	return (0);
}
