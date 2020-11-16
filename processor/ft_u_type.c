/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:29 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 17:35:00 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_u_type(t_save *data, va_list ap)
{
	char		*output;
	int	i;
	i=data->type;
	
	output = ft_itoa(va_arg(ap, unsigned int));
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}
