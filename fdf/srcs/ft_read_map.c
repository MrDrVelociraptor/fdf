/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:26:18 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/13 14:44:24 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	"libft.h"


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

static void	getdimensions(char *file, t_data *data)
{
	int		fd;
	char	*read;

	fd = open(file, O_RDONLY);
	ft_printf("%i\n", fd);
	while (1)
	{
		read = ft_get_next_line(fd);
		if (!read)
			break;
		ft_printf("%s", read);
		if (data->width == 0)
			data->width = cntsplit(ft_split(read, ' '));
		data->height++;
		free(read);
	}
	//ft_printf("%i\n", close(fd));
	ft_printf("\n");
	ft_printf("%i - %i\n", data->height, data->width);
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

void	read_fdf(char *filename, t_data *ptr)
{
	int	i;
	int	fd;

	ft_printf("Start\n");
	ft_printf("%i - %i\n", ptr->height, ptr->width);
	getdimensions(filename, ptr);
	ft_printf("%i\n %i\n", ptr->height, ptr->width);
	ptr->map = (int **)malloc(sizeof(int *) * ptr->height);
	i = 0;
	while (i < ptr->height)
		ptr->map[i++] = (int *)malloc(sizeof(int) * ptr->width);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < ptr->height)
	{
		fill_map(ptr->map[i], ft_get_next_line(fd));
		i++;
	}
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		ft_printf("%s", "Nope\n");
	if (argc == 2) 
	{
		ft_printf("%s\n", "fuck this shit");
		ft_bzero(&data, sizeof(t_data));
		read_fdf(argv[1], &data);
		for(int i =0; i < data.height; i++){
			for(int j = 0; j < data.width; j++)
				printf("%2i ", data.map[i][j]);
			printf("\n");
		}
	}
	return (0);
}

