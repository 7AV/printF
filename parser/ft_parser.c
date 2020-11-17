/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:29:32 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 21:04:29 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_parser(char *line, int *ptr, va_list ap)
{
	t_save		*data;
	char		*tmp;
	int			line_len;

	tmp = line;
	line_len = 1;
	if (!(data = (t_save *)malloc(sizeof(t_save))))
		return (-1);
	line_len += ft_flag_parse(line + 1, &(data->flags), ptr);
	line_len += ft_width_parse(line + line_len, &(data->width), ptr, ap);
	line_len += ft_precision_parse(line + line_len,
	&(data->precision), ptr, ap);
	line_len += ft_type_parse(line + line_len, &(data->type));
	*ptr += ft_processor(data, ap);
	free(data);
	return (line_len);
}
