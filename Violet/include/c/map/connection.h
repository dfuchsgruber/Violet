/*
 * connection.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_CONNECTION_H_
#define INCLUDE_C_MAP_CONNECTION_H_

// A single map connection

typedef struct {
    u32 direction;
    int displacement;
    u8 bank;
    u8 map;
    u8 field_A;
    u8 field_B;
} map_connection_t;

// A list containing map connections
typedef struct {
    u32 count;
    map_connection_t *connections;
} map_connection_header_t;

#endif /* INCLUDE_C_MAP_CONNECTION_H_ */
