/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:12:52 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/21 17:09:17 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_map	*normalize(t_map *map)
{
	int			i;
	int			j;
	t_vector	*curr;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			curr = &map->point_data[i][j];
			curr->x = (int)(1920 / 2 + ((curr->x - map->width / 2) * (1920 / map->width / 2) * 2));
			curr->y = (int)(1080 / 2 + ((curr->y - map->width / 2) * (1920 / map->width / 2) * 2));
			j++;
		}
		i++;
	}
	return (map);
}

t_rgb	colgrad(t_rgb c1, t_rgb c2, double percent)
{
	t_rgb	new;

	new.b = (1 - percent) * c1.b + percent * c2.b;
	new.g = (1 - percent) * c1.g + percent * c2.g;
	new.r = (1 - percent) * c1.r + percent * c2.r;
	return (new);
}

void	draw_line(t_image *img, t_vector p1, t_vector p2)
{
	int			i;
	double		slope;
	double		percent;
	t_vector	p3;

	p3 = p1;
	slope = (p2.y - p1.y) / (p2.x - p1.x);
	percent = 0.0;
	while (percent <= 1.0)
	{
		put_pixel(img, p3);
		if (fabs(p2.x - p1.x) > fabs(p2.y - p1.y))
		{
			p3.x += 1 - (2 * (p2.x < p1.x));
			p3.y = p1.y + slope * (p3.x - p1.x);
		}
		else
		{
			p3.y += 1 - (2 * (p2.y < p1.y));
			p3.x = p1.x + (p3.y - p1.y) / slope;
		}
		percent = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2)) / sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
		p3.rgb = colgrad(p1.rgb, p2.rgb, percent);
	}
}

void	draw(t_image *img, t_map *data, t_mlx *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j + 1 < data->width)
				draw_line(img, data->point_data[i][j], data->point_data[i][j + 1]);
			if (i + 1 < data->height)
				draw_line(img, data->point_data[i][j], data->point_data[i + 1][j]);
			if (i + 1 < data->width && j + 1 < data->width)
				draw_line(img, data->point_data[i][j], data->point_data[i + 1][j + 1]);
			if (i - 1 >= 0 && j + 1 < data->width)
				draw_line(img, data->point_data[i][j], data->point_data[i - 1][j + 1]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, img->img, 0, 0);
}
