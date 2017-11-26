/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transfpiece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:36:44 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:46:42 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void		push_tl(char *buf, size_t count)
{
	size_t i;

	i = 0;
	while (buf[0] == '.' && buf[5] == '.' && buf[10] == '.' &&
			buf[15] == '.' && !(i = 0))
	{
		while (i < count)
		{
			if (buf[i] == '#' && (buf[i - 1] = '#'))
				buf[i] = '.';
			i++;
		}
	}
	while (buf[0] == '.' && buf[1] == '.' && buf[2] == '.' &&
			buf[3] == '.' && !(i = 0))
	{
		while (i < count)
		{
			if (buf[i] == '#' && (buf[i - 5] = '#'))
				buf[i] = '.';
			i++;
		}
	}
}

static char		**redubuf(t_piece *piece, char *buf, char letter)
{
	char	**tab;
	size_t	a;
	size_t	b;

	a = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * piece->width)))
		return (NULL);
	while (a < piece->width && !(b = 0))
	{
		if (!(tab[a] = (char *)malloc(sizeof(char) * piece->lenght)))
			return (NULL);
		while (b < piece->lenght)
		{
			if (buf[b + (a * 5)] == '#')
				tab[a][b] = letter;
			else
				tab[a][b] = buf[b + (a * 5)];
			b++;
		}
		a++;
	}
	return (tab);
}

static void		tab_size(char *buf, size_t count, size_t *square)
{
	size_t	l;

	square[0] = 3;
	square[1] = 0;
	square[2] = 3;
	square[3] = 0;
	l = 0;
	while (l < count)
	{
		if (buf[l] == '#')
		{
			if (l % 5 < square[0])
				square[0] = l % 5;
			if (l % 5 > square[1])
				square[1] = l % 5;
			if (l / 5 < square[2])
				square[2] = l / 5;
			if (l / 5 > square[3])
				square[3] = l / 5;
		}
		l++;
	}
}

t_piece			*transf(char *buf, char letter, size_t count)
{
	t_piece	*tet;
	size_t	*square;

	if (!(tet = malloc(sizeof(t_piece))))
		return (NULL);
	if (!(square = (size_t *)malloc(sizeof(size_t) * 4)))
		return (NULL);
	tab_size(buf, count, square);
	tet->line = -1;
	tet->col = -1;
	tet->lenght = square[1] - square[0] + 1;
	tet->width = square[3] - square[2] + 1;
	tet->letter = letter;
	push_tl(buf, count);
	tet->tab = redubuf(tet, buf, letter);
	free(square);
	return (tet);
}
