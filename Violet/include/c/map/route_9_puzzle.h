#ifndef INCLUDE_C_MAP_ROUTE_9_PUZZLE_H_
#define INCLUDE_C_MAP_ROUTE_9_PUZZLE_H_

#include "types.h"

/**
 * Checks if a connection between rocks is set.
 * @param first idx of the first rock
 * @param second idx of the second rock
 * @return if the connection between those two rocks was drawn
 */
bool route_9_cave_puzzle_connection_check(int first, int second);

/**
 * Sets the connection between two rocks.
 * @param first idx of the first rock
 * @param second idx of the second rock
 */
void route_9_cave_puzzle_connection_set(int first, int second);

/**
 * Gets the state of the cave puzzle.
 * @return the number of valid lines in the pentagram or -1 if any line is invalid
 */
s16 route_9_cave_puzzle_get_state();

/**
 * Sets the index of the rock that was spoken to last. Value taken from variable 0x8000.
 */
void route_9_cave_puzzle_set_last_rock();

/**
 * Gets the index of the rock that was spoken to last
 * @return idx the index of the rock
 */
s16 route_9_cave_puzzle_get_last_rock();

/**
 * Triggered when speaking to a rock. Sets the line to the previous rock. Value taken from variable 0x8000.
 */
void route_9_cave_puzzle_rock();

/**
 * Resets the state of the cave puzzle
 */
void route_9_cave_puzzle_reset();

#endif /* INCLUDE_C_MAP_ROUTE_9_PUZZLE_H_ */
