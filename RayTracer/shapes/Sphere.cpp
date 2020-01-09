/*
 * Sphere.cpp
 *
 *
 */
#include "Sphere.h"
#define PI 3.1415926



namespace rt{


	/**
	 * Computes whether a ray hit the specific instance of a sphere shape and returns the hit data
	 *
	 * @param ray cast ray to check for intersection with shape
	 *
	 * @return hit struct containing intersection information
	 *
	 */
	Sphere::~Sphere(){};
	Hit Sphere::intersect(Ray ray,double& t){
		Vec3f cent = Sphere::getSphereCenter();
		float radi = Sphere::getSphereRadius();

		//Hit h = Hit(Vec3f(0,0,0),false);
		Hit h;
		//-----------to be implemented -------------
		Vec3f o = ray.camposition;
		Vec3f d = ray.camdirection;
		Vec3f oc = o - cent;

		double b = 2*(oc.dotProduct(d));
		double c = oc.dotProduct(oc)-radi*radi;
		double disc = b*b-4*c;
		if(disc<0){
			h.hitPoint = Vec3f(0,0,0);
		 	h.notMiss=false;
		}
		else{
			disc = sqrt(disc);
			double t0 = -b-disc;
			double t1 = -b+disc;

			t = (t0<t1)? t0:t1;
			Vec3f p = ray.getPoint(t);
			h.hitPoint=p;
			h.notMiss=true;
			

		}
		return h;

	}

	

	Vec2f Sphere::mapuv(Vec3f p){
		
		Vec3f cent = Sphere::getSphereCenter();
		Vec3f de = (p-cent).normalize();
		float beta = acos(de.dotProduct(Vec3f(0,0,1)));
		float u = beta/PI;

		
		float alpha = acos(de.dotProduct(Vec3f(0,-1,0)));
		if(de.dotProduct(Vec3f(1,0,0)) < 0)
			alpha = 2*PI-alpha;
		
		float v = alpha/(2*PI);

		return Vec2f(u,v);

	}


} //namespace rt


