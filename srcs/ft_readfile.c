/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfil.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:42:06 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 15:08:03 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	check_link(char *str)
{
	int	link;
	int	i;

	link = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i - 1 >= 0 && str[i - 1] == '#')
				link++;
			if (i + 1 < 20 && str[i + 1] == '#')
				link++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				link++;
			if (i + 5 < 20 && str[i + 5] == '#')
				link++;
		}
		i++;
	}
	return (link == 6 || link == 8);
}

static int	check_piece(char *str, size_t nbrbyte)
{
	size_t	i;
	size_t	countsharp;

	countsharp = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		else if (str[i] != '.' && str[i] != '#' && i % 5 != 4)
			return (0);
		else if (str[i] == '#')
			countsharp++;
		i++;
	}
	if (str[20] != '\n' && nbrbyte == 21)
	{
		return (0);
	}
	else if (countsharp != 4 || check_link(str) == 0)
		return (0);
	return ((nbrbyte == 21) ? 1 : 2);
}

int			valid_file(size_t fd, t_piece **tab)
{
	size_t	count;
	char	buf[21];
	int		last;
	char	letter;

	count = 0;
	letter = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if ((last = check_piece(buf, count)) == 0 || letter - 'A' >= 26)
			return (0);
		else if (letter - 'A' < 26)
			tab[letter - 'A'] = transf(buf, letter, count);
		letter++;
	}
	tab[letter - 'A'] = NULL;
	return (last == 2 ? letter - 'A' : 0);
}
