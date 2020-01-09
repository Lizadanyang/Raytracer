/*
 * Plane.h
 *
 *
 */

#ifndef PLANE_H_
#define PLANE_H_


#include "../core/Shape.h"

namespace rt{

class Plane:public Shape{
    Vec3f planenormal;
    float planedistance;

public:

	//
	// Constructors
	//

    Plane();
    Plane(Vec3f planepointA, Vec3f planepointB,Vec3f planepointC, Vec3f planepointD, Vec3f planenormal, float planedistance,Material* mater):Shape(mater),planepointA(planepointA),planepointB(planepointB),planepointC(planepointC),planepointD(planepointD),planenormal(planenormal),planedistance(planedistance){};

	~Plane();


	//
	// Functions that need to be implemented, since Plane is a subclass of Shape
	//
	
	Vec3f getPlaneNormal(){return planenormal;}
	float getPlaneDistance(){return planedistance;}
	
	Vec3f getNormal(Vec3f pi){
		Vec3f CA (planepointC.x-planepointA.x,planepointC.y-planepointA.y,planepointC.z-planepointA.z);
        Vec3f BA (planepointC.x-planepointB.x,planepointC.y-planepointB.y,planepointC.z-planepointB.z);
        //std::cerr<<"calcu"<<CA.crossProduct(BA).normalize()<<C<<std::endl;

        planenormal = CA.crossProduct(BA).normalize();
		return planenormal;}

	Hit intersect(Ray ray, double& t);

    Vec3f getNormalAt(Vec3f planepoint){
        return planenormal;
    }
	Vec3f getPlaneposition(){
		Vec3f planeposition = (planepointA+planepointB+planepointC+planepointD)*(1/4);
		return planeposition;
	}

	BBox getBBox(){
        BBox b;
        b.min=planepointA;
        b.max=planepointD;
        return b;
    }

	  Vec3f getCentroid(){
        Vec3f planecenter=(planepointA+planepointB+planepointC+planepointD)*(1/4);
       
        return planecenter;
    }

	 Vec2f mapuv(Vec3f p);


    

protected:
	Vec3f planepointA,planepointB,planepointC,planepointD;


};

// Plane::Plane (){
// 	normal = Vec3f(1,0,0);
// 	distance = 0.0;
// }



} //namespace rt




#endif /* Plane_H_ */
