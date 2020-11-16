/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:48 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 19:42:49 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_put_hex_with_count(unsigned int num, int *count)
{
	if (num >= 16)
	{
		ft_put_hex_with_count(num / 16, count);
		if ((num % 16) < 10)
			ft_putchar_fd(num % 16 + '0', 1);
		else
			ft_putchar_fd(num % 16 + '7', 1);
		*count += 1;
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num + '7', 1);
		*count += 1;
	}
}

int				ft_xX_type(t_save *data, va_list ap)
{
	int			count;
	int	i;
	i=data->type;
	
	count = 0;
	ft_put_hex_with_count(va_arg(ap, unsigned int), &count);
	return (count);
}