/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
#ifndef _LIBGPU_H_
#define _LIBGPU_H_
/*
 *  (C) Copyright 1993/1994 Sony Corporation,Tokyo,Japan. All Rights Reserved
 *
 * 		libgpu.h: Graphic Primitive Structures Database
 *
 *$Id: libgpu.h,v 1.81 1995/03/13 08:48:17 suzu Exp $
 *
 * Primitive list:
 *
 *      Name     |Size*1|Shade  |Vertex |Texture| Function
 *      ---------+------+-------+-------+-------+------------------------
 *      POLY_F3  | 5	|Flat   |   3   |OFF    | Flat Triangle
 *      POLY_FT3 | 8	|Flat   |   3   |ON     | Flat Textured Triangle
 *      POLY_G3  | 7	|Gouraud|   3   |OFF    | Gouraud Triangle
 *      POLY_GT3 |10	|Gouraud|   3   |ON     | Gouraud Textured Triangle
 *      POLY_F4  | 6	|Flat   |   4   |OFF    | Flat Quadrangle
 *      POLY_FT4 |10	|Flat   |   4   |ON     | Flat Textured Quadrangle
 *      POLY_G4  | 9	|Gouraud|   4   |OFF    | Gouraud Quadrangle
 *      POLY_GT4 |12	|Gouraud|   4   |ON     | Gouraud Textured Quadrangle
 *      ---------+------+-------+-------+-------+------------------------
 *      LINE_F2  | 4	|Flat   |   2   | -	| unconnected Flat Line 
 *      LINE_G2  | 5	|Gouraud|   2   | -	| unconnected Gouraud Line 
 *      LINE_F3  | 6	|Flat	|   3	| -	| 3-connected Flat Line
 *      LINE_G3  | 8	|Gouraud|   3	| -	| 3-connected Gouraud Line
 *      LINE_F4  | 7	|Flat	|   4	| -	| 4-connected Flat Line
 *      LINE_G4  |10	|Gouraud|   4	| -	| 4-connected Gouraud Line
 *      ---------+------+-------+-------+-------+------------------------
 *	BLK_FILL | 4	|Flat	|   1   |OFF	| Block Write
 *      ---------+------+-------+-------+-------+------------------------
 *      SPRT	 | 5	|Flat	|   1   |ON     | free size Sprite
 *      SPRT_16	 | 4	|Flat	|   1   |ON     | 16x16 Sprite
 *      SPRT_8	 | 4	|Flat	|   1   |ON     | 8x8 Sprite
 *      ---------+------+-------+-------+-------+------------------------
 *      TILE	 | 4	|Flat	|   1   |ON     | free size Sprite
 *      TILE_16	 | 3	|Flat	|   1   |ON     | 16x16 Sprite
 *      TILE_8	 | 3	|Flat	|   1   |ON     | 8x8 Sprite
 *      TILE_1	 | 3	|Flat	|   1   |ON     | 8x8 Sprite
 *      ---------+------+-------+-------+-------+------------------------
 *      DR_TWIN	 | 3	|   -	|   -   | -     | Texture Window
 *      DR_AREA	 | 3	|   -	|   -   | -     | Drawing Area
 *      DR_OFFSET| 3	|   -	|   -   | -     | Drawing Offset
 *      DR_PRIO  | 3	|   -	|   -   | -     | Drawing Priority
 *      DR_MODE  | 3	|   -	|   -   | -     | Drawing Mode
 *      DR_ENV   |16	|   -	|   -	| -	| Drawing Environment
 *
 *	*1: in long-word
 *
 * Texture Attributes:
 *	abr: ambient rate
 *		abr	0	1	2	3
 *		-------------------------------------
 *		Front	0.5	1.0	0.5	-1.0
 *		Back	0.5	1.0	1.0	 1.0
 *
 *	tp: texture mode
 *		 tp	0	1	2	
 *		 -----------------------------
 *		 depth	4bit	8bit	16bit
 *		 color	CLUT	CLUT	DIRECT
 */

