/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:45:04 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/14 14:31:11 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int				ft_printf(const char *fmt, ...)		// printf("%d, %u, %x, %c, %s, %p", d&i, u, xX, chr, *str, *ptr, f, g, n, e);
{
	va_list		ap;
	char			*format;

	int				d&i;	//десятичное знаковое по умолчанию правое выравнивание
	unsigned int	u;		//десятичное беззнаковое
	unsigned int	xX;		//16-ричное беззнаковое lower/upper case
	int				chr;
	char			*str;	//вывод с '\0'
	//char			*ptr;	//узнать тип вывести пойнтер на него
					%%		//%% вывод процента
	//bonus part
	double			f;
	double			g;
					n;
					e;

	ind = 0 ;
	va_start(ap, fmt);		//	установка на 1й элемент
	format = ft_strdup(fmt);
	while (*format)
	{
		while (*format != '%')
		{
			write(1, format, 1);
			format++;
		}
		ft_processor(ft_parser(format, int));
		
	}
	
	d&i = va_arg(ap, int);

	u = va_arg(ap, unsigned int);

	xX = va_arg(ap, unsigned int);

	//  и т.д.

	va_end(ap);
}