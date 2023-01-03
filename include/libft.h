/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:46:02 by NOAHHHHHHHH       #+#    #+#             */
/*   Updated: 2023/01/03 15:06:21 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_token {
	char			*content;
	struct s_token	*next;
}		t_token;

typedef struct s_input
{
	t_token			*token;
	int				in;
	int				out;
	int				pid;
	struct s_input	*next;
}		t_input;

int		ft_isalpha(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int character);
int		ft_isspace(char c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *array, size_t size);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memmove(void *destination, const void *source, size_t size);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);
size_t	ft_strlcat(char *destination, const char *source, size_t size);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);
int		ft_toupper(int character);
int		ft_tolower(int character);
int		ft_strchr(const char *string, int searchedChar);
char	*ft_strrchr(const char *string, int searchedChar);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strnstr(const char	*big, const char *little, size_t length);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *source);
char	*ft_strdup_and_free(char *source);
char	*ft_strldup(const char *source, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *string, char separator);
char	*ft_itoa(int number);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_token	*ft_lstlast(t_token *lst);
t_token	*ft_lst_before_last(t_token *lst);
void	ft_lstadd_back(t_token **lst, t_token *new);
void	ft_lstclear(t_token *stack);
void	ft_lstiter(t_token *lst, void (*f)(t_token *));
t_token	*ft_lstnew(char *content);
void	ft_insert_token(t_token *t, t_token *new);

#endif
