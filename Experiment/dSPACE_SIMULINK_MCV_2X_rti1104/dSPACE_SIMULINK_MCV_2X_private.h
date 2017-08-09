/*
 * dSPACE_SIMULINK_MCV_2X_private.h
 *
 * Real-Time Workshop code generation for Simulink model "dSPACE_SIMULINK_MCV_2X.mdl".
 *
 * Model version              : 1.40
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C source code generated on : Tue Oct 08 20:27:24 2013
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_dSPACE_SIMULINK_MCV_2X_private_h_
#define RTW_HEADER_dSPACE_SIMULINK_MCV_2X_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern int slaveDSPPwmStopFlagCh1;
extern int slaveDSPPwmStopFlagCh2;
extern int slaveDSPPwmStopFlagCh3;
extern int slaveDSPPwmStopFlagCh4;

/* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:SETUP */
extern dsserChannel *rtiDS1104SER_B1_Ser[1];

/* private model entry point functions */
extern void dSPACE_SIMULINK_MCV_2X_derivatives(void);

#endif                                 /* RTW_HEADER_dSPACE_SIMULINK_MCV_2X_private_h_ */
