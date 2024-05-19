/* Local header files */
#include "libraries.h"
#include "gameplay.h"
#include "game_states.h"

int main(void)
{
	irqInit();
	irqEnable(IRQ_VBLANK);
	
	/* Set GBA to Mode 3 */
	SetMode(MODE_3 | BG2_ON);

	MainMenu();
	return 0;
}