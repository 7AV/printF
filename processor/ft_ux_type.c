/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ux_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:48 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 21:33:05 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_hex_count(unsigned int num, int *count, int dota)
{
	if ((num == 0) && (dota))
	{
		*count = 0;
		return ;
	}
	if (num == 0)
	{
		*count = 1;
		return ;
	}
	if (num < 0)
		*count += 1;
	while (num / 16)
	{
		num = num / 16;
		*count += 1;
	}
	if (num % 16)
		*count += 1;
	return ;
}

static void		ft_put_hex(unsigned int num, int dota)
{
	if ((num == 0) && (dota))
		return ;
	if (num >= 16)
	{
		ft_put_hex(num / 16, dota);
		if ((num % 16) < 10)
			ft_putchar_fd(num % 16 + '0', 1);
		else
			ft_putchar_fd(num % 16 + '7', 1);
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num + '7', 1);
	}
}

static void		ft_phwp(t_save *data, long long hex, int hex_len, int *len)
{
	while (data->precision > hex_len)
	{
		ft_putchar_fd('0', 1);
		hex_len++;
		*len += 1;
	}
	ft_put_hex(hex, data->dota);
}

static void		ft_put_all(t_save *data, long long *hex, int *hex_len, int *len)
{
	if (data->flags == 2)
		ft_phwp(data, *hex, *hex_len, len);
	while ((data->width > data->precision) && (data->width > *hex_len))
	{
		if ((data->precision == 0) && (data->flags == 1))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		data->width -= 1;
		*len += 1;
	}
	if (data->flags != 2)
		ft_phwp(data, *hex, *hex_len, len);
}

int				ft_ux_type(t_save *data, va_list ap)
{
	long long	hex;
	int			hex_len;
	int			len;

	hex_len = 0;
	hex = va_arg(ap, long long);
	ft_hex_count(hex, &hex_len, data->dota);
	len = hex_len;
	if (data->width != 0)
		ft_put_all(data, &hex, &hex_len, &len);
	else
		ft_phwp(data, hex, hex_len, &len);
	return (len);
}
