/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:15:00 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/20 22:16:02 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_atoi_mod(const char *str, int *num)
{
	int		count;

	count = 0;
	while (ft_isdigit(*str))
	{
		count++;
		*num = *num * 10 + (*str - '0');
		str++;
	}
	return (count);
}
