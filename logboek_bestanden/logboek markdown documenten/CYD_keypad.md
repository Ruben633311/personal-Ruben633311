Ik heb bij het maken van de CYD Keypad opdracht de spanningen gemeten als ik elke knop indruk. De spanningen die ik krijg zijn wel wat ik zou verwachten als ik naar de stroomkring van het keypad systeem kijk. Ook moest ik in de code van de main.cpp en de AnalogButtonReader.cpp werken om het weer werkend te krijgen.

Ik heb niet een berekening gedaan welke spanningen ik verwachte als ik elke knop in zou drukken maar ik had wel verwacht dat er een soort incrementele verandering zou zijn tussen de spanningen. 

Ik had vooraf geen berekening gemaakt van de spanningen die ik per knop zou verwachten. Wel ging ik ervan uit dat de spanningen een geleidelijke, incrementele verandering zouden laten zien. De gemeten waarden zijn als volgt:

GEEN: 3,30V  
SELECT: 2,40V  
RIGHT: 1,64V  
DOWN: 1,07V  
UP: 0,47V   
LEFT: 0V  

Ik heb nog een keer naar de resultaten en naar het schema van de keypad gekeken maar dit resultaat klopt niet met het schema. Om de spanning voor RIGHT en LEFT met de spanningsdeler formule te berekenen gebruik je deze formule: Vout = vin × r2 / (r1 + r2). Als RIGHT is ingedrukt is er volgens het schema geen weerstand en als LEFT is ingedrukt is er volgens het schema 1950 ohm aan weerstand. Dit betekend dat er bij het indrukken van RIGHT geen spanningsverschil tussen Vout en GND is, omdat Vout = vin × 0 / (r1 + 0) = 0 en geeft de multimeter 0V. Bij LEFT zou er wel een verschil moeten zijn, omdat er een r2 van 1950 ohm is. Als je 1950 deelt door (2000 + 1950) en dit keer Vin, oftewel 3,3 volt doet is het verschil tussen Vout en GND bijna de helft van 3,3V. Daarom meet de multimeter hier 1,64V. 

Dit betekend dat mijn metingen niet kloppen met het schema hieronder, want als je naar het schema kijkt dan verwacht je dat bij het indrukken van RIGHT geen spanningsverschil is en dat er bij LEFT een spanningsverschil van 1,64 is. Maar wat ik eigenlijk meet is dat het bij RIGHT 1,64V en bij LEFT 0V is dus ik denk dat de RIGHT en LEFT van het schema eigenlijk omgewisseld moeten worden zodat het weer klopt. Mijn metingen heb ik gedaan met de text op de keypad rechtop dus ik ga ervanuit dat dit de goede oriëntatie was om het te meten. 
![alt text](../foto's/keypad%20schema%202025-10-02%20111702.png)
Ik Heb hier alle knoppen ingedrukt en het is heel mooi zichtbaar bij welke ADC waardes de knoppen ingedrukt zijn.
![alt text](../foto's/CYD%20Keypad%202025-09-29%20142709.png)