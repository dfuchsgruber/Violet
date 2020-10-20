/*
 * polygon.c
 *
 *  Created on: Feb 19, 2019
 *      Author: dominik
 */

#include "types.h"
#include "math.h"
#include "gpu.h"

void gpu_render_polygon_by_radius(FIXED *ratios, int num_edges, int radius,
		void (*set_pixel)(int, int)) {
	FIXED dphi = FIXED_DIV(INT_TO_FIXED(1), INT_TO_FIXED(6)); // move clockwise
	FIXED phi0 = -FIXED_DIV(INT_TO_FIXED(1), INT_TO_FIXED(4)); // start at 90 degrees
	for (int i = 0; i < num_edges; i++) {
		FIXED phi1 = FIXED_ADD(phi0, i * dphi);
		FIXED phi2 = FIXED_ADD(phi0, (i + 1) * dphi);
		FIXED x1 = FIXED_MUL(FIXED_COS(phi1), ratios[i]);
		FIXED x2 = FIXED_MUL(FIXED_COS(phi2), ratios[(i + 1) % num_edges]);
		FIXED y1 = FIXED_MUL(FIXED_SIN(phi1), ratios[i]);
		FIXED y2 = FIXED_MUL(FIXED_SIN(phi2), ratios[(i + 1) % num_edges]);
		// Draw triangle projected by the matrix [[x1, x2], [y1, y2]]
		for (int x = 0; x < radius; x++) {
			for (int y = 0; y < radius - x; y++) {
				int x_prime = FIXED_TO_INT(x * x1 + y * x2);
				int y_prime = FIXED_TO_INT(x * y1 + y * y2);
				set_pixel(x_prime, y_prime);
			}
		}
	}
}
