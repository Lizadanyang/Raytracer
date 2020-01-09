/*
 * PointLight.h
 *
 *
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "../core/LightSource.h"


namespace rt{

class PointLight: public LightSource{
    public:
        Vec3f pointlightcolor,pointlightposition;
        PointLight();
        PointLight(Vec3f pointlightposition, Vec3f pointlightcolor):pointlightposition(pointlightposition),pointlightcolor(pointlightcolor){};
        ~PointLight();


        Vec3f getLightSourcePosition(){return pointlightposition;}
        Vec3f getLightSourceColor(){return pointlightcolor;}
      


};



} //namespace rt




#endif /* POINTLIGHT_H_ */
