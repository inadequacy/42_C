/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:07:42 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/19 12:07:42 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* check a single character */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* modify a letter */
int		ft_tolower(int c);
int		ft_toupper(int c);

/* modify a string */
char	**ft_split(const char *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/* also returns it as a new string */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* conversion */
int		ft_atoi(const char *nptr);			// string to number
char	*ft_itoa(int n);					// number to string

/* search */
char	*ft_strchr(const char *s, int c);

/* erase */
void	ft_bzero(void *s, size_t n);

/* print-like functions */
void	ft_putchar_fd(char c, int fd);		// one character
void	ft_putstr_fd(char *s, int fd);		// a string
void	ft_putendl_fd(char *s, int fd);		// a string & new line
void	ft_putnbr_fd(int n, int fd);		// number

/* no idea */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	*ft_calloc(size_t nelem, size_t elsize);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);

/* list modifying functions */
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);	
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif