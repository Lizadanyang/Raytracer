/*
 * Scene.h
 *
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include "../parsers/rapidjson/document.h"
#include "../parsers/rapidjson/istreamwrapper.h"

#include "../core/LightSource.h"
#include "../core/Shape.h"


using namespace rapidjson;

namespace rt{

	class Scene {
	public:

		Scene();
		Vec3f backgroundcolor;
		void createScene(Value& scenespecs);
		

		virtual ~Scene();
	
	
		std::vector<LightSource*> lightSources;
		std::vector<Shape*> shapes;

		Vec3f* texturebuffer;
	
		  int twidth;
		  
		  int theight;

	};

//Scene::Scene(){}
}; //namespace rt

#endif /* SCENE_H_ */
