/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:12:52 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/21 13:10:09 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	draw_line(t_image *img, t_vector p1, t_vector p2)
{
	int			i;
	double		slope;
	t_vector	p3;

	p3 = p1;
	slope = (p2.y - p1.y) / (p1.x - p2.x);
	if (fabs(p2.x - p1.x) > fabs(p2.y - p1.y))
	{
		while (p3.x <= p2.x)
		{
			put_pixel(img, p3);
			p3.x++;
			p3.y = p1.y + slope * (p3.x - p1.x);
		}
	}
	else
	{
		while (p3.y <= p2.y)
		{
			put_pixel(img, p3);
			p3.y++;
			p3.x = p1.x + (p3.y - p1.y) / slope;
		}
	}
}
