int alarme(int hora, int minuto){

  int hAtual[15] = {(hora*900)+minuto};
  int hLiga[15] = {(horaLiga*900)+minutoLiga};
  int hDesliga[15] = {(horaDesliga*900)+minutoDesliga};

  if(hDesliga[] < hLiga[]){
    if(hAtual[] >= hLiga[]){
      digitalWrite(sirene,HIGH);
      }
    }
  if (hAtual[] >= hDesliga[] && hAtual[] < hLiga[]){
    digitalWrite(sirene,LOW);
    }
  if( hDesliga[] > hLiga[]) {
    if( hAtual[] >= hLiga[] && hAtual[] =< hDesliga[]){
    digitalWrite(sirene,LOW);}
    
  if(hAtual[] >= hDesliga[]){
    digitalWrite(sirene,LOW);}
     }
   }
}
 
