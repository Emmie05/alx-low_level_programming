#include "main.h"

/**
 * error_exit - Exits the program with an error message.
 * @exit_code: The exit code to use.
 * @message: The error message to display.
 */
void error_exit(int exit_code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char **argv)
{
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1)
        error_exit(98, "Error: Can't read from file");
    
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (dest_fd == -1)
        error_exit(99, "Error: Can't write to file");

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written == -1)
            error_exit(99, "Error: Can't write to file");
    }

    if (bytes_read == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(source_fd) == -1)
        error_exit(100, "Error: Can't close source file");
    if (close(dest_fd) == -1)
        error_exit(100, "Error: Can't close destination file");

    return (0);
}
