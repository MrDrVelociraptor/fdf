/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:24:44 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/01 15:24:46 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*normalize(t_map *map)
{
	int			i;
	int			j;
    t_vector   *curr;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			curr = &map->point_data[i][j];
			curr->x = (int)(1920 / 2 + ((curr->x - map->width / 2) * (1920 / map->width / 2) * 1));
			curr->y = (int)(1080 / 2 + ((curr->y - map->height / 2) * (1920 / map->width / 2) * 1));
			j++;
		}
		i++;
	}
	return (map);
}
