/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:37:59 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/16 23:21:22 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "structure.h"

// lib/ft_convert_rgba.c
int		ft_convert_rgba(int r, int g, int b, int a);

// lib/ft_strlen.c
int		ft_strlen(const char *s);

// lib/ft_calloc.c
void	*ft_calloc(size_t elementSize);

// lib/ft_strdup.c
char	*ft_strldup(const char *s, const int n);
char	*ft_strdup_and_free(char *s);
char	*ft_strdup(const char *s);

// lib/ft_atoi.c
int		ft_atoi(const char *s);

// lib/ft_isspace.c
int		ft_isspace(const char c);

// lib/ft_split.c
char	**ft_split(const char *s, const char c);

// lib/ft_strcmp.c
int		ft_reverse_strncmp(const char *s1, const char *s2, const int lenght);
int		ft_strncmp(const char *s1, const char *s2, const int lenght);
int		ft_strcmp(const char *s1, const char *s2);

// lib/ft_put.c
void	ft_put(const char *s, const int fd);
void	ft_put3(const char *s1, const char *s2, const char *s3, const int fd);

// src/ft_move.c
void	ft_move(t_cub3d *cub3d, t_vector v);

// src/ft_rotate_vector.c
void	ft_rotate_vector(t_vector *v, double angle);

#endif
