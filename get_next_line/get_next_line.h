/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/03 14:01:20 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char const *arr);
char	*ft_strncpy(char *dest, char *src, int n);
int		check_buf_newline(char *buf, int *index, int buf_sz);
char	*reallocate(char *buf, int *buf_sz, int new_buf_sz);
char	*get_next_line(int fd);
char	*read_file(int fd);
void	str_clean(char *buf, int size);

#endif
