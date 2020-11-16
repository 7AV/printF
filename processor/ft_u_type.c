/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:29 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 20:30:14 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	ft_putnbr_longlong(long long n, int *count)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", 1);
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_longlong(-n, count);
	}
	else if (n >= 10)
	{
		ft_putnbr_longlong(n / 10, count);
		ft_putchar_fd(n % 10 + '0', 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*count += 1;
	}
}

int			ft_u_type(t_save *data, va_list ap)
{
	int		count;
	int	i;
	i=data->type;
	
	count = 0;
	ft_putnbr_longlong(va_arg(ap, unsigned int), &count);
	return (count);
}
