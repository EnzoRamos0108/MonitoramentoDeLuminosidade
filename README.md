<!DOCTYPE html>
<html lang="pt-BR">
<head>
<meta charset="UTF-8">
 
</head>
<body style="font-family: Arial, sans-serif; line-height: 1.6; max-width: 800px; margin: auto; padding: 20px; background: #f8f8f8; color: #333;">
<h1>🐎 Cyber Horses - Monitoramento de Luminosidade para Vinheria Agnello</h1>
<p>Bem-vindo ao repositório do projeto do sensor de luminosidade da empresa  <strong> Cyber Horses</strong>, desenvolvido para a <strong>Vinheria Agnello</strong> como parte de uma atividade prática com Arduino. Este sistema tem como objetivo <strong>monitorar a luminosidade do ambiente</strong> onde os vinhos são armazenados, garantindo condições ideais de conservação por meio de alertas visuais e sonoros.</p>
 
  <hr>
 
  <h2>📌 Objetivo</h2>
<ul>
<li>Ler os níveis de luminosidade com um sensor LDR.</li>
<li>Avisar com LEDs (verde, amarelo e vermelho) dependendo da luz ambiente.</li>
<li>Emitir alerta sonoro com buzzer em níveis críticos.</li>
<li>Exibir os dados e mensagens no LCD 16x2, como a porcentagem de luminosidade. Esse é nosso <strong>diferencial!</strong>.</li>
<li>Fazer uma <strong>animação de cavalo</strong> no início e exibir mensagens.</li>
</ul>
 
  <hr>
 
  <h2>⚙️ Estrutura do Projeto</h2>
<p>O projeto funciona da seguinte forma:</p>
<ul>
<li>No display LCD 16x2, é exibida uma animação inicial de um cavalo correndo, seguida da mensagem “Boas Vindas“ e o nome do grupo “Cyber Horses”.</li>
<li>O sensor LDR capta a luminosidade do ambiente em tempo real.</li>
<li>O valor da luz é convertido para uma porcentagem usando a função <code>map()</code>.</li>
<li>Depois disso, a porcentagem de luz ambiente é exibida continuamente no display.</li>
<li>Um LED verde acende em condições ideais de luminosidade (penumbra).</li>
<li>Um LED amarelo acende e o buzzer toca em luminosidade moderada (alerta).</li>
<li>Um LED vermelho acende e o buzzer toca em luminosidade alta (crítica).</li>

</ul>
 
  <hr>
 
  <h2>📦 Dependências</h2>
 
  <h3>Componentes:</h3>
<ul>
<li>1x Arduino Uno</li>
<li>1x Sensor de luminosidade (LDR)</li>
<li>3x LEDs (verde, amarelo, vermelho)</li>
<li>5x Resistores para os LEDs (220Ω)</li>
<li>1x Buzzer</li>
<li>1x Display LCD 16x2 </li>
<li>1x Potenciômetro (para ajuste do contraste do LCD)</li>
<li>Jumpers e Protoboard</li>
</ul>
 
  <h3>Biblioteca:</h3>
<ul>
<li><code>LiquidCrystal.h</code> (já incluída por padrão na IDE do Arduino)</li>
</ul>
 
  <hr>
 
  <h2>🚀 Como Reproduzir</h2>
<ol>
<li>Clone ou baixe este repositório.</li>
<li>Abra o arquivo <code>sensor_codigo.ino</code> na <strong>IDE do Arduino</strong>.</li>
<li>Monte o circuito no <strong>Tinkercad</strong> ou fisicamente com os componentes listados.</li>
<li>Faça upload do código para a placa Arduino Uno.</li>
<li>Observe a animação de cavalo no LCD, a mensagem de boas-vindas e os alertas de luminosidade em tempo real.</li>
</ol>
 
  <hr>
 
  <h2>🎬 Demonstração</h2>
<p>📽️ Vídeo da implementação: <br>
  🔗 <a href="https://youtu.be/4OFOkI4_-yM" target="_blank">Link para o vídeo explicativo</a></p>
 
  <p>📸 Simulação no Tinkercad: <br>
  🔗 <a href="https://www.tinkercad.com/things/k4LHzFHOLUS-sensor-de-luminosidade-cp1?sharecode=Iv1HATuLXksxAsXpvUjJxfrMW1nhzDDG-hkY6SXjGIA" target="_blank">Link da simulação pública</a></p>
 
  <hr>
 
  <h2>🤝 Contribuições</h2>
<p>Este projeto foi desenvolvido como parte da avaliação prática da disciplina de Edge Computing and Computer Systems.  
  Tem como destaque:</p>
<ul>
<li>Animação criativa no LCD.</li>
<li>Uso da função <code>map()</code> para converter valores do LDR em porcentagens.</li>
<li>Integração total entre hardware e exibição em display.</li>
<li>Estética, clareza no código e documentação completa.</li>
</ul>
 
  <hr>
 
  <h2>📄 Licença</h2>
<p>Este projeto é de uso educacional. Sinta-se livre para estudar, modificar e se inspirar. ✨</p>
 
  <blockquote style="margin-top: 30px; font-style: italic;">
    Desenvolvido com dedicação, bom humor e muita parceria por Enzo Ramos, Gustavo Peaguda, Felipe Cerazi e Lorenzo Coque 💻
</blockquote>
</body>
</html>
