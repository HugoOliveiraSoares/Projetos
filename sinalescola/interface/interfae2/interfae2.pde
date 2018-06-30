PFont fonte;
void setup() {
 size(600,500);
 fonte = createFont("Georgia", 32);
textFont(fonte, 23);
}
void draw() {
text("L=liga a musica", 200, 100);
text("D=desliga a musica", 200, 150);

}
void keyPressed(){
if (keyCode == 'L'){
  //text("ligou",50, 40);
  println("ligou");
  
    }
   
 if (keyCode == 'D'){
   //text("desligou",50, 60);
   println("Desliga");
    }
}