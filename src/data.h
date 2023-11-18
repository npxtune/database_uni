#pragma once
#include <stdint.h>
#include <stdbool.h>
int8_t data_handler(int32_t id_argument);
bool product_data_exists(uint64_t product_id);
bool customer_data_exists(uint64_t customer_id);