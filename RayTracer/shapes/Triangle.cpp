/*
 * Triangle.cpp
 *
 *
 */
#include "Triangle.h"




namespace rt{
Triangle::~Triangle(){};

Hit Triangle::intersect(Ray ray,double& t){

		Hit h;
       
		Vec3f o = ray.camposition;
		Vec3f d = ray.camdirection;
        //std::cerr<<"ns"<<getTriangleNormal()<<std::endl;
        //std::cerr<<"A"<<B<<std::endl;
		//-----------to be implemented -------------
        

        Vec3f CA (C.x-A.x,C.y-A.y,C.z-A.z);
        Vec3f BA (B.x-A.x,B.y-A.y,B.z-A.z);

        

        Vec3f trianglenormal1 = CA.crossProduct(BA).normalize();
        //std::cerr<<"nor"<<trianglenormal1<<std::endl;

        float a = d.dotProduct(trianglenormal1);
        float u = ((o-A).dotProduct(d.crossProduct(CA)) )/ (BA.dotProduct(d.crossProduct(CA)));

        float v = d.dotProduct((o-A).crossProduct(BA))/ (BA.dotProduct(d.crossProduct(CA)));
        
        if((u<0)||(u>1)){
            h.notMiss=false;
            //std::cerr<<"uv1"<<trianglenormal1<<std::endl;


        }
        else if((v<0||(u+v)>1)){
            h.notMiss=false;
            //std::cerr<<"uv2"<<trianglenormal1<<std::endl;

        }
        else{
            t = (CA.dotProduct((o-A).crossProduct(BA))) / (BA.dotProduct(d.crossProduct(CA)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
            //std::cerr<<"nor"<<h.hitPoint<<std::endl;

        }
          

		return h;

	}


    Vec2f Triangle::mapuv(Vec3f p){
        Vec2f result;
       
        return result;
	}




} //namespace rt
