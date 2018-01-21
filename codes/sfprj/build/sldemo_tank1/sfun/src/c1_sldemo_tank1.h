#ifndef __c1_sldemo_tank1_h__
#define __c1_sldemo_tank1_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */

typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c1_ResolvedFunctionInfo;

typedef struct {
  real_T c1_T1[3];
  real_T c1_T2[3];
  real_T c1_last_t[3];
  real_T c1_last_y[3];
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_T1_not_empty;
  boolean_T c1_T2_not_empty;
  boolean_T c1_doneDoubleBufferReInit;
  boolean_T c1_last_t_not_empty;
  boolean_T c1_last_y_not_empty;
  uint8_T c1_is_active_c1_sldemo_tank1;
  ChartInfoStruct chartInfo;
} SFc1_sldemo_tank1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c1_sldemo_tank1_get_eml_resolved_functions_info(void);

/* Function Definitions */

extern void sf_c1_sldemo_tank1_get_check_sum(mxArray *plhs[]);
extern void c1_sldemo_tank1_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

