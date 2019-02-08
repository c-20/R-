#define CMDSRC		"/tau/src/cmd"
#define CMDDIR		"/tau/cmd"
#define CODEHEAD	"code.h"
#define CODEHD		CODEHEAD
#define IF		if
#define If		IF
#define IFEQ(var, num)	IF (var EQ num)
#define IFLT(var, num)	IF (var LT num)
#define IFLQ(var, num)	IF (var LQ num)
#define IFGT(var, num)	IF (var GT num)
#define IFGQ(var, num)	IF (var GQ num)
#define IFNQ(var, num)	IF (var NQ num)
#define IFEQOR2(var, n1, n2)            IF (var EQ n1 OR var EQ n2)
#define IFEQAND2(var, n1, n2)           IF (var EQ n1 AND var EQ n2)
#define IFEQOR3(var, n1, n2, n3)        IF (var EQ n1 OR var EQ n2 OR var EQ n3)
#define IFEQAND3(var, n1, n2, n3)       IF (var EQ n1 AND var EQ n2 AND var EQ n3)
#define IFEQOR4(var, n1, n2, n3, n4)    IF (var EQ n1 OR var EQ n2 OR var EQ n3 OR var EQ n4)
#define IFEQAND4(var, n1, n2, n3, n4)   IF (var EQ n1 AND var EQ n2 AND var EQ n3 AND var EQ n4)
#define IFEQ1(var, n1)                  IFEQ(var, n1)
#define IFEQ2(var, n1, n2)              IFEQOR2(var, n1, n2)
#define IFEQ3(var, n1, n2, n3)          IFEQOR3(var, n1, n2, n3)
#define IFEQ4(var, n1, n2, n3, n4)      IFEQOR4(var, n1, n2, n3, n4)
#define IFEQ5(var, n1, n2, n3, n4, n5)  IFEQOR5(var, n1, n2, n3, n4, n5)
#define EF		else if
#define ELSEIF		EF
#define ELIF		ELSEIF
#define ElseIf		ELSEIF
#define EFEQ(var, num)	EF (var EQ num)
#define EFLT(var, num)	EF (var LT num)
#define EFLQ(var, num)	EF (var LQ num)
#define EFGT(var, num)	EF (var GT num)
#define EFGQ(var, num)	EF (var GQ num)
#define EFNQ(var, num)	EF (var NQ num)
#define EFEQOR2(var, n1, n2)            EF (var EQ n1 OR var EQ n2)
#define EFEQAND2(var, n1, n2)           EF (var EQ n1 AND var EQ n2)
#define EFEQOR3(var, n1, n2, n3)        EF (var EQ n1 OR var EQ n2 OR var EQ n3)
#define EFEQAND3(var, n1, n2, n3)       EF (var EQ n1 AND var EQ n2 AND var EQ n3)
#define EFEQOR4(var, n1, n2, n3, n4)    EF (var EQ n1 OR var EQ n2 OR var EQ n3 OR var EQ n4)
#define EFEQAND4(var, n1, n2, n3, n4)   EF (var EQ n1 AND var EQ n2 AND var EQ n3 AND var EQ n4)
#define EFEQOR5(var, n1, n2, n3, n4, n5)    EF (var EQ n1 OR var EQ n2 OR var EQ n3 OR var EQ n4 OR var EQ n5)
#define EFEQAND5(var, n1, n2, n3, n4, n5)   EF (var EQ n1 AND var EQ n2 AND var EQ n3 AND var EQ n4 OR var EQ n5)
#define EFEQ1(var, n1)                  EFEQ(var, n1)
#define EFEQ2(var, n1, n2)              EFEQOR2(var, n1, n2)
#define EFEQ3(var, n1, n2, n3)          EFEQOR3(var, n1, n2, n3)
#define EFEQ4(var, n1, n2, n3, n4)      EFEQOR4(var, n1, n2, n3, n4)
#define EFEQ5(var, n1, n2, n3, n4, n5)  EFEQOR5(var, n1, n2, n3, n4, n5)
#define EL		else
#define ELSE		EL
#define Else		ELSE
#define DO		do
#define Do		DO
#define WI		while
#define WHILE		WI
#define While		WHILE
#define WHILELOOP	WHILE
#define LOOP		WHILE (1)
#define LP		LOOP
#define WhileLoop	WHILE
#define WINQEOF(var)	WI (var NQEOF)
#define WIEQ(var, num)	WI (var EQ num)
#define WILT(var, num)	WI (var LT num)
#define WILQ(var, num)	WI (var LQ num)
#define WIGT(var, num)	WI (var GT num)
#define WIGQ(var, num)	WI (var GQ num)
#define WINQ(var, opt)  WI (var NQ opt)
#define WINQ2(var, o1, o2)  WI (var NQ o1 AND var NQ o2)
#define WINQ3(var, o1, o2, o3)  WI (var NQ o1 AND var NQ o2 AND var NQ o3)
#define WINQ4(var, o1, o2, o3, o4)  WI (var NQ o1 AND var NQ o2 AND var NQ o3 AND var NQ o4)
//#define INWINCEQ(var, num)     IN var = -1; WI (INC var EQ num)
#define INWI1(var, val)             IN var = val; WI (1)
#define INWINCLT(var, num)          IN var = -1; WI (INC var LT num)
#define INWINCLQ(var, num)          IN var = -1; WI (INC var LQ num)
#define IN0WINCLT(var, num)         IN var = 0; WI (INC var LT num)
#define IN0WINCLQ(var, num)         IN var = 0; WI (INC var LQ num)
#define INWDECGT(lim, var, num)     IN var = lim; WI (DEC var GT num)
#define INWDECGQ(lim, var, num)     IN var = lim; WI (DEC var GQ num)
//#define INWINCNQ(var, num)     IN var = -1; WI (INC var NQ num)
#define INWINCNQNUL(var, str)  IN var = -1; WI (str[INC var] NQNUL)
#define INWINCELNQ(var, str, elch)   IN var = -1; WI (str[INC var] NQNUL AND str[var] NQ elch)
#define INWINC(var, str) INWINCNQNUL(var, str)
#define FOR		for
#define For		FOR
#define FORLOOP		FOR
#define ForLoop		FOR
#define IN		int
#define UIN		unsigned IN
#define SIN		signed IN
#define UNSIGNEDINT	UIN
#define UNSIGNEDINTEGER	    UIN
#define UNSIGNEDINTEGERNUMBER	UIN
#define SIGNEDINTEGERNUMBER	IN
#define SIGNEDINTEGER		IN
//#define SIN		SIGNEDINTEGERNUMBER
//#define SIN		SINE  <-- no, that is sin(). SIN can mean Signed Integer Number
// define SIN as SINE over SIGNEDINTEGERNUMBER <-- no, but this should be configurable

//#define INT		IN <-- conflicts with INT(name, value) definition.. fix! IN() LN() etc also
#define INTEGER		IN
#define INTEGERNUMBER	INTEGER
#define IntegerNumber   INTEGERNUMBER
#define INP		IN *

#define LONGTYPE	long long
#define LONGLIMIT	LLONG_MAX
#define LN		LONGTYPE
#define LL		LONGLIMIT
#define LLDIGITS	19    // 18 whole digits actually
typedef struct { LN numb; LN frac; LN diff; } LF;
#define LFP		LF *
#define ULN		unsigned LN
#define SLN		signed LN
#define LONG		LN
#define LNP		LN *
#define LNA		LNP
#define LONGARRAY	LNA
#define LONGPOINTER	LNP
#define LONGP		LONGPOINTER
#define LONGNUMBER	LONG
#define LongNumber      LONGNUMBER
// ------------------------------------------------------------------------------------
// all deprecated in favour of lf.h
/*
#define LONGFLOATSTRUCT	LF
#define LongFloatStruct	LONGFLOATSTRUCT
#define LONGFLOAT	LONGFLOATSTRUCT
#define LongFloat	LONGFLOAT
typedef struct { LF  valueA; LF  valueB; LF  valueC;
                 LF digitsA; LF digitsB; LF digitsC;
                 LF  scaleA; LF  scaleB; LF  scaleC;
                 LF excessA; LF excessB; LF excessC; } LFP;
#define LONGFLOATPAIR		LFP
#define LongFloatPair		LONGFLOATPAIR
//typedef struct { LF valuenumb; LF valuefrac; LF valuemeld; } LFMUL;
//#define LFADD LFMUL
//#define LFSUB LFMUL
//#define LFDIV LFMUL
//#define LFMOD LFMUL
// later, more complicated constructs may have extra variables
//#define LONGFLOATMULTIPLY	LFMUL
// also LFA, LFS, LFD, LFMOD (LFM -> LFMUL, not LFMOD) .. or just use non-ambiguous names
// so, LFADD, LFSUB, LFMUL, LFDIV, LFMOD
#define LF_0_0(lf)	lf.numb = 0; lf.frac = 0; lf.diff = -1; // -0.0

typedef struct { LF value; LF scale; LN overflow; } LFO;
typedef struct { LF value; LF digits; LF scale; } LFDS;
#define LONGFLOATOVERFLOW        LFO
#define LongFloatOverflow        LONGFLOATOVERFLOW
#define LONGFLOATDIGITSCALE      LFDS
#define LongFloatDigitScale      LONGFLOATDIGITSCALE
#define LONGFLOATDETAIL          LFD
#define LongFloatDetail          LONGFLOATDETAIL
#define LONGFLOATDETAILSTRUCT    LFD
#define LongFloatDetailStruct    LONGFLOATDETAILSTRUCT
#define LDF  LFD
#define LONGDETAILEDFLOATSTRUCT  LDF
#define LongDetailedFloatStruct  LONGDETAILEDFLOATSTRUCT
#define LONGDETAILEDFLOAT  LONGDETAILEDFLOATSTRUCT
#define LongDetailedFloat  LONGDETAILEDFLOAT

*/

#define FIX1(pre, suf1)			pre##suf1
#define FIX2(pre, suf1, suf2)		pre##suf1; pre##suf2
#define FIX3(pre, suf1, suf2, suf3)	pre##suf1; pre##suf2; pre##suf3;



#define GLFLOATTYPE	GLfloat
#define GLFP		GLFLOATTYPE
#define GLFPP		GLFP *
#define GLFPA		GLFPP
#define GLFLOATARRAY	GLFPA
#define GLFloatArray	GLFLOATARRAY

#define FLOATTYPE	float
#define FP		FLOATTYPE
#define FPP		FP *
#define FPA		FPP
#define FLOATARRAY      FPA
#define FloatArray      FLOATARRAY
#define FLOATINGPOINTARRAY  FPA
#define FloatingPointArray  FLOATINGPOINTARRAY
#define FLOATPOINTER	FPP
#define FLOATP		FLOATPOINTER
#define FLOAT		FP
#define FLOATINGPOINT	FLOAT
#define FloatingPoint   FLOATINGPOINT

#define DOUBLETYPE	double
#define DP		DOUBLETYPE
#define DPP		DP *
#define DPA		DPP
#define DOUBLEARRAY     DPA
#define DoubleArray     DOUBLEARRAY
#define DOUBLEPRECISIONFLOATINGPOINTARRAY  DPA
#define DoublePrecisionFloatingPointArray  DOUBLEPRECISIONFLOATINGPOINTARRAY
#define DOUBLEPOINTER	DPP
#define DOUBLEP		DOUBLEPOINTER
#define DOUBLE		DP
#define DOUBLINGPOINT	DOUBLE
#define DoublingPoint   DOUBLINGPOINT




// exclude the below if kernel mode active (was KLOG used?)
#ifndef KERNELMODE

#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
// for printf
#endif
#define FS		FILE *
#define CMD		FILE *
#define FILEP		FILE *
// ^ file string ? i guess that makes sense
// ^ no, file stream...
#define FILESTRING	FS
#define FileString	FILESTRING
#define FILESTREAM	FS
#define FileStream	FILESTREAM
#define OPENCMD(cmd)     popen(cmd, "r")
#define OPENFILE(f)      fopen(f, "r")
#define OPENFILENAME(f)  OPENFILE(f)     // open by name, close file
#define SAVEFILE(f)      fopen(f, "w")
#define SENDCMD(cmd)     popen(cmd, "w")
#define MODIFYFILE(f)    fopen(f, "r+")
#define EDITFILE(f)      MODIFYFILE(f)
#define WRITEFILE(f)     fopen(f, "w+")
#define OPENBLOCKFILE(f) fopen(f, "rb")
#define SAVEBLOCKFILE(f) fopen(f, "wb")
#define GETCH(fs)        fgetc(fs)
#define GETFCH(fs)       fgetc(fs)
#define GETCMDCH(fs)     GETCH(fs)
#define GETFILECH(fs)    GETCH(fs)
#define GETSTDCH         GETCH(stdin)
#define GETSTDCHAR       GETSTDCH
#define PUTSTDCH(ch)     fputc(ch, stdout)
#define PUTSTDCHAR(ch)   PUTSTDCH(ch)
#define PUTFCH(fs, ch)   fputc(ch, fs)
#define STDGETCHAR       GETSTDCHAR
#define STDPUTCHAR(ch)   PUTSTDCH(ch)
#define FGETCHAR(fs)     GETFCH(fs)
#define FPUTCHAR(fs, ch) PUTFCH(fs, ch)
#define STDGETCH         STDGETCHAR
#define STDPUTCH(ch)     STDPUTCHAR(ch)
#define FGETCH(fs)       FGETCHAR(fs)
#define FPUTCH(fs, ch)   FPUTCHAR(fs, ch)
//#define CLOSECMD(cmd)	IF (cmd) { pclose(cmd); }
#define CLOSEFILE(f)	IF (f) { fclose(f); } // cannot be used as QUICKFILE ...
// graceful in case of failed open, should have error handler functions
#define CLOSEBLOCKFILE(f) fclose(f)
#define GOTOEOF(fs)	fseek(fs, 0, SEEK_END)
#define GOTOSOF(fs)	fseek(fs, 0, SEEK_SET)
#define GETFPOS(fs)	ftell(fs)
#define NEXTFCH(fs)	fseek(fs, 1, SEEK_CUR)
#define PREVFCH(fs)	fseek(fs, -1, SEEK_CUR)
#define NEXTCH(fs)	NEXTFCH(fs) // <-- deprecated
#define PREVCH(fs)	PREVFCH(fs) // <-- deprecated
#define STEPF(fs, n)	fseek(fs, n, SEEK_CUR)
#define ISFEOF(fs)	(feof(fs))
#define NOTFEOF(fs)	(!feof(fs))
#define NOTSTDEOF	NOTFEOF(stdin)
#define MORECHARS	NOTSTDEOF
//#define FCHOUT(ch,fs)	fputc(ch, fs)
#define CHFOUT(ch, fs)  fputc(ch, fs)
#define FCHOUT(fs, ch)  fputc(ch, fs)
#define OUTFCH(fs, ch)  fputc(ch, fs)
#define PUTFCH(fs, ch)  fputc(ch, fs)
#define PUTFCS(fs, cs)  fputs(cs, fs)
//#define FPUTCH(fs, ch)  fputc(ch, fs) // already defined above....
// do not encourage FPUTC since params are backwards
#define STDCHOUT(ch)	CHFOUT(ch, stdout)
#define STDOUTCH(ch)	STDCHOUT(ch)
// ^^ CLOSECMD(cmd) --> IF (OPENCMD(cmd)) { pclose(OPENCMD(cmd); } // nope ....
//#define CLOSECMD(fs)	fclose(fs)		 // assumes command opens
// wait wut ^ and ^^
#define CLOSECMD(cmd)	pclose(cmd) // does not check .. should CLOSEFILE ? TRY-
#define QUICKCMD(cmd)	CLOSECMD(OPENCMD(cmd))
#define IFNOTFEOF(fs)	IF (NOTFEOF(fs))
#define IFNFEOF(fs)	IFNOTFEOF(fs)
#define EFNFEOF(fs)	EF (NOTFEOF(fs))
#define EFNOTFEOF(fs)	EFNFEOF(fs)
#define WINOTFEOF(fs)	WI (NOTFEOF(fs))
#define WINFEOF(fs)	WINOTFEOF(fs)
#define WINEOF(fs)	WINOTFEOF(fs)

