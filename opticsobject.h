#ifndef _OPTICSOBJECT_H
#define _OPTICSOBJECT_H

#include<iostream>
#include<vector>
using namespace std;

#define UNDEFINED -10000

class opticsobject{
	private:
		int id,cluster_id;
		bool is_core,is_processed;
		double core_distance,reach_distance;
		


	public:
		void set_id(int);
		void set_cluster_id(int);
		void set_is_core(bool);
		void set_is_processed(bool);
		void set_core_distance(double);
		void set_reach_distance(double);

		int get_id();
		int get_cluster_id();
		bool get_is_core();
		bool get_is_processed();
		double get_core_distance();
		double get_reach_distance();
		
		bool operator < ( const opticsobject x)const;
		double distance(opticsobject * next);
		double find_core_distance(vector<opticsobject> * ,int );
		vector<opticsobject> find_neighbors(vector<opticsobject> *,double);
};

#endif
