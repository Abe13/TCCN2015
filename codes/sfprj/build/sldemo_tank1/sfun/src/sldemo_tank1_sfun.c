/* Include files */
#include "sldemo_tank1_sfun.h"
#include "c1_sldemo_tank1.h"
#include "c2_sldemo_tank1.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _sldemo_tank1MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void sldemo_tank1_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void sldemo_tank1_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_sldemo_tank1_method_dispatcher(SimStruct *simstructPtr, unsigned
 int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==1) {
    c1_sldemo_tank1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==2) {
    c2_sldemo_tank1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_sldemo_tank1_process_check_sum_call( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1898064481U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4075487334U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4267367185U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3030153975U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2369826687U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3164150236U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2656043003U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2590156687U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 1:
        {
          extern void sf_c1_sldemo_tank1_get_check_sum(mxArray *plhs[]);
          sf_c1_sldemo_tank1_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_sldemo_tank1_get_check_sum(mxArray *plhs[]);
          sf_c2_sldemo_tank1_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(643529248U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1058096195U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3308740155U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3053004113U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2675220344U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2663417662U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3679257861U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(898334890U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_sldemo_tank1_autoinheritance_info( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_sldemo_tank1_get_autoinheritance_info(void);
        plhs[0] = sf_c1_sldemo_tank1_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_sldemo_tank1_get_autoinheritance_info(void);
        plhs[0] = sf_c2_sldemo_tank1_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
unsigned int sf_sldemo_tank1_get_eml_resolved_functions_info( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0])) return 0;
  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_eml_resolved_functions_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 1:
      {
        extern const mxArray
        *sf_c1_sldemo_tank1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c1_sldemo_tank1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
        *sf_c2_sldemo_tank1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c2_sldemo_tank1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void sldemo_tank1_debug_initialize(void)
{
  _sldemo_tank1MachineNumber_ =
  sf_debug_initialize_machine("sldemo_tank1","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(_sldemo_tank1MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_sldemo_tank1MachineNumber_,0);
}

void sldemo_tank1_register_exported_symbols(SimStruct* S)
{
}