#include <LIBGTE.H>

/*
 *	Externals
 */
extern	int (*GPU_printf)();	/* printf() object */

/*
 *	Time-out Cycle
 */
#define WAIT_TIME	0x800000

/*
 *	General Macros
 */
#define limitRange(x, l, h)	((x)=((x)<(l)?(l):(x)>(h)?(h):(x)))

/*
 *	Set/Add Vector/Rectangle Attributes
 */
#define setVector(v, _x, _y, _z) \
	(v)->vx = _x, (v)->vy = _y, (v)->vz = _z	

#define copyVector(v0, v1) \
	(v0)->vx = (v1)->vx, (v0)->vy = (v1)->vy, (v0)->vz = (v1)->vz 

#define addVector(v0, v1) \
	(v0)->vx += (v1)->vx,	\
	(v0)->vy += (v1)->vy,	\
	(v0)->vz += (v1)->vz	
	
#define setRECT(r, _x, _y, _w, _h) \
	(r)->x = (_x),(r)->y = (_y),(r)->w = (_w),(r)->h = (_h)

/*
 *	Set Primitive Attributes
 */
#define setTPage(p,tp,abr,x,y) \
	((p)->tpage = GetTPage(tp,abr,x,y))

#define setClut(p,x,y) \
	((p)->clut = GetClut(x,y))
					   
/*
 * Set Primitive Colors
 */
#define setRGB0(p,_r0,_g0,_b0)						\
	(p)->r0 = _r0,(p)->g0 = _g0,(p)->b0 = _b0
	
#define setRGB1(p,_r1,_g1,_b1)						\
	(p)->r1 = _r1,(p)->g1 = _g1,(p)->b1 = _b1

#define setRGB2(p,_r2,_g2,_b2)						\
	(p)->r2 = _r2,(p)->g2 = _g2,(p)->b2 = _b2
	
#define setRGB3(p,_r3,_g3,_b3)						\
	(p)->r3 = _r3,(p)->g3 = _g3,(p)->b3 = _b3
	
/*
 * Set Primitive Screen Points
 */
#define setXY0(p,_x0,_y0)						\
	(p)->x0 = (_x0), (p)->y0 = (_y0)				\

#define setXY2(p,_x0,_y0,_x1,_y1)					\
	(p)->x0 = (_x0), (p)->y0 = (_y0),				\
	(p)->x1 = (_x1), (p)->y1 = (_y1)

#define setXY3(p,_x0,_y0,_x1,_y1,_x2,_y2)				\
	(p)->x0 = (_x0), (p)->y0 = (_y0),				\
	(p)->x1 = (_x1), (p)->y1 = (_y1),				\
	(p)->x2 = (_x2), (p)->y2 = (_y2)

#define setXY4(p,_x0,_y0,_x1,_y1,_x2,_y2,_x3,_y3) 			\
	(p)->x0 = (_x0), (p)->y0 = (_y0),				\
	(p)->x1 = (_x1), (p)->y1 = (_y1),				\
	(p)->x2 = (_x2), (p)->y2 = (_y2),				\
	(p)->x3 = (_x3), (p)->y3 = (_y3)

#define setXYWH(p,_x0,_y0,_w,_h)					\
	(p)->x0 = (_x0),      (p)->y0 = (_y0),				\
	(p)->x1 = (_x0)+(_w), (p)->y1 = (_y0),				\
	(p)->x2 = (_x0),      (p)->y2 = (_y0)+(_h),			\
	(p)->x3 = (_x0)+(_w), (p)->y3 = (_y0)+(_h)

/*
 * Set Primitive Width/Height
 */
#define setWH(p,_w,_h)	(p)->w = _w, (p)->h = _h

/*
 * Set Primitive Texture Points
 */
#define setUV0(p,_u0,_v0)						\
	(p)->u0 = (_u0), (p)->v0 = (_v0)				\
	
