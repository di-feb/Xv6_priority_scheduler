# Xv6_priority_scheduler

This project extends the xv6 operating system with :

- A `priority-based round-robin scheduler`
- Two new system calls: `setpriority()` and `getpinfo()`
- A user program, `ps`, that shows information about active processes
- A priority control program, `priotest`, that tests the `setpriority()` system call

## System Calls

### setpriority(int num)

This system call sets the priority of the calling process to `num`. The permissible values for priority range from 1 (highest priority) to 20 (lowest priority). The default priority is 10. If the system call executes successfully, it returns 0; otherwise, it returns -1.

### getpinfo(struct pstat *)

This system call copies information about each active process into a `struct pstat`. The information includes the process ID (pid), parent process ID (ppid), name, priority, status, size, and other necessary details. The `struct pstat` is defined according to `struct proc`. If the system call executes successfully, it returns 0; otherwise, it returns -1.

## User Program: ps

This project includes a user program, `ps`, that shows information about active processes in xv6. It uses the `getpinfo(struct pstat *)` system call to retrieve process information.

## Priority Control Program: priotest

This project also includes a priority control program, `priotest`, which tests the `setpriority()` system call. The corresponding command has been added to the Makefile. Note that `priotest` assumes the `setpriority()` system call exists. To make it compile temporarily, there is a stub function `setpriority()` inside the code, which you should delete when you are going to use it.

## Priority-Based Scheduler

The scheduler in xv6 is implemented in the `priority_rr_scheduler()` function in the `proc.c` file. This function is called by the `main()` function in `main.c` as the last step of initialization. The `priority_rr_scheduler()` function never returns; it continuously schedules the next available process to run.

The scheduler searches all processes for the one that is in the RUNNABLE state and has the highest priority. If there are multiple processes with the same priority, it schedules them in a round-robin manner. It saves the last process and starts from there to search all processes.

## Testing

After completing the task, the kernel should pass all the tests in the `usertests` programs. Run the tests with the following command:

```bash
$ usertests
...
ALL TESTS PASSED
$
```

## Setting up xv6 development environment

### Prerequisites

If you are using a Linux virtual machine (Ubuntu or Debian), you can install the necessary packages by running the following command:

```bash
sudo apt install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

### Getting the xv6 code

This project contains __only__ the files that have been changed.  
Therefore, you need to clone the original xv6 code from the MIT PDOS GitHub repository by running the following command:

```bash
git clone git://github.com/mit-pdos/xv6-riscv.git
```

### xv6 Manual

The xv6 manual can be found at the following URL:

[https://pdos.csail.mit.edu/6.828/2022/xv6/book-riscv-rev3.pdf](https://pdos.csail.mit.edu/6.828/2022/xv6/book-riscv-rev3.pdf)

## Credits

The original xv6 operating system is developed by Frans Kaashoek, Robert Morris, and Russ Cox. You can find the original project [here](https://github.com/mit-pdos/xv6-riscv).