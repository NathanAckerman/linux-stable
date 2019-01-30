#ifndef _CNTR_HEADER_DEFINE_
#define _CNTR_HEADER_DEFINE_

#include <linux/types.h>
struct Pid_and_wasted_cycles{
	pid_t pid;
	long wasted_cycles;
};

#endif


#ifndef _CNTR_HISTORY_SIZE_DEFINE_
#define _CNTR_HISTORY_SIZE_DEFINE_

#define HISTORY_SIZE_CNTR 20
#define NUM_CPUS_CNTR 4

#endif
