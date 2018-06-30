int alarme(int hora,int minuto){
  
  int hAtual = {((hora*60)+minuto)}; //soma os minutos hora atual
  int hLiga = {(horaLiga*60)+minutoLiga};
  int hDesliga = {(horaDesliga*60)+minutoDesliga};

  if (hDesliga < hLiga){
    if (hAtual >= hLiga){
      digitalWrite(sirene,LOW);
       
      }
      if (hAtual >= hDesliga && hAtual < hLiga){
      digitalWrite(sirene,LOW);
          
      }
    }
  if (hDesliga > hLiga ){
      if ( hAtual >= hLiga and hAtual <= hDesliga ){
       digitalWrite(sirene,LOW);
       
      }
    if (hAtual >= hDesliga){
     digitalWrite(sirene,LOW);
         
       } 
  }
}
