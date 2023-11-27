#include "main.h"

/**
 * create_file - creates a file and writes text_content in it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 * - if filename is NULL return -1
 * - if text_content is NULL create an empty file
 * - if the file exists, truncate it
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int count;
	int count_wr;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (count = 0; text_content[count]; count++)
		;
	count_wr = write(fd, text_content, count);
	if (count_wr == -1)
		return (-1);
	close(fd);
	return (1);
}

