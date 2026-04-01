//==============================================================
// drivers/microphone/volume.h
// Controle de volume do microfone
//==============================================================

#ifndef MICROPHONE_VOLUME_H
#define MICROPHONE_VOLUME_H

//==============================
// Constantes de volume
//==============================
#define VOLUME_MIN      0       // Silêncio
#define VOLUME_DEFAULT  128     // Volume médio (0–255)
#define VOLUME_MAX      255     // Máximo

//==============================
// Estrutura de configuração do microfone
//==============================
typedef struct {
    unsigned char volume;   // Volume atual
    unsigned char mute;     // 0 = ativo, 1 = mudo
} mic_volume_t;

//==============================
// Variável global do microfone
//==============================
extern mic_volume_t mic_volume;

//==============================
// Funções do driver de volume
//==============================

/**
 * Inicializa o volume do microfone
 * Define volume padrão e mudo desativado
 */
void mic_volume_init(void);

/**
 * Define o volume do microfone
 * @param vol: 0 (mínimo) a 255 (máximo)
 */
void mic_volume_set(unsigned char vol);

/**
 * Aumenta o volume em um passo
 * @param step: valor a adicionar
 */
void mic_volume_increase(unsigned char step);

/**
 * Diminui o volume em um passo
 * @param step: valor a subtrair
 */
void mic_volume_decrease(unsigned char step);

/**
 * Ativa ou desativa o mudo
 * @param mute: 0 = ativo, 1 = mudo
 */
void mic_volume_mute(unsigned char mute);

#endif // MICROPHONE_VOLUME_H