#define setUV3(p,_u0,_v0,_u1,_v1,_u2,_v2)				\
	(p)->u0 = (_u0), (p)->v0 = (_v0),				\
	(p)->u1 = (_u1), (p)->v1 = (_v1),				\
	(p)->u2 = (_u2), (p)->v2 = (_v2)
	
#define setUV4(p,_u0,_v0,_u1,_v1,_u2,_v2,_u3,_v3) 			\
	(p)->u0 = (_u0), (p)->v0 = (_v0),				\
	(p)->u1 = (_u1), (p)->v1 = (_v1),				\
	(p)->u2 = (_u2), (p)->v2 = (_v2),				\
	(p)->u3 = (_u3), (p)->v3 = (_v3)

#define setUVWH(p,_u0,_v0,_w,_h)					\
	(p)->u0 = (_u0),      (p)->v0 = (_v0),				\
	(p)->u1 = (_u0)+(_w), (p)->v1 = (_v0),				\
	(p)->u2 = (_u0),      (p)->v2 = (_v0)+(_h),			\
	(p)->u3 = (_u0)+(_w), (p)->v3 = (_v0)+(_h)

	
/*
 * Dump Primivie Parameters
 */
#define dumpRECT(r)	\
	GPU_printf("(%d,%d)-(%d,%d)\n", (r)->x,(r)->y,(r)->w,(r)->h)

#define dumpWH(p)	GPU_printf("(%d,%d)\n", (p)->w,  (p)->h ) 
#define dumpXY0(p)	GPU_printf("(%d,%d)\n", (p)->x0, (p)->y0) 
#define dumpUV0(p)	GPU_printf("(%d,%d)\n", (p)->u0, (p)->v0) 

#define dumpXY2(p)							\
	GPU_printf("(%d,%d)-(%d,%d)\n",					\
	(p)->x0, (p)->y0, (p)->x1, (p)->y1)

#define dumpXY3(p)							\
	GPU_printf("(%d,%d)-(%d,%d)-(%d,%d)\n",				\
	(p)->x0, (p)->y0, (p)->x1, (p)->y1,				\
	(p)->x2, (p)->y2)

#define dumpUV3(p)							\
	GPU_printf("(%d,%d)-(%d,%d)-(%d,%d)\n",				\
	(p)->u0, (p)->v0, (p)->u1, (p)->v1,				\
	(p)->u2, (p)->v2)

#define dumpXY4(p)							\
	GPU_printf("(%d,%d)-(%d,%d)-(%d,%d)-(%d,%d)\n",			\
	(p)->x0, (p)->y0, (p)->x1, (p)->y1,				\
	(p)->x2, (p)->y2, (p)->x3, (p)->y3)

#define dumpUV4(p)							\
	GPU_printf("(%d,%d)-(%d,%d)-(%d,%d)-(%d,%d)\n",			\
	(p)->u0, (p)->v0, (p)->u1, (p)->v1,				\
	(p)->u2, (p)->v2, (p)->u3, (p)->v3)			

#define dumpRGB0(p)							\
	GPU_printf("(%3d,%3d,%3d)\n", (p)->r0, (p)->g0, (p)->b0) 	
		   
#define dumpRGB1(p)							\
	GPU_printf("(%3d,%3d,%3d)\n", (p)->r1, (p)->g1, (p)->b1)	
		   
#define dumpRGB2(p)							\
	GPU_printf("(%3d,%3d,%3d)\n", (p)->r2, (p)->g2, (p)->b2) 
		   
#define dumpRGB3(p)							\
	GPU_printf("(%3d,%3d,%3d)\n", (p)->r3, (p)->g3, (p)->b3) 	

/*
 * Primitive Handling Macros
 */
#define setlen( p, _len) 	(((P_TAG *)(p))->len  = (u_char)(_len))
#define setaddr(p, _addr)	(((P_TAG *)(p))->addr = (u_long)(_addr))
#define setcode(p, _code)	(((P_TAG *)(p))->code = (u_char)(_code))

