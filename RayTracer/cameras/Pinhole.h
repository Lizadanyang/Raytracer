/*
 * Pinhole.h
 *
 *
 */

#ifndef PINHOLE_H_
#define PINHOLE_H_

#include "../core/Camera.h"
#include "../math/geometry.h"

namespace rt{

class Pinhole:public Camera{
public:

	
	Pinhole();
	Pinhole(int width, int height, int fov, Vec3f eye, Vec3f pindir, Vec3f pinright, Vec3f pindown):Camera(width, height, fov, eye, lookat, camright, camdown){

	};

	//
	//Destructor
	//
	~Pinhole(){};

	//
	// print function (implementing abstract function of base class)
	//
	void printCamera();
	//generate ray 
	Ray makeRay(int i, int j);
};



} //namespace rt




#endif /* PINHOLE_H_ */
