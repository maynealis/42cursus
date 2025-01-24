#ifndef FLAGS_MANAGER_H
# define FLAGS_MANAGER_H

# include "libft.h"

typedef struct s_flags
{
	char	minus;
	char	zero;
	char	dot;
	char	hash;
	char	space;
	char	plus;
	int		width;
	int		precision;
}	t_flags;

t_flags	init_flags(void);
void	reset_flags(t_flags *flags);
void	set_flags(char *str_flags, char t, t_flags *flags);

#endif