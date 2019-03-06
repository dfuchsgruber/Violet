/*
 * gpu.h
 *
 *  Created on: Feb 19, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_GPU_H_
#define INCLUDE_C_GPU_H_

/**
 * Draws a rasterized line
 * @param x0 x coordinate of first point
 * @param y0 y coordinate of first point
 * @param x1 x coordinate of second point
 * @param y1 y coordinate of second point
 * @param set_pixel callback that draws a pixel at given coordinates
 */
void gpu_render_line(int x0, int y0, int x1, int y1, void (*set_pixel)(int, int));

/**
 * Draws a rasterized polygon with N edges centered at an image with size 2 * radius.
 * @param ratios a set of N ratios <= 1.0 that give the length of the line from the center to
 * the edge (ratio * radius)
 * @param num_edges the number of edges the polygon has
 * @param max_radius the maximal radius of the polygon. Do not use a ratio of > 1.0, instead use a
 * larger maximal radius to scale, otherwise some points in the polygon might not be drawn
 * @param set_pixel callback that draws a pixel at given coordinates. All coordinates it receives
 * are in the range [-radius, radius]. These pixels fill the entire polygon
 */
void gpu_render_polygon_by_radius(FIXED *ratios, int num_edges, int max_radius,
		void (*set_pixel)(int, int));

#endif /* INCLUDE_C_GPU_H_ */
