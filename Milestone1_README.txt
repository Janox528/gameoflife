Prg Praktikum WS2017/2018
Milestone 1 
Autor der Readme: Rene Meier

ÜbungsGruppe 6
Mitglieder: Rene Meier 6322672,Lam,Sitong Yu 4878869,Alon kvin 6330787



Die 3 Aufgaben wurden jeweils in 3 verschiedenen Projekten gelöst.
Die Projekte sind in unterschiedlichen Ordnern und können einfach bei QT geladen werden.
Sollte sich das Projekt nicht öffnen lassen kann man die xxx.pro.user Datei löschen 
und erstellt dann beim laden automatisch ein neues Projekt. Der Vollständigkeit halber habe ich sie in der Abgabe gelassen,
sie sollte aber gelöscht oder ausgelagert werden vor dem laden des Projektes da es sonst zu Konflikten der Pfade kommen kann.
Da wir auf Windows gearbeitet haben, haben wir das Programm ohne Konsole ausgeführt.


Aufgabe 1 ist einfach gehalten und am besten im Code nachzulesen,
da mir keine vernünftige Ausgabe eingefallen ist. (array wird wie gefordert ausgegeben).
Am Anfang wird Hello World (mit einer vorherigen Namensabfrage) ausgeführt, danach folgt der Teil mit den arrays.
Das Array wird hier im gegensatz zu Aufgabe 2 nur ausgegeben wenn man dies per Eingabe fordert.
Hier ist das Element oben links (0,0). (nicht wie in Aufgabe 2 (1,1))

Aufgabe 2 ist ein Konsolen Programm.
Alle geforderten Funktionalitäten sind erfüllt.
Ausserdem kann man mit der Eingabe 5 ein zufälliges Testfeld erzeugen,
dies reduziert die Zeit beim testen enorm und ich dachte es wäre(für das vorrechnen)
nützlich die Funktion nicht zu löschen.
Jede andere Funktion steht im Hauptmenü bzw den Untermenüs.
Die Ausgabe des Arrays erfolgt automatisch nach jeder Eingabe im Hauptmenü, 
dies empfand ich als angenehmer als es manuell neu printen zu lassen.
Die reprint Funktion ist natürlich trotzdem vorhanden und funktionsfähig.
Hinweis zur funktion set alive: Die Zellennumerierung startet mit 1 und geht bis ax.
0 ist somit eine falsche Eingabe.


Aufgabe 3 erfüllt ebenfalls alle geforderten Funktionalitäten.
Ich denke ich brauche hier nicht die Funktionen aus der Aufgabenstellung wiederholen.
Die standart Zeit des Timers beträgt 500ms. Ich habe festgestellt, dass bei geringeren Werten 
die Ausführungsgeschwindigkeit irgendwann vom Gerät abhängt und nicht vom Timer. 
Bis 100ms sollte dies aber kein Problem darstellen.
Sämmtliche Methoden, welche die Funktionalität des CA garantieren befinden sich in CABase.
Die ist die gleiche CABase wie in Aufgabe 2.
Diese Methoden werden über Gamewidget angesprochen. 
Die grafischen Elemente wiederum sind mit den Methoden vom Gamewidget connectet.
Die Zeichnung des Spielfeldes befindet sich in Gamewidget.





Ergebnisdateien: die savegame.txt aus Ausgabe 3 befindet sich im Build Ordner welcher beim laden des Projekts erstellt wird.
Zeile 1 ist die Weltengrösse und alle folgenden Zeilen sind die gespeicherten Zellen(0=tot,1= lebendig).

bekannte Probleme: Nach mehrmaligem Testen auf unterschiedlichen Bildschirmen habe ich festgestellt,
dass manchmal ein kleiner Teil der Button auf der rechten Seite weggeschnitten sein kann.
Ich habe dieses Problem zumindest auf meinen Bildschirmen gelöst, es kann aber bei anderen Auflösungen eventuell zu Problemem kommen.
Wenn es zu Problemen kommt, kann die SpinBox nicht mehr "gespinnt" werden, da das entsprechende Element abgeschnitten ist.
Der Wert kann aber trotzdem immernoch direkt eingegeben werden.
Wie gesagt auf meinen verfügbaren Geräten tritt dieses Problem nicht mehr auf, ich hoffe auf sämtlichen anderen Geräten auch nicht mehr :)



Wer hat woran gearbeitet?:

LAM war ab dem 1. Termin zu keinem Treffen anwesend. Er hat nichts zu dem Projekt beigetragen.

ALON hat die savegame Funktion aus Aufgabe 3 versucht, sie aber leider nicht hinbekommen.

YU hat die Grafische oberfläche der Aufgabe 3 gemacht(Buttons,Layouts, ohne das die Buttons mit irgendetwas connecten wären). 
Leider zu einem Zeitpunkt als ich dies schon hatte, deshalb habe ich im Projekt mein Layout benutzt.


RENE:Hat das Projekt vollständig alleine gemacht(Code,Layout,Kommentare,Readme etc.)
und hat trotz mehrmaliger Nachfrage bei den Gruppenmitglieder so gut wie keine Hilfe bekommen.



Alon und yu waren bei jedem unserer Treffen(Übungstermine) anwesend.





Sonstige Kommentare:
Ich habe versucht den Code möglichst anpassungsfähig zu gestalten, sodass ich in späteren Milestones einige Funktionen wieder verwenden kann.
Das ist auch der Grund dafür das die Zellen einen int wert als Status haben. Für Milestone 1 wäre ein boolean ausreichend gewesen.






