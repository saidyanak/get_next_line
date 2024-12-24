/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:34:25 by syanak            #+#    #+#             */
/*   Updated: 2024/12/24 19:35:19 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char	*content;

	void	*next;
}			t_list;

size_t		ft_len(t_list *list);
t_list		*ft_last_node(t_list *list);
int			ft_found_nl(t_list *list);
void		copy_line(t_list *list, char *line);
void		ft_free_linked_list(t_list **list, t_list *new_node, char *buf);
char		*get_next_line(int fd);

#endif
