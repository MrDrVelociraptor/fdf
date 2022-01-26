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

t_vector	coord_data(int x, int y, char *data)
{
	t_vector	point_data;

	point_data.x = x;
	point_data.y = y;
	point_data.z = ft_atoi(data);
	point_data.rgb = hex_colour(ft_strchr(data, ','));
	return (point_data);
}