#define getlen(p)    		(u_char)(((P_TAG *)(p))->len)
#define getcode(p)   		(u_char)(((P_TAG *)(p))->code)
#define getaddr(p)   		(u_long)(((P_TAG *)(p))->addr)

#define nextPrim(p)  		(void *)((((P_TAG *)(p))->addr)|0x80000000)
#define isendprim(p) 		((((P_TAG *)(p))->addr)==0xffffff)

#define addPrim(ot, p)		setaddr(p, getaddr(ot)), setaddr(ot, p)
#define addPrims(ot, p0, p1)	setaddr(p1, getaddr(ot)),setaddr(ot, p0)

#define catPrim(p0, p1)		setaddr(p0, p1)
#define termPrim(p)		setaddr(p, 0xffffffff)

#define setSemiTrans(p, abe) \
	((abe)?setcode(p, getcode(p)|0x02):setcode(p, getcode(p)&~0x02))

#define setShadeTex(p, tge) \
	((tge)?setcode(p, getcode(p)|0x01):setcode(p, getcode(p)&~0x01))

#define getTPage(tp, abr, x, y) 					\
	(GetGraphType()?						\
	 (((tp&0x3)<<9)|((abr&0x3)<<7)|((y&0x300)>>3)|((x&0x3ff)>>6)):	\
	 (((tp&0x3)<<7)|((abr&0x3)<<5)|((y&0x100)>>4)|((x&0x3ff)>>6)))	

#define getClut(x, y) \
	((y<<6)|((x>>4)&0x3f))

#define dumpTPage(tpage)						\
	(GetGraphType()?						\
	GPU_printf("tpage: (%d,%d,%d,%d)\n",				\
			   (tpage>>9)&0x003,(tpage>>7)&0x003,		\
			   (tpage<<6)&0x7c0,(tpage<<3)&0x300):		\
	GPU_printf("tpage: (%d,%d,%d,%d)\n",				\
			   (tpage>>7)&0x003,(tpage>>5)&0x003,		\
			   (tpage<<6)&0x7c0,(tpage<<4)&0x100))		


#define dumpClut(clut) \
	GPU_printf("clut: (%d,%d)\n", (clut&0x3f)<<4, (clut>>6))

/*	Primitive 	Lentgh		Code				*/
/*--------------------------------------------------------------------	*/
/*									*/
#define setPolyF3(p)	setlen(p, 4), 	setcode(p, 0x20)
#define setPolyFT3(p)	setlen(p, 7), 	setcode(p, 0x24)
#define setPolyG3(p)	setlen(p, 6), 	setcode(p, 0x30)
#define setPolyGT3(p)	setlen(p, 9), 	setcode(p, 0x34)
#define setPolyF4(p)	setlen(p, 5), 	setcode(p, 0x28)
#define setPolyFT4(p)	setlen(p, 9), 	setcode(p, 0x2c)
#define setPolyG4(p)	setlen(p, 8), 	setcode(p, 0x38)
#define setPolyGT4(p)	setlen(p, 12), 	setcode(p, 0x3c)

#define setSprt8(p)	setlen(p, 3), 	setcode(p, 0x74)
#define setSprt16(p)	setlen(p, 3), 	setcode(p, 0x7c)
#define setSprt(p)	setlen(p, 4), 	setcode(p, 0x64)

#define setTile1(p)	setlen(p, 2), 	setcode(p, 0x68)
#define setTile8(p)	setlen(p, 2), 	setcode(p, 0x70)
#define setTile16(p)	setlen(p, 2), 	setcode(p, 0x78)
#define setTile(p)	setlen(p, 3), 	setcode(p, 0x60)

#define setBlockFill(p)	setlen(p, 3), 	setcode(p, 0x02)

