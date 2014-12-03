void setup() {
  pinMode(13, OUTPUT); //pin dei led, vi consiglio di usare un ciclo for in quella finale. I pin 0 e 1 non si possono usare
  pinMode(2, INPUT); //pin del bottone
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, LOW); //Da fare per ogni led, usare un for iterato su una lista
  Serial.print("1"); //questa è importante per la comunicazione con l'interfaccia desktop
  while (1){    //assegnate le `coreografie` dentro questo loop, uno per coreografia. 
    digitalWrite(13,HIGH);
    if (lstnr(1000, 2)==1) {goto end1;} //questo deve essere usate al posto del delay. Se usate una variabile per il delay questa deve essere di tipo !!!long!!! non int
                                        //non copiate e incollate ovunque. Se si deve uscire dal primo ciclo usare end1, dal secondo end2 e così via
    digitalWrite(13,LOW);
    if (lstnr(1000, 2)==1) {goto end1;}
  }
  end1:;
  
  Serial.print("2");
  digitalWrite(13,LOW);         //si assicura che il led sia spento (fatela per ogni led che accendete in quella sopra)
  while (1){
    digitalWrite(13,HIGH);
    if (lstnr(5000, 2)==1) {goto end2;} 
    digitalWrite(13,LOW);
    if (lstnr(2000, 2)==1) {goto end2;}
  }
  end2:;
  
  Serial.print("3");
  digitalWrite(13,LOW);
  while (1){
    digitalWrite(13,HIGH);
    if (lstnr(3000, 2)==1) {goto end3;} 
    digitalWrite(13,LOW);
    if (lstnr(3000, 2)==1) {goto end3;}
  }
  end3:;

}


int lstnr(long dl, int pn_i ){  //Attenzione! Se si usa una variabile per passare il tempo di attesa deve essere di tipo long
//usare questa funzione così: if (lstnr(1000, 2)==1) {goto statement;}
//1000 è l'attesa, 2 il pin del bottone
  long c_t = millis();
  int a=0;
  while ((millis()-c_t)< dl) {
    if (digitalRead(pn_i)==HIGH) {
      a=1;
      break;
    }
  }
  delay(250); //se non c'è questo delay il bottone è come fosse premuto anche molte volte di fila
  return a;
}
