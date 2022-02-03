/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:48:06 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/21 13:18:44 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*coord_data(int x, int y, char *data)
{
	t_vector	*point_data;

	point_data = (t_vector *)malloc(sizeof(t_vector) * 1);
	point_data->x = x;
	point_data->y = y;
	point_data->z = ft_atoi(data);
	point_data->rgb = hex_colour(ft_strchr(data, ','));
	return (point_data);
}

t_map	*normalize(t_vector *curr, t_map *map)
{
	int			i;
	int			j;
    
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			curr = &map->point_data[i][j];
			iso(curr);
			curr->x = (int)(1920 / 2 + ((curr->x - map->width / 2) * (1920 / map->width / 2) * 0.5));
			curr->y = (int)(1080 / 2 + ((curr->y - map->height / 2) * (1920 / map->width / 2) * 0.5));
			j++;
		}
		i++;
	}
	return (map);
}
