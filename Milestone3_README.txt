Prg Praktikum WS2017/2018
Milestone 2

Autoren: Rene Meier 6322672.Adrian Musella 5697191,Fanjun Weng 6468138. 


Aufgabenteilung: Im Verlauf des Projektes hat jeder �berall gearbeitet und eine genaue Einteilung ist kaum m�glich.
Wir hatten viele Bugs(alle behoben), daher waren 90% unserer Arbeitszeit debuggen und neu schreiben, so hat jeder in den beide Hauptfunktionen mitgewirkt.
Den Rahmen des Projektes haben wir aus Milestone 1&2 �bernommen und leicht angepasst. Deshalb liegen f�r bereits vorher realisierte Funktionen die alten Readme�s bei.




Hinweis: wie in Milestone 1&2 muss vermutlich die xxx.pro.user Datei gel�scht werden, bevor das Projekt geladen und ausgef�hrt werden kann.


Ergebnisdateien: wie in Milestone 1: Die Safe Datei im Projekt Ordner, f�r mehr Infos siehe Milestone1_README.
Safe und Load haben wir f�r Milestone 3 blockiert, da es zu bugs kommen kann, wenn die hidden fields nicht gespeichert werden.
Wir m�ssten dazu die safe funktion auf s�mtliche hidden Arrays erweitern, dies war aber in der Aufgabenstellung nichtgefordert.



Bekannte Probleme: Keine


Kurze Beschreibung unserer Implementierung:
Wie in den anderen Milestones: Ein �ndern des Gamemodes muss mit dem darunter liegenden Button best�tigt werden.
"Single Evolutionstep" Button kann (in allen Gamemodes) benutzt werden um exakt einen Zeitschritt zu beobachten. So ist ein Debuggen bzw genaueres beobachten einfacher.
Hier wird kein Timer gestartet!

Timer: Start und Stop Button zum steuern benutzen,Timesteps f�r den Zeitabstand.
Niedrigere Werte als der Standartwert sind m�glich, aber nur auf guter Hardware zu empfehlen. 
Der Timer darf nicht schneller als die Laufzeit des Evolutionsteps werden(in der Theorie.. in der Praxis haben wir nicht beobachten k�nnen das er bei 1 ms schneller war als der evolution step.)

Zeichnen:
Feldgr�sse �ndern wie in den alten Milestones.
Clear Button ebenfalls bekannt..
Cellmode: Schaltet die 3 verschiedenen Zeichenmodi um(Hunter Victim Grass).


Lebenszeit:
standartwert:5
Maximalwert:99   (theoretisch mehr m�glich, aber 99 ist eine ausreichend lange Zeit)


Eine Zelle mit einem Lebenszeitwert von 1 hat noch einen Zug, sollte sie in diesem zug es nicht schaffen zu fressen, so stirbt sie direkt nach ihrem Zug.
F�r den Beobachter ist dieser Zug somit nicht sichtbar.
Sollte gefressen werden, so wird unabh�ngig vom momentanen Wert, der Lebenzeitwert auf den eingestellten Maximalwert gesetzt.




Wir haben uns zu begin sehr streng an die Aufgabenstellung gehalten(bez�glich cellEvolutionMove() und cellEvolutionDirection()), 
haben aber, im Laufe unserer Debugphase, einen Grossteil der Funktionalit�t von cellEvolutionMove() in cellEvolutionDirection() ausgelagert. 
Trotzdem sollten alle Punkte in der Aufgabenstellung erf�llt sein. 





