#ifndef _OPTICSOBJECT_H
#define _OPTICSOBJECT_H

#include"opticsobject.h"

class optics{
private:
	void run_optics(double, int);		// epsilone parameter, and MinPts
	void update();				// in update(), the priority queue Seeds is updated with the ε-neighborhood of p and q
	void extract_cluster();			// from ordering of the points and the reachability distance set by the update function the cluster numbers are assigned to the points
};

#endif
