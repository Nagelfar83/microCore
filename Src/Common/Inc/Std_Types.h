/*
 * Standard_Types.h
 *
 *  Created on: 18 Sep 2018
 *      Author: Nagelfar
 */

#ifndef SRC_COMMON_INC_STD_TYPES_H_
#define SRC_COMMON_INC_STD_TYPES_H_

#include <stdint.h>

/* Type declaration */
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;

#define E_OK 0x00
#define E_NOT_OK 0x01

typedef uint8 Std_ReturnType;

#endif /* SRC_COMMON_INC_STD_TYPES_H_ */
