/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:43:49 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/20 11:13:29 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_is_star(char **line, int *width_len, t_save *data, va_list ap)
{
	if ((*line)[0] == '*')
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width = data->width * (-1);
			data->flags = 2;
		}
		*width_len += 1;
		*line += 1;
		return (1);
	}
	return (0);
}

int			ft_width_parse(char *line, t_save *data, int *ptr, va_list ap)
{
	int		width_len;
	int		check;
	char	*tmp;

	width_len = 0;
	check = 0;
	if (ft_is_star(&line, &width_len, data, ap))
		return (width_len);
	tmp = ft_strdup(line);
	while (ft_isdigit(*line))
	{
		width_len++;
		line++;
		ft_double_trouble(&line, &width_len, ptr);
	}
	data->width = ft_atoi(tmp);
	free(tmp);
	return (width_len);
}
