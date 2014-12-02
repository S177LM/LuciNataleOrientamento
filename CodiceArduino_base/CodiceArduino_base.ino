void setup() {
  pinMode(13, OUTPUT); //pin dei led, vi consiglio di usare un ciclo for in quella finale. I pin 0 e 1 non si possono usare
  pinMode(2, INPUT); //pin del bottone
  Serial.begin(9600);
}

void loop() {
  while (1){    //assegnate le `coreografie` dentro questo loop, uno per coreografia. 
    digitalWrite(13,HIGH);
    if (lstnr(1000, 2)==1) {break;} //questo deve essere usate al posto del delay. Se usate una variabile per il delay questa deve essere di tipo !!!long!!! non int
    digitalWrite(13,LOW);
    if (lstnr(1000, 2)==1) {break;}
  }
  Serial.println("Stato 1->2"); //questa è importante per la comunicazione con l'interfaccia desktop
  digitalWrite(13,LOW);         //si assicura che il led sia spento (fatela per ogni led che accendete in quella sopra)
/*  
  while (1){
    digitalWrite(13,HIGH);
    if (lstnr(5000, 2)==1) {break;} 
    digitalWrite(13,LOW);
    if (lstnr(2000, 2)==1) {break;}
  }
  Serial.println("Stato 2->3");
  digitalWrite(13,LOW);
  
  while (1){
    digitalWrite(13,HIGH);
    if (lstnr(3000, 2)==1) {break;} 
    digitalWrite(13,LOW);
    if (lstnr(3000, 2)==1) {break;}
  }
  Serial.println("Stato 3->1");
  digitalWrite(13,LOW);
*/
}

int lstnr(long dl, int pn_i ){  //Attenzione! Se si usa una variabile per passare il tempo di attesa deve essere di tipo long
//usare questa funzione così: if (lstnr(1000, 2)==1) {break;}
//1000 è l'attesa, 2 il pin del bottone
  long c_t = millis();
  int a=0;
  while ((millis()-c_t)< dl) {
    if (digitalRead(pn_i)==HIGH) {
      a=1;
      break;
    }
  }
  delay(200); //se non c'è questo delay il bottone è come fosse premuto anche molte volte di fila
  return a;
}
