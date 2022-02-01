/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:05:52 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/20 12:16:13 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	*new_image(t_fdf *mlx, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ln_len,
			&img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

static t_camera	new_camera(void)
{
	t_camera	new;

	new.x_off = 0;
	new.y_off = 0;
	new.zoom = 1;
	return (new);
}

static bool	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (false);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Wireframez");
	fdf->camera = new_camera();
	return (true);
}

