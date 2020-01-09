/*
 * BlinnPhong.h
 *
 *
 */

#ifndef BLINNPHONG_H_
#define BLINNPHONG_H_

#include "../core/Material.h"


namespace rt{

class BlinnPhong: public Material{
    BlinnPhong();
    BlinnPhong(float ka,float ks,float kd,float specularexponent,Vec3f diffusecolor):Material(ka,ks,kd,specularexponent,diffusecolor){};
    
    Vec3f createphong(Vec3f N, Vec3f L, Vec3f V,Vec3f lightcolor,Material* m );


};



} //namespace rt



#endif /* BLINNPHONG_H_ */
