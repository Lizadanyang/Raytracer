/*
 * ThinLens.h
 *
 */

#ifndef THINLENS_H_
#define THINLENS_H_

#include "../core/Camera.h"
//#include "../math/geometry.h"


namespace rt{

class ThinLens:public Camera{
public:

	//
	// Constructors
	//
	ThinLens();
 	ThinLens(int width, int height, int fov,Vec3f eye, Vec3f lookat, Vec3f right, Vec3f down):Camera(width, height, fov, eye, lookat, right, down){};

	//
	//Destructor
	//
	~ThinLens(){};

	//
	// print function (implementing abstract function of base class)
	//
	void printCamera();
	Ray makeRay(int i, int j);

};

//ThinLens::~ThinLens(){};

} //namespace rt




#endif /* THINLENS_H_ */
