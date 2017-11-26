/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_inittab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:58:40 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:16:15 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	print_tab(char **tab, size_t line, size_t col)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < line && !(j = 0))
	{
		while (j < col)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**ft_inittab(size_t n)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n && !(j = 0))
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		while (j < n)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
