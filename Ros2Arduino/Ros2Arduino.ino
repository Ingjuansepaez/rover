int IN1 = 8;
int IN2 = 7; 
int IN3 = 9;
int IN4 = 10;

int led_pin = 26;

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios
  pinMode(led_pin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
   
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
     /// float valuesArray[0] = atof(valuesArray[0].c_str()); 
     /// float valuesArray[1] = atof(valuesArray[1].c_str()); 

      if(atof(valuesArray[0].c_str()) > 0)
    {
      digitalWrite(led_pin, HIGH);
      delay(100);  // Espera un breve periodo de tiempo
      digitalWrite(led_pin, LOW);
      
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if(atof(valuesArray[0].c_str()) < 0)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      }
      else if(atof(valuesArray[0].c_str()) == 0)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        }

        else if(atof(valuesArray[1].c_str()) > 0) //derecha
        {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          
          }
          else if(atof(valuesArray[1].c_str()) < 0) //izquierda
          {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            }

             else if(atof(valuesArray[1].c_str()) == 0)
             {
               digitalWrite(IN1, LOW);
               digitalWrite(IN2, LOW);
               digitalWrite(IN3, LOW);
               digitalWrite(IN4, LOW);
              }
    }
   }

 }
 
