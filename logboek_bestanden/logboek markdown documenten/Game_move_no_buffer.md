Bij deze opdracht heb ik aan Ryan een paar vragen gesteld over hoe de code kan werken zonder buffer. In het MovingRect.cpp en in het main.cpp bestand hoefde ik bijna code te veranderen omdat de beweging hetzelfde moest blijven en er staat geen buffer code in die weggehaald moest worden. In de main.cpp moest ik wel de display.present() lijn weghalen, omdat deze met een buffer werkte en ik moest code maken zonder buffer.

Ik moest in het Display.hpp bestand weer ervoor zorgen dat de functies in de class stonden. In het Display.cpp bestand heb ik code geplakt dat ik ook in het LCD_drawables heb staan voor de eerste opdracht waarin ik de code ging maken om rechthoeken en cirkels te kunnen tekenen. Ik heb deze code gebruikt omdat deze geen buffer gebruikt.

Video van vierkant zonder backbuffer.
<video controls src="without_backbuffer.mp4" title="Title"></video>

Zoals te zien is wordt de vierkant zonder buffer niet in een keer geladen maar wordt het bij elke update van één kant weer steeds opnieuw geladen, als je wilt dat het er mooi uitziet moet je dus een buffer gebruiken.