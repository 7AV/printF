/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:30 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 16:16:10 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_di_type(t_save *data, va_list ap)
{
	char		*output;
	int	i;
	i=data->type;
	
	output = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}