#define setLineF2(p)	setlen(p, 3), 	setcode(p, 0x40)
#define setLineG2(p)	setlen(p, 4), 	setcode(p, 0x50)
#define setLineF3(p)	setlen(p, 5), 	setcode(p, 0x48), (p)->pad = 0x55555555
#define setLineG3(p)	setlen(p, 7), 	setcode(p, 0x58), (p)->pad = 0x55555555
#define setLineF4(p)	setlen(p, 6), 	setcode(p, 0x4c), (p)->pad = 0x55555555
#define setLineG4(p)	setlen(p, 9), 	setcode(p, 0x5c), (p)->pad = 0x55555555

/*
 * Rectangle:
 */
typedef struct {
	short x, y;		/* offset point on VRAM */
	short w, h;		/* width and height */
} RECT;

/*
 * Environment 
 */
typedef struct {
	u_long	tag;
	u_long	code[15];
} DR_ENV;				/* Packed Drawing Environment */
	       
typedef struct {
	RECT	clip;		/* clip area */
	short	ofs[2];		/* drawing offset */
	RECT	tw;		/* texture window */
	u_short tpage;		/* texture page */	
	u_char	dtd;		/* dither flag (0:off, 1:on) */
	u_char	dfe;		/* flag to draw on display area (0:off 1:on) */
	u_char	isbg;		/* enable to auto-clear */
	u_char	r0, g0, b0;	/* initital background color */
	DR_ENV	dr_env;		/* reserved */
} DRAWENV;
	       
typedef struct {
	RECT	disp;		/* display area */
	RECT	screen;		/* display start point */
	u_char	isinter;	/* interlace 0: off 1: on */
	u_char	isrgb24;	/* RGB24 bit mode */
	u_char	pad0, pad1;	/* reserved */
} DISPENV;

/*
 * Polygon Primitive Definitions
 */
typedef struct {
	unsigned	addr: 24;
	unsigned 	len:   8;
	u_char		r0, g0, b0, code;
} P_TAG;
	
typedef struct {
	u_char	r0, g0, b0, code;
} P_CODE;
	
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
	short	x2,	y2;
} POLY_F3;				/* Flat Triangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
	short	x2,	y2;
	short	x3,	y3;
} POLY_F4;				/* Flat Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad1;
} POLY_FT3;				/* Flat Textured Triangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad1;
	short	x3,	y3;
	u_char	u3, v3;	u_short	pad2;
} POLY_FT4;				/* Flat Textured Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, pad1;
	short	x1,	y1;
	u_char	r2, g2, b2, pad2;
	short	x2,	y2;
} POLY_G3;				/* Gouraud Triangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, pad1;
	short	x1,	y1;
	u_char	r2, g2, b2, pad2;
	short	x2,	y2;
	u_char	r3, g3, b3, pad3;
	short	x3,	y3;
} POLY_G4;				/* Gouraud Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	u_char	r1, g1, b1, p1;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	u_char	r2, g2, b2, p2;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad2;
} POLY_GT3;				/* Gouraud Textured Triangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	u_char	r1, g1, b1, p1;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	u_char	r2, g2, b2, p2;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad2;
	u_char	r3, g3, b3, p3;
	short	x3,	y3;
	u_char	u3, v3;	u_short	pad3;
} POLY_GT4;				/* Gouraud Textured Quadrangle */

/*
 * Line Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
} LINE_F2;				/* Unconnected Flat Line */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, p1;
	short	x1,	y1;
} LINE_G2;				/* Unconnected Gouraud Line */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
	short	x2,	y2;
	u_long	pad;
} LINE_F3;				/* 2 connected Flat Line */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, p1;
	short	x1,	y1;
	u_char	r2, g2, b2, p2;
	short	x2,	y2;
	u_long	pad;
} LINE_G3;				/* 2 connected Gouraud Line */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
	short	x2,	y2;
	short	x3,	y3;
	u_long	pad;
} LINE_F4;				/* 3 connected Flat Line Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, p1;
	short	x1,	y1;
	u_char	r2, g2, b2, p2;
	short	x2,	y2;
	u_char	r3, g3, b3, p3;
	short	x3,	y3;
	u_long	pad;
} LINE_G4;				/* 3 connected Gouraud Line */

