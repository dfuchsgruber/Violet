/*
 * bresenham.c
 *
 *  Created on: Feb 19, 2019
 *      Author: dominik
 */
#include "types.h"
#include "math.h"
#include "gpu.h"

void gpu_render_line(int x0, int y0, int x1, int y1, void (*set_pixel)(int, int)) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int inc_x = SGN(dx);
	int inc_y = SGN(dy);
	dx = ABS(dx);
	dy = ABS(dy);

	int pdx, pdy, ddx, ddy, dslow, dfast;

	// Compute the fast direction
	if (dx > dy) {
		// Horizontal iteration
		pdx = inc_x; pdy = 0;
		ddx = inc_x; ddy = inc_y;
		dslow = dy; dfast = dx;
	} else {
		// Vertical direction
		pdx = 0; pdy = inc_y;
		ddx = inc_x; ddy = inc_y;
		dslow = dx; dfast = dy;
	}
	int x = x0;
	int y = y0;
	int err = dfast / 2;
	set_pixel(x, y);

	// Draw line pixels
	for (int t = 0; t < dfast; t++) {
		err -= dslow;
		if (err < 0) {
			err += dfast;
			x += ddx;
			y += ddy;
		} else {
			x += pdx;
			y += pdy;
		}
		set_pixel(x, y);
	}
}
