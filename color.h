//
// Created by A on 2023/6/11.
//

#ifndef RAYTRACINGONEWEEKEND_COLOR_H
#define RAYTRACINGONEWEEKEND_COLOR_H

#include "vec3.h"

#include <iostream>
#include "rtweekend.h"

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {

    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // Divide the color by the number of samples.
    double scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif //RAYTRACINGONEWEEKEND_COLOR_H