#define IFNOT(cn)	IF (!(cn))

#define MAXNEGINT	-2147483648
#define MAXNEG		MAXNEGINT
#define ISNEG		LT 0
#define NEG		ISNEG

#define INMUL10ADDCH(in, ch)	in = (in * 10) + (ch - A0);
#define INMULADD(in, ch)	INMUL10ADDCH(in, ch)
//#define INNEGMUL10ADDCH(in, ch)	in MULS -1; INMUL10ADDCH(in, ch); in MULS -1;
#define INNEGMUL10ADDCH(in, ch)	in = 0 - in; INMUL10ADDCH(in, ch); in = 0 - in;
#define INNEGMULADD(in, ch)	INNEGMUL10ADDCH(in, ch)
#define INCHADD(in, ch)		IF (in NEG) { INNEGMULADD(in, ch); } EL { INMULADD(in, ch); }

// unpredictable but perhaps reasonable results for non-alphanum
#define INCALPHANUM(ch)		(INRANGE(ch, A9, AA - 1) ? AA : INRANGE(ch, AZ, Aa - 1) ? Aa : (ch GQ Az - 1) ? Az : (ch LT A0) ? A0 : ch + 1)
#define DECALPHANUM(ch)		(INRANGE(ch, A9 + 1, AA) ? A9 : INRANGE(ch, AZ + 1, Aa) ? AZ : (ch GQ Az) ? Az : (ch LQ A0) ? A0 : ch - 1)

// assume base 10 for now
#define GETIN(ch, fs, to)	  \
  IF (IRA09(ch) OR ch EQ Adash) { \
    IF (ch EQ Adash) { ch = GETCH(fs); to = 0 - (ch - A0); ch = GETCH(fs); } \
    WI (IRA09(ch)) { INCHADD(to, ch); ch = GETCH(fs); }      }
#define GETPADIN(ch, fs, to)				\
  WI (ch EQ Atab OR ch EQ Aspace) { ch = GETCH(fs); }	\
  GETIN(ch, fs, to);
// ^ uses current char and grabs more until not int
// ^ not going to work when there are pair bytes
// contrast with MUNCHIN (which eats strings)

#define MUNCHIN(var, tgt)		      \
  IF (IRA09(EL0(var)) OR EL0(var) EQ Adash) { \
    IF (EL0(var) EQ Adash) { NEXT1(var); tgt = 0 - (EL0(var) - A0); NEXT1(var); } \
    WI (IRA09(EL0(var))) { INCHADD(tgt, EL0(var)); NEXT1(var); } }
#define MUNCHPADIN(var, tgt)					\
  WI (EL0(var) EQ Atab OR EL0(var) EQ Aspace)) { NEXT1(var); }	\
  MUNCHIN(var, tgt);

// consider a MUNCHIN that allows -00001, though that probably implies octal representation. or not. w/e it's erroneous.
// LFDS tgt = { { 0, 0 }, { 0, 0 }, { 1, 1 } };
#define MUNCHLFDS(var, tgt)     \
  IF (IRA09(EL0(var)) OR EL0(var) EQ Adash) { \
    IF (EL0(var) EQ Adash) { tgt.scale.numb = -tgt.scale.numb; NEXT1(var); } \
    WI (IRA09(EL0(var))) { INCHADD(tgt.value.numb, EL0(var)); NEXT1(var); } \
    IF (EL0(var) EQ Adot) { tgt.scale.frac = -tgt.scale.frac; NEXT1(var); } \
    WI (IRA09(EL0(var))) { INCHADD(tgt.value.frac, EL0(var)); NEXT1(var); } }
#define LFDSTOFP(lfds)	((lfds.value.numb * lfds.scale.numb) + ((0.1f * lfds.value.frac) / lfds.scale.frac))
// #define LFDSTOLF( ....)       10.123      but 10.000123 .... as 10.123000 ? seems counterintuitive
//  WI (IRA09(var[0])) { tgt = (tgt * 10) + (var[0] - A0); var = &var[1]; } // "555" -> 555

// MUNCHLF deprecated in favour of storing fractions with backward scaling
// LF should be { 0, 0, 1 } .. but can probably have an offset at MSD scale
#define MUNCHLF(var, tgt)   \
  IF (IRA09(EL0(var)) OR EL0(var) EQ Adash) { \
    IF (EL0(var) EQ Adash) { tgt.diff = -tgt.diff; NEXT1(var); } \
    WI (IRA09(EL0(var))) { INCHADD(tgt.numb, EL0(var)); NEXT1(var); } \
    IF (EL0(var) EQ Adot) { \
      tgt.diff = tgt.diff; NEXT1(var); \
      WI (IRA09(EL0(var))) { INCHADD(tgt.frac, EL0(var)); NEXT1(var); } } }
#define LFTOFP(lf)	(((1.0f / lf.diff) * lf.frac) + lf.numb)

//#define EATCH(var)	var = &var[1];
//#define NEXTCH(var)	EATCH(var)
// ^ defined earlier - need reordering tool

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
// for malloc
#endif
#ifndef STRING_H
#include <string.h>
#define STRING_H
// for strcmp
#endif
#ifndef UNISTD_H
#include <unistd.h>
#define UNISTD_H
// for usleep, isatty
#endif

#endif

#define STDLINESIZE	4096
#define WAIT(n)		usleep(n * 1000000)
#define FPSWAIT(n)	IF (n GT 0) { usleep(1000000 / n); } EL { _c('*'); }
#define WAITFPS(n)	FPSWAIT(n)
#define WAITMS(n)	usleep(n * 1000)
#define WAIT1MS		WAIT(0.001)
#define WAIT10MS	WAIT(0.01)
#define WAIT50MS	WAIT(0.05)
#define WAIT100MS	WAIT(0.1)
#define WAIT200MS	WAIT(0.2)
#define WAIT300MS	WAIT(0.3)
#define WAIT400MS	WAIT(0.4)
#define WAIT500MS	WAIT(0.5)
#define WAIT600MS	WAIT(0.6)
#define WAIT700MS	WAIT(0.7)
#define WAIT800MS	WAIT(0.8)
#define WAIT900MS	WAIT(0.9)
#define WAIT1S		WAIT(1)
#define WAIT1SEC	WAIT1S
#define Wait1Sec	WAIT1SEC
#define WAIT1SECOND	WAIT1SEC
#define Wait1Second	WAIT1SECOND
#define SLEEP1MS	WAIT1MS
#define SLEEP10MS	WAIT10MS
#define SLEEP100MS	WAIT100MS
#define SLEEP200MS	WAIT100MS; WAIT100MS;
#define SLEEP1S		WAIT1S
#define SLEEP5FPS	SLEEP200MS
#define SLEEPMS(n)	WAITMS(n)

// ^ this should be replaced with BOUNDARY CHECKS - flag recompile with larger buffer if exceeded
#define GLFPMEM(n)	(GLFPP) malloc(sizeof(GLFP) * (n))
#define INMEM(n)	(INP) malloc(sizeof(IN) * (n))
#define CHMEM(n)	(CHP) malloc(sizeof(CH) * (n))
#define FPMEM(n)	(FPP) malloc(sizeof(FP) * (n))
#define KCHMEM(n)	(UCHP) kmalloc(sizeof(UCH) * (n))
#define MALLOC		malloc
#define NEWMEM		malloc
#define MEM		malloc
#define UNMEM(v)	free(v)
#define NOMEM(v)	UNMEM(v)
#define INTMEM(n)	INMEM(n)
#define STRMEM(n)	CHMEM(n)
//^ file stream
#define UCH		unsigned char
#define UCHP		UCH *
#define UCHPOINTER	UCHP
#define UCHSIZE		sizeof(UCH)
#define SCH		signed char
#define SC		SCH // .. actually CCH has the same issue
#define CH		char // UCH
#define CHP		UCHP
#define CHARPOINTER	CHP
#define CHPOINTER	CHP
#define CCH		const CH
// #define CCH		const CH // CCH * for const char string.. CCS label (not function) could still be used
// ^ signed char
#define SH		short
#define SSH		signed short
#define USH		unsigned short
//#define ST		char *
// ST no longer means string, use CS
#define ST		static
#define STATIC		ST
#define CN		const
#define CONSTANT	CN

#define CS		CH *
#define CSA		CS *
#define CSAA		CS **
#define CSAAA		CS ***
#define CHARSTR		CS
#define CHARSTRARRAY	CSA
#define CHARSTRARRAYOFARRAYS CSAA
#define CHARSTRARRAYOFARRAYSOFARRAYS CSAAA
#define CCS		CCH *
#define CNCS		CCS
#define CNIN		CONSTANT INTEGER
#define CIN		CNIN
#define CINP		CN INP
#define UCS		unsigned CS
// DEF: name a b c -> blabc (syn, syn, syn -> def)
// --> to set output file for -  and -> commands
// -> #define name(a,b,c)  blabc
// -> #define syn1 name
// -> #define syn2 name
// -> #define syn3 def)

#define STCS		ST CS
#define SCS		signed CS
//^define SCS		// SCS :> SIGNED CONSTANT string
// (:> :> would be / should be - check, remark (suggested secondary connection)
// (=> => is - check, error if not (required secondary connection))
#define STCNCS		ST CNCS
#define SCCS		STCNCS
#define CUCS		CN UCS
#define CUCH		CN UCH
#define CUCHP		CUCS
#define CUSHP		CN USH *

// #define CSCS		SCCS
// ^ static const character string
#define STIN		ST IN
//#define SIN		STIN <-- support math probably


// ^ simple throwback definitions should point to the best word
#define STCNIN		ST CN IN
#define STCIN		STCNIN
#define SCIN		STCNIN

#define STCNCH		ST CN CH
#define STCNUCH		ST CN UCH
#define SCCH		STCNCH
#define SCUCH		STCNUCH

#define STCNSH		ST CN SH
#define STCNUSH		ST CN USH
#define SCSH		STCNSH
#define SCUSH		STCNUSH

#define CNFP		CN FP
#define CFP		CNFP
#define STFP		ST FP
#define SFP		STFP // no signed FP to compete with
#define STCSFP		ST CS FP
#define SCFP		STCSFP


// #define CCS		CCH *    // need to allow label and function definitions
#define VD		void
#define VDP		VD *
#define VDPP		VDP *
#define VDPPP		VDPP *
#define BK		break
#define CT		continue
#define RT		return
#define RT0Rs(str)	R1_("%s", str); RT 0;
#define RT1Rs(str)	R1_("%s", str); RT 1;
#define RT2Rs(str)	R1_("%s", str); RT 2;
#define RT3Rs(str)	R1_("%s", str); RT 3;
#define RT4Rs(str)	R1_("%s", str); RT 4;
#define RT5Rs(str)	R1_("%s", str); RT 5;
#define RTREDERR(str)	RT1Rs(str)
#define RT0(str)	RT0Rs(str)
#define RT1(str)	RT1Rs(str)
#define RT2(str)	RT2Rs(str)
#define RT3(str)	RT3Rs(str)
#define RT4(str)	RT4Rs(str)
#define RT5(str)	RT5Rs(str)
#define EXIT		RT
#define ERT		RLOG("***********"); RT

// ----- NOP -------!

#define NOP      0;     // presumably compiles to nothing
// e.g. IF (bla) { NOP } EF (bla) { NOP } EL { SOMETHING; }

// ------------------------- EQUAL ------------------------------------------------------------------------------------

