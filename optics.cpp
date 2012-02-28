#include<iostream>
#include"optics.h"
using namespace std;


const int MN=1000;
double dis[MN][MN];

void optics::run_optics(vector<opticsobject> * input,vector<opticsobject> * output,double eps, int minpts){
	multiset<opticsobject> seeds;
	for(int i=0; i<(int)input->size(); i++)
		(*input)[i].set_reach_distance(UNDEFINED);

	for(int i=0; i<(int)input->size(); i++)
		if((*input)[i].get_is_processed()==false){
			vector<opticsobject> temp_neighbors=(*input)[i].find_neighbors(input,eps);
			(*input)[i].set_is_processed(true);
			output->push_back(((*input)[i]));
			seeds.clear();
			if((*input)[i].get_core_distance() != UNDEFINED){
				update(&temp_neighbors,&(*input)[i],&seeds,eps,minpts);
				for( set<opticsobject>::iterator it=seeds.begin(); it!=seeds.end(); it++){
					opticsobject temp=*it;
					vector<opticsobject> temp_neighbors2=temp.find_neighbors(input,eps);
					seeds.erase(it);

					(*input)[temp.get_id()].set_is_processed(true);
					temp.set_is_processed(true);

					double temp_core_dist=(*input)[temp.get_id()].find_core_distance(&temp_neighbors2,minpts);
					(*input)[temp.get_id()].set_core_distance(temp_core_dist);
					temp.set_core_distance(temp_core_dist);
		
					output->push_back((*input)[i]);
					if(temp.get_core_distance() != UNDEFINED)
						update(&temp_neighbors2,&temp,&seeds,eps,minpts);
				}
			}
		}
}
/*
update(N, p, Seeds, eps, Minpts)
    coredist = core-distance(p, eps, MinPts)
    for each o in N
       if (o is not processed)
          new-reach-dist = max(coredist, dist(p,o))
          if (o.reachability-distance == UNDEFINED) // o is not in Seeds
              o.reachability-distance = new-reach-dist
              Seeds.insert(o, new-reach-dist)
          else               // o in Seeds, check for improvement
              if (new-reach-dist < o.reachability-distance)
                 o.reachability-distance = new-reach-dist
                 Seeds.move-up(o, new-reach-dist)
*/
void optics::update(vector<opticsobject> * neighbors, opticsobject * node, multiset<opticsobject> * seeds, double eps, int minpts){
	double temp_core_dist=node->find_core_distance(neighbors,eps);
	node->set_core_distance(temp_core_dist);
	for(int i=0; i<(int)neighbors->size(); i++){
		if((*neighbors)[i].get_is_processed()==false){
			double new_reach_distance= max(temp_core_dist,node->distance(&(*neighbors)[i]));
			if((*neighbors)[i].get_reach_distance() == UNDEFINED){ /// this neighbor is not a seed
				(*neighbors)[i].set_reach_distance(new_reach_distance);
				seeds->insert((*neighbors)[i]);
			}
			else{			// o is seeds, check for improvement
				if(new_reach_distance < (*neighbors)[i].get_reach_distance()){
					multiset<opticsobject>::iterator it=seeds->find((*neighbors)[i]);
					(*neighbors)[i].set_reach_distance(new_reach_distance);
				}
			}
		}
	}
}

void optics::extract_cluster(){

}
