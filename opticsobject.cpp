#include<iostream>
#include"opticsobject.h"
#include<vector>
using namespace std;

const int MN=1000;
double dis[MN][MN];

bool opticsobject::operator < ( const opticsobject x)const{
	if(reach_distance==x.reach_distance)
		return id<x.id;
	return reach_distance<x.reach_distance;
}

void opticsobject::set_id(int _id){
	id=_id;
}

void opticsobject::set_cluster_id(int _cluster_id){
	cluster_id=_cluster_id;
}

void opticsobject::set_is_core(bool _is_core){
	is_core=_is_core;
}

void opticsobject::set_is_processed(bool _is_processed){
	is_processed=_is_processed;
}

void opticsobject::set_core_distance(double _core_distance){
	core_distance=_core_distance;
}

void opticsobject::set_reach_distance(double _reach_distance){
	reach_distance=_reach_distance;
}

int opticsobject::get_id(){
	return id;
}

int opticsobject::get_cluster_id(){
	return cluster_id;
}

bool opticsobject::get_is_core(){
	return is_core;
}

bool opticsobject::get_is_processed(){
	return is_processed;
}

double opticsobject::get_core_distance(){
	return core_distance;
}

double opticsobject::get_reach_distance(){
	return reach_distance;
}

double opticsobject::find_core_distance(vector<opticsobject> * neigh,int minpts){
	if(neigh->size()<minpts)
		return UNDEFINED;
	return distance(&((*neigh)[minpts-1]));
}

vector<opticsobject> opticsobject::find_neighbors(vector<opticsobject> * input,double eps){	
	vector<opticsobject> temp_neighbor;
	for(int i=0; i<(int)input->size(); i++)
		if(distance(&((*input)[i]))<=eps && (*input)[i].id!=id)
			temp_neighbor.push_back((*input)[i]);
	return temp_neighbor;
}

double opticsobject::distance(opticsobject *next){
	return dis[id][next->id];
}

