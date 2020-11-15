/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:29:32 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 20:47:34 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_clean_data(t_save *data)
{
	data->flags = 0;
	data->width = 0;
	data->precision = 0;
	data->type = 0;
	data->lenght = 0;
	return (0);
}

int				ft_parser(char *line, int *ptr, va_list ap)
{
	t_save		*data;
	char		*tmp;
	int			line_len;
	
	tmp = line;
	line_len = 1;
	data = (t_save *)malloc(sizeof(t_save));
	line_len += ft_flag_parse(line + 1, &(data->flags), ptr);				// -0
	line_len += ft_width_parse(line + line_len, &(data->width), ptr);				// *.
	// line_len += ft_precision_parse(*line, &(data->precision));		// .*
	line_len += ft_type_parse(line + line_len, &(data->type));					// d&i, u, xX, chr, *str, *ptr

	*ptr += ft_processor(data, ap);
	ft_clean_data(data);
	return (line_len);
}