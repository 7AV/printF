/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:26:19 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 12:14:26 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_ppwp(t_save *data, int perc, int perc_len, int *len)
{
	while (data->precision > perc_len)
	{
		ft_putchar_fd('0', 1);
		perc_len++;
		*len += 1;
	}
	ft_putchar_fd(perc, 1);
}

int				ft_percent_type(t_save *data)
{
	int			perc_len;
	int			len;

	perc_len = 1;
	len = perc_len;
	if (data->width != 0)
	{
		if (data->flags == 2)
			ft_ppwp(data, '%', perc_len, &len);
		while ((data->width > data->precision) && (data->width > perc_len))
		{
			if ((data->precision == 0) && (data->flags == 1))
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			data->width -= 1;
			len++;
		}
		if (data->flags != 2)
			ft_ppwp(data, '%', perc_len, &len);
	}
	else
		ft_ppwp(data, '%', perc_len, &len);
	return (len);
}
