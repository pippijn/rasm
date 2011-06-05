/*	OPCODE	+ i		= immediate operand
 *		+ r		= register operand
 *		+ m		= memory operand (disp,base,index,scale)
 *		+ sr/sm		= a star preceding a register or memory
 */

#if defined(_ASM_SAFETY)
#define _r1(R)          ( ((R) & ~3) == _AL || ((R) & ~3) == _AH ? _rN(R) : JITFAIL( "8-bit register required"))
#endif

#define _rA(R)          _r4(R)

/* Use RIP-addressing in 64-bit mode, if possible */
#define _r_X(   R, D,B,I,S,O)	(_r0P(I) ? (_r0P(B)    ? _r_D   (R,D                ) : \
				           (_rsp12P(B) ? _r_DBIS(R,D,_ESP,_ESP,1)   : \
						         _r_DB  (R,D,     B       )))  : \
				 (_r0P(B)	       ? _r_4IS (R,D,	         I,S)   : \
				 (!_rspP(I)            ? _r_DBIS(R,D,     B,     I,S)   : \
						         JITFAIL("illegal index register: %esp"))))
#define _m32only(X)		(X)
#define _m64only(X)		JITFAIL("invalid instruction in 32-bit mode")
#define _m64(X)			(0)

#define _AH		0x24
#define _CH		0x25
#define _DH		0x26
#define _BH		0x27

#define CALLsr(R)			CALLLsr(R)
#define JMPsr(R)			JMPLsr(R)

#define DECWr(RD)	(_d16(),	_Or		(0x48,_r2(RD)							))
#define DECLr(RD)		 	_Or		(0x48,_r4(RD)							)
#define INCWr(RD)	(_d16(),	_Or		(0x40,_r2(RD)							))
#define INCLr(RD)	 		_Or		(0x40,_r4(RD)							)
