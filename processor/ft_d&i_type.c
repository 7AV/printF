/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d&i_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:30 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 13:14:17 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include "../includes/ft_parser.h"

int				ft_processor(t_save *data, va_list ap)
{
	char		*output;
	
	output = NULL;
	output = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}