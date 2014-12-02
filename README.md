v0.0
Git repository initialised
v0.1
Aggiunta la funzione che sta in ascolto per la pressione del bottone

**IMPORTANTE**: perchéla funzione listener sia efficace immediatamente dopo ogni loop ci dovra' essere il seguente listato:
```
end*n*:;
```
dove la n finale va' sostituita con il numero del ciclo che segue. Per esempio il terzo while sara' seguido da ```end3:;```.

Questa notazione lavora in pari con il seguente codice:
```
if (lstnr(*wait*, *pin*)==1) {goto end*n*;}
```
dove *wait* è il tempo di attesa, *pin* il pin di input del bottone e *n* il numero del ciclo in cui è inserito il listato
