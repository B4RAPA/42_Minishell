/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:51:26 by lfabel            #+#    #+#             */
/*   Updated: 2025/01/23 11:54:26 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

size_t	ft_strle(char *s);
char	*ft_strndup_gnl(char *input, size_t n);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strnjoin_gnl(char *s1, char *s2, size_t n);
void	*ft_memmove_gnl(void *des, const void *src, size_t num);

char	*get_next_line(int fd);
char	*buffer_check(char *buf);
char	*zwei(char *line, char *buf);
char	*position(char *pos, char *line, char *buf);
char	*freigabe(char *line);

#endif