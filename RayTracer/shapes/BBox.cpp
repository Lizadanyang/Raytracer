#include "BBox.h"
#include <algorithm>
namespace rt{

BBox::BBox(Vec3f min, Vec3f max)
  : min(min), max(max) {}

BBox::BBox(Vec3f p)
  : min(p), max(p) {}


Hit BBox::intersect(Ray ray, double& t)
{ 

    Hit h;
    
    Vec3f invDir = ray.camdirection;
    Vec3f orig = ray.camposition;

    float tmin, tmax, tymin, tymax, tzmin, tzmax; 
 
    tmin  = (min.x - orig.x) * invDir.x; 
    tmax  = (max.x - orig.x) * invDir.x; 
    
    tymin = (min.y - orig.y) * invDir.y; 
    tymax = (max.y - orig.y) * invDir.y; 
 
    if ((tmin > tymax) || (tymin > tmax)) 
        h.notMiss=false; 
 
    if (tymin > tmin) 
        tmin = tymin; 
    if (tymax < tmax) 
        tmax = tymax; 
 
    tzmin = (min.z - orig.z) * invDir.z; 
    tzmax = (max.z - orig.z) * invDir.z; 
 
    if ((tmin > tzmax) || (tzmin > tmax)) 
        h.notMiss=false; 
 
    if (tzmin > tmin) 
        tmin = tzmin; 
    if (tzmax < tmax) 
        tmax = tzmax; 

    h.notMiss=true; 
 
    t = tmin; 
    Vec3f p = ray.getPoint(t);
	h.hitPoint=p;
 
    return h; 
} 



 


} //namespace rt


