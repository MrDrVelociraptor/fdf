/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:26:18 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/13 13:25:36 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	"libft.h"

f:wq

static int	cntsplit(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		i++;
		free(splits[i]);
	}
	free(splits);
	return (i);
}

static void	getdimensions(char *file, t_map *data)
{
	int		fd;
	char	*read;

	fd = open(file, O_RDONLY);
	while (1)
	{
		read = ft_get_next_line(fd);
		if (!read)
			break;
		if (data->width == 0)
			data->width = cntsplit(ft_split(read, ' '));
		data->height++;
		free(read);
	}
	close(fd);
}

void	fill_map(int *points, char *line)
{
	char	**f_line;
	int		i;

	i = 0;
	f_line = ft_split(line, ' ');
	while (f_line[i])
	{
		points[i] = ft_atoi(f_line[i]);
		i++;
		free(f_line[i]);
	}
	free(f_line);
	free(line);
}

void	read_fdf(char *filename, t_map *data)
{
	int	i;
	int	fd;

	getdimensions(filename, data);
	ft_printf("%i\n %i\n %i\n", data->height, data->width, data->height*data->width);
	data->coord = (int **)malloc(sizeof(int *) * data->height);
	i = 0;
	while (i < data->height)
		data->coord[i++] = (int *)malloc(sizeof(int) * data->width);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		fill_map(data->coord[i], ft_get_next_line(fd));
		i++;
	}
}

int main(void)
{
	t_map	data;

	read_fdf(filname, &data);
	return (0);
}

