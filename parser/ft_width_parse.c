/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:43:49 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 20:45:14 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_width_parse(char *line, int *width, int *ptr)
{
	int		width_len;
	int			check;
	char		*tmp;

	width_len = 0;
	check = 0;
	tmp = line;
	while (ft_isalpha(*line))
	{
		width_len++;
		line++;
		ft_double_trouble(&line, &width_len, ptr);
	}
	tmp[width_len] = '\0';
	*width = ft_atoi(tmp);
	printf(" -%d- ", width_len);
	return (width_len);
}