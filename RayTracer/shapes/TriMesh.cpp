/*
 * TriMesh.cpp
 *
 *
 */
#include "TriMesh.h"


namespace rt{
    TriMesh::~TriMesh(){};

    Hit TriMesh::intersect(Ray ray, double& t){

        Hit h;
		Vec3f o = ray.camposition;
		Vec3f d = ray.camdirection;

        Vec3f A = TriMesh::triangle1A;
		Vec3f B = TriMesh::triangle1B;
		Vec3f C = TriMesh::triangle1C;
		Vec3f D = TriMesh::triangle0D;
        Vec3f E = TriMesh::triangle2E;
        // CA BA
        Vec3f CA (C.x-A.x,C.y-A.y,C.z-A.z);
        Vec3f BA (B.x-A.x,B.y-A.y,B.z-A.z);

        Vec3f planenormal1 = CA.crossProduct(BA).normalize();
        //std::cerr<<"nor"<<trianglenormal1<<std::endl;

        float a = d.dotProduct(planenormal1);
        float u = ((o-A).dotProduct(d.crossProduct(CA)) )/ (BA.dotProduct(d.crossProduct(CA)));
        float v = d.dotProduct((o-A).crossProduct(BA))/ (BA.dotProduct(d.crossProduct(CA)));
        
		//BA DA 
        Vec3f DA = D-A;
       

		Vec3f planenormal2 = DA.crossProduct(BA).normalize();

		float a1 = d.dotProduct(planenormal2);
		float u1 = ((o-A).dotProduct(d.crossProduct(DA)) )/ (BA.dotProduct(d.crossProduct(DA)));
        float v1 = d.dotProduct((o-A).crossProduct(BA))/ (BA.dotProduct(d.crossProduct(DA)));
        
        // EA CA
        Vec3f EA =E-A;
      

		Vec3f planenormal3 = CA.crossProduct(EA).normalize();

		float a2 = d.dotProduct(planenormal3);
		float u2 = ((o-A).dotProduct(d.crossProduct(CA)) )/ (EA.dotProduct(d.crossProduct(CA)));
        float v2 = d.dotProduct((o-A).crossProduct(EA))/ (EA.dotProduct(d.crossProduct(CA)));

        if (u>0 && u<1 && v>0 && v<1){
            t = (CA.dotProduct((o-A).crossProduct(BA))) / (BA.dotProduct(d.crossProduct(CA)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
			//std::cerr<<"u+v"<<std::endl;
		}
		else if(u1>0 && u1<1 && v1>0 && v1<1){
			t = (DA.dotProduct((o-A).crossProduct(BA))) / (BA.dotProduct(d.crossProduct(DA)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
		 	//std::cerr<<"u1+v1"<<std::endl;

		}
        else if(u2>0 && u2<1 && v2>0 && v2<1){
			t = (CA.dotProduct((o-A).crossProduct(EA))) / (EA.dotProduct(d.crossProduct(CA)));
            Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
		 	//std::cerr<<"u1+v1"<<std::endl;

		}
        else{h.notMiss=false;}

        return h;
    }


    Vec2f TriMesh::mapuv(Vec3f p){
        Vec2f result;
       
        return result;
	}






} //namespace rt


