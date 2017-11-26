/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_optabl.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 20:17:22 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:16:50 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**reductab(char **tab, size_t line, size_t col, t_piece *piece)
{
	char	**reduc;
	size_t	a;
	size_t	b;

	if (!(reduc = (char **)malloc(sizeof(char *) * piece->width)))
		return (NULL);
	a = 0;
	while (a < piece->width && !(b = 0))
	{
		if (!(reduc[a] = (char *)malloc(sizeof(char) * piece->lenght)))
			return (NULL);
		while (b < piece->lenght)
		{
			reduc[a][b] = tab[a + line][b + col];
			b++;
		}
		a++;
	}
	return (reduc);
}

size_t		fit_in(t_piece *piece, char **reduc)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < piece->width && !(j = 0))
	{
		while (j < piece->lenght)
		{
			if ((piece->tab)[i][j] == piece->letter && reduc[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	del(void **reduc, size_t i)
{
	ft_memdel(reduc);
	return (i);
}

size_t		put_in(char **tab, t_piece *piece, size_t line, size_t col)
{
	char	**reduc;
	size_t	i;
	size_t	j;

	i = 0;
	reduc = reductab(tab, line, col, piece);
	if (fit_in(piece, reduc))
	{
		while (i < piece->width && !(j = 0))
		{
			while (j < piece->lenght)
			{
				if (piece->tab[i][j] != '.')
					tab[line + i][col + j] = piece->tab[i][j];
				j++;
			}
			i++;
		}
		piece->stat = 1;
		piece->line = line;
		piece->col = col;
		return (del((void **)reduc, 1));
	}
	else
		return (del((void **)reduc, 0));
}

void		del_in(char **tab, t_piece *piece)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i] && !(j = 0))
	{
		while (tab[i][j])
		{
			if (tab[i][j] == piece->letter)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
	piece->stat = 0;
}
