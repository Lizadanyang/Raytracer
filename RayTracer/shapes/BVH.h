/*
 * BVH.h
 *
 *
 */

#ifndef BVH_H_
#define BVH_H_

#include "../core/Shape.h"

#include "../shapes/BBox.h"
#include <vector>
#include <limits>
#include <cstddef>
#include <iostream>



namespace rt{
      
      


class BVH{
    
    public:


    Hit intersect(Ray ray,double& t);

   
    //std::vector<Shape*> build_prims;

    //! Build the BVH tree out of build_prims
  

    // Fast Traversal System;
    

    Hit shapehit;
    
    BVH(std::vector<Shape*> objects, Ray ray);
    
    //bool getIntersection(const Ray& ray, IntersectionInfo *intersection, bool occlusion) const ;

    ~BVH();

    private:

    //vector<Shape*> objects;
    std::vector<Shape*> build_prims;
  




       



        




      
  

    
    
    };
       


} //namespace rt



#endif /* BVH_H_ */