#define IS		= // <- allow IS and IS() when func and word unique (maybe)
// Prefer to retain IS as this IS that;, but IF IS(this) { } has its value
// Also, IF this IS that-> IF IS(this, that)-> IF (this EQ that)-> IF (this == that)
//#define AT		&
// ^ also ASCII T
#define AT(var)		&var
// ATn defubed kater.. AT before var is probably not ASCII T - can has universal def?
#define EQ		==
#define OEQ1(dv, o, a)			dv[0 + o] EQ a
#define OEQ(dv, o, a)			OEQ1(dv, o, a)
#define OEQ2(dv, o, a, b)		OEQ(dv, 0, a) AND OEQ(dv, 1, b)
#define OEQ3(dv, o, a, b, c)		OEQ2(dv, 0, a, b) AND OEQ(dv, 2, c)
#define OEQ4(dv, o, a, b, c, d)		OEQ3(dv, 0, a, b, c) AND OEQ(dv, 3, d)
#define OEQ5(dv, o, a, b, c, d, e)	OEQ4(dv, 0, a, b, c, d) AND OEQ(dv, 4, e)
#define OEQ6(dv, o, a, b, c, d, e, f)	OEQ5(dv, 0, a, b, c, d, e) AND OEQ(dv, 5, f)
#define OEQNUL(dv, o)			OEQ(dv, o, NUL)
#define OFFSETEQUAL(dv, o, a)		OEQ(dv, o, a)
// VALUE EQUALS ---------------- VEQ4(abcd, 'a', 'b', 'c', 'd')
#define VEQ1(dv, a)			(OEQ1(dv, 0, a))
#define VEQ2(dv, a, b)			(OEQ2(dv, 0, a, b))
#define VEQ3(dv, a, b, c)		(OEQ3(dv, 0, a, b, c))
#define VEQ4(dv, a, b, c, d)		(OEQ4(dv, 0, a, b, c, d))
#define VEQ5(dv, a, b, c, d, e)		(OEQ5(dv, 0, a, b, c, d, e))
#define VEQ6(dv, a, b, c, d, e, f)	(OEQ6(dv, 0, a, b, c, d, e, f))
// ^^ These are for VEQ, VALUE EQUALS, V[0] ==, *V ==
// ELEMENTS EQUAL
#define SEQ0(dv)			(OEQNUL(dv, 0))
#define SEQ1(dv, a)			(OEQ1(dv, 0, a) AND OEQNUL(dv, 1))
#define SEQ2(dv, a, b)			(OEQ2(dv, 0, a, b) AND OEQNUL(dv, 2))
#define SEQ3(dv, a, b, c)		(OEQ3(dv, 0, a, b, c) AND OEQNUL(dv, 3))
#define SEQ4(dv, a, b, c, d)		(OEQ4(dv, 0, a, b, c, d) AND OEQNUL(dv, 4))
#define SEQ5(dv, a, b, c, d, e)		(OEQ5(dv, 0, a, b, c, d, e) AND OEQNUL(dv, 5))
#define SEQ6(dv, a, b, c, d, e, f)	(OEQ6(dv, 0, a, b, c, d, e, f) AND OEQNUL(dv, 6))
#define SEQNUL(dv)			(SEQ0(dv))
// SEQUENCE EQUALS (with NUL terminator)
#define OEQQ1(dv, o, a)			(OEQ1(dv, o, a) OR (a EQ '?'))
#define EQQ1(dv, a)			(OEQQ1(dv, 0, a))
#define EQQ2(dv, a, b)			(EQQ1(dv, a) AND OEQQ1(dv, 1, b))
#define EQQ3(dv, a, b, c)		(EQQ2(dv, a, b) AND OEQQ1(dv, 2, c))
#define EQQ4(dv, a, b, c, d)		(EQQ3(dv, a, b, c) AND OEQQ1(dv, 3, d))
#define EQQ5(dv, a, b, c, d, e)		(EQQ4(dv, a, b, c, d) AND OEQQ1(dv, 4, e))
#define EQQ6(dv, a, b, c, d, e, f)	(EQQ5(dv, a, b, c, d, e) AND OEQQ1(dv, 5, f))
// ELEMENTS EQUAL QUERY (where EL '?' EQ anything)
#define SEQQ1(dv, a)			(EQQ1(dv, a) AND OEQNUL(dv, 1))
#define SEQQ2(dv, a, b)			(EQQ2(dv, a, b) AND OEQNUL(dv, 2))
#define SEQQ3(dv, a, b, c)		(EQQ3(dv, a, b, c) AND OEQNUL(dv, 3))
#define SEQQ4(dv, a, b, c, d)		(EQQ4(dv, a, b, c, d) AND OEQNUL(dv, 4))
#define SEQQ5(dv, a, b, c, d, e)	(EQQ5(dv, a, b, c, d, e) AND OEQNUL(dv, 5))
#define SEQQ6(dv, a, b, c, d, e, f)	(EQQ6(dv, a, b, c, d, e, f) AND OEQNUL(dv, 6))
// SEQUENCE EQUALS QUERY (where EL '?' EQ anything, with NUL terminator)
#define CSQ1(dv, cs)			SEQQ1(dv, cs[0])
#define CSQ2(dv, cs)			SEQQ2(dv, cs[0], cs[1])
#define CSQ3(dv, cs)			SEQQ3(dv, cs[0], cs[1], cs[2])
#define CSQ4(dv, cs)			SEQQ4(dv, cs[0], cs[1], cs[2], cs[3])
#define CSQ5(dv, cs)			SEQQ5(dv, cs[0], cs[1], cs[2], cs[3], cs[4])
#define CSQ6(dv, cs)			SEQQ6(dv, cs[0], cs[1], cs[2], cs[3], cs[4], cs[5])
// later: #define CSQ(dv, cs) should check cs length and trigger the appropriate function
// requires: string.h
#define STREQ(str, str1)		(str && str1 && strcmp(str, str1) == 0)
#define STREQ2(str, str1, str2)		(STREQ(str, str1) OR STREQ(str, str2))
// ^ either A or B......... this should maybe be BOTH by default... AND
// STREQALL2 ... STREQBOTH ... STREQEITHER2
#define STRNEQ(str, str1)		(str && str1 && strcmp(str, str1) != 0)
#define STRNEQ2(str, str1, str2)	(STRNEQ(str, str1) AND STRNEQ(str, str2))
// ^ neither A nor B
#define STREQANY2(str, str1, str2)		(STREQ(str, str1) OR STREQ(str, str2))
#define STREQANY3(str, str1, str2, str3)	 (STREQANY2(str, str1, str2) OR STREQ(str, str3))
#define STREQANY4(str, str1, str2, str3, str4)    (STREQANY3(str, str1, str2, str3) OR STREQ(str, str4))
#define STRNUL(str)	STREQ(str, "")
#define STRNNUL(str)	STRNEQ(str, "")
#define STRNQNUL(str)	STRNEQ(str, "")
// Case insensitive string matches:
//#define STREQCI(str, str1)		(str && str1 && strcmpi(str, str1) == 0)
// requires: strings.h
#define STREQCI(str, str1)		(str AND str1 AND strcasecmp(str, str1) EQ 0)
#define STREQANY2CI(str, str1, str2)    	(STREQCI(str, str1) OR STREQCI(str, str2))
#define STREQANY3CI(str, str1, str2, str3)       (STREQANY2CI(str, str1, str2) OR STREQCI(str, str3))
#define STREQANY4CI(str, str1, str2, str3, str4)  (STREQANY3CI(str, str1, str2, str3) OR STREQCI(str, str4))
// String prefix matches:
#define STRPREFIXEQ(str, prefix)        (str AND prefix AND strncmp(str, prefix, strlen(prefix)) EQ 0)
// etc...

// #define STREQ2(dv, ab)  SEQ2(dv, ab[0], ab[1])
// ^ STREQ and STRNEQ
//#define CSQ(dv, cs)	 (cs[0] EQNUL) 
// #define SEQ2ANY2(dv, ab, cd) (STREQ2(dv, ab) OR STREQ2(dv, cd))
// THIS EQUALS ANY OF THESE
#define EQANY2(var, opt1, opt2)				(var EQ opt1 OR var EQ opt2)
#define EQANY3(var, opt1, opt2, opt3)			(var EQ opt1 OR var EQ opt2 OR var EQ opt3)
#define EQANY4(var, opt1, opt2, opt3, opt4)		(var EQ opt1 OR var EQ opt2 OR var EQ opt3 OR var EQ opt4)
#define EQANY5(var, opt1, opt2, opt3, opt4, opt5)	(var EQ opt1 OR var EQ opt2 OR var EQ opt3 OR var EQ opt4 OR var EQ opt5)
// #define IFANY2SEQ(var, opt1, opt2)			IFSEQ2ANY2 <-- will check the first two characters, not the whole string
// IFANY2SEQ should check the whole string and allow for varying size

#define EL0(var)	var[0]
#define EL1(var)	var[1]
#define EL2(var)	var[2]
#define EL3(var)	var[3]
#define EL4(var)	var[4]
#define EL5(var)	var[5]
//#defube AT(var)		&var <-- defubed earuker, also consider ASCII T
#define AT0(var)	&var[0]
#define AT1(var)	&var[1]
#define AT2(var)	&var[2]
#define AT3(var)	&var[3]
#define AT4(var)	&var[4]
#define AT5(var)	&var[5]
#define NEXT1(var)	var = AT1(var);


// ---------------------- NOT EQUAL -----------------------------------------------------------------------------------

#define NOT		!

#define NQ		!=
#define NEQ		NQ
#define ISEQUAL		EQ
#define EQUALS		EQ
#define NOTEQUAL	NQ
#define ISNOTEQUALTO	NQ
#define UNEQUAL		NQ
#define EQEOF		EQ EOF
#define NQEOF		NQ EOF
#define IFEQEOF(ch)	IF (ch EQEOF)
#define IFNQEOF(ch)	IF (ch NQEOF)
#define EFEQEOF(ch)	EF (ch EQEOF)
#define EFNQEOF(ch)	EF (ch NQEOF)
#define BKIFEQEOF(ch)		IF (ch EQEOF) { BK; }
#define BKIFEQEOFORNEWLINE(ch)	IF (ch EQEOF OR ch EQ Anewline) { BK; }
#define BKEQEOF(ch)	BKIFEQEOF(ch)
#define BKEQEOFORNL(ch)	BKIFEQEOFORNEWLINE(ch)
#define BKIFNQEOF(ch)	IF (ch EQEOF) { BK; }
#define BKNQEOF(ch)	BKIFNQEOF(ch)
#define BKIFEQNUL(ch)	IF (ch EQNUL) { BK; }
#define BKEQNUL(ch)	BKIFEQNUL(ch)
#define BKIFNQNUL(ch)	IF (ch EQNUL) { BK; }
#define BKNQNUL(ch)	BKIFNQNUL(ch)
#define BKEQNEWLINE(ch)	IF (ch EQ NEWLINE) { BK; }
#define BKEQAnewline(ch) BKEQNEWLINE(ch)
#define BKEQAnl(ch)	 BKEQNEWLINE(ch)
#define BKEQNULL(ch)	IF (ch EQNULL) { BK; }
#define IFYESNO(yv, nv) IF (yv YES AND nv NO)
#define IFNOYES(nv, yv) IF (nv NO AND yv YES)
#define IFYN(yv, nv)    IFYESNO(yv, nv)
#define IFNY(yv, nv)    IFNOYES(nv, yv)
#define EQNUL		EQ NUL
#define NQNUL		NQ NUL
#define EQNULL		EQ NULL
#define NQNULL		NQ NULL
//#define 0EQ		0 EQ <-- can't, but try IF0EQ ... no, that's IFEL0EQ ... ambiguity flag
//#define OBJ		NQNULL <-- OBJ now means STRUCT
#define ISOBJ		NQNULL
#define NOBJ		EQNULL
#define NOTOBJ		NQNULL
#define LT		<
#define LESSTHAN	LT
#define LQ		<=
#define LESSEQUAL	LQ
#define MT		>
#define MORETHAN	MT
#define MQ		>=
#define MOREEQUAL	MQ
#define GT		>
#define GREATERTHAN	GT
#define GQ		>=
#define GREATEREQUAL	GQ
#define PLUS		+
//#define PL		PLUS
#define MINUS		-
//#define MN		MINUS
#define TIMES		*
#define MULTIPLIEDBY	TIMES
#define MultipliedBy	MULTIPLIEDBY
#define MUL		TIMES
#define MULTIPLY	MUL
//#define TM		TIMES
#define DIVIDEDBY	/
#define DividedBy	DIVIDEDBY
#define DIV		DIVIDEDBY
#define DIVIDE		DIV
//#define DV		DIVIDEDBY
#define MOD		%
#define MODULUS		MOD
#define Modulus		MODULUS
#define AND		&&
#define OR		||
#define ORR		OR
#define INCMOD(var,lim)	(INC var MOD lim)
#define RINC		RLOG("++"); ++
#define YINC		YLOG("++"); ++
#define GINC		GLOG("++"); ++
#define CINC		CLOG("++"); ++
#define BINC		BLOG("++"); ++
#define MINC		MLOG("++"); ++
#define OREQ2(dv, a, b)		(dv EQ a OR dv EQ b)
#define EQOR2(dv, a, b) OREQ2(dv, a, b)
#define OREQ3(dv, a, b, c)	(dv EQ a OR dv EQ b OR dv EQ c)
#define ORNQ2(dv, a, b)		(dv NQ a OR dv NQ b)
#define ORNQ3(dv, a, b, c)	(dv NQ a OR dv NQ b OR dv NQ c)
#define ANDNQ2(dv, a, b)	(dv NQ a AND dv NQ b)
#define ANDNQ3(dv, a, b, c)	(dv NQ a AND dv NQ b AND dv NQ c)
#define ORREQ2(dv, a, b)	OREQ2(dv, a, b)
#define ORREQ3(dv, a, b, c)	OREQ3(dv, a, b, c)
#define ORRNQ2(dv, a, b)	ORNQ2(dv, a, b)
#define ORRNQ3(dv, a, b, c)	ORNQ3(dv, a, b, c)
#define ORRNEQ2(dv, a, b)	ORNQ2(dv, a, b)
#define ORRNEQ3(dv, a, b, c)	ORNQ3(dv, a, b, c)
#define ANDNEQ2(dv, a, b)	ANDNQ2(dv, a, b)
#define ANDNEQ3(dv, a, b, c)	ANDNQ3(dv, a, b, c)
#define LT1(n, v1)			(v1 LT n)
#define LT2(n, v1, v2)			(v1 LT n AND v2 LT n)
#define LT3(n, v1, v2, v3)		(v1 LT n AND v2 LT n AND v3 LT n)
#define LT4(n, v1, v2, v3, v4)		(LT2(n, v1, v2) AND LT2(n, v3, v4))
#define LT5(n, v1, v2, v3, v4, v5)	(LT3(n, v1, v2, v3) AND LT2(n, v4, v5))
#define LT6(n, v1, v2, v3, v4, v5, v6)	(LT3(n, v1, v2, v3) AND LT3(n, v4, v5, v6))
#define GT1(n, v1)			(v1 GT n)
#define GT2(n, v1, v2)			(v1 GT n AND v2 GT n)
#define GT3(n, v1, v2, v3)		(v1 GT n AND v2 GT n AND v3 GT n)
#define GT4(n, v1, v2, v3, v4)		(GT2(n, v1, v2) AND GT2(n, v3, v4))
#define GT5(n, v1, v2, v3, v4, v5)	(GT3(n, v1, v2, v3) AND GT2(n, v4, v5))
#define GT6(n, v1, v2, v3, v4, v5, v6)	(GT3(n, v1, v2, v3) AND GT3(n, v4, v5, v6))
#define MIN2(a, b)			((b < a) ? b : a)
#define MIN3(a, b, c)			MIN2(MIN2(a, b), MIN2(b, c))
#define MIN4(a, b, c, d)		MIN2(MIN3(a, b, c), d)
#define MAX2(a, b)			((b > a) ? b : a)
#define MAX3(a, b, c)			MAX2(MAX2(a, b), MAX2(b, c))
#define MAX4(a, b, c, d)		MAX2(MAX3(a, b, c), d)
#define XOR		^
// ^ XOR should be changed to ^|, freeing ^ to mean power
#define INC		++
#define INCS		++
#define DEC		--
#define DECS		--
#define ADDS		+=
#define SUBS		-=
#define MULS		*=
#define DIVS		/=
#define INC1(v)		INC v;
#define INC2(v)		INC v; INC v;
#define INC3(v)		INC v; INC v; INC v;
#define DEC1(v)		DEC v;
#define DEC2(v)		DEC v; DEC v;
#define DEC3(v)		DEC v; DEC v; DEC v;
#define INCONTO(str, ch)	WI (ANDNQ2(str[0], ch, NUL)) { INC str; }
#define INCONTO0(str)		INCONTO(str, NUL)
//#define INCONTO0(str)		WI (str[0] NQNUL) { INC str; printf("%c", str[0]); }
#define INCONTO1(str, c1)	INCONTO(str, c1)
#define INCONTO2(str, c1, c2)	WI (ANDNQ3(str[0], c1, c2, NUL)) { INC str; }
#define INCTHRU(str, ch)	INCONTO(str, ch); INC str;
#define INCTHRU0(str)		INCTHRU(str, NUL)
#define INCTHRU1(str, c1)	INCTHRU(str, c1)
#define INCTHRU2(str, c1, c2)	INCONTO2(str, c1, c2); INC str;

