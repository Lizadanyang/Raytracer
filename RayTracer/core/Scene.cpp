/*
 * Scene.cpp
 *
 */

#include "Scene.h"

#include <vector>

#include "../parsers/rapidjson/document.h"
#include "../parsers/rapidjson/istreamwrapper.h"


#include "../lights/PointLight.h"
#include "../lights/AreaLight.h"
#include "../shapes/Sphere.h"
#include "../shapes/Plane.h"
#include "../shapes/Triangle.h"
#include "../shapes/TriMesh.h"

#include "../math/geometry.h"

#include "../parsers/PPMWriter.h"

using namespace std;

namespace rt{

/**
 * Parses json scene object to generate scene to render
 *
 * @param scenespecs the json scene specificatioon
 */
	Scene::Scene(){}
	Scene::~Scene() {}

	void Scene::createScene(Value& scenespecs){
		std::printf("enter json");
		
		
		backgroundcolor[0] = scenespecs["backgroundcolor"][0].GetFloat();
		backgroundcolor[1] = scenespecs["backgroundcolor"][1].GetFloat();
		backgroundcolor[2] = scenespecs["backgroundcolor"][2].GetFloat();


		Value& lightsources=scenespecs["lightsources"];
		
		string lighttype;
		lighttype = lightsources[0].GetObject()["type"].GetString();

		Vec3f lightposition;
		lightposition[0] = lightsources[0].GetObject()["position"][0].GetFloat();
		lightposition[1] = lightsources[0].GetObject()["position"][1].GetFloat();
		lightposition[2] = lightsources[0].GetObject()["position"][2].GetFloat();

		Vec3f lightintensity;
		lightintensity[0] = lightsources[0].GetObject()["intensity"][0].GetFloat();
		lightintensity[1] = lightsources[0].GetObject()["intensity"][1].GetFloat();
		lightintensity[2] = lightsources[0].GetObject()["intensity"][2].GetFloat();

		if (lighttype.compare("pointlight")==0){
			PointLight* pointlight_ptr = new PointLight(lightposition,lightintensity);
			lightSources.push_back(pointlight_ptr);
			std::cerr<<lightposition<<std::endl;

		}

		Value& shape=scenespecs["shapes"];
		//sphere1
		string shapetype1;
		shapetype1 = shape[0].GetObject()["type"].GetString();

		Vec3f spherecenter1;
		spherecenter1[0] = shape[0].GetObject()["center"][0].GetFloat();
		spherecenter1[1] = shape[0].GetObject()["center"][1].GetFloat();
		spherecenter1[2] = shape[0].GetObject()["center"][2].GetFloat();

		float radius1;
		radius1 = shape[0].GetObject()["radius"].GetFloat();

		Value& mspecs = shape[0].GetObject()["material"];
		float ka = mspecs["ka"].GetFloat();
    	float ks = mspecs["ks"].GetFloat();
   		float kd = mspecs["kd"].GetFloat();
    	float specularexponent = mspecs["specularexponent"].GetFloat();
    	Vec3f diffusecolor = Vec3f(mspecs["diffusecolor"][0].GetFloat(), mspecs["diffusecolor"][1].GetFloat(),mspecs["diffusecolor"][2].GetFloat() );

		
		if(mspecs.HasMember("texture")){
			 PPMWriter::PPMReader(twidth, theight, texturebuffer, mspecs["texture"].GetString());

		}
		
		Material* material1= new Material(ka,ks,kd,specularexponent,diffusecolor);


		if (shapetype1.compare("sphere")==0){
			Sphere* sph_ptr1 = new Sphere(spherecenter1,radius1,material1);
			shapes.push_back(sph_ptr1);
		}
		//sphere2
		string shapetype2;
		shapetype2 = shape[1].GetObject()["type"].GetString();

		Vec3f spherecenter2;
		spherecenter2[0] = shape[1].GetObject()["center"][0].GetFloat();
		spherecenter2[1] = shape[1].GetObject()["center"][1].GetFloat();
		spherecenter2[2] = shape[1].GetObject()["center"][2].GetFloat();

		float radius2;
		radius2 = shape[1].GetObject()["radius"].GetFloat();

		 mspecs = shape[1]["material"];
		 ka = mspecs["ka"].GetFloat();
    	 ks = mspecs["ks"].GetFloat();
   		 kd = mspecs["kd"].GetFloat();
    	 specularexponent = mspecs["specularexponent"].GetFloat();
    	 diffusecolor = Vec3f(mspecs["diffusecolor"][0].GetFloat(), mspecs["diffusecolor"][1].GetFloat(),mspecs["diffusecolor"][2].GetFloat() );
		
		Material* material2= new Material(ka,ks,kd,specularexponent,diffusecolor);

		if (shapetype2.compare("sphere")==0){
			Sphere* sph_ptr2 = new Sphere(spherecenter2,radius2,material2);
			shapes.push_back(sph_ptr2);
			std::cerr<<"success sphere2"<<std::endl;
		}

		//plane
		string shapetype3;
		shapetype3 = shape[2].GetObject()["type"].GetString();

		Vec3f planepointa;
		planepointa[0] = shape[2].GetObject()["pointA"][0].GetFloat();
		planepointa[1] = shape[2].GetObject()["pointA"][1].GetFloat();
		planepointa[2] = shape[2].GetObject()["pointA"][2].GetFloat();
		
		Vec3f planepointb;
		planepointb[0] = shape[2].GetObject()["pointB"][0].GetFloat();
		planepointb[1] = shape[2].GetObject()["pointB"][1].GetFloat();
		planepointb[2] = shape[2].GetObject()["pointB"][2].GetFloat();

		Vec3f planepointc;
		planepointc[0] = shape[2].GetObject()["pointC"][0].GetFloat();
		planepointc[1] = shape[2].GetObject()["pointC"][1].GetFloat();
		planepointc[2] = shape[2].GetObject()["pointC"][2].GetFloat();

		Vec3f planepointd;
		planepointd[0] = shape[2].GetObject()["pointD"][0].GetFloat();
		planepointd[1] = shape[2].GetObject()["pointD"][1].GetFloat();
		planepointd[2] = shape[2].GetObject()["pointD"][2].GetFloat();
		 //std::cerr<<"D"<<planepointd<<std::endl;


		Vec3f planenormal3;
		planenormal3[0] = shape[2].GetObject()["normal"][0].GetFloat();
		planenormal3[1] = shape[2].GetObject()["normal"][1].GetFloat();
		planenormal3[2] = shape[2].GetObject()["normal"][2].GetFloat();

		 mspecs = shape[2]["material"];
		 ka = mspecs["ka"].GetFloat();
     	 ks = mspecs["ks"].GetFloat();
   		 kd = mspecs["kd"].GetFloat();
    	 specularexponent = mspecs["specularexponent"].GetFloat();
    	 diffusecolor = Vec3f(mspecs["diffusecolor"][0].GetFloat(), mspecs["diffusecolor"][1].GetFloat(),mspecs["diffusecolor"][2].GetFloat() );
		
		Material* material3= new Material(ka,ks,kd,specularexponent,diffusecolor);


		if (shapetype3.compare("planar_quad")==0){
			Plane* plane_ptr3 = new Plane(planepointa,planepointb,planepointc,planepointd,planenormal3,(float) 0,material3);
			shapes.push_back(plane_ptr3);
			std::cerr<<"success planes"<<std::endl;

		}



		//triangle
		string shapetype4;
		shapetype4 = shape[3].GetObject()["type"].GetString();

		Vec3f trianglepointA;
		trianglepointA[0] = shape[3].GetObject()["A"][0].GetFloat();
		trianglepointA[1] = shape[3].GetObject()["A"][1].GetFloat();
		trianglepointA[2] = shape[3].GetObject()["A"][2].GetFloat();

		Vec3f trianglepointB;
		trianglepointB[0] = shape[3].GetObject()["B"][0].GetFloat();
		trianglepointB[1] = shape[3].GetObject()["B"][1].GetFloat();
		trianglepointB[2] = shape[3].GetObject()["B"][2].GetFloat();

		Vec3f trianglepointC;
		trianglepointC[0] = shape[3].GetObject()["C"][0].GetFloat();
		trianglepointC[1] = shape[3].GetObject()["C"][1].GetFloat();
		trianglepointC[2] = shape[3].GetObject()["C"][2].GetFloat();

		 mspecs = shape[3]["material"];
		 ka = mspecs["ka"].GetFloat();
    	 ks = mspecs["ks"].GetFloat();
   			kd = mspecs["kd"].GetFloat();
    	 specularexponent = mspecs["specularexponent"].GetFloat();
    	 diffusecolor = Vec3f(mspecs["diffusecolor"][0].GetFloat(), mspecs["diffusecolor"][1].GetFloat(),mspecs["diffusecolor"][2].GetFloat() );
		
		Material* material4= new Material(ka,ks,kd,specularexponent,diffusecolor);

		std::cerr<<material4->diffusecolor<<std::endl;
		if (shapetype4.compare("triangle")==0){
			Triangle* sph_ptr4 = new Triangle(trianglepointA,trianglepointB,trianglepointC,Vec3f(1,1,1),0.0,material4);
			shapes.push_back(sph_ptr4);
			std::cerr<<"success triangle"<<std::endl;

			
		}

		//mesh

		string shapetype5;
		shapetype5 = shape[4].GetObject()["type"].GetString();

		Vec3f meshA;
		meshA[0] = shape[4].GetObject()["A"][0].GetFloat();
		meshA[1] = shape[4].GetObject()["A"][1].GetFloat();
		meshA[2] = shape[4].GetObject()["A"][2].GetFloat();

		Vec3f meshB;
		meshB[0] = shape[4].GetObject()["B"][0].GetFloat();
		meshB[1] = shape[4].GetObject()["B"][1].GetFloat();
		meshB[2] = shape[4].GetObject()["B"][2].GetFloat();

		Vec3f meshC;
		meshC[0] = shape[4].GetObject()["C"][0].GetFloat();
		meshC[1] = shape[4].GetObject()["C"][1].GetFloat();
		meshC[2] = shape[4].GetObject()["C"][2].GetFloat();

		Vec3f meshD;
		meshD[0] = shape[4].GetObject()["D"][0].GetFloat();
		meshD[1] = shape[4].GetObject()["D"][1].GetFloat();
		meshD[2] = shape[4].GetObject()["D"][2].GetFloat();

		Vec3f meshE;
		meshE[0] = shape[4].GetObject()["E"][0].GetFloat();
		meshE[1] = shape[4].GetObject()["E"][1].GetFloat();
		meshE[2] = shape[4].GetObject()["E"][2].GetFloat();


		 mspecs = shape[4]["material"];
		 ka = mspecs["ka"].GetFloat();
    	 ks = mspecs["ks"].GetFloat();
   			kd = mspecs["kd"].GetFloat();
    	 specularexponent = mspecs["specularexponent"].GetFloat();
    	 diffusecolor = Vec3f(mspecs["diffusecolor"][0].GetFloat(), mspecs["diffusecolor"][1].GetFloat(),mspecs["diffusecolor"][2].GetFloat() );
		
		Material* material5= new Material(ka,ks,kd,specularexponent,diffusecolor);

		std::cerr<<material5->diffusecolor<<std::endl;
		if (shapetype5.compare("triangle_meshes")==0){
			
			TriMesh* sph_ptr5 = new TriMesh(meshA,meshB,meshC,meshD,meshE,material5);
			shapes.push_back(sph_ptr5);
			std::cerr<<"success mesh"<<std::endl;

			
		}




	}

	


}; //namespace rt
