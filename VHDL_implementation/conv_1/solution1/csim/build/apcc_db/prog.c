/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv);
void affiche_input(signed int (*)[32]);
void conv1_1(signed int (*)[32], signed int (*)[5][5], signed int (*)[28][28]);
void avg_pool_1(signed int (*)[28], signed int (*)[14][14]);


/* Global Variable Definitions and Initialization */
static signed int aesl_internal_main_OC_input[32][32] = { { 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 1u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 0u, 1u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u }, { 0u, 1u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u }, { 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u } };
static signed int aesl_internal_main_OC_kernel[4][5][5] = { { { 1u, 0u, 1u, 1u, 0u }, { 0u, 1u, 0u, 0u, 1u }, { 1u, 0u, 1u, 1u, 1u }, { 0u, 0u, 0u, 0u, 1u }, { 0u, 0u, 1u, 1u, 1u } }, { { 0u, 0u, 0u, 0u, 1u }, { 0u, 0u, 1u, 0u, 1u }, { 1u, 0u, 1u, 1u, 1u }, { 0u, 1u, 0u, 0u, 1u }, { 1u, 0u, 1u, 1u, 1u } }, { { 1u, 0u, 0u, 1u, 1u }, { 0u, 1u, 1u, 0u, 1u }, { 1u, 0u, 1u, 1u, 1u }, { 0u, 1u, 1u, 0u, 1u }, { 0u, 0u, 1u, 0u, 0u } }, { { 1u, 0u, 1u, 0u, 1u }, { 0u, 1u, 1u, 0u, 1u }, { 1u, 0u, 1u, 1u, 1u }, { 0u, 1u, 0u, 0u, 1u }, { 0u, 1u, 1u, 0u, 0u } } };
static  char aesl_internal__OC_str2[5] = "  { ";
static  char aesl_internal__OC_str3[5] = "%d, ";
static  char aesl_internal__OC_str4[4] = "%d ";
static  char aesl_internal_str10[3] = "} ";
static  char aesl_internal_str[25] = "Output conv1 ====> : \n{ ";
static  char aesl_internal_str4[5] = " }, ";
static  char aesl_internal_str7[25] = "Output pool1 ====> : \n{ ";
static  char aesl_internal_str8[4] = " { ";
static  char aesl_internal_str9[4] = "}, ";
static  char aesl_internal_str11[4] = " },";
static  char aesl_internal_str12[3] = " }";
static  char aesl_internal_str13[2] = "}";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[32][32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[4][5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[4][28][28];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_P_count = 0;
  signed int llvm_cbe_output_P[4][14][14];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed int (*llvm_cbe_tmp__9)[32];
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  signed int (*llvm_cbe_tmp__10)[5][5];
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  signed int (*llvm_cbe_tmp__11)[28][28];
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge24_count = 0;
  unsigned int llvm_cbe_storemerge24;
  unsigned int llvm_cbe_storemerge24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_puts6_count = 0;
  unsigned int llvm_cbe_puts6;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge423_count = 0;
  unsigned int llvm_cbe_storemerge423;
  unsigned int llvm_cbe_storemerge423__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge522_count = 0;
  unsigned int llvm_cbe_storemerge522;
  unsigned int llvm_cbe_storemerge522__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  signed int *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  signed int *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_exitcond27_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts8_count = 0;
  unsigned int llvm_cbe_puts8;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts7_count = 0;
  unsigned int llvm_cbe_puts7;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_exitcond28_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts10_count = 0;
  unsigned int llvm_cbe_puts10;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts9_count = 0;
  unsigned int llvm_cbe_puts9;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_exitcond29_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts11_count = 0;
  unsigned int llvm_cbe_puts11;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  signed int (*llvm_cbe_tmp__25)[28];
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  signed int (*llvm_cbe_tmp__26)[14][14];
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts12_count = 0;
  unsigned int llvm_cbe_puts12;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge121_count = 0;
  unsigned int llvm_cbe_storemerge121;
  unsigned int llvm_cbe_storemerge121__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_puts13_count = 0;
  unsigned int llvm_cbe_puts13;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge220_count = 0;
  unsigned int llvm_cbe_storemerge220;
  unsigned int llvm_cbe_storemerge220__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge319_count = 0;
  unsigned int llvm_cbe_storemerge319;
  unsigned int llvm_cbe_storemerge319__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  signed int *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts15_count = 0;
  unsigned int llvm_cbe_puts15;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts14_count = 0;
  unsigned int llvm_cbe_puts14;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts17_count = 0;
  unsigned int llvm_cbe_puts17;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts16_count = 0;
  unsigned int llvm_cbe_puts16;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_exitcond26_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts18_count = 0;
  unsigned int llvm_cbe_puts18;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast [32 x [32 x i32]]* %%input to i8*, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__1 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memcpy(i8* %%1, i8* bitcast ([32 x [32 x i32]]* @aesl_internal_main.input to i8*), i64 4096 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__1, ( char *)(( char *)(&aesl_internal_main_OC_input)), 4096ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4096ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast [4 x [5 x [5 x i32]]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__3 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* %%3, i8* bitcast ([4 x [5 x [5 x i32]]]* @aesl_internal_main.kernel to i8*), i64 400 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__3, ( char *)(( char *)(&aesl_internal_main_OC_kernel)), 400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast [4 x [28 x [28 x i32]]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__5 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memset(i8* %%5, i32 0, i64 12544 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_12_count);
  ( char *)memset(( char *)llvm_cbe_tmp__5, 0u, 12544ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",12544ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast [4 x [14 x [14 x i32]]]* %%output_P to i8*, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__7 = ( char *)(( char *)(&llvm_cbe_output_P));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memset(i8* %%7, i32 0, i64 3136 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  ( char *)memset(( char *)llvm_cbe_tmp__7, 0u, 3136ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",3136ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [32 x [32 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__9 = (signed int (*)[32])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @affiche_input([32 x i32]* %%9) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  affiche_input(llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [4 x [5 x [5 x i32]]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__10 = (signed int (*)[5][5])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [4 x [28 x [28 x i32]]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__11 = (signed int (*)[28][28])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @conv1_1([32 x i32]* %%9, [5 x [5 x i32]]* %%10, [28 x [28 x i32]]* %%11) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  conv1_1(llvm_cbe_tmp__9, llvm_cbe_tmp__10, llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([25 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__40;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge24 = phi i32 [ 0, %%0 ], [ %%35, %%34  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge24_count);
  llvm_cbe_storemerge24 = (unsigned int )llvm_cbe_storemerge24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%X",llvm_cbe_storemerge24);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts6 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str8, i64 0, i64 0)), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts6_count);
  puts(( char *)((&aesl_internal_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts6 = 0x%X",llvm_cbe_puts6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%storemerge24 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__12 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge24);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
  llvm_cbe_storemerge423__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__41;

llvm_cbe_tmp__42:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts9 = call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_str4, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts9_count);
  puts(( char *)((&aesl_internal_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts9 = 0x%X",llvm_cbe_puts9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%storemerge24, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if (((llvm_cbe_tmp__24&4294967295U) == (4u&4294967295U))) {
    goto llvm_cbe_tmp__43;
  } else {
    llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe_tmp__40;
  }

llvm_cbe_tmp__44:
  if (((llvm_cbe_storemerge24&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe__2e_thread33;
  } else {
    goto llvm_cbe_tmp__42;
  }

llvm_cbe__2e_thread31:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts8 = call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str10, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts8_count);
  puts(( char *)((&aesl_internal_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts8 = 0x%X",llvm_cbe_puts8);
}
  goto llvm_cbe_tmp__44;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__41:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge423 = phi i32 [ 0, %%12 ], [ %%31, %%30  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge423_count);
  llvm_cbe_storemerge423 = (unsigned int )llvm_cbe_storemerge423__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge423 = 0x%X",llvm_cbe_storemerge423);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%storemerge423 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__14 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge423);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
  llvm_cbe_storemerge522__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__45;

llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts7 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str9, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts7_count);
  puts(( char *)((&aesl_internal_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts7 = 0x%X",llvm_cbe_puts7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge423, 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_storemerge423&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
  if (((llvm_cbe_tmp__23&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__44;
  } else {
    llvm_cbe_storemerge423__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__23;   /* for PHI node */
    goto llvm_cbe_tmp__41;
  }

llvm_cbe_tmp__47:
  if (((llvm_cbe_storemerge423&4294967295U) == (27u&4294967295U))) {
    goto llvm_cbe__2e_thread31;
  } else {
    goto llvm_cbe_tmp__46;
  }

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [4 x [28 x [28 x i32]]]* %%output, i64 0, i64 %%13, i64 %%16, i64 27, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__15 = (signed int *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__12))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )llvm_cbe_tmp__14))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )27ull))
#ifdef AESL_BC_SIM
 % 28
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__12) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__14) < 28)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )27ull) < 28)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i32* %%19, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__16 = (unsigned int )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%20) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__16);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
  goto llvm_cbe_tmp__47;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__45:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge522 = phi i32 [ 0, %%14 ], [ %%27, %%22  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge522_count);
  llvm_cbe_storemerge522 = (unsigned int )llvm_cbe_storemerge522__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge522 = 0x%X",llvm_cbe_storemerge522);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
  if (((llvm_cbe_storemerge522&4294967295U) == (27u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__48;
  }

llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%storemerge522 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge522);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [4 x [28 x [28 x i32]]]* %%output, i64 0, i64 %%13, i64 %%16, i64 %%23, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__19 = (signed int *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__12))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )llvm_cbe_tmp__14))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 28
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__12) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__14) < 28)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__18) < 28)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%24, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 %%25) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_68_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__20);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%storemerge522, 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_storemerge522&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  if (((llvm_cbe_tmp__22&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__47;
  } else {
    llvm_cbe_storemerge522__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__45;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_thread33:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts10 = call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str12, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts10_count);
  puts(( char *)((&aesl_internal_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts10 = 0x%X",llvm_cbe_puts10);
}
  goto llvm_cbe_tmp__43;

llvm_cbe_tmp__43:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts11 = call i32 @puts(i8* getelementptr inbounds ([2 x i8]* @aesl_internal_str13, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts11_count);
  puts(( char *)((&aesl_internal_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts11 = 0x%X",llvm_cbe_puts11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [4 x [28 x [28 x i32]]]* %%output, i64 0, i64 0, i64 0, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__25 = (signed int (*)[28])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [4 x [14 x [14 x i32]]]* %%output_P, i64 0, i64 0, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__26 = (signed int (*)[14][14])(&llvm_cbe_output_P[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @avg_pool_1([28 x i32]* %%37, [14 x [14 x i32]]* %%38) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  avg_pool_1(llvm_cbe_tmp__25, llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts12 = call i32 @puts(i8* getelementptr inbounds ([25 x i8]* @aesl_internal_str7, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts12_count);
  puts(( char *)((&aesl_internal_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts12 = 0x%X",llvm_cbe_puts12);
}
  llvm_cbe_storemerge121__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge121 = phi i32 [ 0, %%36 ], [ %%62, %%61  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge121_count);
  llvm_cbe_storemerge121 = (unsigned int )llvm_cbe_storemerge121__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge121 = 0x%X",llvm_cbe_storemerge121);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts13 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str8, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts13_count);
  puts(( char *)((&aesl_internal_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts13 = 0x%X",llvm_cbe_puts13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%storemerge121 to i64, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__27 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge121);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
  llvm_cbe_storemerge220__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__50;

llvm_cbe_tmp__51:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts16 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str11, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts16_count);
  puts(( char *)((&aesl_internal_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts16 = 0x%X",llvm_cbe_puts16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add nsw i32 %%storemerge121, 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_storemerge121&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
  if (((llvm_cbe_tmp__39&4294967295U) == (4u&4294967295U))) {
    goto llvm_cbe_tmp__52;
  } else {
    llvm_cbe_storemerge121__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__39;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

llvm_cbe_tmp__53:
  if (((llvm_cbe_storemerge121&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe__2e_thread39;
  } else {
    goto llvm_cbe_tmp__51;
  }

llvm_cbe__2e_thread37:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts15 = call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str10, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts15_count);
  puts(( char *)((&aesl_internal_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts15 = 0x%X",llvm_cbe_puts15);
}
  goto llvm_cbe_tmp__53;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge220 = phi i32 [ 0, %%39 ], [ %%58, %%57  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge220_count);
  llvm_cbe_storemerge220 = (unsigned int )llvm_cbe_storemerge220__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge220 = 0x%X",llvm_cbe_storemerge220);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%storemerge220 to i64, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__29 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge220);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
  llvm_cbe_storemerge319__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__54;

llvm_cbe_tmp__55:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts14 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str9, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts14_count);
  puts(( char *)((&aesl_internal_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts14 = 0x%X",llvm_cbe_puts14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%storemerge220, 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(llvm_cbe_storemerge220&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__38&4294967295ull)));
  if (((llvm_cbe_tmp__38&4294967295U) == (14u&4294967295U))) {
    goto llvm_cbe_tmp__53;
  } else {
    llvm_cbe_storemerge220__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__38;   /* for PHI node */
    goto llvm_cbe_tmp__50;
  }

llvm_cbe_tmp__56:
  if (((llvm_cbe_storemerge220&4294967295U) == (13u&4294967295U))) {
    goto llvm_cbe__2e_thread37;
  } else {
    goto llvm_cbe_tmp__55;
  }

llvm_cbe__2e_thread35:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [4 x [14 x [14 x i32]]]* %%output_P, i64 0, i64 %%40, i64 %%43, i64 13, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__30 = (signed int *)(&llvm_cbe_output_P[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )llvm_cbe_tmp__29))
#ifdef AESL_BC_SIM
 % 14
#endif
][(((signed long long )13ull))
#ifdef AESL_BC_SIM
 % 14
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__29));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__27) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__29) < 14)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )13ull) < 14)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i32* %%46, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__31 = (unsigned int )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%47) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__31);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
  goto llvm_cbe_tmp__56;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__54:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge319 = phi i32 [ 0, %%41 ], [ %%54, %%49  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge319_count);
  llvm_cbe_storemerge319 = (unsigned int )llvm_cbe_storemerge319__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge319 = 0x%X",llvm_cbe_storemerge319);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__37);
}
  if (((llvm_cbe_storemerge319&4294967295U) == (13u&4294967295U))) {
    goto llvm_cbe__2e_thread35;
  } else {
    goto llvm_cbe_tmp__57;
  }

llvm_cbe_tmp__57:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%storemerge319 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__33 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge319);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [4 x [14 x [14 x i32]]]* %%output_P, i64 0, i64 %%40, i64 %%43, i64 %%50, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__34 = (signed int *)(&llvm_cbe_output_P[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )llvm_cbe_tmp__29))
#ifdef AESL_BC_SIM
 % 14
#endif
][(((signed long long )llvm_cbe_tmp__33))
#ifdef AESL_BC_SIM
 % 14
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__29));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__33));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__27) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__29) < 14)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__33) < 14)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output_P' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i32* %%51, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__35 = (unsigned int )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 %%52) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_132_count);
  printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__35);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add nsw i32 %%storemerge319, 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(llvm_cbe_storemerge319&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
  if (((llvm_cbe_tmp__37&4294967295U) == (14u&4294967295U))) {
    goto llvm_cbe_tmp__56;
  } else {
    llvm_cbe_storemerge319__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe_tmp__54;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_thread39:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts17 = call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str12, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts17_count);
  puts(( char *)((&aesl_internal_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts17 = 0x%X",llvm_cbe_puts17);
}
  goto llvm_cbe_tmp__52;

llvm_cbe_tmp__52:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts18 = call i32 @puts(i8* getelementptr inbounds ([2 x i8]* @aesl_internal_str13, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts18_count);
  puts(( char *)((&aesl_internal_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts18 = 0x%X",llvm_cbe_puts18);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

