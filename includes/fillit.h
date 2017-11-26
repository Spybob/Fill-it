/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: prosnobl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:39:37 by prosnobl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 17:52:33 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_piece
{
	char		letter;
	size_t		lenght;
	size_t		width;
	size_t		line;
	size_t		col;
	size_t		stat;
	char		**tab;
}				t_piece;

void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_memdel(void **ap);
size_t			fit_in(t_piece *piece, char **reduc);
size_t			put_in(char **tab, t_piece *piece, size_t line, size_t col);
void			del_in(char **tab, t_piece *piece);
int				valid_file(size_t fd, t_piece **tab);
t_piece			*transf(char *buf, char letter, size_t count);
char			**ft_inittab(size_t n);
size_t			met_piece(char **tetris, t_piece **tab, size_t len,
				size_t count);
size_t			findlen_min(size_t nbr_piece);
void			init_tab(t_piece **tab, size_t nbr_piece);
void			solve_square(t_piece **tab, size_t nbr_piece);
char			**reductab(char **tab, size_t line, size_t col, t_piece *piece);
void			print_tab(char **tab, size_t line, size_t col);

#endif
