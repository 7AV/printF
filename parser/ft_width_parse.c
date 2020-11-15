/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:43:49 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/15 18:57:50 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/ft_printf.h"

// int				ft_width_parse(char *line, int *width)
// {
// 	int			flag_len;
// 	int			check;

// 	flag_len = 0;
// 	check = 0;
// 	while ((*line) && (*line != '%') && (!ft_isdig(*line)) &&
// 	(*line != '*') && (*line != '.') && (!ft_isalpha(*line)))
// 	{
// 		if (*line == '-')
// 		{
// 			*width = 2;
// 			check++;
// 		}
// 		if ((*line == '0') && (!check))
// 			*width = 1;
// 		flag_len++;
// 		line++;
// 	}
// 	printf(" -%d- ", flag_len);
// 	return (flag_len);
// }