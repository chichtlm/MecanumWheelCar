#include <rtthread.h>


u64 get_systick_counter(void)
{
    return (u64)SysTick->VAL;
}


long long get_time_stamp(void)
{
    long long time_us = (long long)((72000 - get_systick_counter()) / 72);
    long long time_ms2us = (long long)(g_time_control_clock_overflow * 1000);
    return (time_ms2us+time_us);		// us
}

int main(void)
{
	while(1)
	{
        rt_thread_mdelay(100);        	
	}
	
	return 0;
}