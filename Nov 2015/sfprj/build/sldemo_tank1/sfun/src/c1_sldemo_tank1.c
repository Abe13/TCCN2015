/* Include files */
#include "sldemo_tank1_sfun.h"
#include "c1_sldemo_tank1.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "sldemo_tank1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_sldemo_tank1InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_sldemo_tank1(void);
static void initialize_params_c1_sldemo_tank1(void);
static void enable_c1_sldemo_tank1(void);
static void disable_c1_sldemo_tank1(void);
static void finalize_c1_sldemo_tank1(void);
static void sf_c1_sldemo_tank1(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_g_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_h_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_i_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_j_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_k_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_l_sf_marshall(void *c1_chartInstance, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[49]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_sldemo_tank1(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_last_t_not_empty = false;
  chartInstance.c1_last_y_not_empty = false;
  chartInstance.c1_T1_not_empty = false;
  chartInstance.c1_T2_not_empty = false;
  chartInstance.c1_is_active_c1_sldemo_tank1 = 0U;
}

static void initialize_params_c1_sldemo_tank1(void)
{
}

static void enable_c1_sldemo_tank1(void)
{
}

static void disable_c1_sldemo_tank1(void)
{
}

static void finalize_c1_sldemo_tank1(void)
{
}

static void sf_c1_sldemo_tank1(void)
{
  uint8_T c1_previousEvent;
  real_T c1_t;
  real_T c1_H;
  real_T c1_i;
  real_T c1_delta[3];
  real_T c1_N;
  real_T c1_lam2;
  real_T c1_lam1;
  real_T c1_y;
  int32_T c1_i0;
  static char c1_cv0[10] = { 'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e' };
  char c1_u[10];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  static char c1_cv1[11] = { 'e', 'x', 'p', 'o', 'n', 'e', 'n', 't', 'i', 'a',
    'l' };
  char c1_b_u[11];
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_random;
  char *c1_name;
  real_T c1_dv0[3];
  int32_T c1_i6;
  real_T c1_g_y[3];
  int32_T c1_i7;
  int32_T c1_i8;
  char c1_f_u[11];
  const mxArray *c1_h_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_b_random;
  char *c1_b_name;
  real_T c1_dv1[3];
  int32_T c1_i9;
  real_T c1_l_y[3];
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_x[3];
  int32_T c1_i12;
  real_T c1_b_x[3];
  real_T c1_c_x;
  int32_T c1_i13;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_d_x;
  real_T c1_r;
  int32_T c1_i14;
  real_T c1_d0;
  real_T c1_b_i;
  int32_T c1_i15;
  char c1_j_u[11];
  const mxArray *c1_m_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_n_y = NULL;
  const mxArray *c1_c_random;
  char *c1_c_name;
  real_T c1_d1;
  real_T c1_o_y;
  int32_T c1_i16;
  char c1_l_u[11];
  const mxArray *c1_p_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_q_y = NULL;
  const mxArray *c1_d_random;
  char *c1_d_name;
  real_T c1_d2;
  real_T c1_r_y;
  real_T *c1_s_y;
  real_T *c1_b_t;
  real_T *c1_b_H;
  c1_s_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_H = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c1_s_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_t, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_H, 0U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_t = *c1_b_t;
  c1_H = *c1_b_H;
  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("T2", &chartInstance.c1_T2, c1_l_sf_marshall);
  sf_debug_symbol_scope_add("T1", &chartInstance.c1_T1, c1_k_sf_marshall);
  sf_debug_symbol_scope_add("last_y", &chartInstance.c1_last_y,
   c1_j_sf_marshall);
  sf_debug_symbol_scope_add("last_t", &chartInstance.c1_last_t,
   c1_i_sf_marshall);
  sf_debug_symbol_scope_add("i", &c1_i, c1_h_sf_marshall);
  sf_debug_symbol_scope_add("delta", &c1_delta, c1_g_sf_marshall);
  sf_debug_symbol_scope_add("N", &c1_N, c1_f_sf_marshall);
  sf_debug_symbol_scope_add("lam2", &c1_lam2, c1_e_sf_marshall);
  sf_debug_symbol_scope_add("lam1", &c1_lam1, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("y", &c1_y, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("H", &c1_H, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("t", &c1_t, c1_sf_marshall);
  CV_EML_FCN(0, 0);
  /* TIMEAVG Compute time average of input signal U. */
  /*    Y = TIMEAVG(U,T) computes the time average of U, */
  /*    where T is the current simulation time. */
  /*  Declare variables that must retain values between iterations. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c1_lam1 = 0.3;
  /* On parameter */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c1_lam2 = 1.0;
  /* Off parameter */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  c1_N = 3.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
  if(CV_EML_IF(0, 0, !chartInstance.c1_last_t_not_empty)) {
    /*  number of PUs */
    /*  Initialize persistent variables in the first iteration. */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
    for(c1_i0 = 0; c1_i0 < 10; c1_i0 = c1_i0 + 1) {
      c1_u[c1_i0] = c1_cv0[c1_i0];
    }
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create(&c1_u, "y", 8, 0U, 1U, 2, 1, 10));
    sf_mex_call("disp", 0U, 1U, 14, c1_b_y);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
    for(c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
      chartInstance.c1_last_y[c1_i1] = 0.0;
    }
    chartInstance.c1_last_y_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
    for(c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
      chartInstance.c1_last_t[c1_i2] = 0.0;
    }
    chartInstance.c1_last_t_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    for(c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
      chartInstance.c1_T1[c1_i3] = 0.0;
    }
    chartInstance.c1_T1_not_empty = true;
    /*  ON time */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,21);
    for(c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
      chartInstance.c1_T2[c1_i4] = 0.0;
    }
    chartInstance.c1_T2_not_empty = true;
    /*  OFF Time */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
    for(c1_i5 = 0; c1_i5 < 11; c1_i5 = c1_i5 + 1) {
      c1_b_u[c1_i5] = c1_cv1[c1_i5];
    }
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create(&c1_b_u, "y", 8, 0U, 1U, 2, 1, 11));
    c1_c_u = c1_lam1;
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create(&c1_c_u, "y", 0, 0U, 0U, 0));
    c1_d_u = c1_N;
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create(&c1_d_u, "y", 0, 0U, 0U, 0));
    c1_e_u = 1.0;
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create(&c1_e_u, "y", 0, 0U, 0U, 0));
    c1_random = sf_mex_call("random", 1U, 4U, 14, c1_c_y, 14, c1_d_y, 14,
     c1_e_y, 14, c1_f_y);
    c1_name = "random";
    sf_mex_import(sf_mex_dup(c1_random), c1_name, &c1_dv0, 1, 0, 0U, 1, 1, 3);
    for(c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
      c1_g_y[c1_i6] = c1_dv0[c1_i6];
    }
    sf_mex_destroy(&c1_random);
    for(c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
      chartInstance.c1_T1[c1_i7] = c1_g_y[c1_i7];
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
    for(c1_i8 = 0; c1_i8 < 11; c1_i8 = c1_i8 + 1) {
      c1_f_u[c1_i8] = c1_cv1[c1_i8];
    }
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create(&c1_f_u, "y", 8, 0U, 1U, 2, 1, 11));
    c1_g_u = c1_lam1;
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create(&c1_g_u, "y", 0, 0U, 0U, 0));
    c1_h_u = c1_N;
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create(&c1_h_u, "y", 0, 0U, 0U, 0));
    c1_i_u = 1.0;
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create(&c1_i_u, "y", 0, 0U, 0U, 0));
    c1_b_random = sf_mex_call("random", 1U, 4U, 14, c1_h_y, 14, c1_i_y, 14,
     c1_j_y, 14, c1_k_y);
    c1_b_name = "random";
    sf_mex_import(sf_mex_dup(c1_b_random), c1_b_name, &c1_dv1, 1, 0, 0U, 1, 1,
     3);
    for(c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
      c1_l_y[c1_i9] = c1_dv1[c1_i9];
    }
    sf_mex_destroy(&c1_b_random);
    for(c1_i10 = 0; c1_i10 < 3; c1_i10 = c1_i10 + 1) {
      chartInstance.c1_T1[c1_i10] = c1_l_y[c1_i10];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
  for(c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    c1_x[c1_i11] = chartInstance.c1_last_y[c1_i11];
  }
  for(c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
    c1_b_x[c1_i12] = c1_x[c1_i12];
  }
  c1_c_x = c1_b_x[0];
  c1_y = c1_c_x;
  c1_i13 = 2;
  for(c1_k = c1_i13; c1_k < 4; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    c1_d_x = c1_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
     _SFD_INTEGER_CHECK("k", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
    c1_r = c1_d_x;
    c1_y = c1_y + c1_r;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
  for(c1_i14 = 0; c1_i14 < 3; c1_i14 = c1_i14 + 1) {
    c1_delta[c1_i14] = c1_t - chartInstance.c1_last_t[c1_i14];
  }
  /* disp(['t= ',num2str(t),', last_t= ',num2str(last_t),', delta= ',num2str(delta),', T1= ', num2str(T1),', y= ',num2str(y)... */
  /*     ,', delta > T1= ',num2str(delta > T1)]) */
  /*  Compute the outputs. */
  c1_d0 = 1.0;
  c1_i = c1_d0;
  c1_b_i = c1_d0;
  while(c1_b_i <= 3.0) {
    c1_i = c1_b_i;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,36);
    if(CV_EML_COND(0, 0, c1_delta[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("delta",
       (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1]
      > chartInstance.c1_T1[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T1",
       (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1])) {
      if(CV_EML_COND(0, 1,
        chartInstance.c1_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i),
         1, 3, 1, 0) - 1] == 1.0)) {
        CV_EML_MCDC(0, 0, true);
        CV_EML_IF(0, 1, true);
        /*  One PU turns off */
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
        c1_y = c1_y - 1.0;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,38);
        chartInstance.c1_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] =
          0.0;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
        for(c1_i15 = 0; c1_i15 < 11; c1_i15 = c1_i15 + 1) {
          c1_j_u[c1_i15] = c1_cv1[c1_i15];
        }
        c1_m_y = NULL;
        sf_mex_assign(&c1_m_y, sf_mex_create(&c1_j_u, "y", 8, 0U, 1U, 2, 1, 11));
        c1_k_u = c1_lam1;
        c1_n_y = NULL;
        sf_mex_assign(&c1_n_y, sf_mex_create(&c1_k_u, "y", 0, 0U, 0U, 0));
        c1_c_random = sf_mex_call("random", 1U, 2U, 14, c1_m_y, 14, c1_n_y);
        c1_c_name = "random";
        sf_mex_import(sf_mex_dup(c1_c_random), c1_c_name, &c1_d1, 0, 0, 0U, 0,
         0);
        c1_o_y = c1_d1;
        sf_mex_destroy(&c1_c_random);
        chartInstance.c1_T1[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T1",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] = c1_o_y;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,40);
        chartInstance.c1_last_t[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_t",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] =
          c1_t;
        /*        disp(['Turining OFF']) */
        goto label_1;
      }
    }
    CV_EML_MCDC(0, 0, false);
    CV_EML_IF(0, 1, false);
    label_1:;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,44);
    if(CV_EML_COND(0, 2, c1_delta[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("delta",
       (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1]
      > chartInstance.c1_T2[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T2",
       (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1])) {
      if(CV_EML_COND(0, 3,
        chartInstance.c1_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i),
         1, 3, 1, 0) - 1] == 0.0)) {
        CV_EML_MCDC(0, 1, true);
        CV_EML_IF(0, 2, true);
        /*  One PU turns on */
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,45);
        c1_y = c1_y + 1.0;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,46);
        chartInstance.c1_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] =
          1.0;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,47);
        for(c1_i16 = 0; c1_i16 < 11; c1_i16 = c1_i16 + 1) {
          c1_l_u[c1_i16] = c1_cv1[c1_i16];
        }
        c1_p_y = NULL;
        sf_mex_assign(&c1_p_y, sf_mex_create(&c1_l_u, "y", 8, 0U, 1U, 2, 1, 11));
        c1_m_u = c1_lam1;
        c1_q_y = NULL;
        sf_mex_assign(&c1_q_y, sf_mex_create(&c1_m_u, "y", 0, 0U, 0U, 0));
        c1_d_random = sf_mex_call("random", 1U, 2U, 14, c1_p_y, 14, c1_q_y);
        c1_d_name = "random";
        sf_mex_import(sf_mex_dup(c1_d_random), c1_d_name, &c1_d2, 0, 0, 0U, 0,
         0);
        c1_r_y = c1_d2;
        sf_mex_destroy(&c1_d_random);
        chartInstance.c1_T2[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T2",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] = c1_r_y;
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,48);
        chartInstance.c1_last_t[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_t",
         (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] =
          c1_t;
        /*        disp(['Turining ON']) */
        goto label_2;
      }
    }
    CV_EML_MCDC(0, 1, false);
    CV_EML_IF(0, 2, false);
    label_2:;
    c1_b_i = c1_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }
  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-48);
  sf_debug_symbol_scope_pop();
  *c1_s_y = c1_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_sldemo_tank1MachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_g_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i17;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i17 = 0; c1_i17 < 3; c1_i17 = c1_i17 + 1) {
    c1_b_u[c1_i17] = (*((real_T (*)[3])c1_u))[c1_i17];
  }
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_h_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_i_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i18;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i18 = 0; c1_i18 < 3; c1_i18 = c1_i18 + 1) {
    c1_b_u[c1_i18] = (*((real_T (*)[3])c1_u))[c1_i18];
  }
  c1_b_y = NULL;
  if(!chartInstance.c1_last_t_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  }
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_j_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i19;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i19 = 0; c1_i19 < 3; c1_i19 = c1_i19 + 1) {
    c1_b_u[c1_i19] = (*((real_T (*)[3])c1_u))[c1_i19];
  }
  c1_b_y = NULL;
  if(!chartInstance.c1_last_y_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  }
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_k_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i20;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i20 = 0; c1_i20 < 3; c1_i20 = c1_i20 + 1) {
    c1_b_u[c1_i20] = (*((real_T (*)[3])c1_u))[c1_i20];
  }
  c1_b_y = NULL;
  if(!chartInstance.c1_T1_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  }
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_l_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i21;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i21 = 0; c1_i21 < 3; c1_i21 = c1_i21 + 1) {
    c1_b_u[c1_i21] = (*((real_T (*)[3])c1_u))[c1_i21];
  }
  c1_b_y = NULL;
  if(!chartInstance.c1_T2_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  }
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_sldemo_tank1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[49];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i22;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for(c1_i22 = 0; c1_i22 < 49; c1_i22 = c1_i22 + 1) {
    c1_r0 = &c1_info[c1_i22];
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
     "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c1_r0->name)), "name",
     "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved",
     "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i22);
  }
  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[49])
{
  c1_info[0].context = "";
  c1_info[0].name = "random";
  c1_info[0].dominantType = "char";
  c1_info[0].resolved = "[M]$matlabroot$/toolbox/stats/random.m";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[1].name = "not";
  c1_info[1].dominantType = "logical";
  c1_info[1].resolved = "[B]not";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[2].name = "eml_check_dim";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[2].fileLength = 1470U;
  c1_info[2].fileTime1 = 1177099718U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c1_info[3].name = "plus";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]plus";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c1_info[4].name = "isvector";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c1_info[4].fileLength = 284U;
  c1_info[4].fileTime1 = 1160446706U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[5].name = "double";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]double";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c1_info[6].name = "ndims";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c1_info[6].fileLength = 236U;
  c1_info[6].fileTime1 = 1163970776U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[7].name = "nargout";
  c1_info[7].dominantType = "";
  c1_info[7].resolved = "[B]nargout";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "";
  c1_info[8].name = "sum";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[8].fileLength = 2616U;
  c1_info[8].fileTime1 = 1163970698U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[9].name = "intmax";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[9].fileLength = 1575U;
  c1_info[9].fileTime1 = 1160446696U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[10].name = "gt";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]gt";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[11].name = "false";
  c1_info[11].dominantType = "";
  c1_info[11].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[11].fileLength = 631U;
  c1_info[11].fileTime1 = 1163970766U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c1_info[12].name = "strcmp";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved = "[B]strcmp";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[13].name = "isreal";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]isreal";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c1_info[14].name = "length";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[14].fileLength = 347U;
  c1_info[14].fileTime1 = 1163970770U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[15].name = "le";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved = "[B]le";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "";
  c1_info[16].name = "ones";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved = "[B]ones";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[17].name = "isscalar";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c1_info[17].fileLength = 243U;
  c1_info[17].fileTime1 = 1160446704U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c1_info[18].name = "isa";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c1_info[18].fileLength = 791U;
  c1_info[18].fileTime1 = 1160446618U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[19].name = "eq";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]eq";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[20].name = "eml_index_class";
  c1_info[20].dominantType = "";
  c1_info[20].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[20].fileLength = 953U;
  c1_info[20].fileTime1 = 1160446742U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[21].name = "true";
  c1_info[21].dominantType = "";
  c1_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[21].fileLength = 625U;
  c1_info[21].fileTime1 = 1163970786U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[22].name = "isinteger";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c1_info[22].fileLength = 254U;
  c1_info[22].fileTime1 = 1160446620U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[23].name = "logical";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[B]logical";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[24].name = "lt";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[B]lt";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c1_info[25].name = "all";
  c1_info[25].dominantType = "logical";
  c1_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[25].fileLength = 2066U;
  c1_info[25].fileTime1 = 1166598650U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[26].name = "int32";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]int32";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[27].name = "isnumeric";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c1_info[27].fileLength = 250U;
  c1_info[27].fileTime1 = 1160446622U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "";
  c1_info[28].name = "disp";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved = "[MB]$matlabroot$/toolbox/matlab/lang/disp";
  c1_info[28].fileLength = 0U;
  c1_info[28].fileTime1 = 0U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c1_info[29].name = "floor";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[29].fileLength = 595U;
  c1_info[29].fileTime1 = 1163970736U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[30].name = "eml_assert";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved = "[B]eml_assert";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[31].name = "eml_nonsingleton_dim";
  c1_info[31].dominantType = "logical";
  c1_info[31].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c1_info[31].fileLength = 454U;
  c1_info[31].fileTime1 = 1160446750U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c1_info[32].name = "eml_numel";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c1_info[32].fileLength = 278U;
  c1_info[32].fileTime1 = 1163970802U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[33].name = "ischar";
  c1_info[33].dominantType = "char";
  c1_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c1_info[33].fileLength = 244U;
  c1_info[33].fileTime1 = 1160446834U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c1_info[34].name = "eml_is_float_class";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[34].fileLength = 273U;
  c1_info[34].fileTime1 = 1160446744U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[35].name = "isempty";
  c1_info[35].dominantType = "logical";
  c1_info[35].resolved = "[B]isempty";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[36].name = "ge";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]ge";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c1_info[37].name = "cast";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[37].fileLength = 907U;
  c1_info[37].fileTime1 = 1160446618U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c1_info[38].name = "size";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]size";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "";
  c1_info[39].name = "zeros";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]zeros";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c1_info[40].name = "class";
  c1_info[40].dominantType = "char";
  c1_info[40].resolved = "[B]class";
  c1_info[40].fileLength = 0U;
  c1_info[40].fileTime1 = 0U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "";
  c1_info[41].name = "minus";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[B]minus";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context = "";
  c1_info[42].name = "mtimes";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[B]mtimes";
  c1_info[42].fileLength = 0U;
  c1_info[42].fileTime1 = 0U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[43].name = "isequal";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[43].fileLength = 2071U;
  c1_info[43].fileTime1 = 1163970770U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c1_info[44].name = "eml_is_integer_class";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c1_info[44].fileLength = 462U;
  c1_info[44].fileTime1 = 1160446744U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[45].name = "islogical";
  c1_info[45].dominantType = "logical";
  c1_info[45].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/islogical.m";
  c1_info[45].fileLength = 186U;
  c1_info[45].fileTime1 = 1160446622U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[46].name = "nargin";
  c1_info[46].dominantType = "";
  c1_info[46].resolved = "[B]nargin";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c1_info[47].name = "numel";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]numel";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c1_info[48].name = "ne";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[B]ne";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_sldemo_tank1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3960841800U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(219284903U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2142974343U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2360974828U);
}

