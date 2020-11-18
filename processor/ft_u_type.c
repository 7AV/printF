/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:29 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 20:29:03 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putnbr_longlong(long long num, int dota)
{
	if ((num == 0) && (dota))
		return ;
	if (num >= 10)
	{
		ft_putnbr_longlong(num / 10, dota);
		ft_putchar_fd(num % 10 + '0', 1);
	}
	else
		ft_putchar_fd(num + '0', 1);
}

static void		ft_unsign_count(unsigned int num, int *count, int dota)
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
	while (num / 10)
	{
		num = num / 10;
		*count += 1;
	}
	if (num % 10)
		*count += 1;
	return ;
}

static void		ft_puwp(t_save *data, long long uns, int uns_len, int *len)
{
	while (data->precision > uns_len)
	{
		ft_putchar_fd('0', 1);
		uns_len++;
		*len += 1;
	}
	ft_putnbr_longlong(uns, data->dota);
}

int				ft_u_type(t_save *data, va_list ap)
{
	long long	uns;
	int			uns_len;
	int			len;

	uns_len = 0;
	uns = va_arg(ap, unsigned int);
	ft_unsign_count(uns, &uns_len, data->dota);
	len = uns_len;
	if (data->width != 0)
	{
		if (data->flags == 2)
			ft_puwp(data, uns, uns_len, &len);
		while ((data->width > data->precision) && (data->width > uns_len))
		{
			if ((data->precision == 0) && (data->flags == 1))
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			data->width -= 1;
			len++;
		}
		if (data->flags != 2)
			ft_puwp(data, uns, uns_len, &len);
	}
	else
		ft_puwp(data, uns, uns_len, &len);
	return (len);
}
