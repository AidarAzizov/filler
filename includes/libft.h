/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:29:22 by asusan            #+#    #+#             */
/*   Updated: 2019/08/07 15:29:24 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE  10
# define MAX_FD 10240
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *destination, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(intmax_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int ch);
size_t				ft_strlen(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					get_next_line(const int fd, char **line);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnew(size_t size);

#endif
