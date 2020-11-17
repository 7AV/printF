/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:30 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 19:14:38 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putnbr(int num)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar_fd(num % 10 + '0', 1);
	}
	else
		ft_putchar_fd(num + '0', 1);
}

static void		ft_num_count(int num, int *count)
{
	if (num < 0)
		ft_num_count(-num, count);
	if (num >= 10)
	{
		ft_num_count(num / 10, count);
		*count += 1;
	}
	else
		*count += 1;
}

static void		ft_pnwp(t_save *data, int num, int num_len, int *len)
{
	while (data->precision > num_len)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num = -num;
		}
		ft_putchar_fd('0', 1);
		num_len++;
		*len += 1;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	ft_putnbr(num);
}

static void		ft_negative_num(int num, t_save *data)
{
	if ((num < 0) && (data->precision != 0))
		data->precision += 1;
}

int				ft_di_type(t_save *data, va_list ap)
{
	long long	num;
	int			num_len;
	int			len;

	num_len = 0;
	num = va_arg(ap, int);
	ft_num_count(num, &num_len);
	ft_negative_num(num, data);
	len = num_len;
	if (data->width != 0)
	{
		if (data->flags == 2)
			ft_pnwp(data, num, num_len, &len);
		while ((data->width > data->precision) && (data->width > num_len))
		{
			ft_putchar_fd(' ', 1);
			data->width -= 1;
			len++;
		}
		if (data->flags != 2)
			ft_pnwp(data, num, num_len, &len);
	}
	else
		ft_pnwp(data, num, num_len, &len);
	return (len);
}
