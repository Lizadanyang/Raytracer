/*
 * Pinhole.cpp
 *
 *
 */
#include <iostream>

#include "Pinhole.h"

#define PI 3.1415926
//#include "../math/geometry.h"




namespace rt{

	/**
	 * Prints camera data
	 * this function implements the abstract function of the base Camera class
	 */
	void Pinhole::printCamera(){
		printf("I am a pinhole camera! \n");
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	
	}
	
	Ray Pinhole::makeRay(int i, int j){

			Ray ray;

			float imageAspectRatio=width/height;

			float scale = tan(double(fov)*PI/(180*2)); 
				//std::cerr<<"tt"<<scale<<std::endl;
			float _v=0.5;

			float xdwn = (2 * (i + 0.5) / (float)width - 1) * scale; 
            float ydwn = (1 - 2 * (j + 0.5) / (float)height) * scale * 1 / imageAspectRatio;
			Vec3f PcameraSpace = Vec3f(xdwn,ydwn,-_v);
			//std::cerr<<"ca"<<camera->eye<<std::endl;

			Vec3f rayDirection = PcameraSpace-(eye);
			rayDirection = rayDirection.normalize();

			ray.camposition=eye;
			ray.camdirection=rayDirection;


	
		return ray;
	}



} //namespace rt

