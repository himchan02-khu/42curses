/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:22:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/11 15:25:56 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isascii(int c);
int		ft_atoi(char const *str);
void	ft_bzero(void *ptr, size_t len);
void	*ft_calloc(size_t len, size_t size);
int		ft_isalnum(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int input);
void	*ft_memchr(const void *arr, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
void	*ft_memcpy(void *ptr, const void *src, size_t len);
void	*ft_memmove(void *ptr, const void *src, size_t len);
void	*ft_memset(void *ptr, int val, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char charset);
char	*ft_strchr(char const *str, char c);
char	*ft_strdup(const char *src);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *prefix, char const *suffix);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
int		ft_strlen(char const *arr);
char	*ft_strmapi(char const *str, char (*f) (unsigned int, char));
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(char *str, char c);
char	*ft_strtrim(char const *str, char const *word);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newlst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
