int Led_1 = 3; //pines digitale
int Led_2 = 4; //pines digitale
int Led_3 = 5; //pines digitale
int Led_4 = 6; //pines digitale
int Pot = A1; //pin analogico para el potenciometro
int Boton = 9;
int Boton_2 = 10;

//Variables para el funcionamiento
int Read = 0; //Lectura del potenciometro
int Brillo; //variable para el brillo del led en el programa 2
bool estado = 0; //estados para el boton 1
bool estado_2 = 0; //estados para el boton 2



void setup(){
  Serial.begin(9600);
  for(int i=3; i<7; i++ ){
    pinMode(i, OUTPUT);

  }
  pinMode(Pot, INPUT);
  pinMode(Boton, INPUT);
  pinMode(Boton_2, INPUT);
 

}

void loop(){
  if(digitalRead(Boton) == HIGH){
	delay(100);
    estado = true;
        while(estado){
     
//aqui entra el primer codigo
    Read = analogRead(Pot);  
    Serial.println(Read);
    if(Read >= 0 && Read<=100){
      digitalWrite(Led_1, HIGH);
      digitalWrite(Led_2, LOW);
      digitalWrite(Led_3, LOW);
      digitalWrite(Led_4, LOW);
    }

    if(Read > 100 && Read<= 400){
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, HIGH);   
      digitalWrite(Led_3, LOW);
      digitalWrite(Led_4, LOW);
    } 
    
    if(Read > 400 && Read<= 800){
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);   
      digitalWrite(Led_3, HIGH);
      digitalWrite(Led_4, LOW);
    } 

    if(Read > 800 && Read<= 1015){
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);   
      digitalWrite(Led_3, LOW);
      digitalWrite(Led_4, HIGH);
    } 




        delay(100);
            if(digitalRead(Boton) == HIGH){
             	delay(100);
              	Serial.println("para el 1");
              	estado = false;
            	break;
      		}
    	}
  }
  


    if(digitalRead(Boton_2)){
      delay(100);
      estado_2 = true;
      while(estado_2){
          Serial.println("Entra al segundo");

          //Aqui va el otro programa
        Read = analogRead(Pot);
        Brillo = map(Read, 0, 1023, 0, 255);
        analogWrite(Led_1, Brillo);

        
          delay(100);
              if(digitalRead(Boton_2)){
                  delay(100);
                  Serial.println("para el 2");
                  estado_2 = false;
                  break;
      			}
    	}
  	}

 



      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);   
      digitalWrite(Led_3, LOW);
      digitalWrite(Led_4, LOW);


    delay(100);
      }      


 
