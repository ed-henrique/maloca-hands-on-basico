#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

// Defina o pino do sensor DHT11
#define DHTPIN 4       // Pino de dados do DHT11 conectado ao GPIO 4

// Defina o tipo de sensor (DHT11)
#define DHTTYPE DHT11  

// Defina a rede WiFi
const char* ssid = "SSID_DA_REDE";           // Substitua pelo nome da sua rede Wi-Fi
const char* password = "SENHA_DA_REDE";      // Substitua pela senha da sua rede Wi-Fi

// Defina o canal do ThingSpeak (substitua com o seu canal ID e chave de escrita)
unsigned long channelID = 00000000;         // Substitua pelo seu canal ThingSpeak ID
const char * writeAPIKey = "CHAVE";         // Substitua pela chave de escrita do seu canal

// Inicialize o sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

// Inicialize a conexão WiFi
WiFiClient client;

void setup() {
  // Inicia a comunicação serial para monitoramento
  Serial.begin(115200);
  
  // Inicia o sensor DHT11
  dht.begin();
  
  // Conecta-se à rede Wi-Fi
  Serial.println("Conectando-se à rede Wi-Fi...");
  WiFi.begin(ssid, password);
  
  // Aguarda conexão com a rede Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }
  
  Serial.println("Conexão Wi-Fi estabelecida!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // Lê os valores de temperatura e umidade
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  // Verifica se a leitura falhou
  if (isnan(t) || isnan(h)) {
    Serial.println("Falha na leitura do sensor!");
    return;
  }

  // Exibe os dados na porta serial
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" ºC\t");
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");
  
  // Envia os dados para o ThingSpeak
  ThingSpeak.setField(1, t);   // Temperatura
  ThingSpeak.setField(2, h);   // Umidade
  
  // Envia os dados para o ThingSpeak a cada 20 segundos
  int httpResponseCode = ThingSpeak.writeFields(channelID, writeAPIKey);
  
  if (httpResponseCode == 200) {
    Serial.println("Dados enviados para o ThingSpeak com sucesso.");
  } else {
    Serial.println("Falha ao enviar dados para o ThingSpeak.");
  }
  
  // Verifica se a temperatura está acima de um limite de alerta
  if (t > 37.8) {  // Temperatura acima de 37.8°C, possível febre
    Serial.println("Alerta: Temperatura elevada detectada!");
    // Aqui você pode adicionar mais ações, como enviar uma notificação, ativar um alarme, etc.
  }
  
  // Atraso de 20 segundos antes de enviar novos dados
  delay(5000);  // 20 segundos
}