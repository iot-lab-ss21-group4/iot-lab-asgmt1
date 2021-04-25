// #define RUN_POLL_BUTTON
#ifdef RUN_POLL_BUTTON
#include "poll_button.h"
#else
#include "led_task.h"
#endif

void app_main(void)
{
#ifdef RUN_POLL_BUTTON
	setup_poll_button();
#else
	setup_led_task();
#endif

	while (1)
	{
#ifdef RUN_POLL_BUTTON
		loop_poll_button();
#else
		loop_led_task();
#endif
	}
}
