/*
 * Triangle.h
 *
 *
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_



#include "../core/Shape.h"


namespace rt{

class Triangle: public Shape{
    
public:
   
    Triangle();
    //Triangle(Vec3f, Vec3f,Vec3f,Vec3f, float );
    Triangle (Vec3f A, Vec3f B, Vec3f C, Vec3f trianglenormal, float distance,Material* mater):Shape(mater),A(A),B(B),C(C),trianglenormal(trianglenormal),distance(distance){};

	~Triangle();


	//
	// Functions that need to be implemented, since Plane is a subclass of Shape
	//
    //Vec3f getNormal(Vec3f pi){return Vec3f(1,1,1);}

	Vec3f getNormal(Vec3f a){
        Vec3f CA (C.x-A.x,C.y-A.y,C.z-A.z);
        Vec3f BA (B.x-A.x,B.y-A.y,B.z-A.z);
        //std::cerrs<<"calcu"<<CA.crossProduct(BA).normalize()<<C<<std::endl;

        trianglenormal = CA.crossProduct(BA).normalize();
        return trianglenormal;
        }

	float getTriangleDistance(){
        trianglenormal = getNormal(Vec3f(1,1,1));
        distance = trianglenormal.dotProduct(A);
        return distance;
        }

	Hit intersect(Ray ray, double& t);

    BBox getBBox(){
        BBox b1;

        float ac = pow((A.x-C.x),2)+pow((A.y-C.y),2)+pow((A.z-C.z),2);
        float bc = pow((B.x-C.x),2)+pow((B.y-C.y),2)+pow((B.z-C.z),2);
        float ab = pow((A.x-B.x),2)+pow((A.y-B.y),2)+pow((A.z-B.z),2);

    
        if(ac>bc && ac>ab){
            b1.min=A;
            b1.max=C;

        }
        if((bc>ac && bc>ab)){
            b1.min=B;
            b1.max=C;
        }
        if((ab>ac && ab>bc)){
            b1.min=A;
            b1.max=B;
        }

        return b1;
     }

    Vec3f getCentroid(){
        Vec3f triangecenter;
        triangecenter=(A+B+C)*(1/3);

        return triangecenter;
    }

    Vec2f mapuv(Vec3f p);

  
protected: 
    Vec3f A, B, C;
    Vec3f trianglenormal;
    float distance;
  
    



};




} //namespace rt




#endif /* TRIANGLE_H_ */
