/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:20:24 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/14 17:20:02 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

t_image	new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

int close(void)
{
	exit(0);
	return (0);
}

int	keypress(int key, void *data)
{
	data = 0;
	if (key == 53)
		close();
	return (0);
}

void init_hooks(void *win)
{
	mlx_hook(win, 2, 1L<<0, keypress, 0);
	mlx_hook(win, 17, 1L<<17, close, 0);
}

void	put_quad(t_image *img, int x, int y, int w, int h, int c)
{
	int	i;
	int	j;

	i = x;
	while (i < x + (w / 2))
	{
		j = y;
		while (j < y + (h / 2))
		{
			put_pixel(img, i, j, c);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Screen");
	img = new_image(mlx, 1000, 1000);
	put_quad(&img, 100, 600, 400, 300, 0xFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	init_hooks(mlx_win);
	mlx_loop(mlx);
}
