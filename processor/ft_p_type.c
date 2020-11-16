/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:05 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 20:31:02 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_put_hex_with_count(long long num, int *count)
{
	if (num >= 16)
	{
		ft_put_hex_with_count(num / 16, count);
		if ((num % 16) < 10)
			ft_putchar_fd(num % 16 + '0', 1);
		else
			ft_putchar_fd(num % 16 + 'W', 1);
		*count += 1;
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num + 'W', 1);
		*count += 1;
	}
}

int				ft_p_type(t_save *data, va_list ap)
{
	int	i;
	i=data->type;
	int count;
	
	count = 0;
	ft_putstr_fd("0x", 1);
	ft_put_hex_with_count(va_arg(ap, long long), &count);
	return (count + 2);
}