/*
 * Block Fill Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	u_short	x0, 	y0;
	u_short	w, 	h;	
} BLK_FILL;				/* Clear Frame Buffer */
	       
/*
 * Sprite Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	short	w,	h;
} SPRT;					/* free size Sprite */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
} SPRT_16;				/* 16x16 Sprite */
	       
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
} SPRT_8;				/* 8x8 Sprite */
	       
/*
 * Tile Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	w,	h;
} TILE;					/* free size Tile */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
} TILE_16;				/* 16x16 Tile */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
} TILE_8;				/* 8x8 Tile */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
} TILE_1;				/* 1x1 Tile */

/*
 *  Special Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_long	code[2];
} DR_MODE;				/* Drawing Mode */

typedef struct {
	u_long	tag;
	u_long	code[2];
} DR_PRIO;				/* Priority */
	       
typedef struct {
	u_long	tag;
	u_long	code[2];
} DR_TWIN;				/* Texture Window */
	       
typedef struct {
	u_long	tag;
	u_long	code[2];
} DR_AREA;				/* Drawing Area */
	       
typedef struct {
	u_long	tag;
	u_long	code[2];
} DR_OFFSET;				/* Drawing Offset */
	       
/*
 *	Multi-purpose Sony-TMD primitive
 */
typedef struct {
	u_long	id;	
	u_char	r0, g0, b0, p0;		/* Color of vertex 0 */
	u_char	r1, g1, b1, p1;		/* Color of vertex 1 */
	u_char	r2, g2, b2, p2;		/* Color of vertex 2 */
	u_char	r3, g3, b3, p3;		/* Color of vertex 3 */
	u_short	tpage, clut;		/* texture page ID, clut ID */
	u_char	u0, v0, u1, v1;		/* texture corner point */
	u_char	u2, v2, u3, v3;
	
	/* independent vertex model */
	SVECTOR	x0, x1, x2, x3;		/* 3D corner point */
	SVECTOR	n0, n1, n2, n3;		/* 3D corner normal vector */
	
	/* Common vertex model */
	SVECTOR	*v_ofs;			/* offset to vertex database */
	SVECTOR	*n_ofs;			/* offset to normal database */
	
	u_short	vert0, vert1; 		/* index of vertex */
	u_short	vert2, vert3;		
	u_short	norm0, norm1; 		/* index of normal */
	u_short	norm2, norm3;

	
} TMD_PRIM;

/*
 *	Multi-purpose TIM image
 */
typedef struct {
	u_long  mode;		/* pixel mode */
	RECT	*crect;		/* CLUT rectangle on frame buffer */
	u_long	*caddr;		/* CLUT address on main memory */
	RECT	*prect;		/* texture image rectangle on frame buffer */
	u_long	*paddr;		/* texture image address on main memory */
} TIM_IMAGE;
	       
/*
 * Prototypes
 */
