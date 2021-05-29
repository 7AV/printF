/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:17:15 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/20 22:08:30 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_pointer_count(long long num, int *count)
{
	if (num >= 16)
	{
		ft_pointer_count(num / 16, count);
		*count += 1;
	}
	else
		*count += 1;
}

static void		ft_put_pointer(long long num)
{
	if (num >= 16)
	{
		ft_put_pointer(num / 16);
		if ((num % 16) < 10)
			ft_putchar_fd(num % 16 + '0', 1);
		else
			ft_putchar_fd(num % 16 + 'W', 1);
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num + 'W', 1);
	}
}

static void		ft_put_full_pointer(long long ptr, t_save *data, int *counter)
{
	long long	*ptr_ptr;

	ptr_ptr = &ptr;
	ft_putstr_fd("0x", 1);
	if ((data->dota) && (ptr == 0) && (data->precision == 0))
		*counter -= 1;
	else if (!((data->dota) && (data->width == 0) && (ptr == 0)))
		ft_put_pointer(ptr);
	else
		*counter -= 1;
}

static void		ft_put_all(t_save *data, long long *ptr, int *ptr_len)
{
	if (data->flags == 2)
		ft_put_full_pointer(*ptr, data, ptr_len);
	while (data->width > *ptr_len)
	{
		ft_putchar_fd(' ', 1);
		*ptr_len += 1;
	}
	if ((data->dota) && (*ptr == 0) && (data->precision == 0) &&
	(data->flags != 2) && (data->width > 2))
	{
		ft_putchar_fd(' ', 1);
		*ptr_len += 1;
	}
	if (data->flags != 2)
		ft_put_full_pointer(*ptr, data, ptr_len);
}

int				ft_p_type(t_save *data, va_list ap)
{
	long long	ptr;
	int			ptr_len;

	ptr = va_arg(ap, long long);
	ptr_len = 2;
	ft_pointer_count(ptr, &ptr_len);
	if (data->width != 0)
		ft_put_all(data, &ptr, &ptr_len);
	else
		ft_put_full_pointer(ptr, data, &ptr_len);
	return (ptr_len);
}
