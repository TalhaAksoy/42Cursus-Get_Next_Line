#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	fd = open("./test.html",O_RDONLY);
	while(1)
	{
		char *line = get_next_line(fd);
		if(line == NULL)
		{
			break ;
		}
		printf("%s",line);
		free(line);
	}
	system("leaks a.out");
	
}