/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:48:34 by jolopez-          #+#    #+#             */
/*   Updated: 2024/05/09 02:36:43 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include "get_next_line.h"

typedef enum e_location
{
	FRONT,
	BACK
}			t_location;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**********New Functions***********/
size_t			ft_strarraylen(char **strarray);
void			ft_clear_strarray(char **strarray);
char			*ft_strchr_pos(const char *s, int c, int pos);
void			ft_lstclear_nodes(t_list **lst);
void			ft_lstinsert(t_list **list, void *content, t_location location);
t_list			*ft_lstcopy(t_list *list, t_list *limit);
int				ft_chrcount(const char *string, int c);
int				ft_strequal(const char *str1, const char *str2);
char			*ft_strstrip(const char *string);
char			*ft_cutstr(const char *str, const char *strlimit);
int				ft_startswith(const char *string, const char *prefix);
char			*ft_concat_strarray(char **strarray, int joinchar);
int				ft_countalpha(const char *string);
int				ft_endswith(const char *string, const char *suffix);
char			*ft_strclean_withspaces(const char *string, int skip_pipe);
void			ft_strarr_add(
					char ***strarray, const char *newstring, int pos);
int				ft_strcontains(
					const char *fullstring, const char *string_tofind);
int				ft_is_space(const char c);
#endif
