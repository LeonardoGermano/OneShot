

# README - Atividade 2: Temporizador de Um Disparo (One Shot)

## Descrição
Este projeto implementa um sistema de temporização para acionar LEDs com um botão (pushbutton). O sistema usa `add_alarm_in_ms()` para ativar e desligar os LEDs em sequência após um clique no botão.

## Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (Azul, Vermelho e Verde)
- 3 Resistores de 330 Ω
- 1 Botão (Pushbutton)
- Ferramenta Educacional BitDogLab (para testes)

## Como Funciona
1. Quando o usuário pressiona o botão, todos os LEDs são ligados.
2. Após 3 segundos, o LED azul é desligado.
3. Após 6 segundos, o LED vermelho é desligado.
4. Após 9 segundos, o LED verde é desligado e o sistema está pronto para um novo clique no botão.

## Como Executar
1. Configure o ambiente de desenvolvimento no VS Code com o Pico SDK.
2. Clone este repositório e compile o código.
3. Conecte a Raspberry Pi Pico e envie o binário compilado.
4. Pressione o botão para testar a sequência de desligamento dos LEDs.

## Vídeo Demonstrativo
[--]

## Observação
- Durante o ciclo de desligamento dos LEDs, o botão não pode ser pressionado novamente para evitar interferências no processo.

