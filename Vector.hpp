#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class vector
{
public:
	vector(double* arr, int len);
	vector(int dim);

	~vector();

	vector(const vector& other);
	vector(vector&& other);


	vector& operator=(const vector& other);
	vector& operator=(vector&& other);

	      double&       operator[](int idx);
	const double&       operator[](int idx) const;

	int get_dim() const;

	friend std::istream& operator>>(std::istream& is, vector& o);
	friend std::ostream& operator<<(std::ostream& os, const vector& o);
	const vector operator--(int);
	vector&      operator--();
	const vector operator++(int);
	vector&      operator++();
	vector       operator*(double c) const;
	double       operator*(const vector& other) const;
private:
	double* data_;
	int     dim_;
};

//Vector	double *	Vector
//vector operator+ (double* v2,const vector& v1)
//{	
//
//	return v1+v2;//v1.operator+(v2);
//}














#endif // VECTOR_HPP
