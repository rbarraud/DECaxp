/*
 * Copyright (C) Jonathan D. Belanger 2017.
 * All Rights Reserved.
 *
 * This software is furnished under a license and may be used and copied only
 * in accordance with the terms of such license and with the inclusion of the
 * above copyright notice.  This software or any other copies thereof may not
 * be provided or otherwise made available to any other person.  No title to
 * and ownership of the software is hereby transferred.
 *
 * The information in this software is subject to change without notice and
 * should not be construed as a commitment by the author or co-authors.
 *
 * The author and any co-authors assume no responsibility for the use or
 * reliability of this software.
 *
 * Description:
 *
 *	This source file contains the functions needed to implement the
 *	functionality of the Fbox Operate Instructions.
 *
 *	Revision History:
 *
 *	V01.000		24-June-2017	Jonathan D. Belanger
 *	Initially written.
 */
#include "AXP_Configure.h"
#include "AXP_21264_Fbox_Operate.h"

/*
 * AXP_CPYS
 * 	This function implements the Floating-Point Operate Copy Sign instruction of
 * 	the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CPYS(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.s = instr->src2v.fp.s;
	instr->destv.fp.s.sign = instr->src1v.fp.s.sign;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_CPYSE
 * 	This function implements the Floating-Point Operate Copy Sign and Exponent
 * 	instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CPYSE(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.s.sign = instr->src1v.fp.s.sign;
	instr->destv.fp.s.exponent = instr->src1v.fp.s.exponent;
	instr->destv.fp.s.fraction = instr->src2v.fp.s.fraction;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_CPYSN
 * 	This function implements the Floating-Point Operate Copy Sign Negate
 * 	instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CPYSN(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.s = instr->src2v.fp.s;
	instr->destv.fp.s.sign = ~instr->src1v.fp.s.sign;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_CVTLQ
 * 	This function implements the Floating-Point Operate Convert Longword to
 * 	Quadword instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CVTLQ(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.qCvt.sign = instr->src1v.fp.l.sign;
	instr->destv.fp.qCvt.integerHigh = instr->src1v.fp.l.integerHigh;
	instr->destv.fp.qCvt.integerLow = instr->src1v.fp.l.integerLow;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_CVTQL
 * 	This function implements the Floating-Point Operate Convert Quadword to
 * 	Longword without overflow instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CVTQL(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.l.sign = instr->src1v.fp.qVCvt.sign;
	instr->destv.fp.l.integerHigh = instr->src1v.fp.qVCvt.integerLowHigh;
	instr->destv.fp.l.zero_2 = 0;
	instr->destv.fp.l.integerLow = instr->src1v.fp.qVCvt.integerLowLow;
	instr->destv.fp.l.zero_1 = 0;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_CVTQL_V
 * 	This function implements the Floating-Point Operate Convert Quadword to
 * 	Longword with overflow instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CVTQL_V(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{
	AXP_EXCEPTIONS retVal = NoException;

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.l.sign = instr->src1v.fp.qVCvt.sign;
	instr->destv.fp.l.integerHigh = instr->src1v.fp.qVCvt.integerLowHigh;
	instr->destv.fp.l.zero_2 = 0;
	instr->destv.fp.l.integerLow = instr->src1v.fp.qVCvt.integerLowLow;
	instr->destv.fp.l.zero_1 = 0;
	if (instr->src1v.fp.qVCvt.integerHigh != 0)
		retVal = ArithmeticTraps;	// IntegerOverflow;
	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(retVal);
}

/*
 * AXP_CVTQL_SV
 * 	This function implements the Floating-Point Operate Convert Quadword to
 * 	Longword with overflow and software completion instruction of the Alpha AXP
 * 	processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_CVTLQ_SV(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{
	AXP_EXCEPTIONS retVal = NoException;

	/*
	 * Implement the instruction.
	 */
	instr->destv.fp.l.sign = instr->src1v.fp.qVCvt.sign;
	instr->destv.fp.l.integerHigh = instr->src1v.fp.qVCvt.integerLowHigh;
	instr->destv.fp.l.zero_2 = 0;
	instr->destv.fp.l.integerLow = instr->src1v.fp.qVCvt.integerLowLow;
	instr->destv.fp.l.zero_1 = 0;

	/*
	 * TODO:	We need to understand how software-completion differs from just
	 *			reporting the exception.
	 */
	if (instr->src1v.fp.qVCvt.integerHigh != 0)
		retVal = ArithmeticTraps;	// IntegerOverflow;
	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(retVal);
}

