// RTC ticks are good for slow timing (between 1hz and 64hz).
// They are independant of CPU frequency.

#define INT_TICK 0x100
#define SRCPND 0x7100000

int sys_isRTCTick()
{
	// not pending
	if (!(*SRCPND & INT_TICK))
		return 0;
	
	//clear the tick interrupt
	*SRCPND = INT_TICK;
	return 1;
}

int main(void)
{
  puts("works here");
  
  // will stop here!
	while(!sys_isRTCTick());
	
	puts("won't get here");
}
