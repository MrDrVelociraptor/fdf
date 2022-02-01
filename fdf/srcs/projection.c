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

t_vector	normalize(t_vector s)
{
	int		i;
	int		j;
    t_fdf   *fdf;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
            s.x += fdf->camera.x_off;
            s.y += fdf->camera.y_off;
			s.x = (int)(1920 / 2 + ((s.x - fdf->map.width / 2) * (1920 / fdf->map.width / 2) * fdf->camera.zoom));
			s.y = (int)(1080 / 2 + ((s.y - fdf->map.height / 2) * (1920 / fdf->map.width / 2) * fdf->camera.zoom));
			j++;
		}
		i++;
	}
	return (s);
}

void    update_zoom(int keypress, t_fdf *fdf)
{
    if (keypress == XK_DOWN)
    {
        if (fdf->camera.zoom != 2)
            fdf->camera.zoom -= 2;
    }
    else if (keypress == XK_UP)
        fdf->camera.zoom += 2;
    update_image(fdf);
}