/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
/*
 * File:malloc.h
 */
#ifndef _MALLOC_H
#define _MALLOC_H

extern void free();
extern void *malloc();
extern void *calloc();
extern void *realloc();


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;  /* result type of the sizeof operator (ANSI) */
#endif

#ifndef NULL
#define NULL 0		       /* null pointer constant */
#endif

#endif /* _MALLOC_H */
