/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:16 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 15:14:09 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_will_put(char *str, int prc)
{
	int			i;
	int			str_len;
	
	i = 0;
	str_len = ft_strlen(str);
	if (prc != 0)
		while ((i < prc) && (i < str_len))
			i++;
	if (prc == 0)
		i = ft_strlen(str);
	return (i);
}

static int		ft_put_s_with_prc(char *str, int prc)
{
	int			i;
	int			str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (prc > 0)
		while ((i < prc) && (i < str_len))
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	else if (prc == 0)
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
		i = ft_strlen(str);
	}
	// else
	// 	ft_putchar_fd("", 1);
	return (i);
}

int				ft_s_type(t_save *data, va_list ap)
{
	char		*output;
	int			len;
	int			will_put;

	len = 0;
	output = va_arg(ap, char*);
	if (output == NULL)
		output = "(null)";
	will_put = ft_will_put(output, data->precision);
	if (data->width != 0)
	{
		if (data->flags == 2)
			len += ft_put_s_with_prc(output, data->precision);
		while (data->width > will_put)
		{
			ft_putchar_fd(' ', 1);
			will_put++;
			len++;
		}
		if (data->flags != 2)
			len += ft_put_s_with_prc(output, data->precision);
	}
	else
		len += ft_put_s_with_prc(output, data->precision);
	return (len);
}
