/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:47 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/20 13:53:46 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_image {
	int		*img;
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

typedef struct  s_3dd
{
	char	*s;
	t_image	img;
}	t_3dd;

int		ft_read_map(int fd);

#endif
