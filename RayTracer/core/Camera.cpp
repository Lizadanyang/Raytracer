/*
 * Camera.cpp
 *
 */

#include "Camera.h"
#include "../cameras/Pinhole.h"
#include "../cameras/ThinLens.h"



namespace rt{
	
	Camera::Camera(int h, int w, int f, Vec3f e,Vec3f l,Vec3f r,Vec3f d){
		height = h;
		width = w;
		fov = f;
		eye=e;
		lookat=l;
		camright=r;
		camdown=d;
	}
	
	Matrix44f cameraMatrix(const Vec3f& eye, const Vec3f& lookat){ 
	
		Vec3f camdirection = (eye-lookat).normalize();


   		Vec3f right = Vec3f(0,1,0).crossProduct(camdirection).normalize();
    	Vec3f down = right.crossProduct(camdirection);
 
   		Matrix44f camToWorld; 
 
		camToWorld[0][0] = right.x; 
		camToWorld[0][1] = right.y; 
		camToWorld[0][2] = right.z; 
		camToWorld[1][0] = down.x; 
		camToWorld[1][1] = down.y; 
		camToWorld[1][2] = down.z; 
		camToWorld[2][0] = camdirection.x; 
		camToWorld[2][1] = camdirection.y; 
		camToWorld[2][2] = camdirection.z; 
	
		camToWorld[3][0] = eye.x; 
		camToWorld[3][1] = eye.y; 
		camToWorld[3][2] = eye.z; 
	 	return camToWorld;
	}
	
Camera::~Camera(){};
/**
 * Factory function that returns camera subclass based on camera specifications
 *
 * @param cameraSpecs camera specifications json object
 *
 * @return camera subclass instance
 *
 */
Camera* Camera::createCamera(Value& cameraSpecs){

	//check if cameratype is defined

	if (!cameraSpecs.HasMember("type")){
		std::cerr<<"Camera type not specified"<<std::endl;
		exit(-1);
	}

	std::string cameraType=cameraSpecs["type"].GetString();

	//return camera object based on camera specs
	// ==0 equal, ==-1 not equal
	//list1=[cameraSpecs["eye"][0].GetFloat(),cameraSpecs["eye"][1].GetFloat(),cameraSpecs["eye"][2].GetFloat()];

	if (cameraType.compare("pinhole")==0){
		int imagewidth = cameraSpecs["width"].GetInt();
		int imageheight = cameraSpecs["height"].GetInt();
		int imagefov = cameraSpecs["fov"].GetInt();
		std::cerr<<imagewidth<<imageheight<<std::endl;

		Vec3f cameye;
		cameye[0] = cameraSpecs["eye"][0].GetFloat();
		cameye[1] = cameraSpecs["eye"][1].GetFloat();
		cameye[2] = cameraSpecs["eye"][2].GetFloat();

		Vec3f camlookat;
		camlookat[0] = cameraSpecs["lookat"][0].GetFloat();
		camlookat[1] = cameraSpecs["lookat"][1].GetFloat();
		camlookat[2] = cameraSpecs["lookat"][2].GetFloat();

		Vec3f camright;
		camright[0] = cameraSpecs["right"][0].GetFloat();
		camright[1] = cameraSpecs["right"][1].GetFloat();
		camright[2] = cameraSpecs["right"][2].GetFloat();

		Vec3f camdown;
		camdown[0] = cameraSpecs["down"][0].GetFloat();
		camdown[1] = cameraSpecs["down"][1].GetFloat();
		camdown[2] = cameraSpecs["down"][2].GetFloat();

		return new Pinhole(imagewidth, imageheight, imagefov, cameye, camlookat, camright, camdown);
		
	}else if (cameraType.compare("thinlens")==0){
		int imagewidth = cameraSpecs["width"].GetInt();
		int imageheight = cameraSpecs["height"].GetInt();
		int imagefov = cameraSpecs["fov"].GetInt();
		std::cerr<<imagewidth<<imageheight<<std::endl;

		Vec3f cameye;
		cameye[0] = cameraSpecs["eye"][0].GetFloat();
		cameye[1] = cameraSpecs["eye"][1].GetFloat();
		cameye[2] = cameraSpecs["eye"][2].GetFloat();

		Vec3f camlookat;
		camlookat[0] = cameraSpecs["lookat"][0].GetFloat();
		camlookat[1] = cameraSpecs["lookat"][1].GetFloat();
		camlookat[2] = cameraSpecs["lookat"][2].GetFloat();

		Vec3f camright;
		camright[0] = cameraSpecs["right"][0].GetFloat();
		camright[1] = cameraSpecs["right"][1].GetFloat();
		camright[2] = cameraSpecs["right"][2].GetFloat();

		Vec3f camdown;
		camdown[0] = cameraSpecs["down"][0].GetFloat();
		camdown[1] = cameraSpecs["down"][1].GetFloat();
		camdown[2] = cameraSpecs["down"][2].GetFloat();

		return new ThinLens(imagewidth, imageheight, imagefov, cameye, camlookat, camright, camdown);

	}

	return 0;

}




} //namespace rt
