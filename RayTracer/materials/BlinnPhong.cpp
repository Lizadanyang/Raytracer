/*
 * BlinnPhong.cpp
 *
 *
 */

#include "BlinnPhong.h"
#include <iostream>  



namespace rt{
    Vec3f BlinnPhong::createphong(Vec3f N, Vec3f L, Vec3f V,Vec3f lightcolor,Material* m ){
                    Vec3f halfVector = (L+V).normalize();
			
					float spectfactor= m->ks*pow(std::max(((halfVector).dotProduct(N)),float(0.0)),m->specularexponent);//32==specularexponent
	
					Vec3f diffuse = lightcolor*(std::max(((L).dotProduct(N)),float(0.0)));
					//std::cerr<<"D"<<diffuse<<std::endl;
	

					Vec3f specular= lightcolor*spectfactor;
					Vec3f ambient = m->ka*lightcolor;
				
					//std::cerr<<"lc"<<specular<<std::endl;
					Vec3f sum =  (diffuse+specular+ambient);
                    return sum;
    
    }





} //namespace rt
