/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:16 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 11:37:33 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_space_count(char *str, int len)
{
	int			i;

	i = 0;
	if (len != 0)
		while (len > i)
			i++;
	if (len == 0)
		i = ft_strlen(str);
	return (i);
}

static int		ft_put_s_with_prc(char *str, int len)
{
	int			i;

	i = 0;
	if (len != 0)
		while (len > i)
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	if (len == 0)
	{
		ft_putstr_fd(str, 1);
		i = ft_strlen(str);
	}
	return (i);
}

int				ft_s_type(t_save *data, va_list ap)
{
	char		*output;
	int			len;
	int			space_count;
	
	len = 0;
	output = va_arg(ap, char*);
	space_count = ft_space_count(output, data->precision);
	if (data->width != 0)
	{
		if (data->flags == 2)
			len += ft_put_s_with_prc(output, data->precision);
		while (data->width > space_count)
		{
			ft_putchar_fd(' ', 1);
			space_count++;
			len++;
		}
		if (data->flags != 2)
			len += ft_put_s_with_prc(output, data->precision);
	}
	else
		len += ft_put_s_with_prc(output, data->precision);
	return(len);
}