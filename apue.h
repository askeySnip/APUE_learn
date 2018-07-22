/* the header for using apue book code */
#ifndef _APUE_H
#define _APUE_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 4096

/*
* default file access permissions for new files.
*/
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#endif
