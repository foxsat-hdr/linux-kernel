/* gcclib.h -- definitions for various functions 'borrowed' from gcc-2.95.3 */
/* I Molton     29/07/01 */

#include <linux/config.h>

#define BITS_PER_UNIT  8
#define SI_TYPE_SIZE (sizeof (SItype) * BITS_PER_UNIT)

typedef unsigned int UQItype    __attribute__ ((mode (QI)));
typedef          int SItype     __attribute__ ((mode (SI)));
typedef unsigned int USItype    __attribute__ ((mode (SI)));
typedef          int DItype     __attribute__ ((mode (DI)));
typedef          int word_type 	__attribute__ ((mode (__word__)));
typedef unsigned int UDItype    __attribute__ ((mode (DI)));

#ifdef CONFIG_CPU_LITTLE_ENDIAN
  struct DIstruct {SItype low, high;};
#else
  struct DIstruct {SItype high, low;};
#endif

typedef union
{
  struct DIstruct s;
  DItype ll;
} DIunion;

