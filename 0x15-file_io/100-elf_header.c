#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void print_magic(const Elf64_Ehdr *header);
void print_class_and_data(const Elf64_Ehdr *header);
void print_version_and_abi(const Elf64_Ehdr *header);
void print_type_and_entry(const Elf64_Ehdr *header);

/**
 * main - Displays the information contained in
 * the ELF header at the start of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 *
 * Description: Opens the specified ELF file, reads its header,
 * and prints relevant information.
 *              If the file is not an ELF file or encounters
 *              an error, it exits with status code 98.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	Elf64_Ehdr header;
	ssize_t read_result = read(fd, &header, sizeof(Elf64_Ehdr));

	if (read_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	print_magic(&header);
	print_class_and_data(&header);
	print_version_and_abi(&header);
	print_type_and_entry(&header);

	close(fd);
	return (0);
}
/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @header: A pointer to the Elf64_Ehdr structure containing the ELF header.
 *
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(const Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class_and_data - Prints the class and data format of an ELF header.
 * @header: A pointer to the Elf64_Ehdr structure containing the ELF header.
 *
 * Description: Outputs the class (ELF32 or ELF64) and data format (endianess).
 */

void print_class_and_data(const Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}

	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}
}
/**
 * print_version_and_abi - Prints the version and OS/ABI of an ELF header.
 * @header: A pointer to the Elf64_Ehdr structure containing the ELF header.
 *
 * Description: Outputs the ELF version and the OS/ABI information.
 */

void print_version_and_abi(const Elf64_Ehdr *header)
{
	printf("  Version:                           %d",
		header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type_and_entry - Prints the type and entry
 * point address of an ELF header.
 * @header: A pointer to the Elf64_Ehdr structure containing the ELF header.
 *
 * Description: Outputs the type of ELF file and the entry point address.
 */

void print_type_and_entry(const Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_type);
	}

	printf("  Entry point address:               %#lx\n",
		header->e_entry);
}

