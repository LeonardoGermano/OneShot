#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos
#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

// Variável para verificar se o sistema está ativo
bool ativo = false;

// Estado do LED no ciclo de desligamento
int estado = 0;

// Callback para desligar LEDs em etapas
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (estado == 1) {
        gpio_put(LED_BLUE, 0);  // Desliga o LED Azul
    } else if (estado == 2) {
        gpio_put(LED_RED, 0);   // Desliga o LED Vermelho
    } else if (estado == 3) {
        gpio_put(LED_GREEN, 0); // Desliga o LED Verde
        ativo = false;  // Permite um novo acionamento do botão
    }
    
    estado++;  // Próximo estado do LED
    return 0;  // Timer de disparo único (one-shot)
}

// Callback do botão para ativar LEDs
void button_callback(uint gpio, uint32_t events) {
    if (!ativo) {
        ativo = true;
        estado = 1;  // Reinicia o ciclo de desligamento
        
        // Liga todos os LEDs
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);

        // Configura os timers para desligar os LEDs em etapas
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        add_alarm_in_ms(6000, turn_off_callback, NULL, false);
        add_alarm_in_ms(9000, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Configuração dos LEDs como saída
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Configuração do botão como entrada com pull-up interno
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Ativação da interrupção do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        printf("Aguardando clique no botão...\n");
        sleep_ms(1000);
    }
}
