/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:05 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 17:07:01 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_p_type(t_save *data, va_list ap)
{
	char		*output;
	int	i;
	i=data->type;
	
	output = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}