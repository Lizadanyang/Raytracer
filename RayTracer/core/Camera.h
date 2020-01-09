/*
 * Camera.h
 *
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../parsers/rapidjson/document.h"
#include "../math/geometry.h"
#include "../core/RayHitStructs.h"

using namespace rapidjson;

namespace rt{

class Camera{
public:

	//
	// Constructors
	//eye = cam position
	// lookat = cam direction
	// 
	//
	Vec3f eye, lookat, camright, camdown;
	//Matrix44f camToWorld; 
	//
	//camera members
	//
	int height;
	int width;
	int fov; //field of view

	Camera(){};
	//Camera(Vec3f e,Vec3f l,Vec3f r,Vec3f d);
	Camera(int width, int height, int fov, Vec3f e, Vec3f l, Vec3f r, Vec3f d);
	//
	// Destructor
	//
	virtual ~Camera();


	//
	// factory function : returns camera instance dynamically based on camera specifications
	//
	static Camera* createCamera(Value& cameraSpecs);
	Matrix44f cameraMatrix(const Vec3f& eye, const Vec3f& lookat);

	//
	// print function (to be implemented by the subclasses )
	//
	virtual void printCamera()=0;

	virtual Ray makeRay(int i, int j)=0;

	//
	// other camera functions (to complete)
	//
	Vec3f getCameraPosition(){return eye;}
	Vec3f getCameraDirection(){return lookat;}
	Vec3f getCameraRight(){return camright;}
	Vec3f getCameraDown(){return camdown;}

	//virtual Ray makeRay()=0;
	//
	// Getters and Setters
	//
	int getHeight() const {
		return height;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getWidth() const {
		return width;
	}

	void setWidth(int width) {
		this->width = width;
	}

	

};

} //namespace rt



#endif /* CAMERA_H_ */
