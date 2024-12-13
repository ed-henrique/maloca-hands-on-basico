# Maloca das iCoisas - Hands On Básico

Projetos realizados no curso Maloca das iCoisas pelo grupo 13 - Os Suricatos Cibernéticos.

## Big Picture
### Storytelling
![Big Picture](./big_picture.png)
### Situação Hipotética

1. Pessoa doente vai para o hospital, é atendida e admitida na internação;
2. Médicos colocam sensores de temperatura fixos no corpo da paciente;
3. Sensor de temperatura é conectado a uma base de dados alimentada em tempo real;
4. Quando a temperatua do paciente for ≥ 37.8 ºC, o sistema emite um alerta para os profissionais envolvidos;
5. O sistema registra o histórico da temperatura do paciente na base de dados;
6. O profissional verifica condição do paciente após alertas.

## Equipe

<div align="center">

![Organograma](./organograma.svg)

</div>

- **Product Owner**: Marcelle Alencar Urquiza
- **Scrum Master**: Eduardo Henrique Freire Machado

### Equipe de Desenvolvimento

- Eduardo Henrique Freire Machado;
- Gabriel Peixoto Menezes da Costa;
- Natália Ribeiro de Almada;

## Esquema de Conexão

![Esquema de Conexão](./esquema_de_conexao.jpeg)

**Conexões**:

- Pino VCC -> 3.3V do ESP32;
- Pino GND -> GND do ESP32;
- Pino Data -> GPIO 4 (ou qualquer pino disponível no ESP32);

### Requisitos

#### Hardware

- ESP32;
- Sensor DHT22;
- Protoboard e fios de conexão;

#### Software

- Arduino IDE com as bibliotecas DHT, WiFi e ThingSpeak;

## Recursos

- [Kanban](https://trello.com/b/ZGD00PBo/hands-on-maloca)
- [Big Picture]()
- [Esquema de Conexão](https://wokwi.com/projects/417194889520795649)
- [Documento de Definição de Pronto](https://docs.google.com/document/d/19DEppOgMY5BuyY0HxtlvK1HDf5n62W19/edit)
- [Documento de Requisitos Funcionais](https://docs.google.com/document/d/17LjGt8pkkPYk2qunanWLQsBvVkvb5q1w/edit)
