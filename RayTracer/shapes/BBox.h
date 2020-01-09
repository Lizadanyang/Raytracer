
#ifndef BBOX_H_
#define BBOX_H_

#include "../math/geometry.h"
#include "../core/RayHitStructs.h"
#include <cstddef>
#include <limits>
#include <cstddef>
#include <iostream>
#include <vector>
#include <stdint.h>

const float kInfinity = std::numeric_limits<float>::max(); 

namespace rt{

class BBox 
 { 

    public: 
        Vec3f min, max;
        BBox(){};
        BBox(Vec3f min, Vec3f max);
        BBox(Vec3f p);
        

        Hit intersect(Ray ray,double& t);


      //   BBox extendBy(Vec3f p){
      //         BBox b;
      //       if (p.x < bounds[0].x) bounds[0].x = p.x; 
      //       if (p.y < bounds[0].y) bounds[0].y = p.y; 
      //       if (p.z < bounds[0].z) bounds[0].z = p.z; 
      //       if (p.x > bounds[1].x) bounds[1].x = p.x; 
      //       if (p.y > bounds[1].y) bounds[1].y = p.y; 
      //       if (p.z > bounds[1].z) bounds[1].z = p.z; 

      //   }
      
      

  //bool intersect(const Ray& ray, float *tnear, float *tfar) const;

   
 };


}

#endif 