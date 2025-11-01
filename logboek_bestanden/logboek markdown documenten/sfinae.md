voor de Sfinae opdracht was de opdracht dat we van de code van een object willen checken of het een bepaalde memberfunctie heeft. Dit kan met SFINAE en met andere eenvoudigere runtime alternatieven. Ik heb SFINAE vergeleken met 2 runtime alternatieven door twee functies honderduizend keer te runnen en te timen hoe lang het duurt voordat de code klaar is met runnen en te kijken wat de verschillen zijn. 

## A: Snelheidsmeting van Sfinae
Ik heb van sfinae.cpp de couts gecommentarieert in foo() en callFooIfExists(). Ook heb ik dus gemeten hoe lang het duurt om de volgende combi 100000 keer aan te roepen:
```c++
callFooIfExists(a);
callFooIfExists(b);
```

Dit duurde **9,60** seconden

## B: Snelheidsmeting van Sfinae alternatief 1
ik heb hetzelfde gedaan voor [runtime_nosfinae](./runtime_nosfinae.cpp).

Dit duurde **9,88** seconden

## C: Snelheidsmeting van Sfinae alternatief 2
ik heb hetzelfde gedaan voor [runtime_nosfinae_2](./runtime_nosfinae_2.cpp).

Dit duurde **10 seconden** seconden

## D: Vergelijking
Ik heb voor alle drie de manieren opgeschreven wat ik denk dat de voordelen zijn tegenover de andere methodes.

- -> **Voordeel van sfinae:** [het voordeel is dat deze het snelst is]
- -> **Voordeel van alternatief 1:** [het voordeel is dat deze code overerving gebruikt waardoor de WithFoo en WithoutFoo klassen allebei de foo() functie van de Base klasse hebben. Ook dat de function call van callFooIfExists een pointer naar de Base klasse gebruikt is ook fijn]
- -> **Voordeel van alternatief 2:** [het voordeel bij deze is dat de code een refence gebruikt in de callFooIfExists function call en dat het een hasFoo functie heeft dat gebruikt kan worden om andere code te schrijven dat moet runnen als foo wel bestaat]