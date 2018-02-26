/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:24:33 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 14:05:20 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_function_type func_tab[] = {
	{'%', pourcent_spec},
	{'s', s_spec},
	{'c', c_spec},
	{'C', c_spec},
	{'S', ss_spec},
	{'d', d_spec},
	{'i', d_spec},
	{'D', dd_spec},
	{'p', p_spec},
	{'u', u_spec},
	{'U', u_spec},
	{'o', o_spec},
	{'x', x_spec},
	{'O', o_spec},
	{'X', x_spec},
	{'0', no_spec},
};

t_mark	new_format(va_list ap, const char **format, t_mark mk)
{
	int i;

	i = 0;
	format_parsing(format, &mk);
//	printf("New format:                   %s\n", *format);
	while (i < 15)
	{
		if (*format[0] == func_tab[i].type)
		{
			//printf("Format before return:    %s\n", *format);
			//printf("New_format return specc: %s\n", mk.slice);
 			//printf("Type:                    %c\n", func_tab[i].type) ;
			return (func_tab[i].t_function_type(ap, format, mk));
		}
		i++;
	}
	return (mk);
}

/*
   size_t	new_format2(va_list ap, const char **format)
   {
   int i;
   size_t	count;
   t_mark mk;

   i = 0;
   count = 0;
   (*format)++;
   format_parsing(format, &mk);
   while (i < 15)
   {
   if (*format[0] == func_tab[i].type)
   {
   if (-1 == (int)(count = func_tab[i].t_function_type(ap, *format, mk)))
   return (-1);
   else
   return (count);
   }
   i++;
   }
   mk.h = **format;
   return (func_tab[15].t_function_type(ap, *format, mk));
   return (0);
   }
   */
