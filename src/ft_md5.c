#include "ft_ssl.h"
#include "ft_md5.h"
#include <errno.h>

/*
**	if no file is spcecified, read from stdin
*/

static void		is_file(char *file)
{
	int			fd;

	if (file == NULL)
		fd = 0;
	else
	{
		ft_printf("MD5 (%s)\n", file);
		if ((fd = open(file, O_RDONLY)) < 0)
		{
			ft_printf("errno = %d\n", errno);
			return ;
		}
	}
}

static void		is_string(char *str)
{
	ft_printf("MD5 (\"%s\")\n", str);
}

/*
**	ama is either a file name or a string (is data.str == 1)
**	Ask Me Anything
*/

int				ft_md5(char *ama, t_pars *data)
{
	ft_printf("ama = %s\nend = %d\nstd = %d\nqut = %d\nrev = %d\nstr = %d\n", ama, data->end, data->std, data->qut, data->rev, data->str);
	ft_printf("content = %s\n", data->content);
	if (data->str == 1 && data->content != NULL)
	{
		data->content == NULL ? is_string(ama) : is_string(data->content);
		return (data->content == NULL ? 1 : 0);
	}
	is_file(ama);
	return (ama == NULL ? 0 : 1);
}
