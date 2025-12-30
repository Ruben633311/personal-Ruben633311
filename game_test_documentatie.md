# Doel
Beschrijf hier het doel van je test.

# Succes criteria
Beschrijf hier wanneer je test geslaagd is. Dit is vaak mooi in een tabel:
Het is heel belangrijk dat de gemeten waardes in stabiele condities zo min mogelijk van elkaar afwijken en dat de metingen snel op een grafiek zichtbaar zijn. Ook moet de testopstelling zo min mogelijk wilde metingen hebben en heel kleine veranderingen kunnen opnemen in de grafiek. Ook moet de testopstelling in normale omstandigheden zoals 5 of 20 graden celsius kunnen werken.

| # | Test Aspect | Success Criterion   | Pass/Fail Threshold |
|---|-------------|---------------------|---------------------|
| 1 | Munt oppakken | Kan de munt door de speler opgepakt  worden | pass als de munt opgepakt kan worden door de speler |
| 2 | Geraakt worden door projectiel | kan het projectiel tegen de speler botsen | pass als het projectiel tegen de speler kan botsen |
| 3 | Geraakt worden door enemy | kan de enemy tegen de speler botsen | pass als de enemy tegen de speler kan botsen |
| 4 | Beweging | kunnen vijf knoppen gebruikt worden voor beweging | pass als met de juiste knoppen in alle richtingen bewogen kan worden en als de ability knop een soort dash is |
| 5 | Levens | game over komt op het scherm als de speler drie keer geraakt is | pass als game over gebeurt als de levens op zijn |
| 6 | Onkwetsbaarheid | onkwetsbaarheid bij geraakt worden door projectiel of enemy | pass als de onkwetsbaarheid drie seconden duurt en als geen levens er af kunnen gaan tijdens die tijd |
| 7 | Projectielen spawnen | projectielen komen vanaf buitenkant van het scherm en vanaf de enemies op het scherm | fail als projectielen vanaf de binnenkant van het scherm gespawnd worden en niet bij enemies |
| 8 | Levens sprites | drie levens zijn zichtbaar aan het begin van het spel | pass als drie levens zichtbaar zijn en weggaan als de speler geraakt is |
| 9 | Score | score wordt zichtbaar op het scherm bijgehouden | pass als score zichtbaar is op het scherm en de score omhoog gaat als een munt opgepakt is |

# Test setup & condities
<!-- Beschrijving van alle spullen die je nodig hebt voor de test, maar ook bv test condities (het mag niet warmer zijn dan 30 graden, etc). 
bv: -->
Voor de test zijn de volgende spullen nodig:
- Laptop
- self-made Board with five buttons 
- ESP CYD
- Jumper wires
- USB draad voor verbinding met CYD
- pcf8574
  
Het mag niet warmer zijn dan 30 graden celsius en er mag geen water bij de opstelling komen. 

Filmpje van de testopstelling met jumperwires, een pcf8574 en het USB draad:
<video controls src="VID20251208140155.mp4" title="Title"></video>

# Stappenplan / test scenario
Test opstelling opzetten
1) Sluit de ESP aan op de USB aansluiting van je laptop.
2) Start een terminal en run de command cd (plek van de map die je wilt runnen).
3) Run de command idf.py flash monitor.

Test 1
1) Beweeg de speler totdat de sprite tegen een munt aankomt.
2) De speler komt tegen de munt aan.
3) De munt verdwijnt en komt terug op een andere plek, dan werkt het goed.

Test 2
1) Beweeg de speler zodat hij dichtbij een projectiel komt.
2) De speler komt tegen een projectiel aan.
3) Het projectiel verdwijnt en de speler wordt kort onkwetsbaar en een leven verdwijnt, dan werkt het goed.

Test 3
1) Beweeg de speler zodat hij dichtbij een enemy komt.
2) De speler komt tegen een enemy aan.
3) De enemy verdwijnt en de speler wordt kort onkwetsbaar en een leven verdwijnt, dan werkt het goed.

Test 4
1) Druk de knop bovenin, als je naar boven beweegt is het goed.
2) Druk de knop recht, als je naar rechts beweegt is het goed.
3) Druk de knop onderin, als je naar beneden beweegt is het goed.
4) Druk de knop links, als je naar links beweegt is het goed.
5) Druk de knop aan de linkerkant, als je een soort dash doet in de richting dat je aan het bewegen was dan is het goed.

Test 5
1) Beweeg de speler zodat hij dichtbij een enemy of projectiel komt.
2) Laat de speler drie keer geraakt worden.
3) Game over komt op het scherm te staan, dan is het goed.

Test 6
1) Beweeg de speler zodat hij tegen een enemy of projectiel komt.
2) Beweeg de speler binnen drie seconden zodat hij nog een keer tegen een enemy of projectiel komt.
3) Als de tweede keer tijdens onkwetsbaarheid geen leven verloren is, werkt het goed.

Test 7
1) Kijk of de projectielen netjes aan dde buitenkant van het scherm naar binnen bewegen en niet ergens op het veld van het scherm uit het niets gespawnd wordt.
2) Kijk ook of de projectielen van een enemy netjes in de enemy worden gespawnd en van de enemy af bewegen, niet dat het projectiel van de enemy naast de enemy wordt gespawnd. Als deze dingen goed lijken te spawnen werkt het goed.

Test 8
1) Kijk rond de bovenkant van het scherm.
2) Er moeten drie hart sprites zijn.
3) Beweeg de speler zodat hij tegen een enemy of projectiel komt.
4) Als één hart sprite verdwijnt dan werkt het goed.

Test 9
1) Kijk rond de bovenkant van het scherm.
2) Er moet score in text aanwezig zijn met een getal
3) Als een munt opgepakt is en het getal bij score gaat één omhoog, dan werkt het goed. 

# Verwachte resultaten
Ik verwacht dat de resultaten van alle tests goed uitkomen, want als dit zo is dan werkt de game functionaliteit goed en zou het leuk moeten zijn om te spelen. 