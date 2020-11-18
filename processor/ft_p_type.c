/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:05 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 12:26:04 by sbudding         ###   ########.fr       */
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

static void		ft_put_full_pointer(long long ptr)
{
	ft_putstr_fd("0x", 1);
	ft_put_pointer(ptr);
}

int				ft_p_type(t_save *data, va_list ap)
{
	long long	ptr;
	int			ptr_count;

	ptr = va_arg(ap, long long);
	ptr_count = 2;
	ft_pointer_count(ptr, &ptr_count);
	if (data->width != 0)
	{
		if (data->flags == 2)
			ft_put_full_pointer(ptr);
		while (data->width > ptr_count)
		{
			ft_putchar_fd(' ', 1);
			ptr_count++;
		}
		if (data->flags != 2)
			ft_put_full_pointer(ptr);
	}
	else
		ft_put_full_pointer(ptr);
	return (ptr_count);
}
