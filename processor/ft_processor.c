/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:03:42 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 14:29:43 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_processor(t_save *data, va_list ap)
{
	int			len;
	
	len = 0;
	if (data->type == 1)
		len = ft_di_type(data, ap);	//+
	else if (data->type == 2)
		len = ft_u_type(data, ap);	//+
	else if (data->type == 3)
		len = ft_x_type(data, ap);	//+ +
	else if (data->type == 4)
		len = ft_xX_type(data, ap);	//+ +
	else if (data->type == 5)
		len = ft_c_type(data, ap);	//+ +
	else if (data->type == 6)
		len = ft_s_type(data, ap);	//+ +
	else if (data->type == 7)
		len = ft_p_type(data, ap);	//+ +
	return (len);
}