mxArray *sf_c1_sldemo_tank1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(462823305U);
    pr[1] = (double)(1367902832U);
    pr[2] = (double)(1116264811U);
    pr[3] = (double)(2660375856U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
 fullDebuggerInitialization)
{
  if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_sldemo_tank1MachineNumber_,
         1,
         1,
         1,
         3,
         0,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_sldemo_tank1MachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_sldemo_tank1MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_sldemo_tank1MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,c1_c_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0,c1_sf_marshall);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"H",0,c1_b_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,0,1,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1296);
        _SFD_CV_INIT_EML_IF(0,0,399,417,-1,637);
        _SFD_CV_INIT_EML_IF(0,1,888,927,-1,1085);
        _SFD_CV_INIT_EML_IF(0,2,1095,1134,-1,1290);
        _SFD_CV_INIT_EML_FOR(0,0,874,884,1294);
        {
          static int condStart[] = {892,914};
          static int condEnd[] = {908,926};
          static int pfixExpr[] = {0,1,-3};
          _SFD_CV_INIT_EML_MCDC(0,0,891,927,2,0,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {1099,1121};
          static int condEnd[] = {1115,1133};
          static int pfixExpr[] = {0,1,-3};
          _SFD_CV_INIT_EML_MCDC(0,1,1098,1134,2,2,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }

        {
          real_T *c1_y;
          real_T *c1_t;
          real_T *c1_H;
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c1_H = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_H);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_sldemo_tank1MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_sldemo_tank1(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_sldemo_tank1();
  initialize_c1_sldemo_tank1();
}

static void sf_opaque_enable_c1_sldemo_tank1(void *chartInstanceVar)
{
  enable_c1_sldemo_tank1();
}

static void sf_opaque_disable_c1_sldemo_tank1(void *chartInstanceVar)
{
  disable_c1_sldemo_tank1();
}

static void sf_opaque_gateway_c1_sldemo_tank1(void *chartInstanceVar)
{
  sf_c1_sldemo_tank1();
}

static void sf_opaque_terminate_c1_sldemo_tank1(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c1_sldemo_tank1();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_sldemo_tank1(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c1_sldemo_tank1();
  }
}

static void mdlSetWorkWidths_c1_sldemo_tank1(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("sldemo_tank1",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("sldemo_tank1",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"sldemo_tank1",1,2);
      sf_mark_chart_reusable_outputs(S,"sldemo_tank1",1,1);
    }
    sf_set_rtw_dwork_info(S,"sldemo_tank1",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1684531858U));
  ssSetChecksum1(S,(722747203U));
  ssSetChecksum2(S,(4236119574U));
  ssSetChecksum3(S,(3117240851U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_sldemo_tank1(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "sldemo_tank1", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_sldemo_tank1(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_sldemo_tank1;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_sldemo_tank1;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_sldemo_tank1;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_sldemo_tank1;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_sldemo_tank1;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_sldemo_tank1;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_sldemo_tank1;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_sldemo_tank1;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
  chart_debug_initialization(S,1);
}

void c1_sldemo_tank1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_sldemo_tank1(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_sldemo_tank1(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_sldemo_tank1(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_sldemo_tank1_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

