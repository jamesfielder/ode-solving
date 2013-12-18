#ifndef ODES_HPP_
#define ODES_HPP_

class ivp : public MFunction { // an initial value problem class
	MVector operator()(const double& x, const MVector& y);
};

class bvp1 : public MFunction { // a boundary value problem class
	double k;
public: 
	bvp1(){ // by default set k = 1 on initialising class
		k = 1.;
	}
	MVector operator()(const double& x, const MVector& y);
	void setk(double j);
};

class bvp2 : public MFunction { // a boundary value problem class
	MVector operator()(const double& x, const MVector& y);
};

#endif /* ODES_HPP_ */
