/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:43:49 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/16 14:45:45 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_is_star(char **line, int *width_len, int *width)
{
	if (((*line)[0] == '*') && (*(line)[1] == '.'))
	{
		*width = '*';
		*width_len += 2;
		*line += 2;
		printf(" +%d+ ", *width);
		return (1);
	}
	return (0);
}

int				ft_width_parse(char *line, int *width, int *ptr)
{
	int			width_len;
	int			check;
	char		*tmp;

	width_len = 0;
	check = 0;
	if (ft_is_star(&line, &width_len, width))
		return (width_len);
	tmp = ft_strdup(line);
	while (ft_isdigit(*line))
	{
		width_len++;
		line++;
		ft_double_trouble(&line, &width_len, ptr);
	}
	tmp[width_len] = '\0';
	*width = ft_atoi(tmp);
	// if (*line == '.')
		

	
	printf(" +%d+ ", *width);
	printf(" -%d- ", width_len);
	free(tmp);
	return (width_len);
}