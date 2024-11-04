/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
/*
 * File:memory.h
 * memory functions pseudo definition header
 */

#ifndef _QSORT_H
#define _QSORT_H

extern void qsort();


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;  /* result type of the sizeof operator (ANSI) */
#endif

extern void _memcpy();
extern void _swap();

#ifndef NULL
#define NULL 0		       /* null pointer constant */
#endif


#endif  /* _QSORT_H */

