#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/ft_ls.h"
#include <string.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

int		main(int argc, char **argv)
{
	DIR *dirp;
	int len;
	struct dirent *dp;

	if (argc < 2)
		return (0);
	dirp = opendir(".");
	if (dirp == NULL)
		return (0);
	len = strlen(argv[1]);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_putstr("file:      ");
		ft_putstr(dp->d_name);
		ft_putstr("\n     type:      ");
		ft_printf("%hhu\n", dp->d_type);

	}
	(void)closedir(dirp);
	write(1, "File Not Found\n", 15);
	return (1);
}
