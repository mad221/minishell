### Oh mec

## T'es pret?

## chaud !! attend je dois finir mon cub3d !!

# Proffeseur bshi va vous apprendre qqch!

## fork - create a child process
### SYNOPSIS         
       #include <sys/types.h>
       #include <unistd.h>

       pid_t fork(void);
### DESCRIPTION
       fork() creates a new process by duplicating the calling process.  The
       new process is referred to as the child process.  The calling process
       is referred to as the parent process.

       The child process and the parent process run in separate memory
       spaces.  At the time of fork() both memory spaces have the same
       content.  Memory writes, file mappings (mmap(2)), and unmappings
       (munmap(2)) performed by one of the processes do not affect the
       other.


## getcwd - get current working directory
### SYNOPSIS
       #include <unistd.h>

       char *getcwd(char *buf, size_t size);

### DESCRIPTION
       These functions return a null-terminated string containing an
       absolute pathname that is the current working directory of the
       calling process.  The pathname is returned as the function result and
       via the argument buf, if present.

       The getcwd() function copies an absolute pathname of the current
       working directory to the array pointed to by buf, which is of length
       size.
