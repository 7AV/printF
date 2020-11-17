/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:45:04 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 16:06:18 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_putline(char **line, int *output_len)
{
	while ((**line != '%'))
	{
		ft_putchar_fd(**line, 1);
		*line += 1;
		*output_len += 1;
		if (!**line)
			return (0);
	}
	return (1);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*line;
	int			output_len;
	char		*tmp;

	output_len = 0;
	va_start(ap, fmt);
	line = ft_strdup(fmt);
	tmp = line;
	while (*line)
	{
		if (!(ft_putline(&line, &output_len)))
		{
			va_end(ap);
			return (output_len);
		}
		line += ft_parser(line, &output_len, ap);
	}
	va_end(ap);
	free (tmp);
	return (output_len);
}