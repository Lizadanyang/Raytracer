/*
 * RayHitStructs.h
 */

#ifndef CORE_RAYHITSTRUCTS_H_
#define CORE_RAYHITSTRUCTS_H_

#include "../math/geometry.h"

namespace rt{

/*
 * Ray structure definition
 */
enum RayType {PRIMARY, SECONDARY, SHADOW};

struct Ray{

	//RayType raytype;
	Vec3f camposition;
	Vec3f camdirection;
	//float length;
	
	Vec3f getPoint(double t)const{
		return camposition+t*camdirection;
	}

	Vec3f generateRandomraydir(Vec3f hitpoint){
		Vec3f a;
		 a.x = 2.0 * rand() / RAND_MAX - 1.0;
		 a.y = 2.0 * rand() / RAND_MAX - 1.0;
		 a.z = 2.0 * rand() / RAND_MAX - 1.0;
		 return a-hitpoint;

	}

};


struct Hit{

	Vec3f hitPoint;//point where ray hits a shape
	
	bool notMiss;//notmiss= hit
	//Hit(Vec3f p, bool h):hitPoint(p),notMiss(h){};
	
	

};

}


#endif /* CORE_RAYHITSTRUCTS_H_ */
