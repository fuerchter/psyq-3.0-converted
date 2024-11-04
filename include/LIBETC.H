/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
#ifndef _LIBETC_H_
#define _LIBETC_H_

/*
 *  (C) Copyright 1993/1994 Sony Corporation,Tokyo,Japan. All Rights Reserved
 *
 * 			libetc.h: Pad Interface
 *
 * Revised: 1995/01/31  kaol	PADL{1,2},PADR{1,2},PADstart,PADselect, and PAD
 *
 *$Id: libetc.h,v 1.38 1995/03/11 07:12:59 suzu Exp $
 *		       	
 */
extern int PadIdentifier;
/*
 * PAD I/O (SIO Pad)
 */
#define PADLup     (1<<12)
#define PADLdown   (1<<14)
#define PADLleft   (1<<15)
#define PADLright  (1<<13)
#define PADRup     (1<< 4)
#define PADRdown   (1<< 6)
#define PADRleft   (1<< 7)
#define PADRright  (1<< 5)
#define PADi       (1<< 9)
#define PADj       (1<<10)
#define PADk       (1<< 8)
#define PADl       (1<< 3)
#define PADm       (1<< 1)
#define PADn       (1<< 2)
#define PADo       (1<< 0)
#define PADh       (1<<11)
#define PADL1      PADn
#define PADL2      PADo
#define PADR1      PADl
#define PADR2      PADm
#define PADstart   PADh
#define PADselect  PADk
		    
#define MOUSEleft  (1<<3)
#define MOUSEright (1<<2)

/*
 * PAD utility macro: _PAD(x,y)
 *   x: controller ID (0 or 1)
 *   y: PAD assign macro
 *
 * Example: PAD(0,PADstart) ... PADstart of controller 1
 *          PAD(1,PADLup)   ... PADLup of controller 2
 */
#define _PAD(x,y) ((y)<<((x)<<4))

/* scratch pad address 0x1f800000 - 0x1f800400 */
#define getScratchAddr(offset)  ((u_long *)(0x1f800000+offset*4))

/* ----------------------------------------------------------------
 *      End on File
 * ---------------------------------------------------------------- */
/*
 */
#endif /* _LIBETC_H_ */
/* DON'T ADD STUFF AFTER THIS */

