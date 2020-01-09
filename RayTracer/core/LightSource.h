/*
 * LightSource.h
 *
 */

#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_
#include "../math/geometry.h" 

namespace rt{

class LightSource{
    
public:
   

  
    LightSource(){};

    virtual ~LightSource();

    virtual Vec3f getLightSourcePosition()=0;
    virtual Vec3f getLightSourceColor()=0;

 
};



} //namespace rt



#endif /* LIGHTSOURCE_H_ */
