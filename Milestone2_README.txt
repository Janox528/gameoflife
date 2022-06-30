Prg Praktikum WS2017/2018
Milestone 2

Autoren: Rene Meier 6322672.Adrian Musella 5697191,Fanjun Weng 6468138. 
Abgabe basiert auf Milestone 1 von Rene, wurde aber von allen Mitgliedern bearbeitet und gedebuggt.
Eine Einteilung in Methoden ist nicht möglich, da wir es gemeinsamm an einem PC gemacht haben.


Hinweis: wie in Milestone 1 muss vermutlich die xxx.pro.user Datei gelöscht werden, bevor das Projekt geladen und ausgeführt werden kann.


Ergebnisdateien: wie in Milestone 1: Die Safe Datei im Projekt Ordner, für mehr Infos siehe Milestone1_README.
Die Safe funktion funktioniert auch im Spiel Snake, aber nur wenn das Programm zwischen speichern und laden nicht neu gestartet wird.
Laut Aufgabenstellung war die funktionalität der Speichern- und Ladenfunktionen für M2 aber auch nicht verlangt.


Bekannte Probleme: Keine


Kurze Beschreibung unserer Implementierung:
Timer spd startet bei 250 Ms, da wir der Meinung waren, dass eine langsamere Geschwindigkeit den Spielspass trübt.
Jedes mal wenn die Snake frisst wird sie 25 ms schneller, bis sie einen Minimaltimer von 50 ms erreicht hat.
Unsere Snake ist wie abgesprochen nicht Objektorientiert implementiert, da es bei dem geringen Umfang der Funktionen mehr Nachteile als Vorteile gebracht hätte(Laufzeit etc).


Steuerung:
W- Oben
A-Links
S-Unten
D-links



Nach dem umschalten auf Snake muss Change Game die Auswahl bestätigt werden. Im Snakemodus startet dieser Button auch ein neues Spiel.
Ebenfalls ein neues Spiel wird durch "Start new Snake game"gestartet