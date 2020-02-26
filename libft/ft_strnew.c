/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:59:16 by asusan            #+#    #+#             */
/*   Updated: 2019/04/19 23:13:21 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	if (size + 1 == 0)
		return (NULL);
	if (!(ptr = (char*)malloc(size + 1)))
		return (NULL);
	while (size)
		ptr[size--] = 0;
	ptr[size] = 0;
	return (ptr);
}
