Ik heb bij deze opdracht een eigen speler gemaakt, een afbeelding naar een c-array omgezet na twee dagen een werkende website van een groepsgenoot te krijgen want de LVGL tool die aangeboden was werkte voor geen meter. Ik heb de snake sprite voor de speler gebruikt en ik heb een coin sprite en entiteit toegevoegd om de speler de coin te kunnen laten pakken, dit is de simpele gameplay van deze opdracht. In de terminal is de score te zien, oftewel hoeveel coins je hebt opgepakt. Verder heb ik vragen van de opdracht beantwoordt.

Hier de snake sprite voor het karakter.
![alt text](image-17.png)

Hier de coin sprite die ik heb gebruikt die de slang op kan pakken voor een score.
![alt text](image-16.png)

Hier de opdrachten en antwoorden:

We introduceren een entiteit (Entity) een abstract basis-object met minimaal `update(dt, width, height)` en `draw(display)`. Elke game-entiteit (speler, vis, kogel, etc.) weet zelf hoe hij beweegt (in update) en hoe hij getekend wordt (in draw).

In `main.cpp` maken we een speler aan:
```cpp
    PlayerHandle player = acquirePlayerShark();
    centerPlayerShark(Ili9341Display::WIDTH, Ili9341Display::HEIGHT);
    initPlayerSharkVelocity(20.0f, 10.0f);
```
Wat doet dit stukje code? Leg deze drie regels code stap voor stap uit. Er wordt hier een PlayerHandle gemaakt en wordt het gelijk gezet aan een functie die alle belangrijke player informatie pakt. De player wordt in het midden van het scherm gezet en wordt de snelheid van de haai in een richting gezet

De speler is één specifieke Entity. Via een handle krijgt player twee dingen:
`player.entity` de te registreren entiteit.
`player.input` een input dat iets kan ontvangen. In dit geval de knoppen van de keypad.

De Scene beheert een collectie van Entities. De `scene.add(player.entity)` is de registratie van de speler in een interne lijst. De `scene.setInputTarget(player.input)` zorgt voor inputrouting. Het vertelt de Scene waar de keypad events heen moeten. De simulatie en redering wordt gedaan door `scene.update(dt, W, H)` dat alle entities doorloopt en `scene.draw(display)` laat deze tekenen.

De analoge input registreren we als volgt:
```cpp
    AnalogButtonReader buttons(ADC1_CHANNEL_7, GPIO_NUM_35, 200); // 200 ms poll
    buttons.setCallback([&](Button button){
        scene.onButton(button);
    });
    buttons.start();
```
Leg uit waarom dit onze speler van plaats kan veranderen? Nadat je een input geeft via het keypad gaat onze speler versnellen. Welke stuk code is daar verantwoordelijk voor? Kan je een beter implementatie voor versnelling verzinnen?

Dit kan de plaats van speler veranderen om het checkt welke knop is ingedrukt om de 200 milliseconden en wordt de scene geüpdatet met de knop die ingedrukt is, waardoor de speler verplaatst. In de gameEntities.cpp wordt de snelheid verandert, maar er wordt geen versnelling toegepast, als de sprite eerst naar rechts gaat en je drukt naar links dan veranderd hij gelijk van snelheid in de andere richting, er is geen geledelijke versnelling de andere kant op. Er zal vast een goede manier zijn om versnelling toe te voegen zoals in een functie in gameEntities.cpp.

De daadwerkelijke game-loop komt je waarschijnlijk bekend voor. Alleen is `vTaskDelay(frame);` afhankelijk van `frame`. Waarom is dit gedaan? Is er een beter implementatie mogelijk?

Dit is zo gedaan zodat er 30 frames per seconde wordt gedaan, maar frames wordt berekend door 1000 delen door 30 te doen en dan krijg een 1/3 wat niet heel handig is. Frame zou gebruikt kunnen worden omdat je dan een variabele frame in de functie heb staan, wat misschien handiger is dan om zo een waarde erin te zetten. Ik denk dat de frame variabele misschien een betere waarde kan krijgen maar meer kan ik niet bedenken dat beter zou kunnen zijn. 