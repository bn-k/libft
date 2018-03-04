#ifndef FT_PRINT_F
# define FT_PRINT_F
# include "libft.h"
# include "utf8.h"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# define PAD_ZERO (!body->point && body->zero)
# define PAD_SPACE (!body->zero || body->point) 
# define SIGN (body->plus || body->minus)
# define FILL body->fill
# define POS(i) (i < 0 ? 0 : i) 
# define HASH (body->sharp && (!FILL && !PAD_ZERO))
# define BID 1000
# define DEATH -1
# define NO 0 
# define TRUNK_SIZE 1000

// typedef
//
extern char g_trunk[BID];
  
typedef struct	s_total
{
	const char	*format;
	int		i;
	int		quanta;
	va_list 	*ap;
}				t_total;

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
	int		width; 
	int		precis; 
	char	point; 
	// after mathematic
	int	fill; 
	int	left; // distance 
	int	right; // distance 
	// mod 
	char h;
	char l;
	char j;
	char z;
	char q;
} 				t_body;

typedef struct s_on_trunk
{
	char 	code;
	int	(*t_on_trunk)(t_total*, t_body*);
} t_on_trunk;

//kitchen
void	trunk(char *s, t_total *total, t_body *body);
void	trunk_unicode(wchar_t *s, t_total *total, t_body *body);
void	trunk_integers(char *s, t_total *total, t_body *body);
void	trunk_o(char *s, t_total *total, t_body *body);
void	trunk_x(char *s, t_total *total, t_body *body);

//test
void	test_1(void); // driver
void	test_2(void);

// main
int		ft_printf(const char *format, ...);
void	init_total(t_total *total, const char *format, va_list *ap);
void	charcat(char c, t_total *total);

// parsing
void	body_parser(t_total *total, t_body *body);
void	flags(t_total *total, t_body *body);
void	width_and_precision(t_total *total, t_body *body);
void	modifier(t_total *total, t_body *body);

// dispatcher

int 	c_on_trunk(t_total *total, t_body *body); 
int 	wc_on_trunk(t_total *total, t_body *body); 
int 	s_on_trunk(t_total *total, t_body *body); 
int 	ws_on_trunk(t_total *total, t_body *body); 
int 	d_on_trunk(t_total *total, t_body *body);
int 	o_on_trunk(t_total *total, t_body *body);
int 	u_on_trunk(t_total *total, t_body *body);
int 	x_on_trunk(t_total *total, t_body *body);
int		p_on_trunk(t_total *total, t_body *body);
int 	no_on_trunk(t_total *total, t_body *body);
int 	mod_on_trunk(t_total *total, t_body *body);

#endif
