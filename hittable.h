//
// Created by A on 2023/6/11.
//

#ifndef RAYTRACINGONEWEEKEND_HITTABLE_H
#define RAYTRACINGONEWEEKEND_HITTABLE_H

#include "vec3.h"
#include "ray.h"

struct hit_record {

    /**
     * 交点
     */
    point3 p;

    /**
     * 交点法线
     */
    vec3 normal;

    /**
     * t
     */
    double t;

    bool front_surface;


    inline void set_surface_normal(const ray& r, const vec3& outward_normal) {
        front_surface = dot(r.direction(), outward_normal) < 0;
        normal = front_surface ? outward_normal : -outward_normal;
    }

};

class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif //RAYTRACINGONEWEEKEND_HITTABLE_H
