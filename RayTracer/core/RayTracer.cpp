/*
 * RayTracer.cpp
 *
 */
#include "RayTracer.h"
#define PI 3.1415926
#include <iostream>     // std::cout
#include <algorithm>  


//#include "../core/RayHitStructs.h"
//#include <vector>


namespace rt{

Vec3f RayTracer::tracepath(Scene* scene, Ray ray, int depth,Vec3f hitpoint,Vec3f N,Vec3f color){
	
	if(depth < 0) return color;
	Ray newRay;
    newRay.camposition = hitpoint;

	Vec3f lightPosition = scene->lightSources[0]->getLightSourcePosition();
					
	Vec3f lightIntensity = scene->lightSources[0]->getLightSourceColor();
	
	Vec3f V = (Vec3f(0,0,0) - (hitpoint)).normalize();
	Vec3f L = (lightPosition-hitpoint).normalize();
	///BVH
	// std::vector<Shape*> objects;

	// for(size_t i=0; i<scene->shapes.size(); ++i) {
	// 		objects.push_back(scene->shapes[i]);
	// }

	
	newRay.camdirection = 2*(N.dotProduct(V)*N)-V;
	const float p = 1/(2*PI);
	double t = 0;
	for (int q = 0; q<scene->shapes.size();q++){
		//BVH bvh(objects,newRay);
		//Hit newhit = bvh.shapehit;
		


		Hit newhit = scene->shapes[q]->intersect(newRay,t);
	
		if (newhit.notMiss){
			//Vec3f diffuseColor = scene->shapes[k]->Shape::material->diffusecolor;
		    L = (-(lightPosition-newhit.hitPoint)).normalize();
			N = (-(scene->shapes[q]->getNormal(newhit.hitPoint))).normalize();
			V = (-(Vec3f(0,0,0) - (newhit.hitPoint))).normalize();
			color = color+scene->shapes[q]->Shape::material->createphong( N, L, V,lightIntensity,scene->shapes[q]->Shape::material);
			//std::cerr<<"b"<<color<<std::endl;
			
			//float cos_theta = newRay.camdirection.dotProduct(N);
			
			Vec3f newcolor = tracepath(scene,newRay, depth-1,newhit.hitPoint,N,color);	
			color = newcolor;
			
		}
		

	}
		

    return  color*0.5;
	
}

/**
 * Performs ray tracing to render a photorealistic scene
 *
 * @param camera the camera viewing the scene
 * @param scene the scene to render, including objects and lightsources
 * @param nbounces the number of bounces to consider for raytracing
 *
 * @return a pixel buffer containing pixel values in linear RGB format
 * 
 * 
 * 
 **/
Vec3f* RayTracer::render(Camera* camera, Scene* scene, int nbounces){
	int height = camera->height;
	int width = camera->width;
	//int image = width*height;
	
	Vec3f* pixelbuffer=new Vec3f[camera->getWidth()*camera->getHeight()];
	std::cerr<<"tt"<<pixelbuffer->length()<<std::endl;
	Vec3f bgc=scene->backgroundcolor;

	Vec3f *pix = pixelbuffer;

	std::vector<Shape*> objects;

	for(size_t i=0; i<scene->shapes.size(); ++i) {
			objects.push_back(scene->shapes[i]);
	}


	for(int i = 0; i<width;i++){
		for(int j = 0; j<height; j++){

			*(pix++)=bgc;

			}
		}
	
	for(int i = 0; i<width;i++){
		for(int j = 0; j<height; j++){
			
			for (int k =0; k<scene->shapes.size();k++){
				Ray ray= camera->makeRay(i,j);

				double t = 0;
					

  				// Compute a BVH for this object set
  				//BVH bvh(objects,ray);
	
				Hit shape_1hit = scene->shapes[k]->intersect(ray,t);

				//Hit shape_1hit = bvh.shapehit;

				if (shape_1hit.notMiss){

					Vec3f lightPosition = scene->lightSources[0]->getLightSourcePosition();
					//std::cerr<<"light pos"<<lightPosition<<std::endl;

					Vec3f lightIntensity = scene->lightSources[0]->getLightSourceColor();
					//std::cerr<<"light ins"<<lightIntensity<<std::endl;
					Vec3f diffuseColor ;
					
					if (k==0){
					//texture of sphere
						Vec2f hi = scene->shapes[0]->mapuv(shape_1hit.hitPoint);

					//std::cerr<<"hi"<<hi.x<<"  "<< hi.y<<std::endl;
						int hix,hiy;
						if (hi.x<1){
					
						hix=(int)(hi.x*769);
						hiy=(int)(hi.y*1024);

						}
						else{

							hix=(int)(hi.x);
							hiy=(int)(hi.y);

						}
					
						Vec3f textcolor = scene->texturebuffer[hix*1024+hiy];


						 diffuseColor = textcolor;
					}
					else{

						 diffuseColor = scene->shapes[k]->Shape::material->diffusecolor;


					}
					
					
					Vec3f specularColor = Vec3f(1,1,1);
					double shininess=scene->shapes[k]->Shape::material->specularexponent;
					float ks=scene->shapes[k]->Shape::material->ks;
					float ka =scene->shapes[k]->Shape::material->ka;
					float kd = scene->shapes[k]->Shape::material->kd;

					Vec3f N = (scene->shapes[k]->getNormal(shape_1hit.hitPoint)).normalize();
					Vec3f V = ((camera->eye) - (shape_1hit.hitPoint)).normalize();
					//std::cerr<<"N"<<N<<std::endl;
				
					Vec3f lightRay = (lightPosition-shape_1hit.hitPoint).normalize();
					//std::cerr<<"lightray"<<lightRay<<std::endl;
					Vec3f halfVector = (lightRay+V).normalize();
					//std::cerr<<"half"<<halfVector<<std::endl;
					//std::cerr<<"hitpoint"<<shape_1hit.hitPoint<<std::endl;
				
				
					float spectfactor= ks*pow(std::max(((halfVector).dotProduct(N)),float(0.0)),shininess);//32==specularexponent
					//std::cerr<<"s"<<spectfactor<<std::endl;
	
					Vec3f diffuse = diffuseColor*lightIntensity*(std::max(((lightRay).dotProduct(N)),float(0.0)));
					//std::cerr<<"D"<<diffuse<<std::endl;
	

					Vec3f specular= lightIntensity*spectfactor;
					Vec3f ambient = ka*lightIntensity;
				
					//std::cerr<<"lc"<<specular<<std::endl;
					Vec3f sum =  (diffuse+specular+ambient);
					//Vec3f sum = specular*Vec3f(26,260,10);
					//std::cerr<<"raydir"<<sum<<std::endl;


					
					Vec3f add_pixcel= RayTracer::tracepath(scene, ray, nbounces-1,shape_1hit.hitPoint,N,Vec3f(0,0,0));
					//std::cerr<<"b"<<add_pixcel<<std::endl;
					Vec3f newsum=sum+add_pixcel;	
					
					// Ray lightray;
					// lightray.camposition=lightPosition;
					// lightray.camdirection=lightRay;
					// Vec3f add_pixcel1= RayTracer::tracepath(scene, lightray, nbounces-1,shape_1hit.hitPoint,N,Vec3f(0,0,0));
					// newsum=sum+add_pixcel+add_pixcel1;
				
					pixelbuffer[i*width+j].x = newsum.x;
					pixelbuffer[i*width+j].y = newsum.y;
					pixelbuffer[i*width+j].z = newsum.z;

					

		
					}		
				
				}
	
	
			}

			


	
		}

		
	std::cerr<<"tt"<<pixelbuffer<<std::endl;
	return pixelbuffer;

}

/**
 * Tonemaps the rendered image (conversion of linear RGB values [0-1] to low dynamic range [0-255]
 *
 * @param pixelbuffer the array of size width*height containing linear RGB pixel values
 *
 * @return the tonemapped image
 */
Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer,int image_size){


	for(int i = 0; i < image_size; i++){
		pixelbuffer[i] = pixelbuffer[i] * 255;
	}

	return pixelbuffer;

}







} //namespace rt


