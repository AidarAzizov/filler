/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   installation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:51:51 by asusan            #+#    #+#             */
/*   Updated: 2019/08/13 18:51:53 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	null(char **line, char ***map, char ***figure)
{
	*figure = NULL;
	*map = NULL;
	*line = NULL;
}

void	start_install(t_att *attr)
{
	attr->figure_left = 0;
	attr->figure_up = 0;
	attr->result_i = 0;
	attr->result_j = 0;
	attr->map_heigh = 0;
	attr->map_width = 0;
	attr->figure_heigh = 0;
	attr->figure_width = 0;
	attr->i = 0;
	attr->j = 0;
	attr->for_player = 1;
}

int		returning(int true, t_att *attr)
{
	if (true != 1)
		return (0);
	return (attr->sum);
}

int		helper_for_install(int **arr, char **figure, t_att *attr)
{
	int x;
	int y;
	int true;

	true = 0;
	x = -1;
	attr->sum = 0;
	while (figure[++x] != NULL)
	{
		y = -1;
		while (figure[x][++y] != '\0')
		{
			if (y + attr->j >= attr->map_width ||
			x + attr->i >= attr->map_heigh)
				return (0);
			if ((arr[attr->i + x][attr->j + y] == -1) && figure[x][y] == '*')
				++true;
			if ((arr[attr->i + x][attr->j + y] == 1) && figure[x][y] == '*')
				return (0);
			if (arr[attr->i + x][attr->j + y] != -1 &&
			figure[x][y] == '*' && arr[attr->i + x][attr->j + y] != 1)
				attr->sum += arr[attr->i + x][attr->j + y];
		}
	}
	return (returning(true, attr));
}

void	install_on_the_map(char **map, char **figure, t_att *attr)
{
	int result;
	int **arr;

	attr->i = -1;
	result = 0;
	arr = free_memory_for_int(*attr, map);
	change_map(&arr, attr, 2);
	change_map_2(&arr, attr, map);
	while (arr != NULL && arr[++attr->i] != NULL)
	{
		attr->j = -1;
		while (++attr->j != attr->map_width)
		{
			if (helper_for_install(arr, figure, attr) > 0)
			{
				if (attr->sum < result || result == 0)
				{
					attr->result_i = attr->i;
					attr->result_j = attr->j;
					result = attr->sum;
				}
			}
		}
	}
	output(attr, result, &arr);
}
