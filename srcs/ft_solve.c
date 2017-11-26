/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:45:24 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:54:06 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

size_t		met_piece(char **tetris, t_piece **tab, size_t len, size_t count)
{
	size_t	i;
	size_t	j;

	j = ((tab[count])->col + 1) % (len - (tab[count])->lenght + 1);
	i = (tab[count])->line + (j == 0);
	if ((i + (tab[count])->width > len) && count == 0)
		return (30);
	while (i + (tab[count])->width <= len)
	{
		while (j + (tab[count])->lenght <= len)
		{
			if (put_in(tetris, tab[count], i, j))
				return (count + 1);
			j++;
		}
		j = 0;
		i++;
	}
	del_in(tetris, tab[count - 1]);
	init_tab(tab, count);
	return (count - 1);
}

size_t		findlen_min(size_t nbr_piece)
{
	size_t	res;

	res = 0;
	while (res * res < nbr_piece * 4)
		res++;
	return (res);
}

void		init_tab(t_piece **tab, size_t count)
{
	size_t	i;

	i = count;
	while (tab[i])
	{
		(tab[i])->stat = 0;
		(tab[i])->line = -1;
		(tab[i])->col = -1;
		i++;
	}
}

void		solve_square(t_piece **tab, size_t nbr_piece)
{
	size_t	count;
	size_t	len;
	char	**tetris;

	len = findlen_min(nbr_piece);
	while (len)
	{
		count = 0;
		tetris = ft_inittab(len);
		while (count < nbr_piece)
		{
			count = met_piece(tetris, tab, len, count);
		}
		if (count == nbr_piece)
		{
			return (print_tab(tetris, len, len));
		}
		init_tab(tab, 0);
		len++;
		ft_memdel((void **)tetris);
	}
}
