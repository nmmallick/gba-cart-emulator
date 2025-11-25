#include <string.h>
#include <sys/stat.h>
#include <errno.h>

extern int __HeapBase;
extern int __HeapLimit;

int _open(const char * path, int falgs, ...)
{
    return -1;
}

int _close(int fd)
{
    return -1;
}

int _lseek(int fd, int ptr, int dir)
{
    return 0;
}

int __attribute__((weak)) _fstat(int fd, struct stat * st)
{
    return 0;
}

int _isatty(int fd)
{
    return 1;
}

int _read(int fd, char *ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
	*ptr++ = -1;
    }

    return (len - i);
}

int _write(int fd, char * ptr, int len)
{
    int i;
    for (i = 0; i < len; i++) continue;

    return i;
}

void * _sbrk(int incr)
{
    return NULL;
}
