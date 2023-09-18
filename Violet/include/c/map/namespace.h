/*
 * namespace.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_NAMESPACE_H_
#define INCLUDE_C_MAP_NAMESPACE_H_

extern const u8 *const map_namespaces[];

/**
 * Loads the string of a namespace to a given buffer
 * @param dst the destination of the namespace string
 * @param the namespace id
 */
void map_load_namespace(u8 *dst, u8 namespace_id);

/**
 * Gets the namespace of the map that is currently loaded.
 * @return the namespace of the current map
 **/
u8 map_get_current_namespace();

#endif /* INCLUDE_C_MAP_NAMESPACE_H_ */
