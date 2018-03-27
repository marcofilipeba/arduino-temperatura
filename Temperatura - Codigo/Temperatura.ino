#include <DHT.h>

int Sensor = 2;  //Pino onde está ligado o sensor DHT22    
DHT dht(Sensor, DHT22); //Esta instrução indica qual à biblioteca qual o modelo do sensor utilizado
float temperatura; // Variavel que nos irá mostrar a tempetatura 
float humidade; // Variavel que nos irá mostrar a humidade


void setup() {

  Serial.begin(9600);// Sincronizar a porta serial a 9600 bits por segundo
  pinMode(Sensor, INPUT); // Definir o nosso sensor como INPUT
  dht.begin();// Esta instrução é necessaria, para que o nosso sensor possa estar pronto para ser utilizado
}

void loop() {

  temperatura = dht.readTemperature(); // Esta instrução permite que o sensor guarde a leitura da temperatura na variavel
  humidade = dht.readHumidity(); // Esta instrução permite que o sensor guarde a leitura da humidade na variavel
  delay(2000); // Para o prgrama durante 2000 milisegundos;

  // Escreve para a porta serial a temperatura e a humidade:
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("c Humidade: ");
  Serial.print(humidade);
  Serial.println("%");
}

