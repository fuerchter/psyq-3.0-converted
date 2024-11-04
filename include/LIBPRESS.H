/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
#ifndef _LIBPRESS_H_
#define _LIBPRESS_H_
/*
 *  (C) Copyright 1995 Sony Corporation,Tokyo,Japan. All Rights Reserved
 *
 * 		libpress.h: Prototypes for libpress
 *
 *$Id: libpress.h,v 1.4 1995/03/10 13:47:46 kaol Exp $
 */
extern void DecDCTReset(int mode);
extern int DecDCTBufSize(u_long *bs);
extern void DecDCTvlc(u_long *bs, u_long *buf);
extern void DecDCTin(u_long *buf, int mode);
extern void DecDCTout(u_long *buf, int size);
extern int DecDCTinSync( int mode) ;
extern int DecDCToutSync( int mode) ;

#endif /* _LIBPRESS_H_ */
