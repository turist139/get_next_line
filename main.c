#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	// Open a file for reading
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open file 'test.txt'\n");
		return (1);
	}

	printf("--- START READING ---\n");

	// Call get_next_line in a loop until it returns NULL (EOF or Error)
	while ((line = get_next_line(fd)) != NULL)
	{
		// Print the line. GNL should already include the '\n' at the end!
		printf("%s\n", line);
		
		// CRITICAL: Always free the line returned by GNL to prevent leaks
		free(line);
	}

	printf("--- END OF FILE ---\n");

	// Close the file descriptor
	close(fd);
	return (0);
}