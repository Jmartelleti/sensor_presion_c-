double Level,Vout,P,Vs=5.0;
double aux;
double tolP=0.04; // Ajusta la medida de presión
int i, rho = 997;
double g=9.8;
int led = 13;
int Vol_lata = 15 ;
void setup()

{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() 
{
   //Voltaje del Sensor MPx10DP
   aux=0;
   for(i=0;i<10;i++){
    aux = aux + (float(analogRead(A0))*5.0/1023.0); //v
    delay(5);
   }
   Vout=aux/10.0;
  
  //Presión en Kpa según gráfica 4 del Datasheet
  P = ( Vout - 0.04*Vs ) / (0.09 * Vs) + tolP; //kPa
   
  Level = ((P*1000)/(rho*g))*100;  //Medida de Nivel del tanque
  Serial.print("\n\nVoltaje:");
  Serial.print(Vout);
  Serial.println(" v");
  Serial.print("Presión:");
  Serial.print(P);
  Serial.println(" kPa");
  Serial.print("Nivel:");
  Serial.print(Level);
  Serial.println(" cm");

  if (Level >= Vol_lata ) { //Variable con nivel de lata 
  digitalWrite(led , LOW);
  }
  else { // volumen bajo ----> continua tirando
  digitalWrite(led , HIGH);
  }
  
  delay(1000);
  }