int IN1 = 7;
int IN2 = 8; 
int IN3 = 9;
int IN4 = 10;
float lineal=0;
float angular=0;

int led_pin = 26;

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil(';');
    Serial.println("Recibido: " + input);
    
    int startIdx = input.indexOf('[') + 1;
    int endIdx = input.indexOf(']');
    String valuesStr = input.substring(startIdx, endIdx);
    Serial.println("Valores: " + valuesStr);

    String valuesArray[2];
    int count = 0;
    while (valuesStr.length() > 0) {
      int commaIdx = valuesStr.indexOf(',');
      if (commaIdx == -1) {
        valuesArray[count] = valuesStr;
        valuesStr = "";
      } else {
        valuesArray[count] = valuesStr.substring(0, commaIdx);
        valuesStr = valuesStr.substring(commaIdx + 1);
      }
      count++;
      lineal = atof(valuesArray[0].c_str()); 
      angular = atof(valuesArray[1].c_str()); 
    }
  }
      
      Serial.println(lineal);
      if((lineal > 0) && (angular == 0 ))
    {

      Serial.println("adelante");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if((lineal < 0) && (angular == 0))
    {
      Serial.println("atras");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      }
      else if((lineal == 0.0) && (angular == 0.0))
      {
        Serial.println("apagado");
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        }
       else if((lineal == 0) && (angular > 0)) //derecha
        {
          Serial.println("derecha");
          //digitalWrite(IN1, HIGH);
          //digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);

          
          }
          else if(lineal == 0 && angular < 0) //izquierda
          {
            Serial.println("izquierda");
           digitalWrite(IN1, LOW);
           digitalWrite(IN2, HIGH);
            //digitalWrite(IN3, LOW);
           // digitalWrite(IN4, HIGH);
            }
        Serial.println(angular);
        

      delay(2500);

    
   }

 
 