// -------------------------------------------------------------------

#define STRF		sprintf
#define STR1(s,a)	STRF(s, "%s", a)
#define STR2(s,a,b)	STRF(s, "%s%s", a, b)
#define STR3(s,a,b,c)	STRF(s, "%s%s%s", a, b, c)

//#define STRSIZE(str)		snprintf(NULL, 0, str)
// ^ um segfault? ..... works in snprintf.c ..
//#define STR0SIZE(str)		(STRSIZE(str) + 1)
//#define STRNF(var, size, str)	snprintf(var, size + 1, str)
// ^ prints up to the given size (strlen), + 1 for NUL
//#define STR0NF(var, size, str)	snprintf(var, size, str)
// ^ prints up to size - 1 (strlen), + 1 for NUL
// not safe for some reason .............................
  
// --------------------------------------------------------- move --


#define CS1(nm, sz, fmt, p1)              CH nm[sz]; STRF(nm, fmt, p1);
#define CS2(nm, sz, fmt, p1, p2)          CH nm[sz]; STRF(nm, fmt, p1, p2);
#define CS3(nm, sz, fmt, p1, p2, p3)      CH nm[sz]; STRF(nm, fmt, p1, p2, p3);
#define CS4(nm, sz, fmt, p1, p2, p3, p4)  CH nm[sz]; STRF(nm, fmt, p1, p2, p3, p4);

// -- ^ deprecated ... -----------------------------------------

#define INRANGE(var, min, max)		(var >= min && var <= max)
#define INRANGE2(v1, v2, min, max)		(INRANGE(v1, min, max) AND INRANGE(v2, min, max))
#define INRANGE3(v1, v2, v3, min, max)		(INRANGE2(v1, v2, min, max) AND INRANGE(v3, min, max))
#define INRANGE4(v1, v2, v3, v4, min, max)	(INRANGE3(v1, v2, v3, min, max) AND INRANGE(v4, min, max))
#define EXRANGE(var, min, max)		(var < min || var > max)
#define CHISINT(var)			INRANGE(var, A0, A9)
#define ISNUMCH(var)			CHISINT(var)
#define NUMCH(var)			CHISINT(var)
#define SPACH(var)			(var EQ Aspace OR var EQ Atab)
#define ISSPACECH(var)			SPACH(var)
#define IRA09(var)			INRANGE(var, A0, A9)
#define EL0IRA09(var)			INRANGE(EL0(var), A0, A9)
#define ASCH(ch)			((ch < ' ') ? (ch + 'A') : (ch > '~') ? '#' : ch)
#define LOG0				fflush(stdout);
//#define _				printf <-- currently prints newline but - can do that later
#define FPUTF				fprintf
#define LOGF				printf
#define LOG(str)			fprintf(stdout, str); LOG0
#define LOG1(str, v1)			fprintf(stdout, str, v1); LOG0
#define LOG2(str, v1, v2)		fprintf(stdout, str, v1, v2); LOG0
#define LOG3(str, v1, v2, v3)		fprintf(stdout, str, v1, v2, v3); LOG0
#define LOG4(str, v1, v2, v3, v4)	fprintf(stdout, str, v1, v2, v3, v4); LOG0
#define LOG5(str, v1, v2, v3, v4, v5)	fprintf(stdout, str, v1, v2, v3, v4, v5); LOG0
#define LOG6(str, v1, v2, v3, v4, v5, v6)	fprintf(stdout, str, v1, v2, v3, v4, v5, v6); LOG0
#define LOG7(str, v1, v2, v3, v4, v5, v6, v7)	fprintf(stdout, str, v1, v2, v3, v4, v5, v6, v7); LOG0
#define LOG8(str, v1, v2, v3, v4, v5, v6, v7, v8)	fprintf(stdout, str, v1, v2, v3, v4, v5, v6, v7, v8); LOG0
#define LOG9(str, v1, v2, v3, v4, v5, v6, v7, v8, v9)	fprintf(stdout, str, v1, v2, v3, v4, v5, v6, v7, v8, v9); LOG0
#define LOGCH(ix)			LOG1("%c", ix); LOG0
#define EXTCH(ix)			LOG("\016"); LOG1("%c", ix); LOG("\017"); LOG0
#define LOGSPACE			LOGCH(SPACE);
// ^ maybe one day this will be deprecated
#define LOGNEWLINE			LOGCH(NEWLINE);
#define _				LOGNEWLINE;
#define _tab				LOGCH(TAB);
#define _t  _tab
#define _leftspace			MOVELEFT(1);
#define _ls _leftspace
// _s for space when _s() is differentiated
#define LOGNL(str)			LOG(str); _;
//#define LOGN(str)			LOGNL(str); redefined below
#define LOGLINE(str)			LOGNL(str);
// later LOGNEWLINE() function form
// LOGLINE() should consider padding options
// later -(str) -> LOGLINE(str)
// later E(str) can be ECHO(str)
#define ECHO(str)			LOGLINE(str);
#define TOPREVLINE			MOVEUP(1);

#define LO(str)				printf(stdout, str);
#define LO1(str, v1)			printf(stdout, str, v1);
#define LO2(str, v1, v2)		printf(stdout, str, v1, v2);
#define LO3(str, v1, v2, v3)		printf(stdout, str, v1, v2, v3);
#define LO4(str, v1, v2, v3, v4)	printf(stdout, str, v1, v2, v3, v4);
#define LO5(str, v1, v2, v3, v4, v5)	printf(stdout, str, v1, v2, v3, v4, v5);
#define LON(str)			printf("%s%s", str, "\n")
#define LOGN(str)			LON(str)
#define LORN(str)			printf("%s%s", str, "\r\n")
#define LORN1i(str, v1)			printf("%s%d%s", str, v1, "\r\n")
#define LORN1s(str, v1)			printf("%s%s%s", str, v1, "\r\n")
#define LORN2s(str, v1, v2)		printf("%s%s%s%s", str, v1, v2, "\r\n")

#define LORN1F(str, v1)                 printf(str"\r\n", v1)
#define LORN2F(str, v1, v2)             printf(str"\r\n", v1, v2)
#define LORN3F(str, v1, v2, v3)         printf(str"\r\n", v1, v2, v3)
// ^ cannot use dynamically allocated string for format due to concatenation

//#define OUT(str)			LOG(str)
//#define OUT1(str, v1)			LOG1(str, v1)
//#define OUT2(str, v1, v2)		LOG2(str, v1, v2)
//#define OUT3(str, v1, v2, v3)		LOG3(str, v1, v2, v3)
//#define OUT4(str, v1, v2, v3, v4)	LOG4(str, v1, v2, v3, v4)
// ^ currently incompatible with cdat
#define ERR0				fflush(stderr);
#define ERR(str)			fprintf(stderr, str); ERR0
#define ERR1(str, v1)			fprintf(stderr, str, v1); ERR0
#define ERR2(str, v1, v2)		fprintf(stderr, str, v1, v2); ERR0
#define ERR3(str, v1, v2, v3)		fprintf(stderr, str, v1, v2, v3); ERR0
#define ERR4(str, v1, v2, v3, v4)	fprintf(stderr, str, v1, v2, v3, v4); ERR0
#define WITHARGS			IN argc, CH **argv
#define SHIFTARGS			argc--; argv = &argv[1];
#define NOARGS				argc < 1
#define SHIFT1(cval, varr)		DEC1(cval); varr = AT1(varr);
#define SHIFT2(cval, varr)		DEC2(cval); varr = AT2(varr);
#define SHIFT3(cval, varr)		DEC3(cval); varr = AT3(varr);
#define SHIFT4(cval, varr)		DEC4(cval); varr = AT4(varr);
#define SHIFT5(cval, varr)		DEC5(cval); varr = AT5(varr);
#define SHIFT6(cval, varr)		DEC6(cval); varr = AT6(varr);
//#define NEXTCH(cval)			cval = AT1(cval);
//#define EATCH(cval)			NEXTCH(cval)
#define EATCH(cval)			cval = AT1(cval);
#define WRITEBUFCH(buf, bufi, bufsize, ch)	\
  buf[bufi] = ch; buf[INC bufi] = NUL; IF (bufi + 1 GQ bufsize) { bufi = bufsize - 2; }
#define CLEARBUF(buf, bufi)		buf[bufi = 0] = NUL;
#define SHIFT_1				SHIFT1(argc, argv);
#define SHIFT_2				SHIFT2(argc, argv);
#define SHIFT_3				SHIFT3(argc, argv);
#define SHIFT_4				SHIFT4(argc, argv);
#define SHIFT_5				SHIFT5(argc, argv);
#define SHIFT_6				SHIFT6(argc, argv);
#define $$1	SHIFT_1
#define $$2	SHIFT_2
#define $$3	SHIFT_3
#define $$4	SHIFT_4
#define $$5	SHIFT_5
#define $$6	SHIFT_6
#define NEXTDARGCH(var)			var = &var[1]; var[0] = '-';
#define NEXTDASHARGUMENTCHARACTER(var)	NEXTDARGCH(var)
#define NextDashArgumentCharacter(var)	NEXTDASHARGUMENTCHARACTER(var)
#define NEXT_ARGCH(var)			var = &var[1]; var[0] = '_';
#define NEXT_ARGUMENTCHARACTER(var)	NEXT_ARGCH(var)
#define NEXTUNDERSCOREARGUMENTCHARACTER(var) NEXT_ARGCH(var)
#define NextUnderscoreArgumentCharacter	NEXTUNDERSCOREARGUMENTCHARACTER
#define WIEQDASHOR_(var)		WI (var EQ DASH OR var EQ UNDERSCORE)
#define WIPARAM(var)			WI (var NQNULL AND (var[0] EQ DASH OR var[0] EQ UNDERSCORE))
#define PARAMS			\
 IF ($1) { CLOG1("1:%s ", $1); }\
 IF ($2) { CLOG1("2:%s ", $2); }\
 IF ($3) { CLOG1("3:%s ", $3); }\
 IF ($4) { CLOG1("4:%s ", $4); }\
 IF ($5) { CLOG1("5:%s ", $5); }\
 IF ($6) { CLOG1("6:%s ", $6); }\
 IF ($7) { CLOG1("7:%s ", $7); }\
 IF ($8) { CLOG1("8:%s ", $8); }\
 IF ($9) { CLOG1("9:%s ", $9); }

#define ISSTRING(var)			(var NQNULL AND var[0] NQNUL)
#define IsString(var)			ISSTRING(var)

// later: this is that; and this (string) IS that (string);
// for now: IS(this, that);
//#define IS(this, that)
#define CSIS(this, that)  CS that = this;
#define INIS(this, that)  IN that = this;

#define $0      argv[0]
#define $1	argv[MIN2(argc, 1)]
#define $2	argv[MIN2(argc, 2)]
#define $3	argv[MIN2(argc, 3)]
#define $4	argv[MIN2(argc, 4)]
#define $5	argv[MIN2(argc, 5)]
#define $6	argv[MIN2(argc, 6)]
#define $N      (argc - 1)  // later, support $#
// #define $	IN argc, CS *argv
#define $	IN argc, CH **argv

#define AA		'A'
#define AB		'B'
#define AC		'C'
#define AD		'D'
#define AE		'E'
#define AF		'F'
#define AG		'G'
#define AH		'H'
#define AI		'I'
#define AJ		'J'
#define AK		'K'
#define AL		'L'
#define AM		'M'
#define AN		'N'
#define AO		'O'
#define AP		'P'
#define AQ		'Q'
#define AR		'R'
#define AS		'S'
//#define AT		'T' <--- this means AT, as in INTO & ADDRESS OF & .. currently
#define AU		'U'
#define AV		'V'
#define AW		'W'
#define AX		'X'
#define AY		'Y'
#define AZ		'Z'
#define Aa		'a'
#define Ab		'b'
#define Ac		'c'
#define Ad		'd'
#define Ae		'e'
#define Af		'f'
#define Ag		'g'
#define Ah		'h'
#define Ai		'i'
#define Aj		'j'
#define Ak		'k'
#define Al		'l'
#define Am		'm'
#define An		'n'
#define Ao		'o'
#define Ap		'p'
#define Aq		'q'
#define Ar		'r'
#define As		's'
#define At		't'
#define Au		'u'
#define Av		'v'
#define Aw		'w'
#define Ax		'x'
#define Ay		'y'
#define Az		'z'
#define A0		'0'
#define A1		'1'
#define A2		'2'
#define A3		'3'
#define A4		'4'
#define A5		'5'
#define A6		'6'
#define A7		'7'
#define A8		'8'
#define A9		'9'
#define Aplus		'+'
#define Adash		'-'
#define Ads Adash
#define Aminus Adash
#define Aslash		'/'
#define Asl Aslash
#define Abslash		'\\'
#define Abs Abslash
#define Alessthan	'<'
#define Alt Alessthan
#define Agreaterthan	'>'
#define Agt Agreaterthan
#define Aspace		' '
#define Asp Aspace
#define Acomma		','
#define Acm Acomma
#define Asemicolon	';'
#define Asc Asemicolon
#define Afullstop	'.'
#define Adot Afullstop
#define Adt Adot
#define Adollar		'$'
#define Adl Adollar
#define Aleftbracket	'('
#define Alb Aleftbracket
#define Albr Alb
#define Arightbracket	')'
#define Arb Arightbracket
#define Arbr Arb
#define Anewline	'\n'
#define Anl Anewline
#define Atab		'\t'
#define Ahorizontaltab Atab
#define Averticalpipe	'|'
#define Avp Averticalpipe
#define Apipe Averticalpipe
#define Aleftsquarebracket	'['
#define Alsb Aleftsquarebracket
#define Arightsquarebracket	']'
#define Arsb Arightsquarebracket
#define Aasterisk	'*'
#define Asterisk Aasterisk
#define Astar Asterisk
#define Aequals		'='
#define Anequals Aequals
#define Aeq Aequals
#define Aexclamationmark	'!'
#define Axm Aexclamationmark
#define Aexclamationpoint Axm
#define Axp Aexclamationmark
#define Anexclamationmark Aexclamationmark
#define Anexclamationpoint Aexclamationpoint
#define Anexclamation	   Anexclamationpoint
#define Aquestionmark		'?'
#define Aqm Aquestionmark
#define Acolon		':'
#define Acl Acolon
#define Aampersand	'&'
#define Ampersand Aampersand
#define Aamp Aampersand
#define Amp Aamp
#define Anampersand Aampersand
#define Abackspace	'\b'
#define Abell		'\a'
#define Aescape         '\e'
#define Acarriage	'\r'
#define Acarriagereturn	Acarriage
#define Aesc Aescape
// backspace input key is 127 maybe ?

