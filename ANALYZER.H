#ifndef __ANALYZER_H_INCLUDED__
#define __ANALYZER_H_INCLUDED__
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
 * Account guest cpu time to a process.
 * @p: the process that the cpu time gets accounted to
 * @cputime: the cpu time spent in virtual machine since the last update
 * @cputime_scaled: cputime scaled by cpu frequency
 */
static void account_guest_time(struct task_struct *p, cputime_t cputime, cputime_t cputime_scaled);

#endif