#ifndef SOLVERS_HPP_
#define SOLVERS_HPP_

#include "MFunction.hpp"
#include <fstream>
#include <iostream>

class ivp_solvers {
	int steps,j; // variables all functions in the class require
	double a,b;
	MVector out;
	ofstream output;
public:
	ivp_solvers (int step, double m, double n){
		steps = step; // number of steps
		a = m; // lower end of interval
		b = n; // upper end of interval
	}
	MVector euler(MVector &y, MFunction &f, int j);
	MVector midpoint(MVector &y, MFunction &f, int j);
	MVector runge(MVector &y, MFunction &f, int j);
};

#endif /* SOLVERS_HPP_ */
