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
# define BID 1
# define DEATH -1
# define NO 0 
# define EXALT 1
# define TRUNK_SIZE 1000

// typedef
//
char g_trunk[BID];
  
typedef struct	s_total
{
	const char	*format;
	int		i;
	int		quanta;
	va_list 	*ap;
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
	int	precis; 
	char	point; 
	// after mathematic
	int	fill; 
	int	distance; // distance 
	// mod 
	char h;
	char l;
	char j;
	char z;
	char q;
} t_body; // being

typedef struct s_on_trunk
{
	char 	code;
	t_total	(*t_on_trunk)(t_total*, t_body*);
} t_on_trunk;

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
int	ft_printf(const char *format, ...);
void	init_total(t_total *total, const char *format, va_list *ap);
t_total	charcat(char c, t_total *total);
void	materialize(t_total total);


// parsing
void	body_parser(t_total *total, t_body *body);
void	flags(t_total *total, t_body *body);
void	width_and_precision(t_total *total, t_body *body);
void	modifier(t_total *total, t_body *body);

// dispatcher

t_total 	c_on_trunk(t_total *total, t_body *body); 
t_total 	s_on_trunk(t_total *total, t_body *body); 
t_total 	d_on_trunk(t_total *total, t_body *body);
t_total 	o_on_trunk(t_total *total, t_body *body);
t_total 	u_on_trunk(t_total *total, t_body *body);
t_total 	x_on_trunk(t_total *total, t_body *body);
t_total		dd_on_trunk(t_total *total, t_body *body);
t_total		p_on_trunk(t_total *total, t_body *body);
t_total 	no_on_trunk(t_total *total, t_body *body);
t_total 	mod_on_trunk(t_total *total, t_body *body);

#endif
