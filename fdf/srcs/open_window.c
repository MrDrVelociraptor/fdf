/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:20:24 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/13 11:22:34 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

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

void	put_quad(t_image *img, int x, int y, int w, int h, int c)
{
	for (int i = x; i < x + (w/2); i++)
		for (int j = y - (h/2); j < y + (h/2); j++)
			put_pixel(img, i, j, c);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Screen");
	img = new_image(mlx, 1920, 1080);
	put_quad(&img, 100, 600, 400, 300, 0xFF00);
	put_quad(&img, 600, 300, 100, 50, 0xFF);
	put_quad(&img, 1500, 700, 200, 200, 0xFF0000);	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
