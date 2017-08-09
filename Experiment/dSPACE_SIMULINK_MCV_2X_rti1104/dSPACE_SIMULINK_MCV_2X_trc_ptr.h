  /*********************** dSPACE target specific file *************************

   Header file dSPACE_SIMULINK_MCV_2X_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 6.6 (29-Nov-2010)
   Tue Oct 08 20:27:24 2013

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_dSPACE_SIMULINK_MCV_2X_trc_ptr_h_
  #define RTI_HEADER_dSPACE_SIMULINK_MCV_2X_trc_ptr_h_
  /* Include the model header file. */
  #include "dSPACE_SIMULINK_MCV_2X.h"
  #include "dSPACE_SIMULINK_MCV_2X_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_dSPACE_SIMULINK_MCV_2X_B_real_T_0;
              EXTERN_C volatile  uint8_T *p_dSPACE_SIMULINK_MCV_2X_B_uint8_T_1;
              EXTERN_C volatile  boolean_T *p_dSPACE_SIMULINK_MCV_2X_B_boolean_T_2;
              EXTERN_C volatile  real_T *p_dSPACE_SIMULINK_MCV_2X_P_real_T_0;
              EXTERN_C volatile  int_T *p_dSPACE_SIMULINK_MCV_2X_DWork_int_T_0;
              EXTERN_C volatile  real_T *p_dSPACE_SIMULINK_MCV_2X_X_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_dSPACE_SIMULINK_MCV_2X_B_real_T_0 = &dSPACE_SIMULINK_MCV_2X_B.clock;\
              p_dSPACE_SIMULINK_MCV_2X_B_uint8_T_1 = &dSPACE_SIMULINK_MCV_2X_B.SFunction1[0];\
              p_dSPACE_SIMULINK_MCV_2X_B_boolean_T_2 = &dSPACE_SIMULINK_MCV_2X_B.Compare;\
              p_dSPACE_SIMULINK_MCV_2X_P_real_T_0 = &dSPACE_SIMULINK_MCV_2X_P.Signalfiller_Value[0];\
              p_dSPACE_SIMULINK_MCV_2X_DWork_int_T_0 = &dSPACE_SIMULINK_MCV_2X_DWork.SFunction1_IWORK[0];\
              p_dSPACE_SIMULINK_MCV_2X_X_real_T_0 = &dSPACE_SIMULINK_MCV_2X_X.Integrator_CSTATE[0];\

   #endif                       /* RTI_HEADER_dSPACE_SIMULINK_MCV_2X_trc_ptr_h_ */
