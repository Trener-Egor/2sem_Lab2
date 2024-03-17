#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
class vector
{
public:
	vector(double* arr, int len);
	vector(int dim);

	vector(const vector& other);//copy ctr
	vector(vector&& other);//move ctr
	vector& operator=(const vector& other);//copy assigment
	vector& operator=(vector&& other);//move assigment

	~vector();

	      double&       operator[](int idx);
	const double&       operator[](int idx)const;

	int get_dim() const;

	friend std::istream& operator>>(std::istream& is, vector& o);
	friend std::ostream& operator<<(std::ostream& os, const vector& o);

	const vector operator--(int);
	vector&      operator--();
	const vector operator++(int);
	vector&      operator++();
	vector       operator*(double c) const;
	double       operator*(const vector& other) const;	
	vector       operator+ (double* v2);
private:
	double* data_;
	int     dim_;
};

#endif // VECTOR_HPP
