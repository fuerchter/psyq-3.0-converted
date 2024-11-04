/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
/*
 * File:memory.h
 * memory functions pseudo definition header
 */

#ifndef _MEMORY_H
#define _MEMORY_H

extern void *memcpy();
extern void *memmove();
extern int   memcmp();
extern void *memchr();
extern void *memset();


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;  /* result type of the sizeof operator (ANSI) */
#endif

#ifndef NULL
#define NULL 0		       /* null pointer constant */
#endif


#endif  /* _MEMORY_H */

