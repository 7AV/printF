/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:21:51 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 12:09:54 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main (void)
{
		int *a;
		int b;
		b = 0;
		a = &b;
		// ft_puthex_fd(123456789, 1);
	// printf("%d", ft_printf("%*.d 123 %d %d",2, -4221, 2, 1));
	printf(" (%d)", ft_printf("%10p 123  %d  %d", "hello", 2, 1));
	printf("\n");
	// printf("%d", printf("%.*d 123 %d %d",2,  -4221, 2, 1));
	printf(" (%d)", printf("%10p 123  %d  %d", "hello", 2, 1));
}