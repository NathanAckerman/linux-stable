#include "../kernel/sched/sched.h"
#include "CntrDef.h"

asmlinkage long sys_balance_cntr(struct Pid_and_wasted_cycles worst_procs_all_cpus[][HISTORY_SIZE_CNTR]);


void getWastedCycleInfo(struct Pid_and_wasted_cycles worst_procs_all_cpus[][HISTORY_SIZE_CNTR]){
	printk(KERN_INFO "cntr syscall in kernel");
	int i;
	for(i = 0; i < NUM_CPUS_CNTR; i++){
		printk(KERN_INFO "cntr grabbing info from rq %d", i);
		struct rq *the_rq = cpu_rq(i);
		int j;
		for(j = 0; j < HISTORY_SIZE_CNTR; j++){
			worst_procs_all_cpus[i][j].pid = the_rq->worst_procs[j].pid;
			worst_procs_all_cpus[i][j].wasted_cycles = the_rq->worst_procs[j].wasted_cycles;
		}
	}
}
