//==============================================================
// drivers/microphone/microphone_permission_and_control.h
// Controle de permissão e funcionalidades do microfone
//==============================================================

#ifndef MICROPHONE_PERMISSION_AND_CONTROL_H
#define MICROPHONE_PERMISSION_AND_CONTROL_H

#include "volume.h"    // Integração com controle de volume

//==============================
// Estados de permissão do microfone
//==============================
#define MIC_PERMISSION_DENIED     0
#define MIC_PERMISSION_GRANTED    1

//==============================
// Estados de operação do microfone
//==============================
#define MIC_STATE_OFF             0
#define MIC_STATE_ON              1
#define MIC_STATE_TRANSMITTING    2

//==============================
// Estrutura principal do microfone
//==============================
typedef struct {
    unsigned char permission;   // 0 = negada, 1 = concedida
    unsigned char state;        // off/on/transmitindo
    mic_volume_t volume;        // Controle de volume integrado
} mic_control_t;

//==============================
// Variável global do microfone
//==============================
extern mic_control_t microphone;

//==============================
// Funções de controle do microfone
//==============================

/**
 * Solicita permissão para usar o microfone
 * @return 0 = negada, 1 = concedida
 */
unsigned char mic_request_permission(void);

/**
 * Ativa o microfone se a permissão estiver concedida
 */
void mic_enable(void);

/**
 * Desativa o microfone
 */
void mic_disable(void);

/**
 * Começa a transmissão de áudio
 * Só funciona se o microfone estiver ativo e permissão concedida
 */
void mic_start_transmit(void);

/**
 * Para a transmissão de áudio
 */
void mic_stop_transmit(void);

/**
 * Atualiza o volume do microfone
 * @param vol: 0 a 255
 */
void mic_set_volume(unsigned char vol);

/**
 * Ativa ou desativa mudo
 * @param mute: 0 = ativo, 1 = mudo
 */
void mic_set_mute(unsigned char mute);

#endif // MICROPHONE_PERMISSION_AND_CONTROL_H
