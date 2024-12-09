/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:43:24 by syanak            #+#    #+#             */
/*   Updated: 2024/12/09 20:29:12 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strdub(char *buff);
char	*ft_strjoin(char *buff, char *stash);
void	*ft_free_stash(char **stash);
char	*ft_substr(const char *stash, unsigned int start, size_t len);
int		ft_strlen(char *stash);

#endif
