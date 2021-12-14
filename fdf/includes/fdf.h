/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:47 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/14 17:38:20 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>

typedef struct s_image {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_pixel {
	int	x;
	int	y;
	int	colour;
}	t_pixel;

typedef struct s_vector {
	int	x;
	int	y;
	int	z;
}	t_vector;

#endif
