/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:24:33 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 11:36:45 by abbenham         ###   ########.fr       */
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
	while (i < 15)
	{
		if (*format[0] == func_tab[i].type)
			return (func_tab[i].t_function_type(ap, format, mk));
		i++;
	}
	return (mk);
}
