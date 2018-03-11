#ifndef __DHT11_H__
#define __DHT11_H__

#include "defs.h"


typedef struct {
    byte humidity;
    byte temperature;
} DHT_data;

typedef enum {
    TIMEOUT,
    CHECKSUM,
    OK
} DHT11_status;

DHT_data DHT;

DHT11_status DHT11_read();
inline void DHT11_as_input();
inline void DHT11_as_output();



#endif