/*
 * AXP_FCMOVEQ
 *	This function implements the Floating-Point Conditional Move if Equal
 *	instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVEQ(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if ((instr->src1v.fp.s.exponent == 0) && (instr->src1v.fp.s.fraction == 0))
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_FCMOVGE
 *	This function implements the Floating-Point Conditional Move if Greater
 *	Than or Equal instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVGE(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if (instr->src1v.fp.uq <= AXP_R_SIGN)
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_FCMOVGT
 *	This function implements the Floating-Point Conditional Move if Greater
 *	Than instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVGT(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if ((instr->src1v.fp.s.sign == 0) && (instr->src1v.fp.uq != 0))
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_FCMOVLE
 *	This function implements the Floating-Point Conditional Move if Less Than
 *	or Equal instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVLE(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if ((instr->src1v.fp.s.sign == 1) || (instr->src1v.fp.uq == 0))
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_FCMOVLT
 *	This function implements the Floating-Point Conditional Move if Less Than
 *	instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVLT(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if ((instr->src1v.fp.s.sign == 1) || (instr->src1v.fp.uq != 0))
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_FCMOVNE
 *	This function implements the Floating-Point Conditional Move if Not Equal
 *	instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_FCMOVNE(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	if ((instr->src1v.fp.uq & ~AXP_R_SIGN) != 0)
		instr->destv.fp.uq = instr->src2v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_MF_FPCR
 *	This function implements the Floating-Point Move From Floating-Point
 *	Control Register instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_MF_FPCR(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 */
	instr->destv.fp.uq = *(u64 *) &cpu->fpcr;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}

/*
 * AXP_MT_FPCR
 *	This function implements the Floating-Point Move To Floating-Point
 *	Control Register instruction of the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_MF_FTCR(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{

	/*
	 * Implement the instruction
	 *
	 * NOTE: The value will actually be moved into the FPCR at the time of
	 * 		 instruction retirement.
	 */
	instr->destv.fp.uq = instr->src1v.fp.uq;

	/*
	 * Indicate that the instruction is ready to be retired.
	 */
	instr->state = WaitingRetirement;

	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(NoException);
}
#if 0
/*
 * AXP_ADDF
 *	This function implements the VAX F Format Floating-Point ADD instruction of
 *	the Alpha AXP processor.
 *
 * Input Parameters:
 *	cpu:
 *		A pointer to the structure containing the information needed to emulate
 *		a single CPU.
 * 	instr:
 * 		A pointer to a structure containing the information needed to execute
 * 		this instruction.
 *
 * Output Parameters:
 * 	instr:
 * 		The contents of this structure are updated, as needed.
 *
 * Return Value:
 * 	An exception indicator.
 */
AXP_EXCEPTIONS AXP_ADDF(AXP_21264_CPU *cpu, AXP_INSTRUCTION *instr)
{
	AXP_EXCEPTIONS	retVal = NoException;
	u64				signA, expA, fracA;
	u64				signB, expB, fracB;

	AXP_F_UNPACK(instr->src1v, signA, expA, fracA, retVal);
	AXP_F_UNPACK(instr->src2v, signB, expB, fracB, retVal);

	/*
	 * TODO:	We need to understand how software-completion differs from just
	 *			reporting the exception.
	 */
	if (0)
		signB ^= 1;                           /* sub? invert b sign */
	if (expA == 0)
	{
		signA = signB;                                  /* s1 = 0? */
		expA = expB;                                  /* s1 = 0? */
		fracA = fracB;                                  /* s1 = 0? */
	}
	else if (expB)
	{                                       /* s2 != 0? */
	    if ((expA < expB) ||                              /* |s1| < |s2|? swap */
	        ((expA == expB) && (fracA < fracA)))
	    {
	    	u64				signT, expT, fracT;

	    	signT = signA;
	    	expT = expA;
	    	fracT = fracA;
	    	signA = signB;
	    	expA = expB;
	    	fracA = fracB;
	    	signB = signT;
	    	expB = expT;
	    	fracB = fracT;
        }
	    ediff = a.exp - b.exp;                              /* exp diff */
	    if (a.sign ^ b.sign) {                              /* eff sub? */
	        if (ediff > 63) b.frac = 1;                     /* >63? retain sticky */
	        else if (ediff) {                               /* [1,63]? shift */
	            sticky = ((b.frac << (64 - ediff)) & M64)? 1: 0; /* lost bits */
	            b.frac = (b.frac >> ediff) | sticky;
	            }
	        a.frac = (a.frac - b.frac) & M64;               /* subtract fractions */
	        vax_norm (&a);                                  /* normalize */
	        }
	    else {                                              /* eff add */
	        if (ediff > 63) b.frac = 0;                     /* >63? b disappears */
	        else if (ediff) b.frac = b.frac >> ediff;       /* denormalize */
	        a.frac = (a.frac + b.frac) & M64;               /* add frac */
	        if (a.frac < b.frac) {                          /* chk for carry */
	            a.frac = UF_NM | (a.frac >> 1);             /* shift in carry */
	            a.exp = a.exp + 1;                          /* skip norm */
	            }
	        }
	    }                                                   /* end else if */
	return vax_rpack (&a, ir, dp); /* round and pack */
	/*
	 * Return back to the caller with any exception that may have occurred.
	 */
	return(retVal);
}
#endif