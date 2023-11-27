#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of letters read and printed, or 0 if:
 * - the file cannot be opened or read,
 * - filename is NULL,
 * - write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t count_rd, count_wr;
	char *buffer;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);
	count_rd = read(fd, buffer, letters);
	count_wr = write(STDOUT_FILENO, buffer, count_rd);
	close(fd);
	free(buffer);
	return (count_wr);
}

