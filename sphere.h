//
// Created by A on 2023/6/11.
//

#ifndef RAYTRACINGONEWEEKEND_SPHERE_H
#define RAYTRACINGONEWEEKEND_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere: public hittable {
public:
    sphere() {}
    sphere(point3 cen, double  r): center(cen), radius(r) {}
    virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
    point3 center;
    double radius;
};


bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius*radius;

    double discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;

    double sqrtd = sqrt(discriminant);
    double root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) /a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;

    vec3 out_normal = (rec.p -center) / radius;
    rec.set_surface_normal(r, out_normal);

    return true;

}

#endif //RAYTRACINGONEWEEKEND_SPHERE_H