#define Aspin1	'/'
#define Aspin2	'-'
#define Aspin3	'\\'
#define Aspin4	'|'


#define Y	'y'
#define N	'n'
#define M	'm'
// yes no maybe ...

#define _s(s)	 LOG1("%s",s);
#define Rs(s)	RLOG1("%s",s);
#define eRs(s)	RERR1("%s",s);
#define DRs(s)	DRLOG1("%s",s);
#define Ys(s)	YLOG1("%s",s);
#define eYs(s)	YERR1("%s",s);
#define DYs(s)	DYLOG1("%s",s);
#define Gs(s)	GLOG1("%s",s);
#define eGs(s)	GERR1("%s",s);
#define DGs(s)	DGLOG1("%s",s);
#define Cs(s)	CLOG1("%s",s);
#define eCs(s)	CERR1("%s",s);
#define DCs(s)	DCLOG1("%s",s);
#define Bs(s)	BLOG1("%s",s);
#define eBs(s)	BERR1("%s",s);
#define DBs(s)	DBLOG1("%s",s);
#define Ms(s)	MLOG1("%s",s);
#define eMs(s)	MERR1("%s",s);
#define DMs(s)	DMLOG1("%s",s);
#define Ws(s)	WLOG1("%s",s);
#define eWs(s)	WERR1("%s",s);
#define Ls(s)	LLOG1("%s",s);
#define Ds(s)	DLOG1("%s",s);
#define Ks(s)	KLOG1("%s",s);

#define _i(i)	 LOG1("%d",i);
#define Ri(i)	RLOG1("%d",i);
#define eRi(i)	RERR1("%d",i);
#define DRi(i)	DRLOG1("%d",i);
#define Yi(i)	YLOG1("%d",i);
#define eYi(i)	YERR1("%d",i);
#define DYi(i)	DYLOG1("%d",i);
#define Gi(i)	GLOG1("%d",i);
#define eGi(i)	GERR1("%d",i);
#define DGi(i)	DGLOG1("%d",i);
#define Ci(i)	CLOG1("%d",i);
#define eCi(i)	CERR1("%d",i);
#define DCi(i)	DCLOG1("%d",i);
#define Bi(i)	BLOG1("%d",i);
#define eBi(i)	BERR1("%d",i);
#define DBi(i)	DBLOG1("%d",i);
#define Mi(i)	MLOG1("%d",i);
#define eMi(i)	MERR1("%d",i);
#define DMi(i)	DMLOG1("%d",i);
#define Wi(i)	WLOG1("%d",i);
#define eWi(i)	WERR1("%d",i);
#define Li(i)	LLOG1("%d",i);
#define Di(i)	DLOG1("%d",i);
#define Ki(i)	KLOG1("%d",i);

#define _i_(i)	_i(i); _;
#define Ri_(i)	Ri(i); _;
#define Yi_(i)	Yi(i); _;
#define Gi_(i)	Gi(i); _;
#define Ci_(i)	Ci(i); _;
#define Bi_(i)	Bi(i); _;
#define Mi_(i)	Mi(i); _;
#define Wi_(i)	Wi(i); _;
#define Li_(i)	Li(i); _;
#define Di_(i)	Di(i); _;
#define Ki_(i)	Ki(i); _;

#define _s_(s)	_s(s); _;
#define Rs_(s)	Rs(s); _;
#define Ys_(s)	Ys(s); _;
#define Gs_(s)	Gs(s); _;
#define Cs_(s)	Cs(s); _;
#define Bs_(s)	Bs(s); _;
#define Ms_(s)	Ms(s); _;
#define Ws_(s)	Ws(s); _;
#define Ls_(s)	Ls(s); _;
#define Ds_(s)	Ds(s); _;
#define Ks_(s)	Ks(s); _;

#define __(s)	_s_(s);
//#define R_	RLOGF   ->  (s, any, vars) as in STRF style
#define R_(s)	Rs_(s);
#define Y_(s)	Ys_(s);
#define G_(s)	Gs_(s);
#define C_(s)	Cs_(s);
#define B_(s)	Bs_(s);
#define M_(s)	Ms_(s);
#define W_(s)	Ws_(s);
#define L_(s)	Ls_(s);
#define D_(s)	Ds_(s);
#define K_(s)	Ks_(s);

#define E1(f, s)	LOG1(f, s);
#define _1(f, s)	LOG1(f, s);
#define e_1(f, s)	ERR1(f, s);
// _1 or E1 ... _ only linebreak if at end of term ... logical?
#define R1(f, s)	RLOG1(f, s);
#define eR1(f, s)	RERR1(f, s);
#define DR1(f, s)	DRLOG1(f, s);
#define Y1(f, s)	YLOG1(f, s);
#define eY1(f, s)	YERR1(f, s);
#define DY1(f, s)	DYLOG1(f, s);
#define G1(f, s)	GLOG1(f, s);
#define eG1(f, s)	GERR1(f, s);
#define DG1(f, s)	DGLOG1(f, s);
#define C1(f, s)	CLOG1(f, s);
#define eC1(f, s)	CERR1(f, s);
#define DC1(f, s)	DCLOG1(f, s);
#define B1(f, s)	BLOG1(f, s);
#define eB1(f, s)	BERR1(f, s);
#define DB1(f, s)	DBLOG1(f, s);
#define M1(f, s)	MLOG1(f, s);
#define eM1(f, s)	MERR1(f, s);
#define DM1(f, s)	DMLOG1(f, s);
#define W1(f, s)	WLOG1(f, s);
#define L1(f, s)	LLOG1(f, s);
#define D1(f, s)	DLOG1(f, s);
#define K1(f, s)	KLOG1(f, s);
// leading _ means - (out), later _ means _ (linebreak)
#define _1_(f, s)	_1(f, s); _;
#define R1_(f, s)	R1(f, s); _;
#define Y1_(f, s)	Y1(f, s); _;
#define G1_(f, s)	G1(f, s); _;
#define C1_(f, s)	C1(f, s); _;
#define B1_(f, s)	B1(f, s); _;
#define M1_(f, s)	M1(f, s); _;
#define W1_(f, s)	W1(f, s); _;
#define L1_(f, s)	L1(f, s); _;
#define D1_(f, s)	D1(f, s); _;
#define K1_(f, s)	K1(f, s); _;

#define _2(f, s1, s2)	LOG2(f, s1, s2);
#define _2(f, s1, s2)	LOG2(f, s1, s2);
#define R2(f, s1, s2)	RLOG2(f, s1, s2);
#define eR2(f, s1, s2)	RERR2(f, s1, s2);
#define Y2(f, s1, s2)	YLOG2(f, s1, s2);
#define eY2(f, s1, s2)	YERR2(f, s1, s2);
#define G2(f, s1, s2)	GLOG2(f, s1, s2);
#define eG2(f, s1, s2)	GERR2(f, s1, s2);
#define C2(f, s1, s2)	CLOG2(f, s1, s2);
#define eC2(f, s1, s2)	CERR2(f, s1, s2);
#define B2(f, s1, s2)	BLOG2(f, s1, s2);
#define eB2(f, s1, s2)	BERR2(f, s1, s2);
#define M2(f, s1, s2)	MLOG2(f, s1, s2);
#define eM2(f, s1, s2)	MERR2(f, s1, s2);
#define W2(f, s1, s2)	WLOG2(f, s1, s2);
#define eW2(f, s1, s2)	WERR2(f, s1, s2);
#define L2(f, s1, s2)	LLOG2(f, s1, s2);
#define eL2(f, s1, s2)	LERR2(f, s1, s2);
#define D2(f, s1, s2)	DLOG2(f, s1, s2);
#define eD2(f, s1, s2)	DERR2(f, s1, s2);
#define K2(f, s1, s2)	KLOG2(f, s1, s2);
#define eK2(f, s1, s2)	KERR2(f, s1, s2);

#define _2_(f, s1, s2)	_2(f, s1, s2); _;
#define R2_(f, s1, s2)	R2(f, s1, s2); _;
#define Y2_(f, s1, s2)	Y2(f, s1, s2); _;
#define G2_(f, s1, s2)	G2(f, s1, s2); _;
#define C2_(f, s1, s2)	C2(f, s1, s2); _;
#define B2_(f, s1, s2)	B2(f, s1, s2); _;
#define M2_(f, s1, s2)	M2(f, s1, s2); _;
#define W2_(f, s1, s2)	W2(f, s1, s2); _;
#define L2_(f, s1, s2)	L2(f, s1, s2); _;
#define D2_(f, s1, s2)	D2(f, s1, s2); _;
#define K2_(f, s1, s2)	K2(f, s1, s2); _;

#define _3(f, s1, s2, s3)	LOG3(f, s1, s2, s3);
#define R3(f, s1, s2, s3)	RLOG3(f, s1, s2, s3);
#define Y3(f, s1, s2, s3)	YLOG3(f, s1, s2, s3);
#define G3(f, s1, s2, s3)	GLOG3(f, s1, s2, s3);
#define C3(f, s1, s2, s3)	CLOG3(f, s1, s2, s3);
#define B3(f, s1, s2, s3)	BLOG3(f, s1, s2, s3);
#define M3(f, s1, s2, s3)	MLOG3(f, s1, s2, s3);
#define W3(f, s1, s2, s3)	WLOG3(f, s1, s2, s3);
#define L3(f, s1, s2, s3)	LLOG3(f, s1, s2, s3);
#define D3(f, s1, s2, s3)	DLOG3(f, s1, s2, s3);
#define K3(f, s1, s2, s3)	KLOG3(f, s1, s2, s3);

#define _3_(f, s1, s2, s3)	_3(f, s1, s2, s3); _;
#define R3_(f, s1, s2, s3)	R3(f, s1, s2, s3); _;
#define Y3_(f, s1, s2, s3)	Y3(f, s1, s2, s3); _;
#define G3_(f, s1, s2, s3)	G3(f, s1, s2, s3); _;
#define C3_(f, s1, s2, s3)	C3(f, s1, s2, s3); _;
#define B3_(f, s1, s2, s3)	B3(f, s1, s2, s3); _;
#define M3_(f, s1, s2, s3)	M3(f, s1, s2, s3); _;
#define W3_(f, s1, s2, s3)	W3(f, s1, s2, s3); _;
#define L3_(f, s1, s2, s3)	L3(f, s1, s2, s3); _;
#define D3_(f, s1, s2, s3)	D3(f, s1, s2, s3); _;
#define K3_(f, s1, s2, s3)	K3(f, s1, s2, s3); _;

#define _c(c)   LOG1("%c",c);
#define Ec(c)	LOG1("%c",c);
#define Rc(c)	RLOG1("%c",c);
#define eRc(c)	RERR1("%c",c);
#define Yc(c)	YLOG1("%c",c);
#define eYc(c)	YERR1("%c",c);
#define Gc(c)	GLOG1("%c",c);
#define eGc(c)	GERR1("%c",c);
#define Cc(c)	CLOG1("%c",c);
#define eCc(c)	CERR1("%c",c);
#define Bc(c)	BLOG1("%c",c);
#define eBc(c)	BERR1("%c",c);
#define Mc(c)	MLOG1("%c",c);
#define eMc(c)	MERR1("%c",c);
#define Wc(c)	WLOG1("%c",c);
#define eWc(c)	WERR1("%c",c);
#define Lc(c)	LLOG1("%c",c);
#define Dc(c)	DLOG1("%c",c);
#define Kc(c)	KLOG1("%c",c);

#define Gcc(c1, c2)	GLOG2("%c%c", c1, c2)
#define Ccc(c1, c2)	CLOG2("%c%c", c1, c2)

#define _cn(csv, nv)  WI (DEC nv GQ 0) { _c(csv[0]); INC csv; }
#define Rcn(csv, nv)  WI (DEC nv GQ 0) { Rc(csv[0]); INC csv; }
#define Ycn(csv, nv)  WI (DEC nv GQ 0) { Yc(csv[0]); INC csv; }
#define Gcn(csv, nv)  WI (DEC nv GQ 0) { Gc(csv[0]); INC csv; }
#define Ccn(csv, nv)  WI (DEC nv GQ 0) { Cc(csv[0]); INC csv; }
#define Bcn(csv, nv)  WI (DEC nv GQ 0) { Bc(csv[0]); INC csv; }
#define Mcn(csv, nv)  WI (DEC nv GQ 0) { Mc(csv[0]); INC csv; }
#define Wcn(csv, nv)  WI (DEC nv GQ 0) { Wc(csv[0]); INC csv; }
#define Lcn(csv, nv)  WI (DEC nv GQ 0) { Dc(csv[0]); INC csv; }
#define Dcn(csv, nv)  WI (DEC nv GQ 0) { Lc(csv[0]); INC csv; }
#define Kcn(csv, nv)  WI (DEC nv GQ 0) { Kc(csv[0]); INC csv; }

#define _xc(xc)	 EXTCH(xc);
#define Rxc(xc)	 LOG(RFGC); EXTCH(xc); LOG(OFFC);
#define Yxc(xc)	 LOG(YFGC); EXTCH(xc); LOG(OFFC);
#define Gxc(xc)	 LOG(GFGC); EXTCH(xc); LOG(OFFC);
#define Cxc(xc)	 LOG(CFGC); EXTCH(xc); LOG(OFFC);
#define Bxc(xc)	 LOG(BFGC); EXTCH(xc); LOG(OFFC);
#define Mxc(xc)	 LOG(MFGC); EXTCH(xc); LOG(OFFC);
#define Wxc(xc)	 LOG(WFGC); EXTCH(xc); LOG(OFFC);
#define Lxc(xc)	 LOG(LFGC); EXTCH(xc); LOG(OFFC);
#define Dxc(xc)	 LOG(DFGC); EXTCH(xc); LOG(OFFC);
#define Kxc(xc)	 LOG(KFGC); EXTCH(xc); LOG(OFFC);

