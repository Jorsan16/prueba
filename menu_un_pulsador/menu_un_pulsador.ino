int boton = 9;
int i = 0;
int estado = 0;
bool Puls = false;
int Led = 3;
int Led_2 = 4;
int Led_3 = 5;
int Led_4 = 6;

void setup()
{
  pinMode(boton, INPUT);
  pinMode(Led, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  estado = digitalRead(boton);
  if(estado == 1){
  delay(100);
    i= i+1;
    Serial.println(i);
    delay(100);
  }
  
  if(i >= 5){
    delay(100);
  i=0;
  }
  
  
  delay(10);
//Pulso 1
  if(i == 1){
    delay(100);
    Puls = true;
    while(Puls){
      delay(100);
    	//codigo de Pulso 1
      digitalWrite(Led, HIGH);
      
      estado = digitalRead(boton);
      if(estado == HIGH){
        delay(100);
      	Puls = false;
        break;
      }
    }
  }
  delay(10);
//Pulso 2 
  
  if(i == 2){
    delay(10);
    Puls = true;
    while(Puls){
      delay(100);
    	digitalWrite(Led_2, HIGH);
       estado = digitalRead(boton);
      if(estado == HIGH){
        delay(100);
      	Puls = false;
        break;
      }
      
    }
  }  
  delay(10);
  //Pulso 3
  
  if(i == 3){
    delay(10);
    Puls = true;
    while(Puls){
      delay(100);
    	digitalWrite(Led_3, HIGH);
       estado = digitalRead(boton);
      if(estado == HIGH){
        delay(100);
      	Puls = false;
        break;
      }
      
    }
  } 
  
  delay(10);
 //Pulso 4
  if(i == 4){
    delay(10);
    Puls = true;
    while(Puls){
      delay(100);
    	digitalWrite(Led_4, HIGH);
       estado = digitalRead(boton);
      if(estado == HIGH){
        delay(100);
      	Puls = false;
        break;
      }
      
    }
  } 
  
  
  
  
  
	digitalWrite(Led, LOW);
  	digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW);
  	delay(10);
}
