#ifndef FT_PRINT_F
# define FT_PRINT_F
# include "libft.h"
# include <stdarg.h>

// typedef
typedef struct s_mark
{
	char	minus;
	char	plus;
	char	zero;
	char 	hash;
	int		width;
	int		precis;
} t_mark;

typedef struct s_function_type
{
	char 	type;
	size_t	(*t_function_type)(va_list, const char*, t_mark);
} t_function_type;


//test
void	test_1(void);
void	test_2(void);
void	test_3(char *s, char *s2);

// main
int		ft_printf(const char *format, ...);

// parsing
void	format_parsing(const char **format, t_mark *mk);
t_mark		init(void);

// dispatch

size_t	new_format(va_list ap, const char **format);
size_t 	s_spec(va_list ap, const char *format, t_mark mk);
size_t 	d_spec(va_list ap, const char *format, t_mark mk);
size_t 	pourcent_spec(va_list ap, const char *format, t_mark mk);

// display
size_t	s_display(char *s, t_mark mk);

//display tools
size_t		put_padding(int len);
size_t		put_precision(char *s, int len);
#endif
