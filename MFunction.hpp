#ifndef MFUNCTION_HPP_
#define MFUNCTION_HPP_
#include"MVector.hpp"

class MFunction {
public:
	virtual MVector operator()(const double& x, const MVector& y) = 0;
	MFunction() {}
	~MFunction() {}
};

#endif /* MFUNCTION_HPP_ */
