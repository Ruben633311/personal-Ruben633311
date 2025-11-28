Bij het maken van deze opdracht heb ik hulp gevraagd Laurens Richter. Ik wist eerst niet wat een model beschrijving was en Laurens heeft mij uitgelegd waar ik het kon vinden en hoe het ingevuld moest worden. SnoepautomaatControl beheert hoe alle logica werkt en stuurt de data naar andere objecten zoals het automaat display of product dispenser. Deze objecten gebruiken dan deze commands om text te laten zien of om producten de dispenseren.

![alt text](../foto's/snoepautomaat_OM.png)

Onderstaand tabel laat zien wat de objecten voor stereotypes hebben en een beschrijving ervan.

| Object Naam | Stereotype | Beschrijving |
--- | --- | ---
bedrag | entity | bevat de bedragen van de producten |
paymentControl | control | "dirigent" van de payment |
automaat display | boundary | stuurt de display hardware aan |
snoepautomaatControl | control | "dirigent" van het snoepautomaat |
product dispenser | boundary | stuurt de dispenser hardware aan |
RTC | boundary | stuurt clock hardware aan |
display-knoppen | boundary | stuurt knoppen hardware aan |