#include <WiFi.h>
#include <WebServer.h>

// Configuración WiFi
const char *ssid = "BUAP_Trabajadores";
const char *password ="BuaPW0rk.2017";


// Joystick
#define PIN_JOY_X      34   // Entrada Analógica de coordenada X
#define PIN_JOY_Y      35   // Entrada Analógica de coordenada Y
#define PIN_JOY_BOTON  32   // Entrada Digital del Botón

WebServer server(80);

void setup() {
  Serial.begin(115200);

 //En esta sección declaramos Entradas y Salidas Digitales
  pinMode(PIN_JOY_BOTON, INPUT_PULLUP);

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\n¡Conectado!");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();

  int xValue = analogRead(PIN_JOY_X);
  int yValue = analogRead(PIN_JOY_Y);
  int BotónValue = digitalRead(PIN_JOY_BOTON);


  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | BOTÓN: ");
  Serial.println(BotónValue);

  // Botón presionado
  if (BotónValue == LOW) {
    Serial.println("Botón presionado");
    delay(200);
    return;
  }
  delay(100);
}
