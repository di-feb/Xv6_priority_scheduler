// implements a similar function to the ps command in Linux,
// i.e. it will show information about active processes in xv6

#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
#include "kernel/pstat.h"
// number of elements in fixed-size array
#define NELEM(x) (sizeof(x)/sizeof((x)[0]))
int 
main(){

  static char *states[] = {
  [USED]      "used",
  [SLEEPING]  "sleep ",
  [RUNNABLE]  "runble",
  [RUNNING]   "run   ",
  [ZOMBIE]    "zombie"
  };
  char *state;

  // Create a new struct pstat 
  struct pstat pstat;

  // Call getpinfo to fill the struct pstat
  // with the information of active processes
  // If getpinfo fails, print an error message and exit
  if(getpinfo(&pstat) == -1){
    printf("Error: getpinfo failed\n");
    exit(1);
  }
  printf("PID\tPPID\tSTATE\tSIZE\tPRIORITY\n");

  for(int i = 0; i < NPROC; i++){
    if(pstat.pid[i] == -1)
      continue;
    if(pstat.state[i] >= 0 && pstat.state[i] < NELEM(states) && states[pstat.state[i]])
      state = states[pstat.state[i]];
    else
      state = "???";
    printf("%d\t%d\t%s\t%d\t%d", pstat.pid[i], pstat.ppid[i], state, pstat.sz[i], pstat.priority[i]);
    printf("\n");
  }

  exit(0);
}
