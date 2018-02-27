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
# define SLICE_SIZE 2000000

// typedef
typedef struct s_mark
{
	// slice
	char	*slice;
	char	neg;
	int	slice_len;
	int	len;
	// flag
	char	minus;
	char 	space;
	char	apos;
	char	plus;
	char	zero;
	char 	hash;
	// field minimun / precision 
	int	width;
	int	pad;
	int	precis;
	int	fill;
	char	point;
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
	t_mark	(*t_function_type)(va_list, const char**, t_mark);
} t_function_type;

//tools
void	math(char *s, t_mark *mk);
void	d_math(int long long i, t_mark *mk);
void	u_math(unsigned long long i, t_mark *mk);
void	o_math(unsigned long long i, t_mark *mk);
void	x_math(unsigned long long i, t_mark *mk);
void	math_utf8(wchar_t *s, t_mark *mk);
size_t	conv_utf8(char *s, wchar_t wc, int limit);



//test
void	test_1(void);
void	test_2(void);
void	test_3(char *s, char *s2);

// main
int		ft_printf(const char *format, ...);

// parsing
void	flags(const char **format, t_mark *mk);
void	format_parsing(const char **format, t_mark *mk);
void	init(t_mark *mk);
void	modifier(const char **format, t_mark *mk );

// dispatch

t_mark	new_format(va_list ap, const char **format, t_mark mk);
t_mark 	s_spec(va_list ap, const char **format, t_mark mk);
t_mark 	ss_spec(va_list ap, const char **format, t_mark mk);
t_mark 	d_spec(va_list ap, const char **format, t_mark mk);
t_mark 	o_spec(va_list ap, const char **format, t_mark mk);
t_mark 	x_spec(va_list ap, const char **format, t_mark mk);
t_mark 	c_spec(va_list ap, const char **format, t_mark mk);
t_mark	dd_spec(va_list ap, const char **format, t_mark mk);
t_mark	p_spec(va_list ap, const char **format, t_mark mk);
t_mark 	u_spec(va_list ap, const char **format, t_mark mk);
t_mark 	no_spec(va_list ap, const char **format, t_mark mk);
t_mark 	pourcent_spec(va_list ap, const char **format, t_mark mk);

// display
t_mark	s_display(char *s, t_mark mk);
t_mark	c_display(char c, t_mark mk);
t_mark	ss_display(wchar_t *s, t_mark mk);
t_mark	cc_display(wchar_t c, t_mark mk);
t_mark	d_display(int long long i, t_mark mk);
t_mark	o_display(unsigned long long d, t_mark mk);
t_mark	x_display(unsigned long long d, t_mark mk, char *base);
t_mark	u_display(unsigned int long long d, t_mark mk);
t_mark	no_display(t_mark mk);

#endif
