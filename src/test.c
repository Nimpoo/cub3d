/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/11 15:58:09 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_textures
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}		t_textures;

typedef struct s_cub3d
{
	t_textures	textures;
}		t_cub3d;

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*a;

	a = malloc(elementCount * elementSize);
	if (!a)
		return (NULL);
	while (elementCount--)
		((char *) a)[elementCount] = 0;
	return (a);
}

void	ft_parse_file(t_cub3d *cub3d, char *filename)
{
	const int	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		write(2, "error: ", );
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_cub3d	*cub3d;

	if (argc != 2)
	{
		write(2, "error: bad arguments\n", 22);
		return (1);
	}
	cub3d = ft_calloc(1, sizeof(t_cub3d));
	ft_parse_file(cub3d, argv[1]);
	return (0);
}
