/*
 * Plane.cpp
 *
 *
 */
#include "Plane.h"


namespace rt{


	/**
	 * Computes whether a ray hit the specific instance of a Plane shape and returns the hit data
	 *
	 * @param ray cast ray to check for intersection with shape
	 *
	 * @return hit struct containing intersection information
	 *
	 */
	Plane::~Plane(){};
	Hit Plane::intersect(Ray ray, double& t){

		Hit h;
		Vec3f o = ray.camposition;
		Vec3f d = ray.camdirection;

		
		Vec3f A = Plane::planepointA;
		Vec3f B = Plane::planepointB;
		Vec3f C = Plane::planepointC;
		Vec3f D = Plane::planepointD;
		

		Vec3f CA (C.x-A.x,C.y-A.y,C.z-A.z);
        Vec3f BA (B.x-A.x,B.y-A.y,B.z-A.z);

        Vec3f planenormal1 = CA.crossProduct(BA).normalize();
        //std::cerr<<"nor"<<trianglenormal1<<std::endl;

        float a = d.dotProduct(planenormal1);
        float u = ((o-A).dotProduct(d.crossProduct(CA)) )/ (BA.dotProduct(d.crossProduct(CA)));
        float v = d.dotProduct((o-A).crossProduct(BA))/ (BA.dotProduct(d.crossProduct(CA)));
        
		Vec3f CD (C.x-D.x,C.y-D.y,C.z-D.z);
        Vec3f BD (B.x-D.x,B.y-D.y,B.z-D.z);

		Vec3f planenormal2 = CD.crossProduct(BD).normalize();

		float a1 = d.dotProduct(planenormal2);
		float u1 = ((o-D).dotProduct(d.crossProduct(CD)) )/ (BD.dotProduct(d.crossProduct(CD)));
        float v1 = d.dotProduct((o-D).crossProduct(BD))/ (BD.dotProduct(d.crossProduct(CD)));


		if (u>0 && u<1 && v>0 && v<1){
            t = (CA.dotProduct((o-A).crossProduct(BA))) / (BA.dotProduct(d.crossProduct(CA)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
			//std::cerr<<"u+v"<<std::endl;
		}
		else if(u1>0 && u1<1 && v1>0 && v1<1){
			t = (CD.dotProduct((o-D).crossProduct(BD))) / (BD.dotProduct(d.crossProduct(CD)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
		 	//std::cerr<<"u1+v1"<<std::endl;

		}

		else{h.notMiss=false;}
		

	
		return h;

	}


    Vec2f Plane::mapuv(Vec3f p){
        Vec2f result;
       
        return result;
	}




} //namespace rt


