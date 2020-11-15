/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:45:04 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 12:01:09 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

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
		line += ft_parser(line, &output_len, ap);
	 }
	va_end(ap);
	return (output_len);
}