#pragma once

#include <SoftwareSerial.h>

#define HEAD {0x55, 0xAA}
#define HEAD_SIZE 2
#define END 0xFF

typedef struct __attribute__((packed))
{
    char head[HEAD_SIZE] = HEAD;
    float temperature;
    float humidity;
    float pm25;
    char end = END;
} ENVDATA;

SoftwareSerial* serial;

void communication_init(const uint8_t rx, const uint8_t tx);
void communication_send(ENVDATA *envdata);
