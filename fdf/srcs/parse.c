/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:39:44 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/20 13:45:24 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<fcntl.h>
#include	<stdio.h>

static t_vector	*map_row(t_map *map, char **data)//takes t_map struct as arg
{
	t_vector	*row;
	int			i;

	if (!data)
		return (NULL);
	if (map->width == 0)
		while (data[map->width])
			map->width++;
	row = ft_calloc(sizeof(t_vector), map->width);
	if (row)
	{
		i = 0;
		while (i < map->width)
		{
			row[i] = coord_data(i, map->height, data[i]);
			i++;
		}
	}
	ft_freearry((void **)data);
	return (row);
}

static bool	populate_rows(t_map *map, t_vector *row)
{
	t_vector	**tmp;
	int			i;

	if (!row)
		return (false);
	tmp = ft_calloc(sizeof(t_vector *), map->height + 2);
	if (!tmp)
		return (false);
	i = map->height;
	tmp[i] = row;
	while (i-- > 0)
		tmp[i] = map->point_data[i];
	free(map->point_data);
	map->point_data = tmp;
	map->height++;
	return (true);
}

t_vector	**parsemap(t_map *map, char *file) 
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (!populate_rows(map, map_row(map, ft_split(line, ' '))))
		{
			free(line);
			close(fd);
			return (false);
		}
	}
	close(fd);
	return (map->point_data);
}

static t_vector normalize(t_map *map, t_vector p)
{
	p.x = (1920/2 + ((p.x - map->width/2) * (1920/map->width) / 2));
	p.y = (1080/2 + ((p.y - map->height/2) * (1080/map->height) / 2));
	return (p);
}

int main(int argc, char **argv)
{
	t_map		data;
	t_mlx		ptr;
	t_image		img;

	if (argc == 1)
		printf("%s", "No map file given\n");
	if (argc == 2)
	{
		ptr.mlx = mlx_init();
		ptr.win = mlx_new_window(ptr.mlx, 1920, 1080, "Screen");
		img = new_image(ptr.mlx, 1920, 1080);
		parsemap(&data, argv[1]);
		for(int i = 0; i < data.height; i++)
		{
			for(int j = 0; j < data.width; j++)
				put_pixel(&img, normalize(&data, data.point_data[i][j]));
			printf("\n");
		}
		mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
		mlx_window(ptr.win);
		mlx_loop(ptr.mlx);
		printf("Working on it\n");
	}
	return (0);
}

