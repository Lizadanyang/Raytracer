/*
 * Material.cpp
 *
 */
#include "Material.h"



namespace rt{


Vec3f Material::createphong(Vec3f N, Vec3f L, Vec3f V,Vec3f lightcolor,Material* m ){
                    Vec3f halfVector = (L+V).normalize();
			
					float spectfactor= m->ks*pow(std::max(((halfVector).dotProduct(N)),float(0.0)),m->specularexponent);//32==specularexponent
                    
                    Vec3f diffuseColor = m->diffusecolor;

					Vec3f diffuse = diffuseColor*lightcolor*(std::max(((L).dotProduct(N)),float(0.0)));
					//std::cerr<<"Diffuse"<<diffuse<<std::endl;
	

					Vec3f specular= lightcolor*spectfactor;
					Vec3f ambient = m->ka*lightcolor;

                    //std::cerr<<"specular"<<specular<<std::endl;
				
					
					Vec3f sum =  (diffuse+specular);
                    //std::cerr<<"sum"<<sum<<std::endl;

                    return sum;
    
    }
    





} //namespace rt


