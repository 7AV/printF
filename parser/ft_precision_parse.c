/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:39:33 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/20 22:24:09 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_is_comstar(char **line, int *prc_len, t_save *data, va_list ap)
{
	if (((*line)[0] == '.') && ((*line)[1] == '*'))
	{
		data->precision = va_arg(ap, int);
		if (data->precision == 0)
		{
			data->dota = 42;
			if (data->flags == 1)
			{
				data->flags = 0;
				data->dota2 = 1;
			}
		}
		if (data->precision < 0)
			data->precision = 0;
		*prc_len += 2;
		*line += 2;
		return (1);
	}
	return (0);
}

static int	ft_is_star(char **line, int *prc_len, t_save *data, va_list ap)
{
	if ((*line)[0] == '*')
	{
		data->precision = va_arg(ap, int);
		if (data->precision == 0)
		{
			data->dota = 42;
			if (data->flags == 1)
			{
				data->flags = 0;
				data->dota2 = 1;
			}
		}
		if (data->precision < 0)
			data->precision = 0;
		*prc_len += 1;
		*line += 1;
		return (1);
	}
	return (0);
}

static int	ft_is_comnotnull(char **line, int *prc_len, t_save *data)
{
	if (((*line)[0] == '.') && (!(ft_isdigit((*line)[1]))))
	{
		data->dota = 42;
		*prc_len += 1;
		*line += 1;
		return (1);
	}
	if ((*line)[0] == '.')
	{
		*prc_len += 1;
		*line += 1;
	}
	return (0);
}

static int	ft_is_comnull(char **line, int *prc_len, t_save *data)
{
	int		num;
	int		num_len;

	num = 0;
	num_len = ft_atoi_mod(*line + 1, &num);
	if (((*line)[0] == '.') && (!num))
	{
		if (data->flags == 1)
		{
			data->flags = 0;
			data->dota2 = 1;
		}
		data->dota = 42;
		*prc_len += num_len + 1;
		*line += num_len + 1;
		return (1);
	}
	return (0);
}

int			ft_precision_parse(char *line, t_save *data, int *ptr, va_list ap)
{
	int		prc_len;
	int		check;
	char	*tmp;

	prc_len = 0;
	check = 0;
	if (ft_is_comstar(&line, &prc_len, data, ap) ||
	ft_is_star(&line, &prc_len, data, ap))
		return (prc_len);
	if (ft_is_comnull(&line, &prc_len, data) ||
	ft_is_comnotnull(&line, &prc_len, data))
		return (prc_len);
	tmp = ft_strdup(line);
	while (ft_isdigit(*line))
	{
		prc_len++;
		line++;
		ft_double_trouble(&line, &prc_len, ptr);
	}
	data->precision = ft_atoi(tmp);
	free(tmp);
	return (prc_len);
}
