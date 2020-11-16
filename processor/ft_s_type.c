/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:07:16 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 17:29:47 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_s_type(t_save *data, va_list ap)
{
	char		*output;
	int	i;
	i=data->type;
	
	output = va_arg(ap, char*);
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}