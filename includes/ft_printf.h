#ifndef FT_PRINT_F
# define FT_PRINT_F
# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# define POS(i) (i < 0 ? 0 : i)
# define SIGN (((mk.plus || mk.space) && (d >= 0)) || mk.neg)
# define PRECIS (mk.zero ? mk.width : mk.precis )
# define PAD (mk.zero ? 0 : POS(mk.width - (d < 0)))

// typedef
typedef struct s_mark
{
	char	minus;
	char 	space;
	char	apos;
	char	plus;
	char	zero;
	char 	hash;
	int		width;
	int		precis;
	int		len;
	char	point;
	char	neg;
	// mod 
	char h;
	char l;
	char j;
	char z;
	char q;
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
void	flags(const char **format, t_mark *mk);
void	format_parsing(const char **format, t_mark *mk);
t_mark		init(void);
void	modifier(const char **format, t_mark *mk );

// dispatch

size_t	new_format(va_list ap, const char **format);
size_t 	s_spec(va_list ap, const char *format, t_mark mk);
size_t 	ss_spec(va_list ap, const char *format, t_mark mk);
size_t 	d_spec(va_list ap, const char *format, t_mark mk);
size_t 	o_spec(va_list ap, const char *format, t_mark mk);
size_t 	x_spec(va_list ap, const char *format, t_mark mk);
size_t	dd_spec(va_list ap, const char *format, t_mark mk);
size_t	p_spec(va_list ap, const char *format, t_mark mk);
size_t 	u_spec(va_list ap, const char *format, t_mark mk);
size_t 	pourcent_spec(va_list ap, const char *format, t_mark mk);

// display
size_t	s_display(char *s, t_mark mk);
size_t	ss_display(wchar_t *s, t_mark mk);
size_t	d_display(int long long i, t_mark mk);
size_t	o_display(unsigned long long d, t_mark mk);
size_t	x_display(unsigned long long d, t_mark mk, char *base);
size_t	u_display(unsigned int long long d, t_mark mk);
int	rel_sous(int i, int d);


#endif
