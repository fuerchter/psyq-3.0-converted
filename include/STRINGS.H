/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
/*
 * File:strings.h
 * string functions pseudo definition header 
 */

#ifndef	_STRINGS_H
#define	_STRINGS_H

extern char *strchr();
extern char *strrchr();
extern char *strpbrk();
extern int strspn();
extern int strcspn();
extern char *strtok();
extern char *strstr();

#define strdup(p)	( strcpy(malloc(strlen(p)+1),p); )

#define LMAX 256

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;  /* result type of the sizeof operator (ANSI) */
#endif

#ifndef NULL
#define NULL 0		       /* null pointer constant */
#endif

#endif	/* _STRINGS_H */