#define _l(l)	 LOG1("%lld",l);
#define Rl(l)	RLOG1("%lld",l);
#define DRl(l)	DRLOG1("%lld",l);
#define Yl(l)	YLOG1("%lld",l);
#define DYl(l)	DYLOG1("%lld",l);
#define Gl(l)	GLOG1("%lld",l);
#define DGl(l)	DGLOG1("%lld",l);
#define Cl(l)	CLOG1("%lld",l);
#define DCl(l)	DCLOG1("%lld",l);
#define Bl(l)	BLOG1("%lld",l);
#define DBl(l)	DBLOG1("%lld",l);
#define Ml(l)	MLOG1("%lld",l);
#define DMl(l)	DMLOG1("%lld",l);
#define Wl(l)	WLOG1("%lld",l);
#define Ll(l)	LLOG1("%lld",l);
#define Dl(l)	DLOG1("%lld",l);
#define Kl(l)	KLOG1("%lld",l);

#define _f(f)	 LOG1("%.7f",f);
#define Rf(f)	RLOG1("%.7f",f);
#define Yf(f)	YLOG1("%.7f",f);
#define Gf(f)	GLOG1("%.7f",f);
#define Cf(f)	CLOG1("%.7f",f);
#define Bf(f)	BLOG1("%.7f",f);
#define Mf(f)	MLOG1("%.7f",f);
#define Wf(f)	WLOG1("%.7f",f);
#define Lf(f)	LLOG1("%.7f",f);
#define Df(f)	DLOG1("%.7f",f);
#define Kf(f)	KLOG1("%.7f",f);

#define _d(d)	 LOG1("%.14f",d);
#define Rd(d)	RLOG1("%.14f",d);
#define Yd(d)	YLOG1("%.14f",d);
#define Gd(d)	GLOG1("%.14f",d);
#define Cd(d)	CLOG1("%.14f",d);
#define Bd(d)	BLOG1("%.14f",d);
#define Md(d)	MLOG1("%.14f",d);
#define Wd(d)	WLOG1("%.14f",d);
#define Ld(d)	LLOG1("%.14f",d);
#define Dd(d)	DLOG1("%.14f",d);
#define Kd(d)	KLOG1("%.14f",d);

//#define Ylf(lf)		YLOG4("%s%lld.%s%lld", lfnegstr(lf), lf.numb, lfscalestr(lf), lfunscale(lf.frac))
// maybe will add back later but for now use lf.h

//#define _lf(lf)	 LOG2("%lld.%lld",lf.numb,lf.frac);
//#define Rlf(lf)	RLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Ylf(lf)	YLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Glf(lf)	GLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Clf(lf)	CLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Blf(lf)	BLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Mlf(lf)	MLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Wlf(lf)	WLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Llf(lf)	LLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Dlf(lf)	DLOG2("%lld.%lld",lf.numb,lf.frac);
//#define Klf(lf)	KLOG2("%lld.%lld",lf.numb,lf.frac);

//#define _lfp(lfp)	 LOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Rlfp(lfp)	RLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Ylfp(lfp)	YLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Glfp(lfp)	GLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Clfp(lfp)	CLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Blfp(lfp)	BLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Mlfp(lfp)	MLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Wlfp(lfp)	WLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Llfp(lfp)	LLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Dlfp(lfp)	DLOG2("%lld.%lld",lfp->numb,lfp->frac);
//#define Klfp(lfp)	KLOG2("%lld.%lld",lfp->numb,lfp->frac);

//#define _lfAc(lf)	 LOG2("%lld,%lld",lf.numb,lf.frac);
//#define RlfAc(lf)	RLOG2("%lld,%lld",lf.numb,lf.frac);
//#define YlfAc(lf)	YLOG2("%lld,%lld",lf.numb,lf.frac);
//#define GlfAc(lf)	GLOG2("%lld,%lld",lf.numb,lf.frac);
//#define ClfAc(lf)	CLOG2("%lld,%lld",lf.numb,lf.frac);
//#define BlfAc(lf)	BLOG2("%lld,%lld",lf.numb,lf.frac);
//#define MlfAc(lf)	MLOG2("%lld,%lld",lf.numb,lf.frac);
//#define WlfAc(lf)	WLOG2("%lld,%lld",lf.numb,lf.frac);
//#define LlfAc(lf)	LLOG2("%lld,%lld",lf.numb,lf.frac);
//#define DlfAc(lf)	DLOG2("%lld,%lld",lf.numb,lf.frac);
//#define KlfAc(lf)	KLOG2("%lld,%lld",lf.numb,lf.frac);
//#define BRlfAc(lf)	BLOG1("%lld",lf.numb);_c(Acomma);RLOG1("%lld",lf.frac);

//#define _lft(lf)  _l(lf.numb) _t _l(lf.frac);
//#define Rlft(lf)  Rl(lf.numb) _t Rl(lf.frac);
//#define Ylft(lf)  Yl(lf.numb) _t Yl(lf.frac);
//#define Glft(lf)  Gl(lf.numb) _t Gl(lf.frac);
//#define Clft(lf)  Cl(lf.numb) _t Cl(lf.frac);
//#define Blft(lf)  Bl(lf.numb) _t Bl(lf.frac);
//#define Mlft(lf)  Ml(lf.numb) _t Ml(lf.frac);
//#define Wlft(lf)  Wl(lf.numb) _t Wl(lf.frac);
//#define Llft(lf)  Ll(lf.numb) _t Ll(lf.frac);
//#define Dlft(lf)  Dl(lf.numb) _t Dl(lf.frac);
//#define Klft(lf)  Kl(lf.numb) _t Kl(lf.frac);

#define _f1(f,v)      LOG1(f, v);
#define Rf1(f,v)      LOG(RFGC); LOG1(f, v); LOG(OFFC);
#define Yf1(f,v)      LOG(YFGC); LOG1(f, v); LOG(OFFC);
#define Gf1(f,v)      LOG(GFGC); LOG1(f, v); LOG(OFFC);
#define Cf1(f,v)      LOG(CFGC); LOG1(f, v); LOG(OFFC);
#define Bf1(f,v)      LOG(BFGC); LOG1(f, v); LOG(OFFC);
#define Mf1(f,v)      LOG(MFGC); LOG1(f, v); LOG(OFFC);
#define Wf1(f,v)      LOG(WFGC); LOG1(f, v); LOG(OFFC);
#define Lf1(f,v)      LOG(LFGC); LOG1(f, v); LOG(OFFC);
#define Df1(f,v)      LOG(DFGC); LOG1(f, v); LOG(OFFC);
#define Kf1(f,v)      LOG(KFGC); LOG1(f, v); LOG(OFFC);

#define _f2(f,v1,v2)  LOG2(f, v1, v2);
#define Rf2(f,v1,v2)  LOG(RFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Yf2(f,v1,v2)  LOG(YFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Gf2(f,v1,v2)  LOG(GFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Cf2(f,v1,v2)  LOG(CFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Bf2(f,v1,v2)  LOG(BFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Mf2(f,v1,v2)  LOG(MFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Wf2(f,v1,v2)  LOG(WFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Lf2(f,v1,v2)  LOG(LFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Df2(f,v1,v2)  LOG(DFGC); LOG2(f, v1, v2); LOG(OFFC);
#define Kf2(f,v1,v2)  LOG(KFGC); LOG2(f, v1, v2); LOG(OFFC);
//#define Df(f,v) Df1(f,v)
// Df is dark float, DfN is dark format
// Df can refer to DfN is params > 1

#define WiYs(i, s) 	Wi(i) Ys(s) ;
#define cWiYs(c, i, s)	_c(c) Wi(i) Ys(s) ;

//#define _lfpair(lfp) { Cs("VALUE\tDIGITS\tSCALE\tEXCESS\t\n"); \
//                    BRlfAc(lfp.valueA) _t BRlfAc(lfp.digitsA) _t BRlfAc(lfp.scaleA); _t BRlfAc(lfp.excessA) _; \
//                    BRlfAc(lfp.valueB) _t BRlfAc(lfp.digitsB) _t BRlfAc(lfp.scaleB); _t BRlfAc(lfp.excessB) _; \
//                    YlfAc(lfp.valueC) _t YlfAc(lfp.digitsC) _t YlfAc(lfp.scaleC); _t YlfAc(lfp.excessC) _; }

#define SPACE		' '
#define PLUSCH		'+'
#define POSITIVE	'+'
#define MINUSCH		'-'
// later: consider context - + is an operator, '+' is a char. char cannot be where operator can (and vice versa?)
#define NEGATIVE	'-'
#define DASH		'-'
#define UNDERSCORE	'_'
#define DOT		'.'
#define FULLSTOP	'.'
#define DECIMAL		'.'
#define NEWLINE		'\n'
#define CRRT		'\r'
#define LNFD		'\n'
// #define CRLF		'\n' // in Linux
// handle 2 char definitions later somehow ('\r\n' in Windows)
// .. eat \r if Windows .. maybe allow other movement combos later (post next line above prev with \r\b)
#define TAB		'\t'
#define BACKSPACE	'\b'
#define BKSP		BACKSPACE
#define NUL		'\0'
#define WITHNUL		+ 1
#define WITHNULL	+ 1
#define CLEAR		[0] = NUL

#define EQ1(v,a1)		(v EQ a1)
#define EQ2(v,a1,a2)		(v EQ a1 OR v EQ a2)
#define EQ3(v,a1,a2,a3)		(v EQ a1 OR v EQ a2 OR v EQ a3)
#define EQ4(v,a1,a2,a3,a4)	(v EQ a1 OR v EQ a2 OR v EQ a3 OR v EQ a4)
#define EQ5(v,a1,a2,a3,a4,a5)	(v EQ a1 OR v EQ a2 OR v EQ a3 OR v EQ a4 OR v EQ a5)

#define EQY		EQ Y
#define NQY		NQ Y
#define EQN		EQ N
#define NQN		NQ N
#define YES		EQ Y
#define NO		EQ N
// #define NO 0
// #define YES 1
#define IFY(var)	IF (var EQY)
#define IFN(var)	IF (var EQN)
#define IFEL0NUL(var)       IF (var[0] EQNUL)
#define IFEL0EQ(var, ch)    IF (var[0] EQ ch)
#define IFEL0NQ(var, ch)    IF (var[0] NQ ch)
#define WIEL0NQNUL(var)	    WI (var[0] NQNUL)
#define IF0EQ(var)	IF (0 EQ var)
#define IF0NQ(var)	IF (0 NQ var)
#define IX(var, ix)	var[ix]
#define INT(var, val)	IN var = val
#define STR(var, val)	CS var = val
#define NUM(var, val)	FP var = val
#define CHR(var, val)	CH var = val
#define STRS(var, len)	CS var[len]
#define INTS(var, len)	IN var[len]
#define NUMS(var, len)	FP var[len]
#define CHRS(var, len)	CH var[len]
#define STRPS(var, len)	CS *var[len]
#define INTPS(var, len)	IN *var[len]
#define NUMPS(var, len)	FP *var[len]
#define CHRPS(var, len)	CH *var[len]
#define SET(var, val)	var = val;
#define SET1IX(var, ixa, vla)	var[ixa] = vla;
#define SET2IX(var, ixa, ixb, vla, vlb)\
  SET1IX(var, ixa, vla); SET1IX(var, ixb, vlb);
#define SET3IX(var, ixa, ixb, ixc, vla, vlb, vlc)\
  SET2IX(var, ixa, ixb, vla, vlb); SET1IX(var, ixc, vlc);
#define SET4IX(var, ixa, ixb, ixc, ixd, vla, vlb, vlc, vld)\
  SET2IX(var, ixa, ixb, vla, vlb); SET2IX(var, ixc, ixd, vlc, vld);

#define RD	RLOG1("%c", DASH);
#define YD	YLOG1("%c", DASH);
#define GD	GLOG1("%c", DASH);
#define CD	CLOG1("%c", DASH);
#define BD	BLOG1("%c", DASH);
#define MD	MLOG1("%c", DASH);
#define WD	WLOG1("%c", DASH);
#define KD	KLOG1("%c", DASH);

// A for ASCII Char Code .. K for Kernel Code String
#define Kmoveup      "\033[A"
#define Kmovedown    "\033[B"
#define Kmoveleft    "\033[D"
#define Kmoveright   "\033[C"
#define MOVEUP(n)     fprintf(stdout, "\033[%dA", n);
#define MOVEDOWN(n)   fprintf(stdout, "\033[%dB", n);
#define MOVETOSOL     fprintf(stdout, "\n\033[1A");
#define MOVETOEOL     fprintf(stdout, "\n\033[1D");
#define LINEBREAK(w)  fprintf(stdout, "\033[%dD\033[1B", w);
#define MOVERIGHT(n)  fprintf(stdout, "\033[%dC", n);
#define MOVELEFT(n)   fprintf(stdout, "\033[%dD", n);
#define SETCHAR(c)    fprintf(stdout, "%c\033[1D", c);
#define WRITECHAR(c)  fprintf(stdout, "%c", c);
#define LWRITECHAR(c) fprintf(stdout, "%c\033[2D", c);
#define FLUSHBUFFER   LOG0
#define CLEARLINE     fprintf(stdout, "\033[2K");
// http://linux.about.com/library/cmd/blcmdl4_console_codes.htm
// www.systutorials.com/docs/linux/man/4-console_codes/
#define MOVETO(x,y)   fprintf(stdout, "\033[%d;%dH", y, x)
#define MOVETOX(x)    fprintf(stdout, "\033[%dG", x)
#define GOTOCOL(x)    MOVETOX(x)
#define SAVEPOS	      fprintf(stdout, "\033[s")
#define RESTOREPOS    fprintf(stdout, "\033[u")

#define OFFC			"\033[0m"
#define RFGC			"\033[1;31m"
#define YFGC			"\033[1;33m"
#define GFGC			"\033[1;32m"
#define CFGC			"\033[1;36m"
#define BFGC			"\033[1;34m"
#define MFGC			"\033[1;35m"
#define KFGC			"\033[0;30m"
#define DFGC			"\033[1;30m"
#define LFGC			"\033[0;37m"
#define WFGC			"\033[1;37m"
#define DRFGC			"\033[0;31m"
#define DYFGC			"\033[0;33m"
#define DGFGC			"\033[0;32m"
#define DCFGC			"\033[0;36m"
#define DBFGC			"\033[0;34m"
#define DMFGC			"\033[0;35m"
#define OFGC      DYFGC

