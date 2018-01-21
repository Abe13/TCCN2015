/* Include files */
#include "sldemo_tank1_sfun.h"
#include "c2_sldemo_tank1.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "sldemo_tank1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_sldemo_tank1InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_sldemo_tank1(void);
static void initialize_params_c2_sldemo_tank1(void);
static void enable_c2_sldemo_tank1(void);
static void disable_c2_sldemo_tank1(void);
static void finalize_c2_sldemo_tank1(void);
static void sf_c2_sldemo_tank1(void);
static void c2_c2_sldemo_tank1(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[49]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_sldemo_tank1(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_last_t_not_empty = false;
  chartInstance.c2_last_y_not_empty = false;
  chartInstance.c2_T1_not_empty = false;
  chartInstance.c2_T2_not_empty = false;
  chartInstance.c2_is_active_c2_sldemo_tank1 = 0U;
}

static void initialize_params_c2_sldemo_tank1(void)
{
}

static void enable_c2_sldemo_tank1(void)
{
}

static void disable_c2_sldemo_tank1(void)
{
}

static void finalize_c2_sldemo_tank1(void)
{
}

static void sf_c2_sldemo_tank1(void)
{
  uint8_T c2_previousEvent;
  real_T *c2_y;
  real_T *c2_t;
  real_T *c2_H;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_H = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_t, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_H, 0U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_sldemo_tank1();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_sldemo_tank1MachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c2_c2_sldemo_tank1(void)
{
  real_T c2_t;
  real_T c2_H;
  real_T c2_i;
  real_T c2_delta[5];
  real_T c2_N;
  real_T c2_lam2;
  real_T c2_lam1;
  real_T c2_hilim;
  real_T c2_y;
  int32_T c2_i0;
  static char c2_cv0[10] = { 'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e' };
  char c2_u[10];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  static char c2_cv1[11] = { 'e', 'x', 'p', 'o', 'n', 'e', 'n', 't', 'i', 'a',
    'l' };
  char c2_b_u[11];
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_random;
  char *c2_name;
  real_T c2_dv0[5];
  int32_T c2_i6;
  real_T c2_g_y[5];
  int32_T c2_i7;
  int32_T c2_i8;
  char c2_f_u[11];
  const mxArray *c2_h_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_k_y = NULL;
  const mxArray *c2_b_random;
  char *c2_b_name;
  real_T c2_dv1[5];
  int32_T c2_i9;
  real_T c2_l_y[5];
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_x[5];
  int32_T c2_i12;
  real_T c2_b_x[5];
  real_T c2_c_x;
  int32_T c2_i13;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_d_x;
  real_T c2_r;
  int32_T c2_i14;
  real_T c2_d0;
  real_T c2_b_i;
  int32_T c2_i15;
  char c2_j_u[11];
  const mxArray *c2_m_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_n_y = NULL;
  const mxArray *c2_c_random;
  char *c2_c_name;
  real_T c2_d1;
  real_T c2_o_y;
  int32_T c2_i16;
  char c2_l_u[11];
  const mxArray *c2_p_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_q_y = NULL;
  const mxArray *c2_d_random;
  char *c2_d_name;
  real_T c2_d2;
  real_T c2_r_y;
  int32_T c2_i17;
  real_T *c2_b_t;
  real_T *c2_b_H;
  real_T *c2_s_y;
  c2_s_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_H = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c2_t = *c2_b_t;
  c2_H = *c2_b_H;
  sf_debug_symbol_scope_push(13U, 0U);
  sf_debug_symbol_scope_add("T2", &chartInstance.c2_T2, c2_m_sf_marshall);
  sf_debug_symbol_scope_add("T1", &chartInstance.c2_T1, c2_l_sf_marshall);
  sf_debug_symbol_scope_add("last_y", &chartInstance.c2_last_y,
   c2_k_sf_marshall);
  sf_debug_symbol_scope_add("last_t", &chartInstance.c2_last_t,
   c2_j_sf_marshall);
  sf_debug_symbol_scope_add("i", &c2_i, c2_i_sf_marshall);
  sf_debug_symbol_scope_add("delta", &c2_delta, c2_h_sf_marshall);
  sf_debug_symbol_scope_add("N", &c2_N, c2_g_sf_marshall);
  sf_debug_symbol_scope_add("lam2", &c2_lam2, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("lam1", &c2_lam1, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("hilim", &c2_hilim, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("H", &c2_H, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("t", &c2_t, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /* TIMEAVG Compute time average of input signal U. */
  /*    Y = TIMEAVG(U,T) computes the time average of U, */
  /*    where T is the current simulation time. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c2_hilim = 10000.0;
  /*  hilimit */
  /*  Declare variables that must retain values between iterations. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c2_lam1 = 5.0;
  /* On parameter */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c2_lam2 = 1.0;
  /* Off parameter */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  c2_N = 5.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
  if(CV_EML_IF(0, 0, !chartInstance.c2_last_t_not_empty)) {
    /*  number of SUs */
    /*  Initialize persistent variables in the first iteration. */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
    for(c2_i0 = 0; c2_i0 < 10; c2_i0 = c2_i0 + 1) {
      c2_u[c2_i0] = c2_cv0[c2_i0];
    }
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create(&c2_u, "y", 8, 0U, 1U, 2, 1, 10));
    sf_mex_call("disp", 0U, 1U, 14, c2_b_y);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
    for(c2_i1 = 0; c2_i1 < 5; c2_i1 = c2_i1 + 1) {
      chartInstance.c2_last_y[c2_i1] = 0.0;
    }
    chartInstance.c2_last_y_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
    for(c2_i2 = 0; c2_i2 < 5; c2_i2 = c2_i2 + 1) {
      chartInstance.c2_last_t[c2_i2] = 0.0;
    }
    chartInstance.c2_last_t_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    for(c2_i3 = 0; c2_i3 < 5; c2_i3 = c2_i3 + 1) {
      chartInstance.c2_T1[c2_i3] = 0.0;
    }
    chartInstance.c2_T1_not_empty = true;
    /*  ON time */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,21);
    for(c2_i4 = 0; c2_i4 < 5; c2_i4 = c2_i4 + 1) {
      chartInstance.c2_T2[c2_i4] = 0.0;
    }
    chartInstance.c2_T2_not_empty = true;
    /*  OFF Time */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
    for(c2_i5 = 0; c2_i5 < 11; c2_i5 = c2_i5 + 1) {
      c2_b_u[c2_i5] = c2_cv1[c2_i5];
    }
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create(&c2_b_u, "y", 8, 0U, 1U, 2, 1, 11));
    c2_c_u = c2_lam1;
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create(&c2_c_u, "y", 0, 0U, 0U, 0));
    c2_d_u = c2_N;
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create(&c2_d_u, "y", 0, 0U, 0U, 0));
    c2_e_u = 1.0;
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create(&c2_e_u, "y", 0, 0U, 0U, 0));
    c2_random = sf_mex_call("random", 1U, 4U, 14, c2_c_y, 14, c2_d_y, 14,
     c2_e_y, 14, c2_f_y);
    c2_name = "random";
    sf_mex_import(sf_mex_dup(c2_random), c2_name, &c2_dv0, 1, 0, 0U, 1, 1, 5);
    for(c2_i6 = 0; c2_i6 < 5; c2_i6 = c2_i6 + 1) {
      c2_g_y[c2_i6] = c2_dv0[c2_i6];
    }
    sf_mex_destroy(&c2_random);
    for(c2_i7 = 0; c2_i7 < 5; c2_i7 = c2_i7 + 1) {
      chartInstance.c2_T1[c2_i7] = c2_g_y[c2_i7];
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
    for(c2_i8 = 0; c2_i8 < 11; c2_i8 = c2_i8 + 1) {
      c2_f_u[c2_i8] = c2_cv1[c2_i8];
    }
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create(&c2_f_u, "y", 8, 0U, 1U, 2, 1, 11));
    c2_g_u = c2_lam1;
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create(&c2_g_u, "y", 0, 0U, 0U, 0));
    c2_h_u = c2_N;
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create(&c2_h_u, "y", 0, 0U, 0U, 0));
    c2_i_u = 1.0;
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create(&c2_i_u, "y", 0, 0U, 0U, 0));
    c2_b_random = sf_mex_call("random", 1U, 4U, 14, c2_h_y, 14, c2_i_y, 14,
     c2_j_y, 14, c2_k_y);
    c2_b_name = "random";
    sf_mex_import(sf_mex_dup(c2_b_random), c2_b_name, &c2_dv1, 1, 0, 0U, 1, 1,
     5);
    for(c2_i9 = 0; c2_i9 < 5; c2_i9 = c2_i9 + 1) {
      c2_l_y[c2_i9] = c2_dv1[c2_i9];
    }
    sf_mex_destroy(&c2_b_random);
    for(c2_i10 = 0; c2_i10 < 5; c2_i10 = c2_i10 + 1) {
      chartInstance.c2_T2[c2_i10] = c2_l_y[c2_i10];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
  for(c2_i11 = 0; c2_i11 < 5; c2_i11 = c2_i11 + 1) {
    c2_x[c2_i11] = chartInstance.c2_last_y[c2_i11];
  }
  for(c2_i12 = 0; c2_i12 < 5; c2_i12 = c2_i12 + 1) {
    c2_b_x[c2_i12] = c2_x[c2_i12];
  }
  c2_c_x = c2_b_x[0];
  c2_y = c2_c_x;
  c2_i13 = 2;
  for(c2_k = c2_i13; c2_k < 6; c2_k = c2_k + 1) {
    c2_b_k = c2_k;
    c2_d_x = c2_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
     _SFD_INTEGER_CHECK("k", (real_T)c2_b_k), 1, 5, 1, 0) - 1];
    c2_r = c2_d_x;
    c2_y = c2_y + c2_r;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
  for(c2_i14 = 0; c2_i14 < 5; c2_i14 = c2_i14 + 1) {
    c2_delta[c2_i14] = c2_t - chartInstance.c2_last_t[c2_i14];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
  if(CV_EML_IF(0, 1, c2_H < c2_hilim)) {
    /* disp(['t= ',num2str(t),', last_t= ',num2str(last_t),', delta= ',num2str(delta),', T1= ', num2str(T1),', y= ',num2str(y)... */
    /*     ,', delta > T1= ',num2str(delta > T1)]) */
    /*  Compute the outputs. */
    c2_d0 = 1.0;
    c2_i = c2_d0;
    c2_b_i = c2_d0;
    while(c2_b_i <= 5.0) {
      c2_i = c2_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
      if(CV_EML_COND(0, 0,
        c2_delta[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("delta",
         (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1]
        > chartInstance.c2_T1[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T1",
         (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1])) {
        if(CV_EML_COND(0, 1,
          chartInstance.c2_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i),
           1, 5, 1, 0) - 1] == 1.0)) {
          CV_EML_MCDC(0, 0, true);
          CV_EML_IF(0, 2, true);
          /*  One PU turns off */
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,38);
          c2_y = c2_y - 1.0;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
          chartInstance.c2_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] =
            0.0;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,40);
          for(c2_i15 = 0; c2_i15 < 11; c2_i15 = c2_i15 + 1) {
            c2_j_u[c2_i15] = c2_cv1[c2_i15];
          }
          c2_m_y = NULL;
          sf_mex_assign(&c2_m_y, sf_mex_create(&c2_j_u, "y", 8, 0U, 1U, 2, 1,
            11));
          c2_k_u = c2_lam1;
          c2_n_y = NULL;
          sf_mex_assign(&c2_n_y, sf_mex_create(&c2_k_u, "y", 0, 0U, 0U, 0));
          c2_c_random = sf_mex_call("random", 1U, 2U, 14, c2_m_y, 14, c2_n_y);
          c2_c_name = "random";
          sf_mex_import(sf_mex_dup(c2_c_random), c2_c_name, &c2_d1, 0, 0, 0U, 0,
           0);
          c2_o_y = c2_d1;
          sf_mex_destroy(&c2_c_random);
          chartInstance.c2_T1[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T1",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] = c2_o_y;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,41);
          chartInstance.c2_last_t[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_t",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] =
            c2_t;
          /*  disp(['Turining OFF']) */
          goto label_1;
        }
      }
      CV_EML_MCDC(0, 0, false);
      CV_EML_IF(0, 2, false);
      label_1:;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,45);
      if(CV_EML_COND(0, 2,
        c2_delta[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("delta",
         (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1]
        > chartInstance.c2_T2[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T2",
         (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1])) {
        if(CV_EML_COND(0, 3,
          chartInstance.c2_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i),
           1, 5, 1, 0) - 1] == 0.0)) {
          CV_EML_MCDC(0, 1, true);
          CV_EML_IF(0, 3, true);
          /*  One PU turns on */
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,46);
          c2_y = c2_y + 1.0;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,47);
          chartInstance.c2_last_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_y",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] =
            1.0;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,48);
          for(c2_i16 = 0; c2_i16 < 11; c2_i16 = c2_i16 + 1) {
            c2_l_u[c2_i16] = c2_cv1[c2_i16];
          }
          c2_p_y = NULL;
          sf_mex_assign(&c2_p_y, sf_mex_create(&c2_l_u, "y", 8, 0U, 1U, 2, 1,
            11));
          c2_m_u = c2_lam1;
          c2_q_y = NULL;
          sf_mex_assign(&c2_q_y, sf_mex_create(&c2_m_u, "y", 0, 0U, 0U, 0));
          c2_d_random = sf_mex_call("random", 1U, 2U, 14, c2_p_y, 14, c2_q_y);
          c2_d_name = "random";
          sf_mex_import(sf_mex_dup(c2_d_random), c2_d_name, &c2_d2, 0, 0, 0U, 0,
           0);
          c2_r_y = c2_d2;
          sf_mex_destroy(&c2_d_random);
          chartInstance.c2_T2[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("T2",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] = c2_r_y;
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,49);
          chartInstance.c2_last_t[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("last_t",
           (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 5, 1, 0) - 1] =
            c2_t;
          /*  disp(['Turining ON']) */
          goto label_2;
        }
      }
      CV_EML_MCDC(0, 1, false);
      CV_EML_IF(0, 3, false);
      label_2:;
      c2_b_i = c2_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }
    CV_EML_FOR(0, 0, 0);
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,54);
    c2_y = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,55);
    for(c2_i17 = 0; c2_i17 < 5; c2_i17 = c2_i17 + 1) {
      chartInstance.c2_last_y[c2_i17] = 0.0;
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-55);
  sf_debug_symbol_scope_pop();
  *c2_s_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i18;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i18 = 0; c2_i18 < 5; c2_i18 = c2_i18 + 1) {
    c2_b_u[c2_i18] = (*((real_T (*)[5])c2_u))[c2_i18];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 5));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i19;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i19 = 0; c2_i19 < 5; c2_i19 = c2_i19 + 1) {
    c2_b_u[c2_i19] = (*((real_T (*)[5])c2_u))[c2_i19];
  }
  c2_b_y = NULL;
  if(!chartInstance.c2_last_t_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 5));
  }
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i20;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i20 = 0; c2_i20 < 5; c2_i20 = c2_i20 + 1) {
    c2_b_u[c2_i20] = (*((real_T (*)[5])c2_u))[c2_i20];
  }
  c2_b_y = NULL;
  if(!chartInstance.c2_last_y_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 5));
  }
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i21;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i21 = 0; c2_i21 < 5; c2_i21 = c2_i21 + 1) {
    c2_b_u[c2_i21] = (*((real_T (*)[5])c2_u))[c2_i21];
  }
  c2_b_y = NULL;
  if(!chartInstance.c2_T1_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 5));
  }
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i22;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i22 = 0; c2_i22 < 5; c2_i22 = c2_i22 + 1) {
    c2_b_u[c2_i22] = (*((real_T (*)[5])c2_u))[c2_i22];
  }
  c2_b_y = NULL;
  if(!chartInstance.c2_T2_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create(NULL, "y", 0, 0U, 1U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 5));
  }
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_sldemo_tank1_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[49];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i23;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for(c2_i23 = 0; c2_i23 < 49; c2_i23 = c2_i23 + 1) {
    c2_r0 = &c2_info[c2_i23];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i23);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[49])
{
  c2_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[0].name = "gt";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]gt";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[1].name = "double";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]double";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[2].name = "isa";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[2].fileLength = 791U;
  c2_info[2].fileTime1 = 1160446618U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c2_info[3].name = "all";
  c2_info[3].dominantType = "logical";
  c2_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[3].fileLength = 2066U;
  c2_info[3].fileTime1 = 1166598650U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[4].name = "ischar";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c2_info[4].fileLength = 244U;
  c2_info[4].fileTime1 = 1160446834U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[5].name = "int32";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]int32";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "disp";
  c2_info[6].dominantType = "char";
  c2_info[6].resolved = "[MB]$matlabroot$/toolbox/matlab/lang/disp";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[7].name = "eml_check_dim";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[7].fileLength = 1470U;
  c2_info[7].fileTime1 = 1177099718U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "sum";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[8].fileLength = 2616U;
  c2_info[8].fileTime1 = 1163970698U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[9].name = "strcmp";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved = "[B]strcmp";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[10].name = "false";
  c2_info[10].dominantType = "";
  c2_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[10].fileLength = 631U;
  c2_info[10].fileTime1 = 1163970766U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c2_info[11].name = "cast";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[11].fileLength = 907U;
  c2_info[11].fileTime1 = 1160446618U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[12].name = "isscalar";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[12].fileLength = 243U;
  c2_info[12].fileTime1 = 1160446704U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[13].name = "eq";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]eq";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[14].name = "isinteger";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c2_info[14].fileLength = 254U;
  c2_info[14].fileTime1 = 1160446620U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[15].name = "ne";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]ne";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[16].name = "not";
  c2_info[16].dominantType = "logical";
  c2_info[16].resolved = "[B]not";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[17].name = "numel";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]numel";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[18].name = "eml_assert";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved = "[B]eml_assert";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c2_info[19].name = "isvector";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c2_info[19].fileLength = 284U;
  c2_info[19].fileTime1 = 1160446706U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c2_info[20].name = "size";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]size";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[21].name = "nargout";
  c2_info[21].dominantType = "";
  c2_info[21].resolved = "[B]nargout";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "";
  c2_info[22].name = "ones";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]ones";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[23].name = "eml_is_float_class";
  c2_info[23].dominantType = "char";
  c2_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[23].fileLength = 273U;
  c2_info[23].fileTime1 = 1160446744U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c2_info[24].name = "eml_numel";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[24].fileLength = 278U;
  c2_info[24].fileTime1 = 1163970802U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[25].name = "intmax";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[25].fileLength = 1575U;
  c2_info[25].fileTime1 = 1160446696U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[26].name = "le";
  c2_info[26].dominantType = "int32";
  c2_info[26].resolved = "[B]le";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[27].name = "floor";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[27].fileLength = 595U;
  c2_info[27].fileTime1 = 1163970736U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[28].name = "logical";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]logical";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c2_info[29].name = "plus";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]plus";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[30].name = "eml_is_integer_class";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c2_info[30].fileLength = 462U;
  c2_info[30].fileTime1 = 1160446744U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "";
  c2_info[31].name = "mtimes";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]mtimes";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "random";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved = "[M]$matlabroot$/toolbox/stats/random.m";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[33].name = "nargin";
  c2_info[33].dominantType = "";
  c2_info[33].resolved = "[B]nargin";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[34].name = "isempty";
  c2_info[34].dominantType = "logical";
  c2_info[34].resolved = "[B]isempty";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[35].name = "eml_nonsingleton_dim";
  c2_info[35].dominantType = "logical";
  c2_info[35].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[35].fileLength = 454U;
  c2_info[35].fileTime1 = 1160446750U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[36].name = "eml_index_class";
  c2_info[36].dominantType = "";
  c2_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[36].fileLength = 953U;
  c2_info[36].fileTime1 = 1160446742U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[37].name = "length";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[37].fileLength = 347U;
  c2_info[37].fileTime1 = 1163970770U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[38].name = "ge";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved = "[B]ge";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[39].name = "isequal";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[39].fileLength = 2071U;
  c2_info[39].fileTime1 = 1163970770U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context = "";
  c2_info[40].name = "zeros";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[B]zeros";
  c2_info[40].fileLength = 0U;
  c2_info[40].fileTime1 = 0U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "";
  c2_info[41].name = "minus";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved = "[B]minus";
  c2_info[41].fileLength = 0U;
  c2_info[41].fileTime1 = 0U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[42].name = "class";
  c2_info[42].dominantType = "char";
  c2_info[42].resolved = "[B]class";
  c2_info[42].fileLength = 0U;
  c2_info[42].fileTime1 = 0U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[43].name = "isreal";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[B]isreal";
  c2_info[43].fileLength = 0U;
  c2_info[43].fileTime1 = 0U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[44].name = "isnumeric";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[44].fileLength = 250U;
  c2_info[44].fileTime1 = 1160446622U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c2_info[45].name = "ndims";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c2_info[45].fileLength = 236U;
  c2_info[45].fileTime1 = 1163970776U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[46].name = "lt";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved = "[B]lt";
  c2_info[46].fileLength = 0U;
  c2_info[46].fileTime1 = 0U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[47].name = "true";
  c2_info[47].dominantType = "";
  c2_info[47].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[47].fileLength = 625U;
  c2_info[47].fileTime1 = 1163970786U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[48].name = "islogical";
  c2_info[48].dominantType = "logical";
  c2_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/islogical.m";
  c2_info[48].fileLength = 186U;
  c2_info[48].fileTime1 = 1160446622U;
  c2_info[48].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_sldemo_tank1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4161457028U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2722486623U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1374231149U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2735698405U);
}

