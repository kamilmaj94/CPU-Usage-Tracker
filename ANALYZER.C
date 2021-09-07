#include "ANALYZER.H"
#include "READER.H"
/*
 * Account guest cpu time to a process.
 * @p: the process that the cpu time gets accounted to
 * @cputime: the cpu time spent in virtual machine since the last update
 * @cputime_scaled: cputime scaled by cpu frequency
 */
static void account_guest_time(struct task_struct *p, cputime_t cputime,
                   cputime_t cputime_scaled)
{
    u64 *cpustat = kcpustat_this_cpu->cpustat;

    /* Add guest time to process. */
    p->utime += cputime;
    p->utimescaled += cputime_scaled;
    account_group_user_time(p, cputime);
    p->gtime += cputime;

    /* Add guest time to cpustat. */
    if (task_nice(p) > 0) {
        cpustat[CPUTIME_NICE] += (__force u64) cputime;
        cpustat[CPUTIME_GUEST_NICE] += (__force u64) cputime;
    } else {
        cpustat[CPUTIME_USER] += (__force u64) cputime;
        cpustat[CPUTIME_GUEST] += (__force u64) cputime;
    }
}


//

//reader_id = account_guest_time(struct???, cput_time???, scale_time???);