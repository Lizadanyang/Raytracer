/*
 * Shape.h
 *
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "../core/RayHitStructs.h"
#include "../core/Material.h"
#include "../shapes/BBox.h"

namespace rt{

class Shape{
public:

	//
	// Constructors
	//
	//Vec3f color;

	Shape(){};
	Shape(Material* mater){
		material = mater;
	}
	
	
	//
	// Destructor (must be overriden in subclass)
	//
	virtual ~Shape();

	//
	// Shape abstract methods (to be implemented by subclasses)
	//
	virtual Hit intersect(Ray, double&)=0;
	virtual Vec3f getNormal(Vec3f)=0;

	virtual BBox getBBox()= 0;

  //! Return the centroid for this object. (Used in BVH Sorting)
  	virtual Vec3f getCentroid() = 0;

	 virtual Vec2f mapuv(Vec3f p)=0;


//protected:

	Material * material;
	
};


} //namespace rt


#endif /* SHAPE_H_ */
