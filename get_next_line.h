/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezkoro <tbezkoro@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:12 by tbezkoro          #+#    #+#             */
/*   Updated: 2022/11/22 16:52:51 by tbezkoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*ft_strjoin(char const *s1, char const *s2);
char	*cut_buf(char *buf);
char	*read_buf(int fd, char *buf);
size_t	ft_strlen(const char *str);
int		found_new_line(char *line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*get_line(char *buf);

#endif
