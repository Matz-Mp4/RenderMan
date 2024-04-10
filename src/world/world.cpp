#include "../../include/world.h"
#include "../../include/MultipleObjects.h"
#include "../../include/shade_rec.h"
#include "../../include/sphere.h"
#include "../../include/plane.h"

const double kHugeValue	= 1.0E10;

void World::build() {
    vp.length = 200;
    vp.height = 200;
    vp.pixel_size = 1.0;
    vp.gamma = 1.0;

    bg = BLACK;
    tracer_ptr = new MultipleObjects(this);
    Sphere* sphere = new Sphere();
    sphere->center = 0.0;
    sphere->radius = 85.0;
    add_object(sphere);

    sphere = new Sphere(Point4(0.0,30.0,60.0), 60);
    add_object(sphere);

    Plane* plane = new Plane();
    add_object(plane);
}

void World::render_scene() const {
    Color pixel_color;
    Ray ray;
    double x, y, zw = 100.0; //hard wired in (temporary)
    
    open_window(vp.length, vp.height);
    ray.direction = Vector4(0.0,0.0,-1.0);

    for(int i = 0; i < vp.height; i++) {
        for(int j = 0; j < vp.length; j++) {
            x = vp.pixel_size * (j - 0.5 * (vp.length - 1.0));
            y = vp.pixel_size * (i - 0.5 * (vp.height - 1.0));
            ray.origin = Point4(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(i, j, pixel_color);
        }
    }

}

void World::display_pixel(const int row, const int column, const Color& pixel_color) const{
}

void World::open_window(const int length, const int hight) const {
}


void World::add_object(GeometricObject* object_ptr){
    objects.push_back(object_ptr);
}

ShadeRec World::hit_bare_bones_objects(const Ray& ray) {
    ShadeRec shade_rec(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = objects.size();

    for(int i = 0; i < num_objects; i++) {
        if(objects[i]->hit(ray, t, shade_rec) && (t < tmin) ){
            shade_rec.hit_object = true;
            tmin = t;
            shade_rec.color = objects[i]->get_color();
        }
    }

    return shade_rec;
}

