/*
 * Sphere.h
 *
 *
 */

#ifndef SPHERE_H_
#define SPHERE_H_


#include "../core/Shape.h"

namespace rt{

class Sphere:public Shape{

public:

	//
	// Constructors
	//
	Sphere();
	Sphere(Vec3f center, float radius, Material* mater):Shape(mater),center(center),radius(radius){};
		
	~Sphere();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//

	Vec3f getSphereCenter(){return center;}
	float getSphereRadius(){return radius;}
	

	Hit intersect(Ray ray,double& t);
	//Vec3f getNormal(Vec3f);
	Vec3f getNormal(Vec3f pi){
		
		Vec3f a=pi-center;
		Vec3f result;
		result.x=(a.x)/radius;
		result.y=(a.y)/radius;
		result.z=(a.z)/radius;
	
		return result;
	}

	BBox getBBox(){
        BBox b;
        b.min=center + Vec3f(radius,radius,radius);
        b.max=center - Vec3f(radius,radius,radius);
        return b;
     }

	Vec3f getCentroid() {
    return center;
  }

  Vec2f mapuv(Vec3f p);

private:

	Vec3f center;
	float radius;


};

// Sphere::Sphere (){
// 	center = Vec3f(0,0,0);
// 	radius = 1.0;
// }






} //namespace rt




#endif /* SPHERE_H_ */
