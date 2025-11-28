Voor het object model NS trein heb ik naar de twee use cases van de opdracht gekeken en daarop gebaseerd hoe ik de objecten noem en wat voor text op de pijltjes moet staan. 

Ik heb aan Marius vragen gesteld over het object model en ik kreeg de volgende feedback: bij het treinverkeersregelcentrum moet er een aparte gps boundary zijn waar het centrum de locatie van de trein vandaan haalt. Bij de pijlen met de text gevaarlijkeSituatieGedetecteerd en obstakelGedetecteerd stond 'is' ervoor alsof het een vraag was maar dit klopte niet dus is dit veranderd. Ook kreeg ik de tip om de text op de pijltjes met fn + f2 te zetten zodat het er beter uit ziet. 

![alt text](../foto's/object%20model%20NS%20trein%202025-10-01%20134738.png)

| Object Naam | Stereotype | Beschrijving |
--- | --- | ---
| accountgegevens | entity | bevat de accountgegevens van de machinist |
| accountControl | control | de "dirigent" van de use case inlog bijhouden |
| snelheidbeheerControl | control | de "dirigent" van de use case snelheidbeheer |
| treinverkeersregelcentrum | control | de "dirigent" van de use case treinverkeersregels |
| motorControl | control | de "dirigent" van de use case motor besturen|
| noodstopMakenControl | control | de "dirigent" van de use case het maken van een noodstop |
| snelheidSchuif | boundary | stuurt de schuif hardware aan |
| gps | boundary | stuurt de gps hardware aan voor coordinaten |
| yellowLedBlink | boundary | stuurt gele LED hardware aan |
| redLedBlink | boundary | stuurt rode LED hardware aan |
| noodKnop | boundary | stuurt noodKnop hardware aan |
| motor | boundary | stuurt de motor hardware aan |
| display | boundary | stuurt de display hardware aan |
| black box | boundary | bevat de loggegevens van alle voorvallen |
| noodRem | boundary | stuurt de noodRem hardware aan |
| obstakel sensor | boundary | stuurt de obstakel sensor aan |


Tweede les over de NS trein opdracht:
Vandaag heb ik geluisterd naar de uitleg van Marius en op basis van het Design Like a Robot pdf bestand heb ik de volgende twee tabellen gemaakt en ingevuld.

In onderstaand tabel heb ik gekeken naar hoe de taken bij elk object er uit zouden zien.

Taakstructureringstabel NS trein opdracht:
| Objecten | Taaksoort | Periode | Deadline | Prioriteit |
| --- | --- | --- | --- | --- |
| accountgegevens | geen |  |  |  |
| accountControl | Intern, Demand Driven |  | 100ms | 3 |
| snelheidbeheerControl | Intern, Demand Driven |  | 30ms | 1 |
| treinverkeersregelcentrum | Intern, Demand Driven |  | 30ms | 1 |
| motorControl | Intern, Demand Driven |  | 30ms | 1 |
| noodstopMakenControl | Intern, Demand Driven |  | 30ms | 1 |
| gps | IO, Demand Driven |  | 200ms | 4 |
| yellowLedBlink | IO, Demand Driven |  | 200ms | 4 |
| redLedBlink | IO, Demand Driven |  | 200ms | 4 |
| motor | IO, Demand Driven |  | 200ms | 4 |
| display | IO, Demand Driven |  | 200ms | 4 |
| noodRem | IO, Demand Driven |  | 30ms | 1 |
| black box | IO, Demand Driven |  | 4 minuten | 5 |
| noodKnop | IO, Periodical | 60ms | 60ms | 2 |
| obstakel sensor | IO, Periodical | 60ms | 60ms | 2 |
| snelheidSchuif | IO, Periodical | 60ms | 60ms | 2 |


In onderstaand tabel heb ik nagedacht hoe ik de taken zou verdelen over de objecten en hoe ik ze samen kon voegen. Dit heb ik bij de lichtjes en de IO Periodical taaksoorten gedaan, omdat deze samengevoegd kunnen worden in twee Handler objecten

Taken samenvoegen tabel NS trein opdracht:
Taak | Objecten | Taaksoort | Periode | Deadline | Prioriteit |
| --- | --- | --- | --- | --- | --- |
| | accountgegevens | geen |  |  |  |
| AccountTaak | accountControl | Intern, Demand Driven |  | 100ms | 3 |
| SnelheidTaak | snelheidbeheerControl | Intern, Demand Driven |  | 30ms | 1 |
| TreinVerkeerTaak | treinverkeersregelcentrum | Intern, Demand Driven |  | 30ms | 1 |
| MotorTaak | motorControl | Intern, Demand Driven |  | 30ms | 1 |
| NoodstopTaak | noodstopMakenControl | Intern, Demand Driven |  | 30ms | 1 |
| GpsTaak | gps | IO, Demand Driven |  | 200ms | 4 |
| ColorTaak | ColorHandler, yellowLedBlink,  redLedBlink | IO, Demand Driven |  | 200ms | 4 |
| MotorTaak | motor | IO, Demand Driven |  | 200ms | 4 |
| DisplayTaak | display | IO, Demand Driven |  | 200ms | 4 |
| NoodRemTaak | noodRem | IO, Demand Driven |  | 30ms | 1 |
| BlackBoxTaak | black box | IO, Demand Driven |  | 4 minuten | 5 |
| PeriodiekeTaak | PeriodiekeHandler, noodKnop, obstakel sensor, nelheidSchuif | IO, Periodical | 60ms | 60ms | 2 