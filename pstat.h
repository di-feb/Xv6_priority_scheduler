// Description: This file contains the structure of the pstat table 
// that is used to store the information of each process in the system.
struct pstat { 
  int pid[NPROC];              // PID of each process
  int ppid[NPROC];             // PID of each process's parent
  int state[NPROC];           // Current state of each process
  int priority[NPROC];         // Priority of each process
  uint64 sz[NPROC];            // Size of each process (bytes)
};
