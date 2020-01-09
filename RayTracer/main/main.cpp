/*
 * main.cpp
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <sstream>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../parsers/rapidjson/document.h"
#include "../parsers/rapidjson/istreamwrapper.h"

#include "../math/geometry.h"
#include "../parsers/PPMWriter.h"

#include "../core/RayTracer.h"
#include "../core/Camera.h"
#include "../core/Scene.h"


using namespace rt;
using namespace rapidjson;
using namespace std;

struct RGBType{
	double r;
	double g;
	double b;
};


int main(int argc, char* argv[])
{
	cout << "rendering ..." << endl;

	clock_t t1, t2;
	t1 = clock();
	

	//parse commandline arguments
	char* inputFile=argv[1]; //input.json   //first command line argument holds the path to the json input file
	char* outputFile=argv[2]; //output.ppm  //second command line argument holds the path to the output image file

	std::printf("Input file: %s\n",inputFile);

	//parse json input file using rapidjson
	std::ifstream ifs(inputFile);
	IStreamWrapper is(ifs);
	Document d;     // d holds the complete json object
	d.ParseStream(is);

	std::printf("Camera");
	//generate a camera according to the input file: pinhole or thinlens
	Camera* camera=Camera::createCamera(d["camera"]);

	//print camera data (based on the input file provided)
	camera->printCamera();
	
	std::printf("Scene");
	//generate the scene according to the input file
	Scene* scene=new Scene();
	std::printf("ssScene");
	
	scene->createScene(d["scene"]);


	//
	// Main function, render scene
	//

	Vec3f* pixelbuffer=RayTracer::render(camera, scene, d["nbounces"].GetInt());

	//free resources when rendering is finished
	//delete camera;
	//delete scene;


	//convert linear RGB pixel values [0-1] to range 0-255
	RayTracer::tonemap(pixelbuffer,(camera->getWidth()*camera->getHeight()));


	std::printf("Output file: %s\n",outputFile);

	//write rendered scene to file (pixels RGB values must be in range 0255)
	PPMWriter::PPMWriter(camera->getWidth(), camera->getHeight(), pixelbuffer, outputFile);

	delete pixelbuffer;

	t2 = clock();
	float diff = ((float)t2 - (float)t1)/CLOCKS_PER_SEC;
	
	cout << diff << " seconds" << endl;
}


