/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:00:43 by hyunjunl          #+#    #+#             */
/*   Updated: 2024/01/30 18:09:07 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_result {
	int	size;
	int	x;
	int	y;
}	t_result;

int				ft_strlen(char *str);
int				ft_str_is_printable(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);
int				ft_count(char *str, char c);
char			**ft_split(char *str, char sep);
char			*ft_memcpy(char *dest, char *src, unsigned int size);
char			*reallocate(char *buf, int *buf_sz, int new_buf_sz);
char			*read_file(int fd);
void			ft_putstr(char *str);
void			ft_puterr(void);
void			print_lines(char **lines);
void			update_result(int *dp, int width, int row, t_result *res);
t_result		solve_with_dp(char **lines, int **dp, int height, int width);
void			fill_square(char **lines, t_result res);
void			solve(char **lines, int height, int width);
int				check_height(char *str, int len, int height);
int				check_line(char *line, int width, char empty, char obstacle);
int				check_chrs(char *chrs);
int				is_valid(char **lines);
int				contain(char *str, int len, char c);
int				count_lines(char **lines);
int				*alloc_int_arr(int size);
int				min(int a, int b, int c);
void			free_strs(char **strs);
int				process_file(int fd);
int				process(char *file_name);

#endif