#define LOGV			printf // ...
// #define ERRV			fprintf(stderr, ...
//#define ERR(str)		LOGV("%s<%s%s%s>%s", RFGC, YFGC, str, RFGC, OFFC); LOG0;
//#define ERR1N(str, n1)		LOGV("%s<%s%s%s(%s%d%s)%s>%s", RFGC, YFGC, str, WFGC, CFGC, n1, WFGC, RFGC, OFFC); LOG0;
//#define ERR1C(str, c1)		LOGV("%s<%s%s%s(%s%c%s)%s>%s", RFGC, YFGC, str, WFGC, GFGC, c1, WFGC, RFGC, OFFC); LOG0;
//#define ERR2N(str, n1, n2)	LOGV("%s<%s%s%s(%s%d%s,%s%d%s)%s>%s", RFGC, YFGC, str, WFGC, MFGC, n1, WFGC, MFGC, n2, WFGC, RFGC, OFFC); LOG0;
//#define ERR2C(str, c1, c2)	LOGV("%s<%s%s%s(%s%c%s,%s%c%s)%s>%s", RFGC, YFGC, str, WFGC, MFGC, c1, WFGC, MFGC, c2, WFGC, RFGC, OFFC); LOG0;
//#define ERR1N1C(str, n1, c1)	LOGV("%s<%s%s%s(%s%d%s,%s%c%s)%s>%s", RFGC, YFGC, str, WFGC, MFGC, n1, WFGC, MFGC, c1, WFGC, RFGC, OFFC); LOG0;
//#define ERR1C1N(str, c1, n1)	LOGV("%s<%s%s%s(%s%c%s,%s%d%s)%s>%s", RFGC, YFGC, str, WFGC, MFGC, c1, WFGC, MFGC, n1, WFGC, RFGC, OFFC); LOG0;
//#define ERR1IN(str, n1)		ERR1N(str, n1)
//#define ERR1CH(str, c1)		ERR1C(str, c1)
//#define ERR2IN(str, n1, n2)	ERR2N(str, n1, n2)
//#define ERR2CH(str, c1, c2)	ERR2N(str, c1, c2)
//#define ERR1IN1CH(str, n1, c1)	ERR2N(str, n1, c1)
//#define ERR1CH1IN(str, c1, n1)	ERR2N(str, c1, n1)
//#define ERRVAR('name') <-- disp name & value
//EV name; EV IN name;
#define ERRSTRVAR(name, val)	LOGV("%s[%s%s: %s%s%s]%s", RFGC, MFGC, name, WFGC, YFGC, val, RFGC, OFFC);
// create STRF() function that returns the number of characters written

#define COFF			OFFC

#define RLOG(v1)		LOG3("%s%s%s", RFGC, v1, OFFC)
#define RLOG1(str, v1)		LOG(RFGC); LOG1(str, v1); LOG(OFFC);
#define RLOG2(str, v1, v2)	LOG(RFGC); LOG2(str, v1, v2); LOG(OFFC);
#define RLOG3(str, v1, v2, v3)	LOG(RFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define RLOG4(str, v1, v2, v3, v4) LOG(RFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DRLOG1(str, v1);	LOG(DRFGC); LOG1(str, v1); LOG(OFFC);

#define RERR(v1)		ERR3("%s%s%s", RFGC, v1, OFFC)
#define RERR1(str, v1)		ERR(RFGC); ERR1(str, v1); ERR(OFFC);
#define RERR2(str, v1, v2)	ERR(RFGC); ERR2(str, v1, v2); ERR(OFFC);


#define YLOG(v1)		LOG3("%s%s%s", YFGC, v1, OFFC)
#define YLOG1(str, v1)		LOG(YFGC); LOG1(str, v1); LOG(OFFC);
#define YLOG2(str, v1, v2)	LOG(YFGC); LOG2(str, v1, v2); LOG(OFFC);
#define YLOG3(str, v1, v2, v3)	LOG(YFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define YLOG4(str, v1, v2, v3, v4) LOG(YFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DYLOG1(str, v1)		LOG(DYFGC); LOG1(str, v1); LOG(OFFC);

#define YERR(v1)		ERR3("%s%s%s", YFGC, v1, OFFC)
#define YERR1(str, v1)		ERR(YFGC); ERR1(str, v1); ERR(OFFC);
#define YERR2(str, v1, v2)	ERR(YFGC); ERR2(str, v1, v2); ERR(OFFC);


#define GLOG(v1)		LOG3("%s%s%s", GFGC, v1, OFFC)
#define GLOG1(str, v1)		LOG(GFGC); LOG1(str, v1); LOG(OFFC);
#define GLOG2(str, v1, v2)	LOG(GFGC); LOG2(str, v1, v2); LOG(OFFC);
#define GLOG3(str, v1, v2, v3)	LOG(GFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define GLOG4(str, v1, v2, v3, v4) LOG(GFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DGLOG1(str, v1)		LOG(DGFGC); LOG1(str, v1); LOG(OFFC);

#define GERR(v1)		ERR3("%s%s%s", GFGC, v1, OFFC)
#define GERR1(str, v1)		ERR(GFGC); ERR1(str, v1); ERR(OFFC);
#define GERR2(str, v1, v2)	ERR(GFGC); ERR2(str, v1, v2); ERR(OFFC);


#define CLOG(v1)		LOG3("%s%s%s", CFGC, v1, OFFC)
#define CLOG1(str, v1)		LOG(CFGC); LOG1(str, v1); LOG(OFFC);
#define CLOG2(str, v1, v2)	LOG(CFGC); LOG2(str, v1, v2); LOG(OFFC);
#define CLOG3(str, v1, v2, v3)	LOG(CFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define CLOG4(str, v1, v2, v3, v4) LOG(CFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DCLOG1(str, v1)		LOG(DCFGC); LOG1(str, v1); LOG(OFFC);

#define CERR(v1)		ERR3("%s%s%s", CFGC, v1, OFFC)
#define CERR1(str, v1)		ERR(CFGC); ERR1(str, v1); ERR(OFFC);
#define CERR2(str, v1, v2)	ERR(CFGC); ERR2(str, v1, v2); ERR(OFFC);


#define BLOG(v1)		LOG3("%s%s%s", BFGC, v1, OFFC)
#define BLOG1(str, v1)		LOG(BFGC); LOG1(str, v1); LOG(OFFC);
#define BLOG2(str, v1, v2)	LOG(BFGC); LOG2(str, v1, v2); LOG(OFFC);
#define BLOG3(str, v1, v2, v3)	LOG(BFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define BLOG4(str, v1, v2, v3, v4) LOG(BFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DBLOG1(str, v1)		LOG(DBFGC); LOG1(str, v1); LOG(OFFC);

#define BERR(v1)		ERR3("%s%s%s", BFGC, v1, OFFC)
#define BERR1(str, v1)		ERR(BFGC); ERR1(str, v1); ERR(OFFC);
#define BERR2(str, v1, v2)	ERR(BFGC); ERR2(str, v1, v2); ERR(OFFC);


#define MLOG(v1)		LOG3("%s%s%s", MFGC, v1, OFFC)
#define MLOG1(str, v1)		LOG(MFGC); LOG1(str, v1); LOG(OFFC);
#define MLOG2(str, v1, v2)	LOG(MFGC); LOG2(str, v1, v2); LOG(OFFC);
#define MLOG3(str, v1, v2, v3)	LOG(MFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define MLOG4(str, v1, v2, v3, v4) LOG(MFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define DMLOG1(str, v1)		LOG(DMFGC); LOG1(str, v1); LOG(OFFC);

#define MERR(v1)		ERR3("%s%s%s", MFGC, v1, OFFC)
#define MERR1(str, v1)		ERR(MFGC); ERR1(str, v1); ERR(OFFC);
#define MERR2(str, v1, v2)	ERR(MFGC); ERR2(str, v1, v2); ERR(OFFC);


// #define KLOG(v1)		LOG3("%s%s%s", KFGC, v1, OFFC)
#define KLOG1(str, v1)		LOG(KFGC); LOG1(str, v1); LOG(OFFC);
#define KLOG2(str, v1, v2)	LOG(KFGC); LOG2(str, v1, v2); LOG(OFFC);
#define KLOG3(str, v1, v2, v3)	LOG(KFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define KLOG4(str, v1, v2, v3, v4) LOG(KFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);
#define DLOG(v1)		LOG3("%s%s%s", DFGC, v1, OFFC)
#define DLOG1(str, v1)		LOG(DFGC); LOG1(str, v1); LOG(OFFC);
#define DLOG2(str, v1, v2)	LOG(DFGC); LOG2(str, v1, v2); LOG(OFFC);
#define DLOG3(str, v1, v2, v3)	LOG(DFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define DLOG4(str, v1, v2, v3, v4) LOG(DFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);
#define LLOG(v1)		LOG3("%s%s%s", LFGC, v1, OFFC)
#define LLOG1(str, v1)		LOG(LFGC); LOG1(str, v1); LOG(OFFC);
#define LLOG2(str, v1, v2)	LOG(LFGC); LOG2(str, v1, v2); LOG(OFFC);
#define LLOG3(str, v1, v2, v3)	LOG(LFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define LLOG4(str, v1, v2, v3, v4) LOG(LFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);
#define WLOG(v1)		LOG3("%s%s%s", WFGC, v1, OFFC)
#define WLOG1(str, v1)		LOG(WFGC); LOG1(str, v1); LOG(OFFC);
#define WLOG2(str, v1, v2)	LOG(WFGC); LOG2(str, v1, v2); LOG(OFFC);
#define WLOG3(str, v1, v2, v3)	LOG(WFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define WLOG4(str, v1, v2, v3, v4) LOG(WFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);

#define WERR(v1)		ERR3("%s%s%s", WFGC, v1, OFFC)
#define WERR1(str, v1)		ERR(WFGC); ERR1(str, v1); ERR(OFFC);
#define WERR2(str, v1, v2)	ERR(WFGC); ERR2(str, v1, v2); ERR(OFFC);


#define MWLOG(cnd, v1)		IF (cnd) { MLOG1("%s", v1); } EL { WLOG1("%s", v1); }
#define OLOG(v1)		LOG3("%s%s%s", OFGC, v1, OFFC)
#define OLOG1(str, v1)		LOG(OFGC); LOG1(str, v1); LOG(OFFC);
#define OLOG2(str, v1, v2)	LOG(OFGC); LOG2(str, v1, v2); LOG(OFFC);
#define OLOG3(str, v1, v2, v3)	LOG(OFGC); LOG3(str, v1, v2, v3); LOG(OFFC);
#define OLOG4(str, v1, v2, v3, v4) LOG(OFGC); LOG4(str, v1, v2, v3, v4); LOG(OFFC);
// OLOG is probably the same as DYLOG

//#define RS(str)	RLOG1("%s", str);
//#define GS(str)	GLOG1("%s", str);
//#define BS(str)	BLOG1("%s", str);
//#define YS(str)	YLOG1("%s", str);
//#define CS(str)	CLOG1("%s", str);
//#define MS(str)	MLOG1("%s", str);
//#define KS(str)	KLOG1("%s", str);
//#define WS(str)	WLOG1("%s", str);
/*
#define RN(str)		RLOG1("%s\n", str);
#define GN(str)		GLOG1("%s\n", str);
#define BN(str)		BLOG1("%s\n", str);
#define YN(str)		YLOG1("%s\n", str);
//#define CN(str)		CLOG1("%s\n", str);
#define MN(str)		MLOG1("%s\n", str);
#define WN(str)		WLOG1("%s\n", str);
#define KN(str)		KLOG1("%s\n", str);
*/ // ^ use R- G- B- Y- C- M- W- K-
/*
#define R1(str, var1)	RLOG1(str, var1);
#define G1(str, var1)	GLOG1(str, var1);
#define B1(str, var1)	BLOG1(str, var1);
#define Y1(str, var1)	YLOG1(str, var1);
#define C1(str, var1)	CLOG1(str, var1);
#define M1(str, var1)	MLOG1(str, var1);
#define W1(str, var1)	WLOG1(str, var1);
#define K1(str, var1)	KLOG1(str, var1);
#define R1I(in)     RLOG1("%d", in);
#define G1I(in)     GLOG1("%d", in);
#define B1I(in)     BLOG1("%d", in);
#define Y1I(in)     YLOG1("%d", in);
#define C1I(in)     CLOG1("%d", in);
#define M1I(in)     MLOG1("%d", in);
#define W1I(in)     WLOG1("%d", in);
#define K1I(in)     KLOG1("%d", in);
*/
/*
#define RIN(in)     R1I(in)
#define GIN(in)     G1I(in)
#define BIN(in)     B1I(in)
#define YIN(in)     Y1I(in)
#define CIN(in)     C1I(in)
#define MIN(in)     M1I(in)
#define WIN(in)     W1I(in)
#define KIN(in)     K1I(in)
#define R1I_(in)    R1I(in); LOG("\n");
#define G1I_(in)    G1I(in); LOG("\n");
#define B1I_(in)    B1I(in); LOG("\n");
#define Y1I_(in)    Y1I(in); LOG("\n");
#define C1I_(in)    C1I(in); LOG("\n");
#define M1I_(in)    M1I(in); LOG("\n");
#define W1I_(in)    W1I(in); LOG("\n");
#define K1I_(in)    K1I(in); LOG("\n");
*/
/*
#define R1S(cs)     RLOG1("%s", cs);
#define G1S(cs)     GLOG1("%s", cs);
#define B1S(cs)     BLOG1("%s", cs);
#define Y1S(cs)     YLOG1("%s", cs);
#define C1S(cs)     CLOG1("%s", cs);
#define M1S(cs)     MLOG1("%s", cs);
#define W1S(cs)     WLOG1("%s", cs);
#define K1S(cs)     KLOG1("%s", cs);
*/
// ^^ WARNING: conflict between KLOG the kernel log and KLOG black log -- make them the same thing in different modes
// KR- = red, \r\n, kernel target
// W-  white, \n, stdout target
// OW- => white to this output buffer (send)   -> ;
// IW- => white to next input buffer (preload)
// PW- => pipe white ($2- to command $1)
// PW- pipename string value -> PW_
// IF word contains - and is before an =, process as 'special definition', keyword DEF (short for extenDed #dEFine)
// - BECOMES _, and both -_ and _- files are created -> translate from special to C-compatible,
//  then from C-compatible to special considering SYNONYMS as SWITCHABLE OPTIONS available in the GRAPHICS LAYER
// DEFINITION(params) [in context] is equivalent to DEFINITION ([in] context) params 
/*
#define R1C(ch)     RLOG1("%c", ch);
#define G1C(ch)     GLOG1("%c", ch);
#define B1C(ch)     BLOG1("%c", ch);
#define Y1C(ch)     YLOG1("%c", ch);
#define C1C(ch)     CLOG1("%c", ch);
#define M1C(ch)     MLOG1("%c", ch);
#define W1C(ch)     WLOG1("%c", ch);
#define K1C(ch)     KLOG1("%c", ch);  // statement
*/
/*
#define RCH(ch)     R1C(ch)           // translation (no ; suffix)
#define GCH(ch)     G1C(ch)
#define BCH(ch)     B1C(ch)
#define YCH(ch)     Y1C(ch)
#define CCH(ch)     C1C(ch)
#define MCH(ch)     M1C(ch)
#define WCH(ch)     W1C(ch)
#define KCH(ch)     K1C(ch)
*/
// R- target 'c' should write c to the device and the RED LOG
//#define LN          LOG("\n"); // redefine as LONG type (LONG NUMBER)
// ^ use - ; INSTEAD <------- - - - - - will \n 5 times
#define SP          LOG(" ");
/*
#define RLN(str)    RLOG1("%s\n", str); // also RN()
#define GLN(str)    GLOG1("%s\n", str);
#define BLN(str)    BLOG1("%s\n", str);
#define YLN(str)    YLOG1("%s\n", str);
#define CLN(str)    CLOG1("%s\n", str);
#define MLN(str)    MLOG1("%s\n", str);
#define WLN(str)    WLOG1("%s\n", str);
#define KLN(str)    KLOG1("%s\n", str);
*/
#define RXC(ix)		LOG(RFGC); EXTCH(ix); LOG(OFFC);
#define GXC(ix)		LOG(GFGC); EXTCH(ix); LOG(OFFC);
#define BXC(ix)		LOG(BFGC); EXTCH(ix); LOG(OFFC);
#define YXC(ix)		LOG(YFGC); EXTCH(ix); LOG(OFFC);
#define CXC(ix)		LOG(CFGC); EXTCH(ix); LOG(OFFC);
#define MXC(ix)		LOG(MFGC); EXTCH(ix); LOG(OFFC);
#define KXC(ix)		LOG(KFGC); EXTCH(ix); LOG(OFFC);
#define WXC(ix)		LOG(WFGC); EXTCH(ix); LOG(OFFC);
#define INLOG(v1)		YLOG(v1)
#define INNLOG(v1)		INLOG(v1)
#define OUTLOG(v1)		CLOG(v1)
#define ERRLOG(v1)		RLOG(v1)
#define SECTION			OLOG1("%s)",
#define NULLOUT(thing)
#define SUPPRESS		NULLOUT(

