/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:05:56 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 20:31:19 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
// #include "../includes/ft_parser.h"
// #include "../includes/ft_processor.h"
#include <stdarg.h>

typedef struct	s_node
{
	int			flags;
	int			width;
	int			precision;
	int			type;
	int			lenght;
}				t_save;

int				ft_processor(t_save *data, va_list ap);
int				ft_type_parse(char *line, int *type);
int				ft_width_parse(char *line, int *width);
void			ft_double_trouble(char **line, int *flag_len, int *ptr);
int				ft_flag_parse(char *line, int *flags, int *ptr);
int				ft_parser(char *line, int *ptr, va_list ap);
int				ft_printf(const char *fmt, ...);

#endif