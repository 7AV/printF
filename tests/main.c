/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:06:59 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 11:09:04 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <stdarg.h>

typedef struct	s_node
{
	int			flags;
	int			width;
	int			precision;
	char		type;
	int			lenght;
}				t_save;

int				ft_processor(t_save *data, va_list ap)
{
	char		*output;
	
	output = NULL;
	if (data->type == 1)
	{
		output = ft_itoa(va_arg(ap, int));
		ft_putstr_fd(output, 1);
	}
	return (ft_strlen(output));
}

int				ft_type_parse(char *line, char *type)
{
	int			type_len;

	type_len = 0;
	line++;
	if (*line == 'd')
	{
		*type = 1;
		type_len++;
	}
	return (type_len);
}

int				ft_cleandata(t_save *data)
{
	data->flags = 0;
	data->width = 0;
	data->precision = 0;
	data->type = '0';
	data->lenght = 0;
}

int				ft_parser(char *line, va_list ap)	//возврат длинны %...type
{
	t_save		*data;
	char		*tmp;
	int			line_len;
	
	tmp = line;
	line_len = 1;
	data = (t_save *)malloc(sizeof(t_save));
	
	// line_len += ft_flag_parse(*line, &data->flags);
	// line_len += ft_widht_parse(*line, &data->width);
	// line_len += ft_precision_parse(*line, &data->precision);
	line_len += ft_type_parse(line, &data->type);

	ft_processor(data, ap);
	ft_clean_data(data);
	return (line_len);
}

int				ft_printf(const char *fmt, ...)		// printf("%d, %u, %x, %c, %s, %p", d&i, u, xX, chr, *str, *ptr);
{
	va_list		ap;
	char		*line;
	int			output_len;

	output_len = 0;
	va_start(ap, fmt);
	line = ft_strdup(fmt);
	while (*line)
	{
		while ((*line != '%'))
		{
			ft_putchar_fd(*line++, 1);
			output_len++;
			if (!*line)
			{
				va_end(ap);
				return (output_len);
			}
		}
		line += ft_parser(line, ap);
	 }
	va_end(ap);
	return (output_len);
}

int			main(void)
{
	ft_printf("%d%d 123 %d", 4221, 2, 1);
	printf("\n");
	printf("%d%d 123 %d", 4221, 2, 1);
	printf("\n");
	// printf("%s", ft_itoa(4221));
}