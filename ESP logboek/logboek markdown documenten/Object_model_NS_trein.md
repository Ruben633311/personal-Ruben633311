Voor het object model NS trein heb ik naar de twee use cases van de opdracht gekeken en daarop gebaseerd hoe ik de objecten noem en wat voor text op de pijltjes moet staan. 

Ik heb aan Marius vragen gesteld over het object model en ik kreeg de volgende feedback: bij het treinverkeersregelcentrum moet er een aparte gps boundary zijn waar het centrum de locatie van de trein vandaan haalt. Bij de text  de pijlen gevaarlijkeSituatieGedetecteerd en obstakelGedetecteerd stond is alsof het een vraag was maar dit klopte niet dus is dit veranderd. Ook kreeg ik de tip om de text op de pijltjes met fn + f2 te zetten zodat het er beter uit ziet. 

![alt text](image-10.png)

| Object Naam | Stereotype | Beschrijving |
--- | --- | ---
| accountgegevens | entity | bevat de accountgegevens van de machinist |
| accountControl | control | de "dirigent" van de use case inlog bijhouden |
| snelheidbeheerControl | control | de "dirigent" van de use case snelheidbeheer |
| treinverkeersregelcentrum | control | de "dirigent" van de use case treinverkeersregels |
| motorControl | control | de "dirigent" van de use case motor besturen|
noodstopMakenControl | control | de "dirigent" van de use case het maken van een noodstop |
snelheidSchuif | boundary | stuurt de schuif hardware aan |
gps | boundary | stuurt de gps hardware aan voor coordinaten |
yellowLedBlink | boundary | stuurt gele LED hardware aan |
redLedBlink | boundary | stuurt rode LED hardware aan |
noodKnop | boundary | stuurt noodKnop hardware aan |
| motor | boundary | stuurt de motor hardware aan |
| display | boundary | stuurt de display hardware aan |
| black box | boundary | bevat de loggegevens van alle voorvallen |
| noodRem | boundary | stuurt de noodRem hardware aan |
| obstakel sensor | boundary | stuurt de obstakel sensor aan |
