/*
 * $PSLibId: Runtime Library Versin 3.0$
 */
/*
 * File:libcomb.h
*/

/* status bits */
#define COMB_CTS		0x100
#define COMB_DSR		0x80
#define COMB_FE			0x20
#define COMB_OE			0x10
#define COMB_PERROR		0x8
#define COMB_TXU		0x4
#define COMB_RXRDY		0x2
#define COMB_TXRDY		0x1

/*
extern AddCOMB(void);
extern DelCOMB(void);
*/
extern ChangeClearSIO(long);
extern _comb_control(long,long);
