/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:00:34 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/11 17:08:12 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s);

int	ft_reverse_strncmp(const char *s1, const char *s2, const int lenght)
{
	int	i;
	int	j;
	int	l;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	l = 0;
	while (s1[i] && s2[j] && l < lenght)
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i--;
		j--;
		l++;
	}
	if (l < lenght && s1[i] != s2[j])
		return (s1[i] - s2[j]);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, const int lenght)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < lenght)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < lenght && s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
