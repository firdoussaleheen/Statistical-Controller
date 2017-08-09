/*********************** dSPACE target specific file *************************

   Include file dSPACE_SIMULINK_MCV_2X_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1104 6.6 (29-Nov-2010)
   Tue Oct 08 20:27:24 2013

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "dSPACE_SIMULINK_MCV_2X.h"
#include "dSPACE_SIMULINK_MCV_2X_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             dSPACE_SIMULINK_MCV_2X_B
#define RTP_STRUCTURE_NAME             dSPACE_SIMULINK_MCV_2X_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1104.h>
#include <slvdsp1104.h>
#include <rti_slv1104.h>
#include <dsser.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* flag = UNDEF */
int slaveDSPPwmStopFlagCh1 = 2;

/* flag = UNDEF */
int slaveDSPPwmStopFlagCh2 = 2;

/* flag = UNDEF */
int slaveDSPPwmStopFlagCh3 = 2;

/* flag = UNDEF */
int slaveDSPPwmStopFlagCh4 = 2;

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:SETUP */
dsserChannel *rtiDS1104SER_B1_Ser[1];

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);
  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1104, (void *) 0,
                        VCM_TXT_RTI1104, 6, 6, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 11, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 7, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 7, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS1104SLAVE #1 */
  /* Initialize master - slave DSP communication */
  ds1104_slave_dsp_communication_init();

  /* Initialize automatic index generation */
  rti_slv1104_init_fcn_index();

  /* Initialize slave DSP error level */
  rti_slv1104_error_level = 0;

  /* dSPACE I/O Board DS1104SLAVE #1 Unit:PWM */
  /* Initialize Slave DSP PWM Channel 1 */
  ds1104_slave_dsp_pwm_init(0, 1.0/ 100000, 0.5, SLVDSP1104_PWM_MODE_SYM,
    SLVDSP1104_PWM_POL_HIGH, SLVDSP1104_PWM_CH1_MSK);

  /* Start Slave DSP PWM Channel 1 */
  ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH1_MSK);

  /* Register Slave DSP PWM Channel 1 */
  ds1104_slave_dsp_pwm_duty_write_register(0, &rti_slv1104_fcn_index[6], 1);

  /* Initialize Slave DSP PWM Channel 2 */
  ds1104_slave_dsp_pwm_init(0, 1.0/ 100000, 0.5, SLVDSP1104_PWM_MODE_SYM,
    SLVDSP1104_PWM_POL_HIGH, SLVDSP1104_PWM_CH2_MSK);

  /* Start Slave DSP PWM Channel 2 */
  ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH2_MSK);

  /* Register Slave DSP PWM Channel 2 */
  ds1104_slave_dsp_pwm_duty_write_register(0, &rti_slv1104_fcn_index[7], 2);

  /* Initialize Slave DSP PWM Channel 3 */
  ds1104_slave_dsp_pwm_init(0, 1.0/ 100000, 0.5, SLVDSP1104_PWM_MODE_SYM,
    SLVDSP1104_PWM_POL_HIGH, SLVDSP1104_PWM_CH3_MSK);

  /* Start Slave DSP PWM Channel 3 */
  ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH3_MSK);

  /* Register Slave DSP PWM Channel 3 */
  ds1104_slave_dsp_pwm_duty_write_register(0, &rti_slv1104_fcn_index[8], 3);

  /* Initialize Slave DSP PWM Channel 4 */
  ds1104_slave_dsp_pwm_init(0, 1.0/ 100000, 0.5, SLVDSP1104_PWM_MODE_SYM,
    SLVDSP1104_PWM_POL_HIGH, SLVDSP1104_PWM_CH4_MSK);

  /* Start Slave DSP PWM Channel 4 */
  ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH4_MSK);

  /* Register Slave DSP PWM Channel 4 */
  ds1104_slave_dsp_pwm_duty_write_register(0, &rti_slv1104_fcn_index[9], 4);

  /* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:SETUP */
  rtiDS1104SER_B1_Ser[0] = dsser_init(DSSER_ONBOARD,0,64);
  dsser_config(rtiDS1104SER_B1_Ser[0],8, 19200, 7, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_8_BYTE_TRIGGER_LEVEL,0, (DSSER_RS232 |
    DSSER_AUTOFLOW_ENABLE));

  /* Initialization of Master DAC units */
  ds1104_dac_init(DS1104_DACMODE_TRANSPARENT);
  ds1104_dac_trigger_setup(DS1104_TRIGGER_DISABLE);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1104SLAVE #1 Unit:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh1 = 2;
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh2 = 2;
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh3 = 2;
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh4 = 2;

  /* dSPACE I/O Board DS1104 #1 Unit:DAC */
  ds1104_dac_write(1, 0);

  /* dSPACE I/O Board DS1104SER #1 Unit:GENSER Group:SETUP */
  dsser_enable(rtiDS1104SER_B1_Ser[0]);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* dSPACE I/O Board DS1104SLAVE #1 */
  /* Check master - slave dsp communication */
  rti_slv1104_taskqueue_error_all_check();
}

/* Function rti_mdl_sample_input() is empty */
#define rti_mdl_sample_input()
#undef __INLINE

/****** [EOF] ****************************************************************/
