/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:39:33 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 21:11:51 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_isdig(int a)
{
	if ((a >= '1') && (a <= '9'))
		return (1);
	return (0);
}

static int	ft_is_comstar(char **line, int *prc_len, t_save *data, va_list ap)
{
	if (((*line)[0] == '.') && ((*line)[1] == '*'))
	{
		data->precision = va_arg(ap, int);
		if (data->precision == 0)
			data->dota = 42;
		if (data->precision < 0)
			data->precision = 0;
		*prc_len += 2;
		*line += 2;
		return (1);
	}
	if ((*line)[0] == '*')
	{
		data->precision = va_arg(ap, int);
		if (data->precision == 0)
			data->dota = 42;
		if (data->precision < 0)
			data->precision = 0;
		*prc_len += 1;
		*line += 1;
		return (1);
	}
	return (0);
}

static int	ft_is_comnull(char **line, int *prc_len, int *dota)
{
	if (((*line)[0] == '.') && ((*line)[1] == '0') && (!(ft_isdig((*line)[2]))))
	{
		*dota = 42;
		*prc_len += 2;
		*line += 2;
		return (1);
	}
	if (((*line)[0] == '.') && (!(ft_isdigit((*line)[1]))))
	{
		*dota = 42;
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

int			ft_precision_parse(char *line, t_save *data, int *ptr, va_list ap)
{
	int		prc_len;
	int		check;
	char	*tmp;

	prc_len = 0;
	check = 0;
	if (ft_is_comstar(&line, &prc_len, data, ap))
		return (prc_len);
	if (ft_is_comnull(&line, &prc_len, &data->dota))
		return (prc_len);
	tmp = ft_strdup(line);
	while (ft_isdigit(*line))
	{
		prc_len++;
		line++;
		ft_double_trouble(&line, &prc_len, ptr);
	}
	tmp[prc_len] = '\0';
	data->precision = ft_atoi(tmp);
	free(tmp);
	return (prc_len);
}
