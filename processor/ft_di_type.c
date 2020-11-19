/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:30 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/19 08:58:06 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_num_count(int num, int *count, int dota)
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
	if ((num < 0) && (num != -2147483648))
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	if (!((num == 0) && (data->dota)))
		ft_putnbr_fd(num, 1);
}

static void		ft_negative_num(long long *num, int num_len, t_save *data)
{
	if ((*num < 0) && (data->precision != 0))
		data->precision += 1;
	if ((*num < 0) && (data->width > num_len) && (data->flags == 1) &&
	(data->precision == 0))
	{
		ft_putchar_fd('-', 1);
		*num = *num * (-1);
	}
}

static void		ft_put_all(t_save *data, long long *num, int *num_len, int *len)
{
	if (data->flags == 2)
		ft_pnwp(data, *num, *num_len, len);
	while ((data->width > data->precision) && (data->width > *num_len))
	{
		if ((data->precision == 0) && (data->flags == 1))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		data->width -= 1;
		*len += 1;
	}
	if (data->flags != 2)
		ft_pnwp(data, *num, *num_len, len);
}

int				ft_di_type(t_save *data, va_list ap)
{
	long long	num;
	int			num_len;
	int			len;

	num_len = 0;
	num = va_arg(ap, int);
	ft_num_count(num, &num_len, data->dota);
	ft_negative_num(&num, num_len, data);
	len = num_len;
	if (data->width != 0)
		ft_put_all(data, &num, &num_len, &len);
	else
		ft_pnwp(data, num, num_len, &len);
	return (len);
}
