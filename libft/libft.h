/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:34:29 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/18 13:37:44 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# define MAX_STRING_VECTOR	5000
# define FGNL_BUFF_SIZE		100
# define FGNL_FD_MAX		100

typedef struct	s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}				t_list;

typedef struct	s_fp_string
{
	char					str[MAX_STRING_VECTOR];
	size_t					length;
	int						fd;
}				t_fp_string;

typedef struct	s_fgnl_string
{
	char					str[FGNL_BUFF_SIZE];
	size_t					length;
	struct s_fgnl_string	*next;
}				t_fgnl_string;

/*
**	MEMORY FUNCTIONS
*/

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
**	STRING FUNCTIONS
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
size_t			ft_wstrlen(const wchar_t *str);
void			ft_strupr(char *str);
char			*ft_strnewc(size_t size, char c);

/*
**	LOGIC FUNCTIONS
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isall_digit(char *str);
int				ft_isall_hexdigit(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	OUTPUT FUNCTIONS
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbrll(long long n);
size_t			ft_putwchar_fd(wchar_t c, int fd);
size_t			ft_putwstrn_fd(wchar_t *str, size_t len, int fd);
void			ft_putchar_fd_smpl(char c, int fd);

/*
**	CHAINED LIST AND NODE FUNCTIONS
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel_free_content(t_list **alst);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew_fag(void *content, size_t content_size);
t_list			*ft_list_bublesort(t_list *begin_list, int (*f)(t_list *));
void			ft_list_murgesort(t_list **begin_list, \
		int (*f)(t_list *, t_list *));

/*
**	COUNT FUNCTIONS
*/

size_t			count_words(char **arr);
size_t			ft_countwords(char *str, char sep);

/*
**	STRING TO NUMBER
*/

int				ft_atoi(const char *str);
long long		ft_atoll(char const *s);
int				ft_atoi_base(const char *str, int base);

/*
**	NUMBER TO STRING
*/

char			*ft_itoa(int n);
char			*ft_lltoa_base(long long dgt, int base);
char			*ft_ulltoa_base(unsigned long long dgt, int base);
char			*ft_lltoa(long long n);
char			*ft_szttoa(size_t n);

/*
**	MIN MAX ABS
*/

int				ft_mini(int a, int b);
int				ft_maxi(int a, int b);
float			ft_minf(float a, float b);
float			ft_maxf(float a, float b);
double			ft_mind(double a, double b);
double			ft_maxd(double a, double b);
long long		ft_minll(long long a, long long b);
long long		ft_maxll(long long a, long long b);
int				ft_absi(int nbr);
float			ft_absf(float nbr);
double			ft_absd(double nbr);
long long		ft_absll(long long nbr);

/*
**	FPRINT FUNCTIONS
*/

size_t			fp_int_specifier(va_list argptr, t_fp_string *string);
size_t			fp_str_specifier(va_list argptr, t_fp_string *string);
size_t			fp_char_specifier(va_list argptr, t_fp_string *string);
size_t			fp_size_t_specifier(va_list argptr, t_fp_string *string);
size_t			fp_ll_specifier(va_list argptr, t_fp_string *string);
size_t			fprint(const char *format, ...);
size_t			fprint_fd(int fd, const char *format, ...);
size_t			fp_string_print(t_fp_string *string);
size_t			fp_string_fill(t_fp_string *string, char *src, size_t length);
size_t			fp_string_fill_nbr(t_fp_string *string, size_t value, \
		int length);

/*
**	FGNL FUNCTIONS
*/

t_fgnl_string	*fgnl_lstnew(const char *src, size_t length);
void			fgnl_lstdel(t_fgnl_string **head);
t_fgnl_string	**fgnl_head(int fd, char *command);
int				fgnl(int fd, char **line);
void			fgnl_free(void);

#endif
