#include "../../includes/rubbish.h"

int	cmd_count(char **cmds)
{
	int	len;

	len = 0;
	while (cmds[len])
		len++;
	return (len);
}

int	count_dir(void)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(".");
	entry = readdir(dir);
	while (entry != NULL)
	{
		entry = readdir(dir);
		count++;
	}
	closedir(dir);
	return (count);
}
