#include <3ds.h>
#include "menu.hpp"

#define TICKS_PER_SEC 268123480.0

int main() {
	gfxInitDefault();
	MenuInit();

	u64 initialHoldTime = svcGetSystemTick();
	u64 intervalTime = initialHoldTime;
	while (aptMainLoop()) {

		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (kDown & KEY_SELECT) break; //stop the app

		//Time calculations for menu scrolling
		if (kHeld & KEY_DDOWN || kHeld & KEY_DUP) {
			float totalHoldTime = (svcGetSystemTick() - initialHoldTime)/TICKS_PER_SEC;
			float intervalElapsedTime = (svcGetSystemTick() - intervalTime)/TICKS_PER_SEC;

			if (intervalElapsedTime > 0.09 && totalHoldTime > 0.4) {
				kDown |= kHeld & (KEY_DUP | KEY_DDOWN); //add input to kDown for simplicity
				intervalTime = svcGetSystemTick();
			}
		} else {
			initialHoldTime = svcGetSystemTick();
		}

		//send inputs off to the menu
		if (kDown)
			MenuUpdate(kDown);

		//launch oot3d directly by holding L and R (cartridge only)
		if (kHeld & KEY_L && kHeld & KEY_R) {
			aptSetChainloader(0x0004000000033500, 2);
			break;
		}

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
