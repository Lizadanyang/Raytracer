/*
 * ThinLens.cpp
 *
 *
 */
#include <iostream>
#define PI 3.1415926

#include "ThinLens.h"
//#include "../math/geometry.h"




namespace rt{

	Vec3f random_in_unit_disk(){

	Vec3f p;
	do{

		p = 2.0*Vec3f(drand48(), drand48(),0) - Vec3f(1,1,0);

	}while (p.dotProduct(p)>=1.0);

	//std::cerr<<"p"<<p<<std::endl;


	return p;
	}


	/**
	 * Prints camera data
	 * this function implements the abstract function of the base Camera class
	 */
	void ThinLens::printCamera(){
		printf("I am a thin lens camera! \n");
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	}
	
	Ray ThinLens::makeRay(int i, int j){
		Ray ray;

		float imageAspectRatio=width/height;

		
			float scale = tan(double(fov)*PI/(180*2)); 
				//std::cerr<<"tt"<<scale<<std::endl;
			float _v=0.5;

			float xdwn = (2 * (i + 0.5) / (float)width - 1) * scale; 
            float ydwn = (1 - 2 * (j + 0.5) / (float)height) * scale * 1 / imageAspectRatio;
			Vec3f PcameraSpace = Vec3f(xdwn,ydwn,-_v);


			float f = 0.8;

			Vec3f focul(0,0,-f);

			float _u = (f*_v)/(_v-f);
			//std::cerr<<"ca"<< _u <<std::endl;
		
			Vec3f p = ((Vec3f(0,0,-(_v+f)))-PcameraSpace).normalize();
			float aperature=0.5;
			float lens_radius = aperature /2;
			Vec3f rd = lens_radius*random_in_unit_disk();
			Vec3f offset =  Vec3f(PcameraSpace.x*rd.x, PcameraSpace.y*rd.y,-0.5);
			
			PcameraSpace=PcameraSpace*f;
			
			Vec3f lower_left = eye-PcameraSpace;

			ray.camposition=offset;
			ray.camdirection=( PcameraSpace-eye).normalize();
			


		
			return ray;

	}



} //namespace rt
