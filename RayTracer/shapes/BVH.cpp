/*
 * BVH.cpp
 *
 *
 */
#include "BVH.h"
#include "../core/RayHitStructs.h"


namespace rt{

//! - Compute the nearest intersection of all objects within the tree.
//! - Return true if hit was found, false otherwise.
//! - In the case where we want to find out of there is _ANY_ intersection at all,
//!   set occlusion == true, in which case we exit on the first hit, rather
//!   than find the closest.

Hit BVH::intersect(Ray ray,double& t){
  Hit bvhhit;
  BBox big;
  bvhhit = big.intersect(ray, t);

  }

float getDiff(Vec3f A, Vec3f B){

    float ab = pow((A.x-B.x),2)+pow((A.y-B.y),2)+pow((A.z-B.z),2);
    return ab;
}

BVH::~BVH() {}

BVH::BVH(std::vector<Shape*> objects,Ray ray)
  : build_prims(objects) {

    std::vector<BBox> bboxvec;

    for(int i = 0; i<objects.size(); i++){
      
   
   
      BBox bb( (build_prims)[i]->getBBox());
      
   		  //std::cerr<<"bbmin"<< bb.min <<std::endl;
        //std::cerr<<"bbmmax"<< bb.max <<std::endl;
      
        bboxvec.push_back(bb);

    }

    

      Vec3f bigBoxmin;
      float d = getDiff(bboxvec[0].min, bboxvec[0].max);
      
      for(int i=0; i<bboxvec.size();i++){
         for(int j=0; j<bboxvec.size();j++){
           if (d < getDiff(bboxvec[i].min, bboxvec[j].max)){
            d = getDiff(bboxvec[i].min, bboxvec[j].max);
            //std::cerr<<"i  j"<< d <<" "<< i <<" "<< j  <<std::endl;
           }
         }
        }

      BBox bigBox;
      bigBox.min=bboxvec[1].max;
      
      //bigBox.max=bboxvec[1].max;
      bigBox.max=bboxvec[2].min;
     
      double t = 0;

      Hit bighit = bigBox.intersect( ray, t);
      if (bighit.notMiss){
        for(int i=0; i<bboxvec.size(); i++){

          Hit smallhit= bboxvec[i].intersect(ray, t);
          if(smallhit.notMiss){
            for(int j = 0; j<objects.size(); j++){
              shapehit = build_prims[j]->intersect(ray, t);
              if(shapehit.notMiss){

                //std::cerr<<"hitshape"<< j <<std::endl;
                break;
    
              //std::cerr<<"hitshape"<< shapehit.hitPoint <<std::endl;


              }

             }
            }


         }



        }

  }


}//namespace rt


