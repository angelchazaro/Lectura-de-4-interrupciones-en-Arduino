/*Equipo: Karen, Alondra, Angel.  Carrito robot móvil
Este código mide las RPM de las 4 ruedas del robot mediante 4 interrupciones externas en un Arduino MEGA
*/
volatile int rpm, rpm2, rpm3, rpm4; //Variables a usar

unsigned int Int0 = 0;  //Variable para las interrupciones
unsigned int Int1 = 1;
unsigned int Int2 = 2;
unsigned int Int3 = 3;

volatile int pulsos = 0;  //Variable para el contador en cada interrupcion
volatile int pulsos2 = 0;
volatile int pulsos3 = 0;
volatile int pulsos4 = 0;

void setup()
{
  Serial.begin(9600); //Se inicializa la comunicación serial a 9600 baudios ---> Protocolo RS232
  pinMode(2,INPUT); //Se declara como entrada los pines de la interrupción externa
  pinMode(3,INPUT); 
  pinMode(21,INPUT);
  pinMode(20,INPUT);
  attachInterrupt(Int0, interrupcion0, RISING); //Se activan interrupciones externas por flanco de subida //FALLING);   //Se activan interrupciones externas por flanco de bajada
  attachInterrupt(Int1, interrupcion1, RISING); //Se activan interrupciones externas por flanco de subida //FALLING);   //Se activan interrupciones externas por flanco de bajada
  attachInterrupt(Int2, interrupcion2, RISING); //Se activan interrupciones externas por flanco de subida //FALLING);   //Se activan interrupciones externas por flanco de bajada
  attachInterrupt(Int3, interrupcion3, RISING); //Se activan interrupciones externas por flanco de subida //FALLING);   //Se activan interrupciones externas por flanco de bajada

}

void loop() {
  delay(999);
    rpm = (pulsos*((60*2)/100));//((double)pulsos / resolucion) * 60; //Formula para calcular rpm ;  
    //Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.print("RPM motor 1: ");
    Serial.print(rpm);
    Serial.println(" ");
  
    pulsos = 0; //Reinicia la cuenta de los pulsos
  
    rpm2 = (pulsos2*((60*2)/100));//((double)pulsos2 / resolucion2) * 60; //Formula para calcular rpm 
    Serial.println(" ");
    Serial.print("RPM motor 2: ");
    Serial.print(rpm2);
    Serial.println(" ");
    
    pulsos2 = 0; //Reinicia la cuenta de los pulsos
  
    rpm3 = (pulsos3*((60*2)/100));//((double)pulsos3 / resolucion3) * 60; //Formula para calcular rpm  
    Serial.println(" ");
    Serial.print("RPM motor 3: ");
    Serial.print(rpm3);
    Serial.println(" ");

    pulsos3 = 0; //Reinicia la cuenta de los pulsos

    rpm4 = (pulsos4*((60*2)/100));//((double)pulsos4 / resolucion4) * 60; //Formula para calcular rpm 
    Serial.println(" ");
    Serial.print("RPM motor 4: ");
    Serial.print(rpm4);
    Serial.println(" ");

    pulsos4 = 0; //Reinicia la cuenta de los pulsos

    volatile int promedio= (rpm+rpm2+rpm3+rpm4)/4;
    Serial.println("\n");
    Serial.println("Promedio RPM: ");
    Serial.println(promedio);
    Serial.println(" ");
    Serial.println(" ");
}

//Estas serian las funciones interrupcion externa.
void interrupcion0()  //Se ejecuta cada interrupcion
{
  pulsos++;  // contador de pulsos
}

void interrupcion1()  //Se ejecuta cada interrupcion
{
  pulsos2++;  // contador de pulsos
}

void interrupcion2()  //Se ejecuta cada interrupcion
{
  pulsos3++;  // contador de pulsos
}

void interrupcion3()  //Se ejecuta cada interrupcion
{
  pulsos4++;  // contador de pulsos
}
