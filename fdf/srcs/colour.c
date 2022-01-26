/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:04:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/21 16:32:29 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_vector c)
{
	char	*dst;

	if (c.x < 0 || c.y < 0 || c.x >= img->width || c.y >= img->height)
		return ;
	dst = img->addr + ((int)c.y * img->ln_len + (int)c.x * (img->bpp / 8));
	*(unsigned int *)dst = rgbi(c.rgb);
}

t_rgb	hex_colour(char *data)
{
	static char	hex_clr[] = "0123456789abcdef";
	int			n;
	int			i;

	if (!data)
		return (irgb(0xFFFFFF));
	data += 3;
	n = 0;
	while (*data)
	{
		i = 0;
		while (i < 16)
		{
			if (*data == hex_clr[i])
			{
				n = n * 16 + i;
				break ;
			}
			i++;
		}
		data++;
	}
	return (irgb(n));
}

t_rgb	irgb(int colour)
{
	t_rgb	rgb;

	rgb.r = (colour >> 16) & 0xFF;
	rgb.g = (colour >> 8) & 0xFF;
	rgb.b = colour & 0xFF;
	return (rgb);
}

int	rgbi(t_rgb rgb)
{
	return (rgb.r * 0x10000 + rgb.g * 0x100 + rgb.b);
}
/*int	get_gradient(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

t_rgb	get_trgb(int colour)
{
	t_rgb	trgb;

	trgb.t = (colour >> 24) & 0xFF;
	trgb.r = (colour >> 16) & 0xFF;
	trgb.g = (colour >> 8) & 0xFF;
	trgb.b = colour & 0xFF;
	return (trgb);
}

int*/	
