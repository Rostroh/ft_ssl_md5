#include "ft_ssl.h"

int			check_opt(int **var)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (i < NB_OPT)
	{
		ret += *var[i];
		i++;
	}
	return (ret);
}

int			find_opt(t_pars *data, char *str)
{
	int				i;
	int				j;
	int				ret;
	int				*var[NB_OPT] = {&(data->end), &(data->std), &(data->qut), &(data->rev), &(data->str)};
	static char		opt[NB_OPT] = {'-', 'p', 'q', 'r', 's'};

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		ret = 0;
		while (j < NB_OPT)
		{
			if (str[i] == opt[j])
			{
				*var[j] = 1;
				ret = 1;
			}
			if (data->str == 1)
			{
				data->content = &str[i + 1];
				return (0);
			}
			j++;
		}
		if (ret == 0)
		{
			ft_printf("%c: option unknown\nKnowed option: p q r s\n", str[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			parsing(t_pars *data, int nb_arg, char **arg, int i)
{
	while (i < nb_arg)
	{
		if (data->end == 1 || data->str == 1)
			return (i);
		if (arg[i][0] == '-')
		{
			if (find_opt(data, arg[i] + 1) == -1)
				return (-1);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

/*
**	Using memncpy insteed of memcpy cause memcpy have some vulnerabilities
**	(see buffer overflow)
*/

int			check_command(char *cmd)
{
	int				i;
	static int		name_len[NB_CMD] = {3};
	static char		*name[NB_CMD] = {"md5"};

	i = 0;
	while (i < NB_CMD)
	{
		if (ft_strncmp(cmd, name[i], name_len[i]) == 0)
			return (i);
		i++;
	}
	ft_printf("No digest command named %s\n", cmd);
	return (-1);
}

int			main(int argc, char **argv)
{
	int				arg;
	int				idx;
	t_pars			data;
	static int		(*command[NB_CMD])(char *ama, t_pars *data) = {&ft_md5};

	arg = 2;
	ft_bzero(&data, sizeof(t_pars));
	if (argc == 1)
		ft_printf("%s: Error parsing\n", argv[0]);
	else
	{
		if ((idx = check_command(argv[1])) == -1)
			return (0);
		while (arg < argc)
		{
			if ((arg = parsing(&data, argc, argv, arg)) != -1)
			{
				arg += command[idx](argv[arg], &data);
				data.str = 0;
				data.content = NULL;
			}
			else
				break ;
		}
	}
	return (0);
}
