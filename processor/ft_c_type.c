/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:06:41 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 17:13:57 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_c_type(t_save *data, va_list ap)
{
	char		output;
	int	i;
	i=data->type;

	output = va_arg(ap, int);
	ft_putchar_fd(output, 1);
	return(1);
}