mxArray *sf_c2_sldemo_tank1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2777332861U);
    pr[1] = (double)(3208809867U);
    pr[2] = (double)(1666163570U);
    pr[3] = (double)(1015019561U);
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
         2,
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

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0,c2_sf_marshall);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"H",0,c2_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,4,0,1,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1430);
        _SFD_CV_INIT_EML_IF(0,0,421,439,-1,659);
        _SFD_CV_INIT_EML_IF(0,1,896,906,1388,1428);
        _SFD_CV_INIT_EML_IF(0,2,929,968,-1,1150);
        _SFD_CV_INIT_EML_IF(0,3,1160,1199,-1,1379);
        _SFD_CV_INIT_EML_FOR(0,0,911,921,1387);
        {
          static int condStart[] = {933,955};
          static int condEnd[] = {949,967};
          static int pfixExpr[] = {0,1,-3};
          _SFD_CV_INIT_EML_MCDC(0,0,932,968,2,0,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {1164,1186};
          static int condEnd[] = {1180,1198};
          static int pfixExpr[] = {0,1,-3};
          _SFD_CV_INIT_EML_MCDC(0,1,1163,1199,2,2,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
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
          real_T *c2_y;
          real_T *c2_t;
          real_T *c2_H;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_H = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_H);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_sldemo_tank1MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_sldemo_tank1(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_sldemo_tank1();
  initialize_c2_sldemo_tank1();
}

static void sf_opaque_enable_c2_sldemo_tank1(void *chartInstanceVar)
{
  enable_c2_sldemo_tank1();
}

static void sf_opaque_disable_c2_sldemo_tank1(void *chartInstanceVar)
{
  disable_c2_sldemo_tank1();
}

static void sf_opaque_gateway_c2_sldemo_tank1(void *chartInstanceVar)
{
  sf_c2_sldemo_tank1();
}

static void sf_opaque_terminate_c2_sldemo_tank1(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_sldemo_tank1();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sldemo_tank1(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_sldemo_tank1();
  }
}

static void mdlSetWorkWidths_c2_sldemo_tank1(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("sldemo_tank1",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("sldemo_tank1",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"sldemo_tank1",2,2);
      sf_mark_chart_reusable_outputs(S,"sldemo_tank1",2,1);
    }
    sf_set_rtw_dwork_info(S,"sldemo_tank1",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1565160115U));
  ssSetChecksum1(S,(1273625509U));
  ssSetChecksum2(S,(3433499669U));
  ssSetChecksum3(S,(2772568380U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_sldemo_tank1(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "sldemo_tank1", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sldemo_tank1(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_sldemo_tank1;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_sldemo_tank1;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_sldemo_tank1;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_sldemo_tank1;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_sldemo_tank1;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_sldemo_tank1;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_sldemo_tank1;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_sldemo_tank1;
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

void c2_sldemo_tank1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sldemo_tank1(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sldemo_tank1(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sldemo_tank1(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_sldemo_tank1_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

