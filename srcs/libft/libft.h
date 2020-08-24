/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:45:38 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/22 02:43:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_flag
{
	size_t			dash;
	size_t			zero;
	size_t			dot;
	int				pad;
	int				pre;
}					t_flag;

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
long				ft_iswhitespaces(const char *str);

/*
** the first layer, checks for flags, width, precision (-0.)
** ends with a format check (ft_format) and sends them there
*/

void				ft_flags(const char *format, int *i, t_flag *flags);
void				ft_width(const char *format, int *i,
								va_list argp, t_flag *flags);
void				ft_precision(const char *format, int *i,
							va_list argp, t_flag *flag);

/*
** second layer, comes from ft_format, which checks for pdiuxX%
** the following functions are called upon depending on which
** conversion is used.
** these functions call the padding and precision functions if
** needed and then call the function that is actually responsible
** for printing the values correctly
*/

void				ft_hex(const char c, unsigned long n, int *count,
								t_flag *flags);
void				ft_ptr(unsigned long n, int *count, t_flag *flags);
void				ft_signed(long n, int *count, t_flag *flags);
void				ft_unsigned(unsigned long n, int *count, t_flag *flags);

/*
** these functions handle the padding AND
** printing of strings or characters. Unlike number functions
** which need an extra function to do so as shown above.
*/

void				ft_print_char(const char c, int *count, t_flag *flags);
void				ft_print_str(const char *str, int *count, t_flag *flags);

/*
** these functions handle the printing of numeric values
*/

void				ft_print_hex(const char c, unsigned long nb, int *count);
void				ft_print_decimal(unsigned long n, int *count);

/*
** these functions handle the 0 padding or ' ' padding if needed
*/

void				ft_pad(int n, int *count);
void				ft_padzero(int n, int *count);

/*
** printf's putchar & putstr
** checks if any write output is < 0 and if so, sets count to -1 to show
** that an error occured.
*/

void				pft_putchar_fd(char c, int fd, int *count);
void				pft_putstr_fd(char *s, int fd, int *count);

int					ft_printf(const char *format, ...);
#endif
