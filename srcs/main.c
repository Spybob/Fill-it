/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:53:06 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:18:10 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		puterror(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	return (-1);
}

int				main(int argc, char **argv)
{
	size_t		fd;
	t_piece		**tab;
	size_t		nbr;

	if (argc != 2)
		return (puterror("usage : ./fillit input_tetraminos"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (puterror("error"));
	if (!(tab = (t_piece **)malloc(sizeof(t_piece) * 26)))
		return (0);
	if (!(nbr = valid_file(fd, tab)))
		return (puterror("error"));
	if (close(fd) == -1)
		return (puterror("error"));
	solve_square(tab, nbr);
	return (0);
}
