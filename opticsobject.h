#ifndef _OPTICSOBJECT_H
#define _OPTICSOBJECT_H

#include<vector>
using namespace std;

class opticsobject{
	private:
		int id,cluster_id;
		bool is_core,is_processed;
		double core_distance,reach_distance;
		
		vector<opticsobject * > neighbors;

		opticsobject();
		~opticsobject();

		double distance();
		vector<opticsobject> * find_neighbors();
		bool operator < ( const OpticsObject x)const;

	public:
		void set_id(int);
		void set_cluster_id(int);
		void set_is_core(bool);
		void set_is_processed(bool);
		void set_core_distance(double);
		void set_reach_distance(double);

		void get_id(int);
		void get_cluster_id(int);
		void get_is_core(bool);
		void get_is_processed(bool);
		void get_core_distance(double);
		void get_reach_distance(double);
		
};

#endif
