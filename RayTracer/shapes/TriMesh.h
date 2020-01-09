/*
 * TriMesh.h
 *
 *
 */

#ifndef TRIMESH_H_
#define TRIMESH_H_

#include "../core/Shape.h"

namespace rt{

class TriMesh: public Shape{
    
    public:

        TriMesh();
        TriMesh(Vec3f triangle1A,Vec3f triangle1B, Vec3f triangle1C, Vec3f triangle2E,Vec3f triangle0D,Material* mater):
        Shape(mater),triangle1A(triangle1A),triangle1B(triangle1B),triangle1C(triangle1C),triangle2E(triangle2E),triangle0D(triangle0D){};
        ~TriMesh();
    
        Vec3f triangle1A,triangle1B,triangle1C;
        Vec3f triangle2E,triangle0D;
       

        Vec3f getNormal(Vec3f a){

            Vec3f CA (triangle1C.x-triangle1A.x,triangle1C.y-triangle1A.y,triangle1C.z-triangle1A.z);
            Vec3f BA (triangle1B.x-triangle1A.x,triangle1B.y-triangle1A.y,triangle1B.z-triangle1A.z);
        //std::cerr<<"calcu"<<CA.crossProduct(BA).normalize()<<C<<std::endl;

        Vec3f  meshnormal = CA.crossProduct(BA).normalize();
        return meshnormal;
        
        }

        
        Hit intersect(Ray ray, double& t);

        BBox getBBox(){
        BBox b;
        b.min=triangle0D;
        b.max=triangle2E;
        return b;
        }

	Vec3f getCentroid() {
    return triangle1A;

  }

    Vec2f mapuv(Vec3f p);


};



} //namespace rt




#endif /* TRIMESH_H_ */