DISPENV *GetDispEnv(DISPENV *env);
DISPENV *PutDispEnv(DISPENV *env);
DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h);
DRAWENV *GetDrawEnv(DRAWENV *env);
DRAWENV *PutDrawEnv(DRAWENV *env);
DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h);
TIM_IMAGE *ReadTIM(TIM_IMAGE *timimg);
TMD_PRIM *ReadTMD(TMD_PRIM *tmdprim);
char *itoa(int x);
int CheckPrim(char *s, u_long *p);
int ClearImage(RECT *rect, u_char r, u_char g, u_char b);
int DrawSync(int mode);
int FntOpen(int x, int y, int w, int h, int isbg, int n);
/*int FntPrint(int id, ...);*/
int GetGraphDebug(void) ;
int GetGraphType(void) ;
int GetTimSize(u_char *sjis);
int IsEndPrim(void *p) ;
int KanjiFntOpen(int x, int y, int w, int h, int dx, int dy, int cx, int cy, int isbg, int n);
/*int KanjiFntPrint(int id, ...);*/
int Krom2Tim(u_char *sjis, u_long *taddr, int dx, int dy, int cdx, int cdy, u_int fg, u_int bg);
int LoadImage(RECT *rect, u_long *p);
int MargePrim(void *p0, void *p1);
int MoveImage(RECT *rect, int x, int y);
int OpenTIM(u_long *addr);
int OpenTMD(u_long *tmd, int obj_no);
int PutKanji(u_char *sjis);
int ResetGraph(int mode);
int SetGraphDebug(int level);
int SetGraphReverse(int mode);
int StoreImage(RECT *rect, u_long *p);
int hankanjitrans(u_char scode);
int kanjitrans(u_short scode);
int sprintf(char *buffer, char *fmt, ...);
u_long *ClearOTag(u_long *ot, int n);
u_long *ClearOTagR(u_long *ot, int n);
u_long *FntFlush(int id);
u_long *KanjiFntFlush(int id);
u_long DrawSyncCallback(void (*func)());
u_short GetClut(int x, int y) ;
u_short GetTPage(int tp, int abr, int x, int y) ;
u_short GetTPageA(int tp, int abr, int x, int y);
u_short LoadClut(u_long *clut, int x, int y);
u_short LoadTPage(u_long *pix, int tp, int abr, int x, int y, int w, int h);
u_short LoadTPageA(u_long *tex, int tp, int abr, int tx, int ty, int tw, int th);
void *NextPrim(void *p) ;
void AddPrim(void *ot, void *p) ;
void AddPrims(void *ot, void *p0, void *p1) ;
void CatPrim(void *p0, void *p1) ;
void DrawOTag(u_long *p);
void DrawOTagIO(u_long *p);
void DrawPrim(void *p);
void DumpClut(u_short clut) ;
void DumpDispEnv(DISPENV *env);
void DumpDrawEnv(DRAWENV *env);
void DumpOTag(u_long *p);
void DumpTPage(u_short tpage) ;
void FntLoad(int tx, int ty);
void KanjiFntLoad(int tx, int ty);
void SetBlockFill(BLK_FILL *p) ;
void SetDispMask(int mask);
void SetDrawArea(DR_AREA *p, RECT *r);
void SetDrawEnv(DR_ENV *dr_env, DRAWENV *env);
void SetDrawMode(DR_MODE *p, int dfe, int dtd, int tpage, RECT *tw);
void SetDrawOffset(DR_OFFSET *p, u_short *ofs);
void SetDumpFnt(int id);
void SetLineF2(LINE_F2 *p) ;
void SetLineF3(LINE_F3 *p) ;
void SetLineF4(LINE_F4 *p) ;
void SetLineG2(LINE_G2 *p) ;
void SetLineG3(LINE_G3 *p) ;
void SetLineG4(LINE_G4 *p) ;
void SetPolyF3(POLY_F3 *p) ;
void SetPolyF4(POLY_F4 *p) ;
void SetPolyFT3(POLY_FT3 *p) ;
void SetPolyFT4(POLY_FT4 *p) ;
void SetPolyG3(POLY_G3 *p) ;
void SetPolyG4(POLY_G4 *p) ;
void SetPolyGT3(POLY_GT3 *p) ;
void SetPolyGT4(POLY_GT4 *p) ;
void SetPriority(DR_PRIO *p, int pbc, int pbw);
void SetSemiTrans(void *p, int abe) ;
void SetShadeTex(void *p, int tge) ;
void SetSprt(SPRT *p) ;
void SetSprt16(SPRT_16 *p) ;
void SetSprt8(SPRT_8 *p) ;
void SetTexWindow(DR_TWIN *p, RECT *tw);
void SetTile(TILE *p) ;
void SetTile1(TILE_1 *p) ;
void SetTile16(TILE_16 *p) ;
void SetTile8(TILE_8 *p) ;
void TermPrim(void *p) ;

#endif /* _LIBGPU_H_ */
