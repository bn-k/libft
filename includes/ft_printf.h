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
# define DEATH -1
# define NO 0 
# define EXALT 1
# define TRUNK_SIZE 1000

// typedef
//

typedef struct	s_total
{
	char	**trunk;
	char	**format;
	int	*quanta;
	va_list *ap;
}		t_total;

typedef struct s_body
{
	// slice
	int	len;
	char	minus; // minus
	// flag
	char	dash; // dash
	char 	space; //void 
	char	apos; 
	char	plus; // add
	char	zero;
	char 	sharp; //sharp
	// field minimun / precision 
	int	width; 
	int	distance; // distance 
	int	precis; 
	int	fill; 
	char	point; 
	// mod 
	char h;
	char l;
	char j;
	char z;
	char q;
} t_body; // being

typedef struct s_genome
{
	char 	type;
	t_body	(*t_genome)(va_list, const char**, t_body);
} t_genome;

//genuine
void	math(char *s, t_body *body);
void	d_math(int long long i, t_body *body);
void	u_math(unsigned long long i, t_body *body);
void	o_math(unsigned long long i, t_body *body);
void	x_math(unsigned long long i, t_body *body); 
void	math_utf8(wchar_t *s, t_body *body);
size_t	conv_utf8(char *s, wchar_t wc, int limit); // caster unicode

//test
void	test_1(void); // driver
void	test_2(void);
void	test_3(char *s, char *s2);

// main
int		ft_printf(const char *format, ...);

// parsing
void	flags(const char **format, t_body *body);
void	format_parsing(const char **format, t_body *body); // spreading from genome
void	init(t_body *body); // init_body 
void	modifier(const char **format, t_body *body );

// dispatcher

t_body	body_birth(va_list ap, const char **format, t_body body); // body_birth
t_body 	c_genome(t_body body); 
t_body 	di_genome(t_body body);
t_body 	o_genome(t_body body);
t_body 	u_genome(t_body body);
t_body 	x_genome(t_body body);
t_body	dd_genome(t_body body);
t_body	p_genome(t_body body);
t_body 	no_genome(t_body body);
t_body 	mod_genome(t_body body);

// fill trunk
t_body	c_on_trunk(char c, t_body body);
t_body	cc_on_trunk(wchar_t c, t_body body);
t_body	s_on_trunk(char *s, t_body body);
t_body	ss_on_trunk(wchar_t *s, t_body body);
t_body	di_on_trunk(int long long i, t_body body);
t_body	o_on_trunk(unsigned long long d, t_body body); // o_trunker
t_body	u_on_trunk(unsigned int long long d, t_body body);
t_body	x_on_trunk(unsigned long long i, t_body body, char *base);
t_body	no_on_trunk(t_body body);

#endif
