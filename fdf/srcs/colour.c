/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:04:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/17 11:58:06 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_vector c)
{
	char	*dst;

	if (c.x < 0 || c.y < 0 || c.x >= img->width || c.y >= img->height)
		return ;
	dst = img->addr + ((int)c.y *img->ln_len + (int)c.x * (img->bpp / 8));
	*(unsigned int *)dst = c.colour;
}


