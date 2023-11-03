/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:50:08 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/03 15:28:42 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char const *arr);
char	*ft_strncpy(char *dest, char *src, int n);
int		check_buf_newline(char *buf, char *save_buf, int *index, int buf_sz);
char	*reallocate(char *buf, int *buf_sz, int new_buf_sz);
char	*get_next_line(int fd);
char	*read_file(int fd);
void	str_clean(char *buf, int size);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

typedef struct s_lst
{
	int				file;
	char			save_buf[BUFFER_SIZE];
	struct s_lst	*next;
	struct s_lst	*before;
}	t_lst;

t_lst	*ft_lstnew(int fd, const t_lst *head);
void	lst_pull(t_lst *ptr);

//first header static으로 선언 후 next next next... 하면서 일치하는 fd의 save_buf 가져오기
#endif
