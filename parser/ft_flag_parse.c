/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:39:27 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 15:58:27 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isdig(int a)
{
	if ((a >= '1') && (a <= '9'))
		return (1);
	return (0);
}

int				ft_flag_parse(char *line, int *flags)
{
	int			flag_len;
	int			check;

	flag_len = 0;
	check = 0;
	while ((*line) && (*line != '%') && (!ft_isdig(*line)) &&
	(*line != '*') && (*line != '.') && (!ft_isalpha(*line)))
	{
		if (*line == '-')
		{
			*flags = 2;
			check++;
		}
		if ((*line == '0') && (!check))
			*flags = 1;
		flag_len++;
	}
	// printf(" -%d- ", flag_len);
	return (flag_len);
}