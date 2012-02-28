#ifndef _OPTICS_H
#define _OPTICS_H

#include<vector>
#include<set>
#include"opticsobject.h"
using namespace std;

class optics{
private:
	
	void run_optics(vector<opticsobject> * ,vector<opticsobject> * ,double , int );		// epsilone parameter, and MinPts
	
	void update(vector<opticsobject> * , opticsobject * , multiset<opticsobject> * , double, int);				// in update(), the priority queue Seeds is updated with the ε-neighborhood of p and q
	void extract_cluster();			// from ordering of the points and the reachability distance set by the update function the cluster numbers are assigned to the points
};

#endif
