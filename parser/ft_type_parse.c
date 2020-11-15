/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:02:57 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 18:29:09 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_type_parse(char *line, int *type)
{
	int			type_len;

	type_len = 0;
	if (*line == 'd')
	{
		*type = 1;
		type_len++;
	}
	return (type_len);
}