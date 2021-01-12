/*
 * watermark.c
 *
 *  Created on: Jun 12, 2018
 *      Author: dominik
 */

#include "types.h"

// This 8-byte sequence is used to validate the correctness of a symbol table for the indexer
u8 indexer_verification[8] = {1, 3, 3, 7, 4, 2, 4, 2};