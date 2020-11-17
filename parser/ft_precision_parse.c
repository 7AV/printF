/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:39:33 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 19:29:19 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_is_comstar(char **line, int *prc_len, int *prc, va_list ap)
{
	if (((*line)[0] == '.') && ((*line)[1] == '*'))
	{
		*prc = va_arg(ap, int);
		*prc_len += 2;
		*line += 2;
		return (1);
	}
	if (((*line)[0] == '.') && ((*line)[1] != '*'))
	{
		*prc_len += 1;
		*line += 1;
		return (0);
	}
	if ((*line)[0] == '*')
	{
		*prc = va_arg(ap, int);
		*prc_len += 1;
		*line += 1;
		return (1);
	}
	return (0);
}

int				ft_precision_parse(char *line, int *prc, int *ptr, va_list ap)
{
	int			prc_len;
	int			check;
	char		*tmp;

	prc_len = 0;
	check = 0;
	if (ft_is_comstar(&line, &prc_len, prc, ap))
		return (prc_len);
	tmp = ft_strdup(line);
	while (ft_isdigit(*line))
	{
		prc_len++;
		line++;
		ft_double_trouble(&line, &prc_len, ptr);
	}
	tmp[prc_len] = '\0';
	*prc = ft_atoi(tmp);
	free(tmp);
	return (prc_len);
}
