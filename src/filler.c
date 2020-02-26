/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:28:20 by asusan            #+#    #+#             */
/*   Updated: 2019/08/07 15:28:22 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	give_me_players(char *line, t_att *attr)
{
	attr->enemy = 'O';
	if (ft_strstr(line, "exec p1"))
	{
		attr->player = 'O';
		attr->enemy = 'X';
	}
	else
		attr->player = 'X';
	attr->for_player = 0;
}

void	change_map(int ***arr, t_att *attr, int inst)
{
	int i;
	int j;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		j = 0;
		while (j != attr->map_width)
		{
			if ((*arr)[i][j] == 0 &&
			((j + 1 < attr->map_width && ((*arr)[i][j + 1] == inst - 1)) ||
			(j - 1 >= 0 && ((*arr)[i][j - 1] == inst - 1)) ||
			(i + 1 < attr->map_heigh && ((*arr)[i + 1][j] == inst - 1)) ||
			(i - 1 >= 0 && ((*arr)[i - 1][j] == inst - 1))))
				(*arr)[i][j] = inst;
			j++;
		}
		i++;
	}
	if (inst > 1000)
		return ;
	change_map(arr, attr, inst + 1);
}

void	change_map_2(int ***arr, t_att *attr, char **map)
{
	int i;
	int j;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		j = 0;
		while (j != attr->map_width)
		{
			if (map[i][j] == attr->player || map[i][j] == attr->player + 32)
				(*arr)[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	output(t_att *attr, int result, int ***arr)
{
	free_int(arr);
	if (result != 0)
	{
		ft_putnbr(attr->result_i - attr->figure_up);
		write(1, " ", 1);
		ft_putnbr(attr->result_j - attr->figure_left);
		write(1, "\n", 1);
		start_install(attr);
	}
	else
	{
		start_install(attr);
		ft_putnbr(0);
		write(1, " ", 1);
		ft_putnbr(0);
		write(1, "\n", 1);
		exit(0);
	}
}
