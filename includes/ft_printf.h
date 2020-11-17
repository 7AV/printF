/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:05:56 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 19:32:45 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_node
{
	int			flags;
	int			width;
	int			precision;
	int			type;
	int			lenght;
}				t_save;

int				ft_ux_type(t_save *data, va_list ap);
int				ft_x_type(t_save *data, va_list ap);
int				ft_u_type(t_save *data, va_list ap);
int				ft_s_type(t_save *data, va_list ap);
int				ft_p_type(t_save *data, va_list ap);
int				ft_di_type(t_save *data, va_list ap);
int				ft_c_type(t_save *data, va_list ap);
int				ft_processor(t_save *data, va_list ap);
int				ft_type_parse(char *line, int *type);
int				ft_precision_parse(char *line, int *prc, int *ptr, va_list ap);
int				ft_width_parse(char *line, int *width, int *ptr, va_list ap);
void			ft_double_trouble(char **line, int *flag_len, int *ptr);
int				ft_flag_parse(char *line, int *flags, int *ptr);
int				ft_parser(char *line, int *ptr, va_list ap);
int				ft_printf(const char *fmt, ...);

#endif
