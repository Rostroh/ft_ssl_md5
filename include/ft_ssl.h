#ifndef FT_SSL_H
# define FT_SSL_H

#include "../libft/include/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# define NB_OPT 5

typedef struct	s_pars
{
	int			end;
	int			std;
	int			qut;
	int			rev;
	int			str;
	char		*content;
}				t_pars;

# define NB_CMD 1

int				ft_md5(char *ama, t_pars *data);
#endif
