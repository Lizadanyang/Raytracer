/*
 * RayTracer.h
 *
 */
#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "../core/Camera.h"
#include "../core/Scene.h"
#include "../shapes/BVH.h"

namespace rt{



/*
 * Raytracer class declaration
 */
class RayTracer {
public:

	RayTracer();

	static Vec3f* render(Camera* camera, Scene* scene, int nbounces);
	static Vec3f* tonemap(Vec3f* pixelbuffer,int image_sizes);
	static Vec3f tracepath(Scene* scene, Ray ray, int depth,Vec3f hitpoint,Vec3f N,Vec3f color);
	
	

private:


};




} //namespace rt



#endif /* RAYTRACER_H_ */

