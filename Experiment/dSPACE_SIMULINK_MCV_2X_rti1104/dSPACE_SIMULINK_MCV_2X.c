/*
 * dSPACE_SIMULINK_MCV_2X.c
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

#include "dSPACE_SIMULINK_MCV_2X_trc_ptr.h"
#include "dSPACE_SIMULINK_MCV_2X.h"
#include "dSPACE_SIMULINK_MCV_2X_private.h"

/* Block signals (auto storage) */
BlockIO_dSPACE_SIMULINK_MCV_2X dSPACE_SIMULINK_MCV_2X_B;

/* Continuous states */
ContinuousStates_dSPACE_SIMULIN dSPACE_SIMULINK_MCV_2X_X;

/* Block states (auto storage) */
D_Work_dSPACE_SIMULINK_MCV_2X dSPACE_SIMULINK_MCV_2X_DWork;

/* Real-time model */
RT_MODEL_dSPACE_SIMULINK_MCV_2X dSPACE_SIMULINK_MCV_2X_M_;
RT_MODEL_dSPACE_SIMULINK_MCV_2X *dSPACE_SIMULINK_MCV_2X_M =
  &dSPACE_SIMULINK_MCV_2X_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  dSPACE_SIMULINK_MCV_2X_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void dSPACE_SIMULINK_MCV_2X_output(int_T tid)
{
  int32_T x;
  real_T y;
  real_T u;
  real_T u_0;
  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* set solver stop time */
    if (!(dSPACE_SIMULINK_MCV_2X_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                            ((dSPACE_SIMULINK_MCV_2X_M->Timing.clockTickH0 + 1) *
        dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                            ((dSPACE_SIMULINK_MCV_2X_M->Timing.clockTick0 + 1) *
        dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize0 +
        dSPACE_SIMULINK_MCV_2X_M->Timing.clockTickH0 *
        dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    dSPACE_SIMULINK_MCV_2X_M->Timing.t[0] = rtsiGetT
      (&dSPACE_SIMULINK_MCV_2X_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  dSPACE_SIMULINK_MCV_2X_B.clock = dSPACE_SIMULINK_MCV_2X_M->Timing.t[0];
  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* S-Function (rti_commonblock): '<S4>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
    dSPACE_SIMULINK_MCV_2X_DWork.SFunction1_IWORK[0] =
      dSPACE_SIMULINK_MCV_2X_P.Signalfiller_Value[1];

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[6],
      dSPACE_SIMULINK_MCV_2X_P.Signalfiller_Value[0]);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction1_IWORK[0] == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwmStopFlagCh1 == 1)||(slaveDSPPwmStopFlagCh1 == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwmStopFlagCh1 = 0;
        ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
          SLVDSP1104_PWM_TTL_LOW);
      }
    } else if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction1_IWORK[0] == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation once */
      if ((slaveDSPPwmStopFlagCh1 == 0)||(slaveDSPPwmStopFlagCh1 == 2)) {
        slaveDSPPwmStopFlagCh1 = 1;
        ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH1_MSK);
      }
    }
  }

  /* Step: '<Root>/Step Y' */
  y = dSPACE_SIMULINK_MCV_2X_M->Timing.t[0];
  if (y < dSPACE_SIMULINK_MCV_2X_P.StepY_Time) {
    dSPACE_SIMULINK_MCV_2X_B.StepY = dSPACE_SIMULINK_MCV_2X_P.StepY_Y0;
  } else {
    dSPACE_SIMULINK_MCV_2X_B.StepY = dSPACE_SIMULINK_MCV_2X_P.StepY_YFinal;
  }

  /* Gain: '<Root>/MCV Controller Y' */

  /* Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator[0] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[0];
  y = dSPACE_SIMULINK_MCV_2X_P.MCVControllerY_Gain[0] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[0];

  /* Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator[1] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[1];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerY_Gain[1] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[1];

  /* Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator[2] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[2];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerY_Gain[2] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[2];

  /* Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator[3] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[3];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerY_Gain[3] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[3];
  dSPACE_SIMULINK_MCV_2X_B.uyy = y;

  /* Sum: '<Root>/Error Y' */
  dSPACE_SIMULINK_MCV_2X_B.uy = dSPACE_SIMULINK_MCV_2X_B.StepY -
    dSPACE_SIMULINK_MCV_2X_B.uyy;

  /* Gain: '<S10>/gain' */
  dSPACE_SIMULINK_MCV_2X_B.gain = dSPACE_SIMULINK_MCV_2X_P.gain_Gain *
    dSPACE_SIMULINK_MCV_2X_B.uy;

  /* Gain: '<S10>/rad//s to rpm' */
  dSPACE_SIMULINK_MCV_2X_B.radstorpm = dSPACE_SIMULINK_MCV_2X_P.radstorpm_Gain *
    dSPACE_SIMULINK_MCV_2X_B.gain;

  /* Gain: '<S10>/rpm to duty  cycle delta' */
  dSPACE_SIMULINK_MCV_2X_B.rpmtodutycycledelta =
    dSPACE_SIMULINK_MCV_2X_P.rpmtodutycycledelta_Gain *
    dSPACE_SIMULINK_MCV_2X_B.radstorpm;

  /* Saturate: '<Root>/Saturation1' */
  y = dSPACE_SIMULINK_MCV_2X_B.rpmtodutycycledelta;
  u = dSPACE_SIMULINK_MCV_2X_P.Saturation1_LowerSat;
  u_0 = dSPACE_SIMULINK_MCV_2X_P.Saturation1_UpperSat;
  dSPACE_SIMULINK_MCV_2X_B.Saturation1 = y >= u_0 ? u_0 : y <= u ? u : y;

  /* Sum: '<Root>/DC Pitch' incorporates:
   *  Constant: '<Root>/Setpoint X2'
   */
  dSPACE_SIMULINK_MCV_2X_B.DCy = dSPACE_SIMULINK_MCV_2X_B.Saturation1 +
    dSPACE_SIMULINK_MCV_2X_P.SetpointX2_Value;
  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* S-Function (rti_commonblock): '<S2>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:RECEIVE */
    {
      UInt32 bytesActNumOfAddr;
      dsser_receive(rtiDS1104SER_B1_Ser[0], 8U, (UInt8 *)
                    dSPACE_SIMULINK_MCV_2X_B.SFunction1, &(bytesActNumOfAddr));
    }

    /* Embedded MATLAB: '<Root>/deconcatanation' */
    /* Embedded MATLAB Function 'deconcatanation': '<S11>:1' */
    /* '<S11>:1:3' */
    y = (real_T)dSPACE_SIMULINK_MCV_2X_B.SFunction1[0];

    /* '<S11>:1:4' */
    x = dSPACE_SIMULINK_MCV_2X_B.SFunction1[4];
    y += (real_T)dSPACE_SIMULINK_MCV_2X_B.SFunction1[1];
    x += dSPACE_SIMULINK_MCV_2X_B.SFunction1[5];
    y += (real_T)dSPACE_SIMULINK_MCV_2X_B.SFunction1[2];
    x += dSPACE_SIMULINK_MCV_2X_B.SFunction1[6];
    y += (real_T)dSPACE_SIMULINK_MCV_2X_B.SFunction1[3];
    x += dSPACE_SIMULINK_MCV_2X_B.SFunction1[7];
    dSPACE_SIMULINK_MCV_2X_B.x = (real_T)x;
    dSPACE_SIMULINK_MCV_2X_B.y = y;

    /* RelationalOperator: '<S12>/Compare' incorporates:
     *  Constant: '<S12>/Constant'
     */
    dSPACE_SIMULINK_MCV_2X_B.Compare = (dSPACE_SIMULINK_MCV_2X_B.x ==
      dSPACE_SIMULINK_MCV_2X_P.Constant_Value);

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    dSPACE_SIMULINK_MCV_2X_B.Compare_i = (dSPACE_SIMULINK_MCV_2X_B.y ==
      dSPACE_SIMULINK_MCV_2X_P.Constant_Value_j);

    /* Logic: '<S7>/Logical Operator' */
    dSPACE_SIMULINK_MCV_2X_B.LogicalOperator = (dSPACE_SIMULINK_MCV_2X_B.Compare
      && dSPACE_SIMULINK_MCV_2X_B.Compare_i);

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    dSPACE_SIMULINK_MCV_2X_B.DataTypeConversion = (real_T)
      dSPACE_SIMULINK_MCV_2X_B.LogicalOperator;

    /* S-Function (rti_commonblock): '<S4>/S-Function2' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
    dSPACE_SIMULINK_MCV_2X_DWork.SFunction2_IWORK[1] =
      dSPACE_SIMULINK_MCV_2X_B.DataTypeConversion;

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[7],
      dSPACE_SIMULINK_MCV_2X_B.DCy);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction2_IWORK[1] == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwmStopFlagCh2 == 1)||(slaveDSPPwmStopFlagCh2 == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwmStopFlagCh2 = 0;
        ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
          SLVDSP1104_PWM_TTL_LOW);
      }
    } else if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction2_IWORK[1] == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation once */
      if ((slaveDSPPwmStopFlagCh2 == 0)||(slaveDSPPwmStopFlagCh2 == 2)) {
        slaveDSPPwmStopFlagCh2 = 1;
        ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH2_MSK);
      }
    }
  }

  /* Step: '<Root>/Step X' */
  y = dSPACE_SIMULINK_MCV_2X_M->Timing.t[0];
  if (y < dSPACE_SIMULINK_MCV_2X_P.StepX_Time) {
    dSPACE_SIMULINK_MCV_2X_B.StepX = dSPACE_SIMULINK_MCV_2X_P.StepX_Y0;
  } else {
    dSPACE_SIMULINK_MCV_2X_B.StepX = dSPACE_SIMULINK_MCV_2X_P.StepX_YFinal;
  }

  /* Gain: '<Root>/MCV Controller X' */

  /* Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator_e[0] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[0];
  y = dSPACE_SIMULINK_MCV_2X_P.MCVControllerX_Gain[0] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[0];

  /* Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator_e[1] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[1];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerX_Gain[1] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[1];

  /* Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator_e[2] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[2];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerX_Gain[2] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[2];

  /* Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_B.Integrator_e[3] =
    dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[3];
  y += dSPACE_SIMULINK_MCV_2X_P.MCVControllerX_Gain[3] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[3];
  dSPACE_SIMULINK_MCV_2X_B.uxx = y;

  /* Sum: '<Root>/Error X' */
  dSPACE_SIMULINK_MCV_2X_B.ux = dSPACE_SIMULINK_MCV_2X_B.StepX -
    dSPACE_SIMULINK_MCV_2X_B.uxx;

  /* Gain: '<S9>/gain' */
  dSPACE_SIMULINK_MCV_2X_B.gain_d = dSPACE_SIMULINK_MCV_2X_P.gain_Gain_c *
    dSPACE_SIMULINK_MCV_2X_B.ux;

  /* Gain: '<S9>/rad//s to rpm' */
  dSPACE_SIMULINK_MCV_2X_B.radstorpm_g =
    dSPACE_SIMULINK_MCV_2X_P.radstorpm_Gain_g * dSPACE_SIMULINK_MCV_2X_B.gain_d;

  /* Gain: '<S9>/rpm to duty  cycle delta' */
  dSPACE_SIMULINK_MCV_2X_B.rpmtodutycycledelta_k =
    dSPACE_SIMULINK_MCV_2X_P.rpmtodutycycledelta_Gain_b *
    dSPACE_SIMULINK_MCV_2X_B.radstorpm_g;

  /* Saturate: '<Root>/Saturation' */
  y = dSPACE_SIMULINK_MCV_2X_B.rpmtodutycycledelta_k;
  u = dSPACE_SIMULINK_MCV_2X_P.Saturation_LowerSat;
  u_0 = dSPACE_SIMULINK_MCV_2X_P.Saturation_UpperSat;
  dSPACE_SIMULINK_MCV_2X_B.Saturation = y >= u_0 ? u_0 : y <= u ? u : y;

  /* Sum: '<Root>/DC Yaw' incorporates:
   *  Constant: '<Root>/Setpoint X1'
   */
  dSPACE_SIMULINK_MCV_2X_B.DCx = dSPACE_SIMULINK_MCV_2X_B.Saturation +
    dSPACE_SIMULINK_MCV_2X_P.SetpointX1_Value;
  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* S-Function (rti_commonblock): '<S4>/S-Function3' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
    dSPACE_SIMULINK_MCV_2X_DWork.SFunction3_IWORK[2] =
      dSPACE_SIMULINK_MCV_2X_B.DataTypeConversion;

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[8],
      dSPACE_SIMULINK_MCV_2X_B.DCx);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction3_IWORK[2] == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwmStopFlagCh3 == 1)||(slaveDSPPwmStopFlagCh3 == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwmStopFlagCh3 = 0;
        ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
          SLVDSP1104_PWM_TTL_LOW);
      }
    } else if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction3_IWORK[2] == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation once */
      if ((slaveDSPPwmStopFlagCh3 == 0)||(slaveDSPPwmStopFlagCh3 == 2)) {
        slaveDSPPwmStopFlagCh3 = 1;
        ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH3_MSK);
      }
    }

    /* S-Function (rti_commonblock): '<S4>/S-Function4' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
    dSPACE_SIMULINK_MCV_2X_DWork.SFunction4_IWORK[3] =
      dSPACE_SIMULINK_MCV_2X_P.Signalfiller1_Value[1];

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[9],
      dSPACE_SIMULINK_MCV_2X_P.Signalfiller1_Value[0]);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction4_IWORK[3] == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwmStopFlagCh4 == 1)||(slaveDSPPwmStopFlagCh4 == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwmStopFlagCh4 = 0;
        ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
          SLVDSP1104_PWM_TTL_LOW);
      }
    } else if (dSPACE_SIMULINK_MCV_2X_DWork.SFunction4_IWORK[3] == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation once */
      if ((slaveDSPPwmStopFlagCh4 == 0)||(slaveDSPPwmStopFlagCh4 == 2)) {
        slaveDSPPwmStopFlagCh4 = 1;
        ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH4_MSK);
      }
    }
  }

  /* Gain: '<S5>/A' */
  for (x = 0; x < 4; x++) {
    dSPACE_SIMULINK_MCV_2X_B.A[x] = 0.0;
    dSPACE_SIMULINK_MCV_2X_B.A[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain[x] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator_e[0] + dSPACE_SIMULINK_MCV_2X_B.A[x];
    dSPACE_SIMULINK_MCV_2X_B.A[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain[x + 4] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator_e[1] + dSPACE_SIMULINK_MCV_2X_B.A[x];
    dSPACE_SIMULINK_MCV_2X_B.A[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain[x + 8] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator_e[2] + dSPACE_SIMULINK_MCV_2X_B.A[x];
    dSPACE_SIMULINK_MCV_2X_B.A[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain[x + 12] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator_e[3] + dSPACE_SIMULINK_MCV_2X_B.A[x];
  }

  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* Product: '<Root>/Product1' incorporates:
     *  Constant: '<Root>/cm conversion factor2'
     */
    dSPACE_SIMULINK_MCV_2X_B.yx =
      dSPACE_SIMULINK_MCV_2X_P.cmconversionfactor2_Value *
      dSPACE_SIMULINK_MCV_2X_B.x;
  }

  /* Gain: '<S5>/C1' */
  y = dSPACE_SIMULINK_MCV_2X_P.C1_Gain[0] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[0];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain[1] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[1];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain[2] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[2];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain[3] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator_e[3];
  dSPACE_SIMULINK_MCV_2X_B.C1 = y;

  /* Sum: '<S5>/Sum4' */
  dSPACE_SIMULINK_MCV_2X_B.Sum4 = dSPACE_SIMULINK_MCV_2X_B.yx -
    dSPACE_SIMULINK_MCV_2X_B.C1;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtBInport1' */
  dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1[0] =
    dSPACE_SIMULINK_MCV_2X_B.StepX;
  dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1[1] =
    dSPACE_SIMULINK_MCV_2X_B.Sum4;
  for (x = 0; x < 4; x++) {
    /* Gain: '<S5>/B' */
    dSPACE_SIMULINK_MCV_2X_B.B[x] = 0.0;
    dSPACE_SIMULINK_MCV_2X_B.B[x] = dSPACE_SIMULINK_MCV_2X_P.B_Gain[x] *
      dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1[0] +
      dSPACE_SIMULINK_MCV_2X_B.B[x];
    dSPACE_SIMULINK_MCV_2X_B.B[x] = dSPACE_SIMULINK_MCV_2X_P.B_Gain[x + 4] *
      dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1[1] +
      dSPACE_SIMULINK_MCV_2X_B.B[x];

    /* Sum: '<S5>/Sum1' */
    dSPACE_SIMULINK_MCV_2X_B.Sum1[x] = dSPACE_SIMULINK_MCV_2X_B.B[x] +
      dSPACE_SIMULINK_MCV_2X_B.A[x];

    /* Gain: '<S6>/A' */
    dSPACE_SIMULINK_MCV_2X_B.A_k[x] = 0.0;
    dSPACE_SIMULINK_MCV_2X_B.A_k[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain_n[x] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator[0] + dSPACE_SIMULINK_MCV_2X_B.A_k[x];
    dSPACE_SIMULINK_MCV_2X_B.A_k[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain_n[x + 4] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator[1] + dSPACE_SIMULINK_MCV_2X_B.A_k[x];
    dSPACE_SIMULINK_MCV_2X_B.A_k[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain_n[x + 8] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator[2] + dSPACE_SIMULINK_MCV_2X_B.A_k[x];
    dSPACE_SIMULINK_MCV_2X_B.A_k[x] = dSPACE_SIMULINK_MCV_2X_P.A_Gain_n[x + 12] *
      dSPACE_SIMULINK_MCV_2X_B.Integrator[3] + dSPACE_SIMULINK_MCV_2X_B.A_k[x];
  }

  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* Product: '<Root>/Product2' incorporates:
     *  Constant: '<Root>/cm conversion factor1'
     */
    dSPACE_SIMULINK_MCV_2X_B.yy = dSPACE_SIMULINK_MCV_2X_B.y *
      dSPACE_SIMULINK_MCV_2X_P.cmconversionfactor1_Value;
  }

  /* Gain: '<S6>/C1' */
  y = dSPACE_SIMULINK_MCV_2X_P.C1_Gain_h[0] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[0];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain_h[1] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[1];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain_h[2] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[2];
  y += dSPACE_SIMULINK_MCV_2X_P.C1_Gain_h[3] *
    dSPACE_SIMULINK_MCV_2X_B.Integrator[3];
  dSPACE_SIMULINK_MCV_2X_B.C1_o = y;

  /* Sum: '<S6>/Sum4' */
  dSPACE_SIMULINK_MCV_2X_B.Sum4_p = dSPACE_SIMULINK_MCV_2X_B.yy -
    dSPACE_SIMULINK_MCV_2X_B.C1_o;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtBInport1' */
  dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1_m[0] =
    dSPACE_SIMULINK_MCV_2X_B.StepY;
  dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1_m[1] =
    dSPACE_SIMULINK_MCV_2X_B.Sum4_p;
  for (x = 0; x < 4; x++) {
    /* Gain: '<S6>/B' */
    dSPACE_SIMULINK_MCV_2X_B.B_n[x] = 0.0;
    dSPACE_SIMULINK_MCV_2X_B.B_n[x] = dSPACE_SIMULINK_MCV_2X_P.B_Gain_a[x] *
      dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1_m[0] +
      dSPACE_SIMULINK_MCV_2X_B.B_n[x];
    dSPACE_SIMULINK_MCV_2X_B.B_n[x] = dSPACE_SIMULINK_MCV_2X_P.B_Gain_a[x + 4] *
      dSPACE_SIMULINK_MCV_2X_B.TmpSignalConversionAtBInport1_m[1] +
      dSPACE_SIMULINK_MCV_2X_B.B_n[x];

    /* Sum: '<S6>/Sum1' */
    dSPACE_SIMULINK_MCV_2X_B.Sum1_g[x] = dSPACE_SIMULINK_MCV_2X_B.B_n[x] +
      dSPACE_SIMULINK_MCV_2X_B.A_k[x];
  }

  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    /* S-Function (rti_commonblock): '<S1>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:DAC */
    ds1104_dac_write(1, dSPACE_SIMULINK_MCV_2X_P.LASEREnable_Value);

    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */
  }

  /* user code (Output function Trailer) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  if (rtmIsContinuousTask(dSPACE_SIMULINK_MCV_2X_M, 0) && rtmIsMajorTimeStep
      (dSPACE_SIMULINK_MCV_2X_M)) {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void dSPACE_SIMULINK_MCV_2X_update(int_T tid)
{
  if (rtmIsMajorTimeStep(dSPACE_SIMULINK_MCV_2X_M)) {
    rt_ertODEUpdateContinuousStates(&dSPACE_SIMULINK_MCV_2X_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++dSPACE_SIMULINK_MCV_2X_M->Timing.clockTick0)) {
    ++dSPACE_SIMULINK_MCV_2X_M->Timing.clockTickH0;
  }

  dSPACE_SIMULINK_MCV_2X_M->Timing.t[0] = rtsiGetSolverStopTime
    (&dSPACE_SIMULINK_MCV_2X_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++dSPACE_SIMULINK_MCV_2X_M->Timing.clockTick1)) {
      ++dSPACE_SIMULINK_MCV_2X_M->Timing.clockTickH1;
    }

    dSPACE_SIMULINK_MCV_2X_M->Timing.t[1] =
      dSPACE_SIMULINK_MCV_2X_M->Timing.clockTick1 *
      dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize1 +
      dSPACE_SIMULINK_MCV_2X_M->Timing.clockTickH1 *
      dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void dSPACE_SIMULINK_MCV_2X_derivatives(void)
{
  /* Derivatives for Integrator: '<S6>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE[0] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1_g[0];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE_e[0] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1[0];

  /* Derivatives for Integrator: '<S6>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE[1] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1_g[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE_e[1] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1[1];

  /* Derivatives for Integrator: '<S6>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE[2] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1_g[2];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE_e[2] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1[2];

  /* Derivatives for Integrator: '<S6>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE[3] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1_g[3];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_dSPACE_SIMULIN *)
    dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs)->Integrator_CSTATE_e[3] =
    dSPACE_SIMULINK_MCV_2X_B.Sum1[3];
}

/* Model initialize function */
void dSPACE_SIMULINK_MCV_2X_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)dSPACE_SIMULINK_MCV_2X_M, 0,
                sizeof(RT_MODEL_dSPACE_SIMULINK_MCV_2X));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                          &dSPACE_SIMULINK_MCV_2X_M->Timing.simTimeStep);
    rtsiSetTPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo, &rtmGetTPtr
                (dSPACE_SIMULINK_MCV_2X_M));
    rtsiSetStepSizePtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                       &dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize0);
    rtsiSetdXPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                 &dSPACE_SIMULINK_MCV_2X_M->ModelData.derivs);
    rtsiSetContStatesPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                         &dSPACE_SIMULINK_MCV_2X_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
      &dSPACE_SIMULINK_MCV_2X_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                          (&rtmGetErrorStatus(dSPACE_SIMULINK_MCV_2X_M)));
    rtsiSetRTModelPtr(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                      dSPACE_SIMULINK_MCV_2X_M);
  }

  rtsiSetSimTimeStep(&dSPACE_SIMULINK_MCV_2X_M->solverInfo, MAJOR_TIME_STEP);
  dSPACE_SIMULINK_MCV_2X_M->ModelData.intgData.f[0] =
    dSPACE_SIMULINK_MCV_2X_M->ModelData.odeF[0];
  dSPACE_SIMULINK_MCV_2X_M->ModelData.contStates = ((real_T *)
    &dSPACE_SIMULINK_MCV_2X_X);
  rtsiSetSolverData(&dSPACE_SIMULINK_MCV_2X_M->solverInfo, (void *)
                    &dSPACE_SIMULINK_MCV_2X_M->ModelData.intgData);
  rtsiSetSolverName(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimes =
      (&dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimesArray[0]);
    dSPACE_SIMULINK_MCV_2X_M->Timing.offsetTimes =
      (&dSPACE_SIMULINK_MCV_2X_M->Timing.offsetTimesArray[0]);

    /* task periods */
    dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimes[0] = (0.0);
    dSPACE_SIMULINK_MCV_2X_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    dSPACE_SIMULINK_MCV_2X_M->Timing.offsetTimes[0] = (0.0);
    dSPACE_SIMULINK_MCV_2X_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(dSPACE_SIMULINK_MCV_2X_M, &dSPACE_SIMULINK_MCV_2X_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = dSPACE_SIMULINK_MCV_2X_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    dSPACE_SIMULINK_MCV_2X_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(dSPACE_SIMULINK_MCV_2X_M, -1);
  dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize0 = 0.0001;
  dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize1 = 0.0001;
  dSPACE_SIMULINK_MCV_2X_M->solverInfoPtr =
    (&dSPACE_SIMULINK_MCV_2X_M->solverInfo);
  dSPACE_SIMULINK_MCV_2X_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&dSPACE_SIMULINK_MCV_2X_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&dSPACE_SIMULINK_MCV_2X_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  dSPACE_SIMULINK_MCV_2X_M->ModelData.blockIO = ((void *)
    &dSPACE_SIMULINK_MCV_2X_B);
  (void) memset(((void *) &dSPACE_SIMULINK_MCV_2X_B), 0,
                sizeof(BlockIO_dSPACE_SIMULINK_MCV_2X));

  /* parameters */
  dSPACE_SIMULINK_MCV_2X_M->ModelData.defaultParam = ((real_T *)
    &dSPACE_SIMULINK_MCV_2X_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &dSPACE_SIMULINK_MCV_2X_X;
    dSPACE_SIMULINK_MCV_2X_M->ModelData.contStates = (x);
    (void) memset((void *)&dSPACE_SIMULINK_MCV_2X_X, 0,
                  sizeof(ContinuousStates_dSPACE_SIMULIN));
  }

  /* states (dwork) */
  dSPACE_SIMULINK_MCV_2X_M->Work.dwork = ((void *) &dSPACE_SIMULINK_MCV_2X_DWork);
  (void) memset((void *)&dSPACE_SIMULINK_MCV_2X_DWork, 0,
                sizeof(D_Work_dSPACE_SIMULINK_MCV_2X));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void dSPACE_SIMULINK_MCV_2X_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function1' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh1 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function2' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh2 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function3' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh3 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function4' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh4 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */

  /* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS1104SER_B1_Ser[0]);
  dsser_fifo_reset(rtiDS1104SER_B1_Ser[0]);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  dSPACE_SIMULINK_MCV_2X_output(tid);
}

void MdlUpdate(int_T tid)
{
  dSPACE_SIMULINK_MCV_2X_update(tid);
}

void MdlInitializeSizes(void)
{
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numContStates = (8);/* Number of continuous states */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numY = (0);/* Number of model outputs */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numU = (0);/* Number of model inputs */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numSampTimes = (2);/* Number of sample times */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numBlocks = (55);/* Number of blocks */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numBlockIO = (40);/* Number of block outputs */
  dSPACE_SIMULINK_MCV_2X_M->Sizes.numBlockPrms = (99);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[0] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC[0];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[0] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC_n[0];

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[1] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC[1];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[1] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC_n[1];

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[2] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC[2];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[2] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC_n[2];

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[3] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC[3];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE_e[3] =
    dSPACE_SIMULINK_MCV_2X_P.Integrator_IC_n[3];
}

void MdlStart(void)
{
  /* Start for S-Function (rti_commonblock): '<S4>/S-Function1' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  dSPACE_SIMULINK_MCV_2X_DWork.SFunction1_IWORK[0] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function2' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  dSPACE_SIMULINK_MCV_2X_DWork.SFunction2_IWORK[1] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function3' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  dSPACE_SIMULINK_MCV_2X_DWork.SFunction3_IWORK[2] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function4' */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  dSPACE_SIMULINK_MCV_2X_DWork.SFunction4_IWORK[3] = 0;
  MdlInitialize();
}

void MdlTerminate(void)
{
  dSPACE_SIMULINK_MCV_2X_terminate();
}

RT_MODEL_dSPACE_SIMULINK_MCV_2X *dSPACE_SIMULINK_MCV_2X(void)
{
  dSPACE_SIMULINK_MCV_2X_initialize(1);
  return dSPACE_SIMULINK_MCV_2X_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
