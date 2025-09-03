/*
 * Special Edition Funstion of INAV
 */

#pragma once
#include "build/version.h"

//FC_FIRMWARE_IDENTIFIER нет в INAV
#ifndef FC_FIRMWARE_IDENTIFIER
#define SE_INAV
#else
#define SE_BF
#endif 

#ifdef SE_BF
#include "pg/pg.h"
#include "pg/piniobox.h"
#include "msp/msp_box.h"
#endif 

#ifdef SE_INAV
#include "config/parameter_group.h"
#include "io/piniobox.h"
#include "fc/fc_msp_box.h"
#endif 

#include "drivers/io_types.h"


// configirated from cli command
typedef struct seConfig_s {
    uint16_t se_test1;
    uint16_t shock_acc_thr;
    uint32_t shock_delay_ms;
    uint8_t shock_box_permanentid;
} seConfig_t;

PG_DECLARE(seConfig_t, seConfig);

// se Shock Sensor
typedef struct seShockValues_s {
    bool init;
    bool enable;
	float acc_thr;
    float acc_max;
    float accADC_max;
    float GForce;
    int pinio_index;
    bool isOn;
    uint32_t enableOnTick;
    const box_t *box;
    bool arm_isOn;
    bool box_isOn;
} seShockValues_t;

void seShockInit(void);
void seShockSetEnable(int pinio_index, boxId_e boxid);
void seShockUpdate(float accADCf);
uint8_t seShockGetBoxId(void);