#define RBGC		"\033[41m"
#define REDBG		LOG(RBGC)
#define YBGC		"\033[43m"
#define YELLOWBG	LOG(YBGC)
#define GBGC		"\033[42m"
#define GREENBG		LOG(GBGC)
#define CBGC		"\033[46m"
#define CYANBG		LOG(CBGC)
#define BBGC		"\033[44m"
#define BLUEBG		LOG(BBGC)
#define MBGC		"\033[45m"
#define MAGENTABG	LOG(MBGC)
#define KBGC		"\033[40m"
#define BLACKBG		LOG(KBGC)
#define WBGC		"\033[47m"
#define WHITEBG		LOG(WBGC)
#define NBGC		"\033[0m"
#define RESETBG		LOG(NBGC)
#define CLS		"\033[2J"
#define CLEARSCREEN	LOG(CLS)
/*
#define REDBG        LOG("\033[41m")
#define YELLOWBG     LOG("\033[43m")
#define GREENBG      LOG("\033[42m")
#define CYANBG       LOG("\033[46m")
#define BLUEBG       LOG("\033[44m")
#define MAGENTABG    LOG("\033[45m")
#define BLACKBG      LOG("\033[40m")
#define WHITEBG      LOG("\033[47m")
#define RESETBG      LOG("\033[0m")
#define CLEARSCREEN  LOG("\033[2J")
*/
#define DEBUGG				LOG(RFGC); fprintf(stdout, "%d",
#define DEBUGH				); fflush(stdout); LOG(OFFC);
#define DEBUGGING			DEBUGG
#define DEBUG				DEBUGH DEBUGG
#define DEBUGGED			DEBUGH LOG("\n");

// #define RLOG1(str, v1)		LOG(RFGC); LOG1(str, v1); LOG(OFFC);
// #define LOG1(str, v1)		fprintf(stdout, str, v1); fflush(stdout);

#define IFNULL(nv)		IF (nv EQNULL)
#define ISNULL(nv)		(nv EQNULL)
//#define IS(nv)			(nv NQNULL)
#define ISBELL(nv)		(nv EQ '\a') // <- error/trigger
#define ISBEL(nv)		ISBELL(nv)
#define ISERR(nv)		ISBELL(nv)
#define ISBKSP(nv)		(nv EQ '\b') // <- back one (el, set, page)
#define ISBS(nv)		ISBKSP(nv)
#define ISHTAB(nv)		(nv EQ '\t') // -> next el (in word list)
#define ISTAB(nv)		ISHTAB(nv)
#define ISHT(nv)		ISHTAB(nv)
#define ISLINE(nv)		(nv EQ '\n') // -> new set (of words)
#define ISLN(nv)		ISLINE(nv)
#define ISNLN(nv)		ISLINE(nv)
#define ISNEWLINE(nv)		ISLINE(nv) // consider NEWLINE CRLF variants later
#define ISVTAB(nv)		(nv EQ '\v') // -> next set (of words)
#define ISVT(nv)		ISVTAB(nv)
#define ISFEED(nv)		(nv EQ '\f') // -> next page (of words)
#define ISFF(nv)		ISFEED(nv)
#define ISCRET(nv)		(nv EQ '\r') // <- seek 0/prev page (of words)
#define ISCR(nv)		ISCRET(nv)
#define NOTBELL(nv)             (NOT ISLINE(nv))
#define NOTBEL(nv)		NOTBELL(nv)
#define NOTERR(nv)		NOTBELL(nv)
#define NOTBKSP(nv)             (NOT ISBKSP(nv))
#define NOTBS(nv)		NOTBKSP(nv)
#define NOTHTAB(nv)             (NOT ISHTAB(nv))
#define NOTTAB(nv)		NOTHTAB(nv)
#define NOTHT(nv)		NOTHTAB(nv)
#define NOTLINE(nv)             (NOT ISLINE(nv))
#define NOTLN(nv)		NOTLINE(nv)
#define NOTNLN(nv)		NOTLINE(nv)
#define NOTNEWLINE(nv)		NOTLINE(nv)
#define NOTVTAB(nv)             (NOT ISVTAB(nv))
#define NOTVT(nv)		NOTVTAB(nv)
#define NOTFEED(nv)             (NOT ISFEED(nv))
#define NOTFF(nv)		NOTFEED(nv)
#define NOTCRET(nv)             (NOT ISCRET(nv))
#define NOTCR(nv)		NOTCRET(nv)
#define NORMCHAR(nv)		(INRANGE(nv, ' ', '~'))
#define ISNUMBER(nv)		(INRANGE(nv, '0', '9'))
#define ISANUMBER(nv)		ISNUMBER(nv)
#define ISNUM(nv)		ISNUMBER(nv)
#define ISANUM(nv)		ISNUMBER(nv)
#define NOTNUMBER(nv)		(!ISNUMBER(nv))
#define NOTANUMBER(nv)		NOTNUMBER(nv)
#define NOTNUM(nv)		NOTNUMBER(nv)
#define NOTANUM(nv)		NOTNUMBER(nv)
#define ISNUMCHAR(nv)		ISNUMBER(nv)    // char numbers are the default b/c all ints are numbers anyway
#define NOTNUMCHAR(nv)		NOTNUMBER(nv)
#define ISHEXCHAR(nv)		(INRANGE(nv, '0', '9') OR INRANGE(nv, 'A', 'F') OR INRANGE(nv, 'a', 'f'))
#define ISHEXCHaf(nv)		INRANGE(nv, 'a', 'f')
#define ISHEXCHAF(nv)		INRANGE(nv, 'A', 'F')
#define ISHEXCH09(nv)		ISNUMBER(nv)    // only true while - is not a number
#define HEXaf(nv)		ISHEXCHaf(nv)
#define HEXAF(nv)		ISHEXCHAF(nv)
#define HEX09(nv)		ISHEXCH09(nv)
#define HEXCHVALUE(nv)		(HEXAF(nv) ? (nv - AA + 10) : HEXaf(nv) ? (nv - Aa + 10) : HEX09(nv) ? (nv - A0) : 0)
#define ISPADCHAR(nv)		(nv EQ ' ' OR nv EQ '\t')
#define ISLETTER(nv)		(INRANGE(nv, 'A', 'Z') OR INRANGE(nv, 'a', 'z'))
#define ISALPHANUM(nv)		(ISLETTER(nv) OR ISNUMBER(nv))
#define LOWERCASE(ch)		(INRANGE(ch, 'A', 'Z') ? (ch - 'A' + 'a') : ch)
#define UPPERCASE(ch)		(INRANGE(ch, 'a', 'z') ? (ch - 'a' + 'A') : ch)
#define LOWEREQ(ch1, ch2)	(LOWERCASE(ch1) EQ LOWERCASE(ch2))
#define UPPEREQ(ch1, ch2)	(UPPERCASE(ch1) EQ UPPERCASE(ch2))

// munch the characters of var to create int var tgt (should be initialised to 0. INMUNCHIN(-1, var, tgt) could create tgt with -1 the default value ? maybe
#define MUNCHPAD(var)		  WI (var[0] EQ Aspace OR var[0] EQ Atab) { var = &var[1]; }
//#define MUNCHIN(var, tgt)	  WI (IRA09(var[0])) { tgt = (tgt * 10) + (var[0] - A0); var = &var[1]; } // "555" -> 555
#define INMUNCHIN(def, var, tgt)  IN tgt = def; MUNCHIN(var, tgt);
#define REMUNCHIN(def, var, tgt)  tgt = def; MUNCHIN(var, tgt);
// redefined next to GETIN for negative number support

#define STRUCT			typedef struct
// note: ST	->	struct

#define KLOG(str)		printk("%s", str);
// ^ is this safe? doubt it
#define KLRN			KLOG("\r\n")
#define KLOGRN(str)		KLOG(str); KLRN;
#define RTKLOGRN(str, rtval)	{ KLOGRN(str); RT rtval; }
// #define KLOGRNRT(str, rt)	KLOGRN(str); RT rt;

#define OBJ		struct
#define	STOBJ		ST OBJ
#define STATICOBJECT	STOBJ
#define StaticObject	STATICOBJECT

#define SW		switch
#define SWITCH		SW
#define CA		case
#define CASE		CA
#define DF		default
#define DEFAULT		DF

#define ISYES		?
#define IFISYES		ISYES
#define ORENO		:
#define OELNO		ORENO
#define ORELNO		ORENO
#define ORELSENO	ORENO  // "or else no" means (=:                                                                                                                                                         ) "oreno" ->   .... also allow oreno <- 
#define IY(v)		ISYES v
#define OE(v)		ORENO v


// #define        ->       [( #define | DEF )] <-- extended #define (DEF) support
// DEF $0 -> $X     AS DEF $0 X
// DEF DEF $0 -> $X AS $0 -> $X
// (user options in [(brackets)])

#define TOGGLE(var)	var = (var) ? 0 : 1;

#define WINCLT(var, init, limit)  IN var = init; WI (INC var LT limit)
#define WINCLQ(var, init, limit)  IN var = init; WI (INC var LQ limit)
#define WDECGT(var, init, limit)  IN var = init; WI (DEC var GT limit)
#define WDECGQ(var, init, limit)  IN var = init; WI (DEC var GQ limit)
#define WINC(var, limit)	WINCLT(var, -1, limit)
//#define ON(eq)		IF (eq)
//#define NO(nq)		IF (!(nq))


// ------------- requires UNISTD.h ------------------------------------------------------------------------------------

#define EMPTYPIPE		(isatty(fileno(stdin)))
#define INPUTPIPE		(!(isatty(fileno(stdin))))
#define STDINCHAR		fgetc(stdin)
#define STDCH			STDINCHAR

// requires sys/types.h and sys/stat.h
#define MAKEPIPEORFAIL(pipe)	IF (mkfifo(pipe, 0666) NQ 0)
// requires sys/stat.h and fnctl.h
#define OPENPIPEREAD(pipe)	open(pipe, O_RDONLY)
#define OPENPIPEWRITE(pipe)	open(pipe, O_WRONLY)
#define WAITFORPIPEKILL(pipe)	WI (access(pipe, F_OK) EQ 0)
#define KILLPIPEORFAIL(pipe)	IF (unlink(pipe) NQ 0)
#define WRITECHARORFAIL(pipe, charbuf)  IF (write(pipe, charbuf, 1) LT 1)
#define WAITFORREADCHAR(pipe, charbuf)	WI (read(pipe, charbuf, 1) LT 1)

//#define OPENPIPEFILEREAD(pipe)  fdopen(pipe, "r")
//#define OPENPIPEFILEWRITE(pipe) fdopen(pipe, "w")
//#define CLOSEPIPEFILE(pfile)    CLOSEFILE(pfile)
// ^ NOT SAFE - EATS BINARY BYTES AND CAUSES 500 ERRORS
#define CLOSEPIPE(pipeid)	close(pipeid)
// pipes can be FS (FILE *) or IN (int)

#define CHDIRORFAIL(dir)	IF (chdir(dir) NQ 0)


#define FILEEXISTS(file)	(access(file, F_OK) EQ 0)
#define FILENEXIST(file)	(!(FILEEXISTS(file))
#define NOFILEEXISTS(file)	FILENEXIST(file)
#define NOFILE(file)		NOFILEEXISTS(file)
#define ISFILE(file)		FILEEXISTS(file)
// requires unistd.h
#define FILEDELETED(file)      (unlink(file) EQ 0)
#define DELETEFILE(file)       FILEDELETED(file)
#define DELFILEORFAIL(file)    IF (!FILEDELETED(file))
#define PIPEDELETED(file)      FILEDELETED(file)
#define DELETEPIPE(file)       DELETEFILE(file)
#define DELPIPEORFAIL(file)    IF (!FILEDELETED(file))

#define ASSERT(this, with, that) IF (this with that) { Gs("Yes"); } EL { Rs("No"); }

#define IFF(cond)	IF (cond) {
#define EFF(cond)	} EF (cond) {
#define ELL		} EL

// ------------- STRUCTURES --------------------------------------------------------------------

#define TS		typedef struct
#define TYPESTRUCT	TS

TS _INxy
  { IN x, y; } XY;
TS _INxywh
  { IN x, y, w, h; } XYWH;
TS _CHrgb
  { UCH r, g, b; } RGB;



// IFF(this) that; that; that; EFF(this) that; that; that; ELL that;
// #include "func.h"
// #include "defs.h"


// RB
// TLB, BLB
// TRB RRB BRB


// drop'top
// -> drop's top
// drop has a top
// drop (extra context) top
// TLB2 BLB2 TRB2 BRB2 RRB3 R[R]B3


// obj'.width' (any param w/ any suffix)
// obj.x y w h = 1 2 4 7;
// gcc: 4 left, 4 right expected
