Prg Praktikum WS2017/2018
Milestone 2

Autoren: Rene Meier 6322672.Adrian Musella 5697191,Fanjun Weng 6468138. 


Aufgabenteilung: Im Verlauf des Projektes hat jeder überall gearbeitet und eine genaue Einteilung ist kaum möglich.
Wir hatten viele Bugs(alle behoben), daher waren 90% unserer Arbeitszeit debuggen und neu schreiben, so hat jeder in den beide Hauptfunktionen mitgewirkt.
Den Rahmen des Projektes haben wir aus Milestone 1&2 übernommen und leicht angepasst. Deshalb liegen für bereits vorher realisierte Funktionen die alten Readme´s bei.




Hinweis: wie in Milestone 1&2 muss vermutlich die xxx.pro.user Datei gelöscht werden, bevor das Projekt geladen und ausgeführt werden kann.


Ergebnisdateien: wie in Milestone 1: Die Safe Datei im Projekt Ordner, für mehr Infos siehe Milestone1_README.
Safe und Load haben wir für Milestone 3 blockiert, da es zu bugs kommen kann, wenn die hidden fields nicht gespeichert werden.
Wir müssten dazu die safe funktion auf sämtliche hidden Arrays erweitern, dies war aber in der Aufgabenstellung nichtgefordert.



Bekannte Probleme: Keine


Kurze Beschreibung unserer Implementierung:
Wie in den anderen Milestones: Ein Ändern des Gamemodes muss mit dem darunter liegenden Button bestätigt werden.
"Single Evolutionstep" Button kann (in allen Gamemodes) benutzt werden um exakt einen Zeitschritt zu beobachten. So ist ein Debuggen bzw genaueres beobachten einfacher.
Hier wird kein Timer gestartet!

Timer: Start und Stop Button zum steuern benutzen,Timesteps für den Zeitabstand.
Niedrigere Werte als der Standartwert sind möglich, aber nur auf guter Hardware zu empfehlen. 
Der Timer darf nicht schneller als die Laufzeit des Evolutionsteps werden(in der Theorie.. in der Praxis haben wir nicht beobachten können das er bei 1 ms schneller war als der evolution step.)

Zeichnen:
Feldgrösse ändern wie in den alten Milestones.
Clear Button ebenfalls bekannt..
Cellmode: Schaltet die 3 verschiedenen Zeichenmodi um(Hunter Victim Grass).


Lebenszeit:
standartwert:5
Maximalwert:99   (theoretisch mehr möglich, aber 99 ist eine ausreichend lange Zeit)


Eine Zelle mit einem Lebenszeitwert von 1 hat noch einen Zug, sollte sie in diesem zug es nicht schaffen zu fressen, so stirbt sie direkt nach ihrem Zug.
Für den Beobachter ist dieser Zug somit nicht sichtbar.
Sollte gefressen werden, so wird unabhängig vom momentanen Wert, der Lebenzeitwert auf den eingestellten Maximalwert gesetzt.




Wir haben uns zu begin sehr streng an die Aufgabenstellung gehalten(bezüglich cellEvolutionMove() und cellEvolutionDirection()), 
haben aber, im Laufe unserer Debugphase, einen Grossteil der Funktionalität von cellEvolutionMove() in cellEvolutionDirection() ausgelagert. 
Trotzdem sollten alle Punkte in der Aufgabenstellung erfüllt sein. 





