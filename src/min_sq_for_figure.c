/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sq_for_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:45:20 by asusan            #+#    #+#             */
/*   Updated: 2019/08/13 18:45:22 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		start_value(char symbol, int *temp, int *remember, t_att attr)
{
	if (symbol == '*')
	{
		*temp = attr.figure_heigh;
		*remember = attr.figure_width;
	}
	else
	{
		*temp = attr.map_heigh;
		*remember = attr.map_width;
	}
}

static int	rbs(char **arr, t_att attr, char symbol)
{
	int	remember;
	int	temp;

	start_value(symbol, &temp, &remember, attr);
	attr.i = -1;
	while (++attr.i != temp)
	{
		attr.j = -1;
		if (ft_strchr(arr[attr.i], symbol) != NULL)
		{
			while (arr[attr.i][++attr.j] != '\0')
			{
				if (arr[attr.i][attr.j] == symbol && remember > attr.j)
					remember = attr.j;
			}
		}
	}
	return (remember);
}

static int	ras(char **arr, t_att attr, char symbol)
{
	int	remember;
	int	temp;

	if (symbol == '*')
		temp = attr.figure_heigh;
	else
		temp = attr.map_heigh;
	attr.i = -1;
	remember = 0;
	while (++attr.i != temp)
	{
		attr.j = -1;
		if (ft_strchr(arr[attr.i], symbol) != NULL)
		{
			while (arr[attr.i][++attr.j] != '\0')
				if (arr[attr.i][attr.j] == symbol && remember < attr.j)
					remember = attr.j;
		}
	}
	if (symbol == '*')
		return (attr.figure_width - remember - 1);
	return (attr.map_width - remember - 1);
}

char		**return_free_list(char **a, t_att *attr, char symbol)
{
	int		c;
	char	**new_figure;
	int		temp;

	if (symbol == '*')
		temp = attr->figure_heigh;
	else
		temp = attr->map_heigh;
	attr->i = -1;
	c = 0;
	while (++attr->i != temp)
		if (ft_strchr(a[attr->i], symbol) != NULL)
			c++;
		else if (c != 0)
			break ;
	if (symbol == '*')
		attr->figure_up = attr->i - c;
	new_figure = (char **)malloc(sizeof(char *) * (c + 1));
	new_figure[c] = NULL;
	while (--c >= 0 && attr->i-- >= 0)
		new_figure[c] = ft_strsub(a[attr->i], rbs(a, *attr, symbol), ft_strlen(
				a[attr->i]) - rbs(a, *attr, symbol) - ras(a, *attr, symbol));
	if (symbol == '*')
		attr->figure_left = rbs(a, *attr, symbol);
	return (new_figure);
}
