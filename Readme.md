functions:

signal: de signal functie wordt gebruikt voor het luisteren naar signalen. de argumenten zijn het signaal nummer en een functie die moet worden aangeroepen om iets te doen met de informatie.
sigemptyset: de sigemptyset functie initialiseert een sigset_t variabele zijn mask naar het hebben van geen signals.
sigaddset: de sigaddset functie voegt een signal toe aan een sigset_t variabele.
sigaction: de sigaction functie wordt op dezelfde manier gebruikt als de signal functie, alleen geeft het een uitgebreidere interface waarbij een sigaction_t variabele meegegeven kan worden.
kill: de kill functie wordt gebruikt om signalen te verzenden naar andere processen. de 2 argumten ervoor zijn de process id van het process waarnaar je stuurt en het nummer van het signaal wat wordt toegepast.
pause: de pause functie zorgt ervoor dat het process wordt gepauzeert totdat een signaal wordt ontvangen
sleep: de sleep functie zorgt ervoor dat het process wordt gepauzeert voor gegeven seconden.
usleep: de usleep functie zorgt ervoor dat het process wordt gepauzeert voor gegeven miniseconden.