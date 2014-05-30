#ifndef MVECTOR_HPP_
#define MVECTOR_HPP_
#include<vector>
#include<iostream>

using namespace std;

class MVector {
	vector<double> v;
public:
	// Constructors: allow various constructors with different arguments
	explicit MVector(){}
	explicit MVector(int n):v(n){}
	explicit MVector(int n, double x):v(n,x){}
	// Destructor
	~MVector() {}	// Destructor does nothing here

	MVector& operator=(const MVector& X);
	double& operator[](int index);
	double operator[](int index) const;
	int size() const;
	vector<double> getVector();
	void push_back(double x);
};

// Function types for operator overloading
MVector operator*(const double& lhs, const MVector& rhs);
MVector operator/(const MVector& lhs, const double& rhs);
MVector operator+(const MVector& lhs, const MVector& rhs);
MVector operator-(const MVector& lhs, const MVector& rhs);
double operator*(const MVector& lhs, const MVector& rhs);
ostream& operator<<(ostream& os, const MVector& v);

#endif /* MVECTOR_HPP_ */
