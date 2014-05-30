#include<vector>
#include<iostream>
#include"MVector.hpp"

using namespace std;

MVector &MVector::operator=(const MVector& X) {
	if(&X==this) return *this;
		v = X.v;
		return *this;
	}

double& MVector::operator[](int index) {
// Overload [] operator for writing
	return v[index];
}

double MVector::operator[](int index) const {
// Overload [] operator for reading
	return v[index];
}

// Methods (functions for this class
int MVector::size() const {
// Return size of vector
	return v.size();
}

vector<double> MVector::getVector() {
// Return the underlying vector object
	return v;
}

void MVector::push_back(double x) {
// Push an element into vector at the back
int s = this->size()+1;
vector<double> temp(s);
	for(int i=0; i<s-1; i++) {
		temp[i] = v[i];
	}
	temp[s-1] = x;
	v = temp;
}

// Overload a series of operators so that they can be used on MVector objects

MVector operator*(const double& lhs, const MVector& rhs) {
	// Overload * operator to multiply MVectors with scalars
	MVector temp(rhs);
	for(int i=0; i<temp.size(); i++) {
		temp[i] *= lhs;
	}
	return temp;
}

MVector operator/(const MVector& lhs, const double& rhs) {
	// Overload / operator to divide MVectors by scalars
	MVector temp(lhs);
	for(int i=0; i<temp.size(); i++) {
		temp[i] = temp[i]/rhs;
	}
	return temp;
}

MVector operator+(const MVector& lhs, const MVector& rhs) {
	// Overload + operator to add MVectors
	if (lhs.size() == rhs.size()){ // Give a warning if the vectors are of difference size,
		MVector temp(lhs); // to state that the operation might not give the expected result.
		for(int i=0; i<temp.size(); i++) {
			temp[i] += rhs[i];
		}
		return temp;
	}
	else {
		cout << "Warning: The vectors are of different sizes! This could be very bad." << endl;
		MVector temp(lhs);
		for(int i=0; i<temp.size(); i++) {
			temp[i] += rhs[i];
		}
		return temp;
	}
}

MVector operator-(const MVector& lhs, const MVector& rhs) {
	// Overload - operator to subtract MVectors
	if (lhs.size() == rhs.size()){
		MVector temp(lhs);
		for(int i=0; i<temp.size(); i++) {
			temp[i] -= rhs[i];
		}
		return temp;
	}
	else{
		cout << "Warning: The vectors are of different sizes! This could be very bad." << endl;
		MVector temp(lhs);
		for(int i=0; i<temp.size(); i++) {
			temp[i] -= rhs[i];
		}
		return temp;
	}
}

double operator*(const MVector& lhs, const MVector& rhs) {
	// Overload the * operator to compute innter product of MVectors
	double ip = 0.;
	for(int i=0; i<rhs.size(); i++) {
		ip += (lhs[i]*rhs[i]);
	}
	return ip;
}

ostream& operator<<(ostream& os, const MVector& v) {
	// Overload the << operator to output MVectors to screen or file
	int n = v.size();
	cout << "(";
	for(int i=0; i<n; i++) {
		os << v[i];
		if(i<n-1) cout << ",";
	}
	cout << ")";
	return os;
}
