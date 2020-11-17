/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:39:27 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 11:52:38 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isdig(int a)
{
	if ((a >= '1') && (a <= '9'))
		return (1);
	return (0);
}

void			ft_double_trouble(char **line, int *flag_len, int *ptr)
{
	while (((*line)[0] == '%') && ((*line)[1] == '%'))
	{
		ft_putchar_fd('%', 1);
		*flag_len += 2;
		*line += 2;
		*ptr += 1;
	}
}

int				ft_flag_parse(char *line, int *flags, int *ptr)
{
	int			flag_len;
	int			check;

	flag_len = 0;
	check = 0;
	ft_double_trouble(&line, &flag_len, ptr);
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
		// ft_double_trouble(&line, &flag_len, ptr);
		line++;
		flag_len++;
		ft_double_trouble(&line, &flag_len, ptr);
	}
	return (flag_len);
}
