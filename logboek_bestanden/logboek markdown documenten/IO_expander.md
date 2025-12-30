Bij deze opdracht is het gelukt om de functies te veranderen en de main zo te maken dat ik een 0 terugkrijg in plaats van een -1. Het lukte niet om twee ledjes bij deze opdracht aan te sturen binnen de tijd die ik had. Ik heb alleen voor elkaar kunnen krijgen dat de code zou kunnen werken, maar ik kon geen toepassing met ledjes maken en ik weet niet hoe ik dit zou kunnen doen.

In het manager.cpp bestand heb ik de readregister functie veranderd door een aantal lines weg te halen die probeerden te schrijven naar de chip.
https://github.com/2025-TICT-TV2SE3-24-1-V/personal-Ruben633311/blob/main/I2C/main/I2CManager.cpp

In het manager.hpp bestand heb ik niks veranderd.
https://github.com/2025-TICT-TV2SE3-24-1-V/personal-Ruben633311/blob/main/I2C/main/I2CManager.hpp

In het main.cpp bestand heb ik de hexadecimale waardes van address en data verandert en een readregister functie in de code gezet.
https://github.com/2025-TICT-TV2SE3-24-1-V/personal-Ruben633311/blob/main/I2C/main/main.cpp

Ik heb de opdracht opnieuw gemaakt

Ik heb feedback van Harm gekregen:

Harm Snippe, 25 nov op 16:58

Je zou een extra functie in de klasse moeten aanmaken en dat iets doen als: i2c.databyte(0x20, 0b00000001); om ledje 1 aan te zetten. 
Ga anders eens kijken bij Joni. Hij wil je vast met deze opdracht helpen.

Ik heb deze feedback gebruikt en hulp van groepgenoot Ryan gevraagd om te helpen om werkende code te maken en uiteindelijk was het gelukt. Ik had meerdere knopjes aangesloten met lampjes erachter en kon ik een lampje aanzetten door op het knopje te drukken. 

Ryan had geholpen om mij te laten begrijpen hoe ik de opstelling per lampje moest aansluiten.
dit was een deel van zijn feedback:
VCC ---> resistor ---> LED ---> P0 - P7 (each LED gets its own) 

ik had dit gebruikt om mijn eigen opstelling te maken, maar dan had ik gekozen om het met knoppen te doen.

Toen vroeg ik af of na die pin nog naar de GND moest, maar toen vertelde Ryan dat de pin een soort van GND is en dat hij dus niet na de pin nog naar GND moet.

Zoals hieronder te zien:

Ruben Kroon — 1-12-2025 16:46
nadat de energie door het lampje heen gaat, komt het dus bij zo'n pin, maar moet het daarna niet naar de GND?

Ryan Smit — 1-12-2025 16:47
Je zet de pin op low
niet op high
dus de pin wordt een soort van GND

Ik heb zo geleerd hoe de code wel kan werken en hoe ik het moet aansluiten.