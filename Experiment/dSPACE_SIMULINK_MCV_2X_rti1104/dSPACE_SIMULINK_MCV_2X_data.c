/*
 * dSPACE_SIMULINK_MCV_2X_data.c
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

#include "dSPACE_SIMULINK_MCV_2X.h"
#include "dSPACE_SIMULINK_MCV_2X_private.h"

/* Block parameters (auto storage) */
Parameters_dSPACE_SIMULINK_MCV_ dSPACE_SIMULINK_MCV_2X_P = {
  /*  Expression: [0.5,1]
   * Referenced by: '<Root>/Signal filler'
   */
  { 0.5, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step Y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step Y'
                                        */
  15.15,                               /* Expression: 15.15
                                        * Referenced by: '<Root>/Step Y'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S6>/Integrator'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: Kpmcv
   * Referenced by: '<Root>/MCV Controller Y'
   */
  { 6.7287176177847039, 262.03099362102864, 43.356254521295774,
    27.827405950463969 },
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S10>/gain'
                                        */
  9.5492965855137211,                  /* Expression: 60/(2*pi)
                                        * Referenced by: '<S10>/rad//s to rpm'
                                        */
  -0.0017,                             /* Expression: -0.0017
                                        * Referenced by: '<S10>/rpm to duty  cycle delta'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Setpoint X2'
                                        */
  381.0,                               /* Expression: const
                                        * Referenced by: '<S12>/Constant'
                                        */
  381.0,                               /* Expression: const
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step X'
                                        */
  15.15,                               /* Expression: 15.15
                                        * Referenced by: '<Root>/Step X'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S5>/Integrator'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: Kymcv
   * Referenced by: '<Root>/MCV Controller X'
   */
  { 1.1217660261094395, 21.267720276262494, 1.4262544862692741,
    0.93822883881461672 },
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S9>/gain'
                                        */
  9.5492965855137211,                  /* Expression: 60/(2*pi)
                                        * Referenced by: '<S9>/rad//s to rpm'
                                        */
  0.0017,                              /* Expression: 0.0017
                                        * Referenced by: '<S9>/rpm to duty  cycle delta'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Setpoint X1'
                                        */

  /*  Expression: [0.5,1]
   * Referenced by: '<Root>/Signal filler1'
   */
  { 0.5, 1.0 },

  /*  Expression: Ayaw-Byaw*Kymcv
   * Referenced by: '<S5>/A'
   */
  { 0.0, -1.2159110647906897E-5, 0.0, -17.058022899430579, 102.80357142857143,
    -0.017230769230769234, 0.0, -323.405461608958, 0.0, 67.500000000000014,
    -1001.6480214539994, -21.688196220005089, 0.0, 0.0, 124.89320080928979,
    -206.26708301455059 },
  0.063125,                            /* Expression: 30.3/480
                                        * Referenced by: '<Root>/cm conversion factor2'
                                        */

  /*  Expression: Cyaw
   * Referenced by: '<S5>/C1'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Expression: [Byaw Kyf]
   * Referenced by: '<S5>/B'
   */
  { 0.0, 0.0, 0.0, 15.206399999999999, 84.7903778566469, 34.96672380719837, 0.0,
    0.0 },

  /*  Expression: Ap-Bp*Kpmcv
   * Referenced by: '<S6>/A'
   */
  { 0.0, -3.265103838319053E-5, 0.0, -25.579892895770328, 94.236607142857181,
    -0.017230769230769234, 0.0, -996.13702534970241, 0.0, 166.15384615384616,
    -1001.774615245475, -164.823137188158, 0.0, 0.0, 124.77817309431556,
    -297.78866646128381 },
  0.063125,                            /* Expression: 30.3/480
                                        * Referenced by: '<Root>/cm conversion factor1'
                                        */

  /*  Expression: Cp
   * Referenced by: '<S6>/C1'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Expression: [Bp Kpf]
   * Referenced by: '<S6>/B'
   */
  { 0.0, 0.0, 0.0, 3.8015999999999996, 127.37526264624336, 86.083625175534223,
    0.0, 0.0 },
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/LASER Enable'
                                        */
};
