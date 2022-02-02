/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:53:34 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/20 13:52:11 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closefdf(void)
{
	exit(0);
	return (0);
}

int	keypress(int key, void *data)
{
	data = 0;
	if (key == 53)
		closefdf();
	return (0);
}

void	mlx_window(void *win)
{
	mlx_hook(win, 2, 1L << 0, keypress, 0);
	mlx_hook(win, 17, 1L << 17, closefdf, 0);
}
