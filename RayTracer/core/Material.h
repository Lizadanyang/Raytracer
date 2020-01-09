/*
 * Material.h
 *
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../math/geometry.h"
#include "../parsers/rapidjson/document.h"
#include "../parsers/rapidjson/istreamwrapper.h"

namespace rt{

class Material{
public:
    float ks,kd,ka;
    double specularexponent;
    Vec3f diffusecolor;
    Material();
    Material(float ka, float ks, float kd,float specularexponent,Vec3f diffusecolor):ka(ka),ks(ks),kd(kd),specularexponent(specularexponent),diffusecolor(diffusecolor){};
    
    Vec3f getMaterialdiffuseColor(){return diffusecolor;}
    float getKs(){return ks;}
    float getKa(){return ka;}
    float getKd(){return kd;}
    float getspecularexp(){return specularexponent;}

    //Material(Value& materialspecs);
    
    Vec3f createphong(Vec3f N, Vec3f L, Vec3f V,Vec3f lightcolor,Material* m );

private:

};


} //namespace rt



#endif /* MATERIAL_H_ */
