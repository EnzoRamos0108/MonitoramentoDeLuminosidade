// Inclui a biblioteca LiquidCrystal para controlar o display LCD
#include <LiquidCrystal.h>

// Define a frequência do tom que será utilizado no buzzer (nota C4)
#define C4 262 // Tom para o buzzer

// Inicializa o LCD, conectando os pinos rs, en, d4, d5, d6, d7 aos pinos 7, 6, 5, 4, 3 e 2 do Arduino
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Definição dos pinos para o LDR e LEDs
int pinLDR = A0; // Pino analógico A0 para o sensor de luminosidade (LDR)
const int ledRed = 10;    // Pino 10 para o LED vermelho
const int ledYellow = 9;  // Pino 9 para o LED amarelo
const int ledGreen = 8;   // Pino 8 para o LED verde
const int buzzer = 11;    // Pino 11 para o buzzer

// Definindo os valores mínimos e máximos de leitura do LDR
const int LDR_MIN = 0;    // Valor mínimo da leitura do LDR
const int LDR_MAX = 680;  // Valor máximo da leitura do LDR (máximo medido no ambiente)

const int notaAlerta = C4; // A nota que o buzzer irá emitir durante o alerta

// Definindo a animação do cavalo, que será uma sequência de frames
byte framesCavalo[2][8][8] = { // Cada "frame" é uma matriz de 8x8 pixels
  {
    {0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0E, 0x0E},
    {0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x05, 0x1F, 0x1D, 0x1F, 0x16, 0x06},
    {0x0C, 0x18, 0x10, 0x00, 0x01, 0x01, 0x01, 0x00},
    {0x1F, 0x1F, 0x1E, 0x17, 0x00, 0x00, 0x10, 0x00},
    {0x1F, 0x1F, 0x03, 0x02, 0x14, 0x04, 0x02, 0x00},
    {0x1C, 0x1C, 0x04, 0x04, 0x08, 0x00, 0x00, 0x00}
  },
  {
    {0x00, 0x00, 0x00, 0x07, 0x0F, 0x0E, 0x1C, 0x18},
    {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x01, 0x03, 0x1F, 0x1F, 0x1F, 0x1F},
    {0x14, 0x1C, 0x1A, 0x1E, 0x1F, 0x13, 0x10, 0x10},
    {0x13, 0x13, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00},
    {0x1F, 0x07, 0x0E, 0x06, 0x01, 0x00, 0x00, 0x00},
    {0x0F, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00},
    {0x10, 0x18, 0x0C, 0x02, 0x02, 0x11, 0x00, 0x00}
  }
};

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
  Serial.begin(9600); // Inicia a comunicação serial para monitoramento de dados

  // Configura os pinos dos LEDs e do buzzer como saída
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Inicia a animação do cavalo
  for (int pos = -3; pos <= 13; pos++) { // A animação vai se mover de -3 a 13
    int f = pos % 2; // A cada nova posição, alterna entre os dois frames da animação
    if (f < 0) f += 2; // Caso o valor de 'f' seja negativo, ajusta para garantir que seja 0 ou 1

    lcd.clear(); // Limpa a tela do LCD
    // Cria os 8 caracteres do LCD para formar a animação
    for (int i = 0; i < 8; i++) {
      lcd.createChar(i, framesCavalo[f][i]); // Cria os caracteres com base nos frames
    }
    // Exibe os 4 quadros do cavalo
    for (int c = 0; c < 4; c++) {
      int x = pos + c;  // Calcula a posição horizontal
      if (x >= 0 && x < 16) { // Verifica se a posição está dentro dos limites da tela LCD
        lcd.setCursor(x, 0); lcd.write(byte(c)); // Escreve o byte (quadro) na linha 0
        lcd.setCursor(x, 1); lcd.write(byte(c + 4)); // Escreve o quadro na linha 1
      }
    }
    delay(300); // Atraso de 300ms para animar cada quadro
  }

  // Mensagem de boas-vindas
  lcd.clear(); // Limpa o LCD
  lcd.setCursor(0, 0); // Define o cursor na posição (0, 0)
  lcd.print("Boas Vindas     "); // Exibe a mensagem de boas-vindas na linha 0
  lcd.setCursor(0, 1); // Define o cursor na segunda linha
  lcd.print("Cyber Horses    "); // Exibe o nome da empresa ou do projeto
  delay(5000); // Aguarda 5 segundos
  lcd.clear(); // Limpa o LCD após a exibição da mensagem
}

void loop() {
  // Lê o valor do LDR (sensor de luminosidade) e armazena em 'dataLDR'
  int dataLDR = analogRead(pinLDR); 
  dataLDR = constrain(dataLDR, LDR_MIN, LDR_MAX); // Limita os valores lidos para o intervalo de LDR_MIN a LDR_MAX
  int luminosidade = map(dataLDR, LDR_MIN, LDR_MAX, 0, 100); // Mapeia os valores lidos para 0% a 100% de luminosidade

  // Exibe os valores lidos no monitor serial para depuração
  Serial.print("LDR: ");
  Serial.print(dataLDR); 
  Serial.print(" | Luminosidade: ");
  Serial.print(luminosidade); 
  Serial.println("%");

  // Exibe a luminosidade no LCD na linha 0
  lcd.setCursor(0, 0);
  lcd.print("Lum: ");
  lcd.print(luminosidade);
  lcd.print("%       "); // Exibe a luminosidade com um espaço extra para limpar o texto antigo

  // Desliga os LEDs e buzzer antes de cada verificação
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  noTone(buzzer); // Desliga o buzzer

  // Verifica os níveis de luminosidade e aciona LEDs e buzzer conforme necessário
  if (luminosidade <= 30) { // Se a luminosidade for menor ou igual a 30%, o ambiente está ideal
    lcd.setCursor(0, 1);
    lcd.print("Ambiente ideal  "); // Exibe "Ambiente ideal"
    digitalWrite(ledGreen, HIGH); // Acende o LED verde
  } else if (luminosidade <= 60) { // Se a luminosidade for menor ou igual a 60%, mas maior que 30%, há alerta de luz alta
    lcd.setCursor(0, 1);
    lcd.print("Alerta luz alta "); // Exibe "Alerta luz alta"
    digitalWrite(ledYellow, HIGH); // Acende o LED amarelo
    tone(buzzer, notaAlerta, 3000); // Emite um som por 3 segundos
  } else { // Se a luminosidade for maior que 60%, acende o LED vermelho e emite alerta
    lcd.setCursor(0, 1);
    lcd.print("Alerta luz alta "); // Exibe "Alerta luz alta"
    digitalWrite(ledRed, HIGH); // Acende o LED vermelho
    tone(buzzer, notaAlerta, 3000); // Emite um som por 3 segundos
  }

  delay(1000); // Aguarda 1 segundo antes de fazer nova leitura
}
