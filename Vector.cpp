#include "Vector.hpp"

vector::vector(double* arr, int len)
{
	this->dim_ = len;
	this->data_ = new double[len];
	for (int i = 0; i < len; ++i)
	{
		this->data_[i] = arr[i];
	}
}

vector::vector( int dim)
{
	dim_ = dim;
	this->data_ = new double[dim];
}
//vector a(d, 3);
//vector b(a);

vector::vector(const vector& other)
{
	if (this != &other)
	{
		dim_ = other.dim_;
		data_ = new double[dim_];
		for (int i = 0; i < dim_; ++i)
		{
			this->data_[i] = other.data_[i];
		}
	}
}
//vector a(d, 3);
//vector b(std::move(a));
vector::vector(vector&& other)
{
	if (this != &other)
	{
		dim_ = other.dim_;
		data_ = other.data_;
		other.data_ = nullptr;
	}
}

vector::~vector()
{
	if (data_ != nullptr)
	{
		delete[] data_;
	}
}

//vector a(d, 3);
//vector b=a;
vector& vector::operator=(const vector& other)
{

	if (this != &other)
	{
		dim_ = other.dim_;
		data_ = new double[dim_];
		for (int i = 0; i < dim_; ++i)
		{
			this->data_[i] = other.data_[i];
		}
	}
	return *this;
}

//vector a(d, 3);
//vector b=std::move(a);
vector& vector::operator=(vector&& other)
{
	if (this != &other)
	{
		dim_ = other.dim_;
		data_ = other.data_;
		other.data_ = nullptr;
	}
	return *this;
}

double&       vector::operator[](int idx)
{	
	return data_[idx];
}
const double& vector::operator[](int idx) const
{	
	return data_[idx];
}

int vector::get_dim() const
{
	return dim_;
}

std::istream& operator>>(std::istream& is, vector& o)
{
	for(int i=0;i<o.dim_;++i)
	{
		is >> o.data_[i];
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, const vector& o)
{
	for (int i = 0; i < o.dim_; ++i)
	{
		os << o.data_[i] << ' ';
		
	}
	return os;
}


//постфиксный декремент
const vector vector::operator--(int)
{
	vector old(dim_);
	for(int i=0;i<dim_;++i)
	{
		old.data_[i] = data_[i];
		data_[i]--;
	}
	return old;
}
//префиксный декремент
vector& vector::operator--()
{
	for (int i = 0; i < dim_; ++i)
	{
		
		data_[i]--;
	}
	return *this;
}


//постфиксный инкремент
const vector vector::operator++(int)
{
	vector old(dim_);
	for (int i = 0; i < dim_; ++i)
	{
		old.data_[i] = data_[i];
		data_[i]++;
	}
	return old;
}
//префиксный инкремент
vector& vector::operator++()
{
	for (int i = 0; i < dim_; ++i)
	{

		data_[i]++;
	}
	return *this;
}


vector       vector::operator*(double c) const 
{
	vector result(dim_);
	for (int i = 0; i < dim_; ++i)
	{
		result.data_[i] = data_[i] * c;
	}
	return result;
}
double       vector::operator*(const vector& other) const
{
	double result = 0.0;
	for (int i = 0; i < dim_; ++i)
	{
		result += data_[i] * other.data_[i];
	}
	return result;
}
vector       vector::operator+ (double* v2)
{
	vector result(2*this->dim_);
	for (int i = 0; i < this->dim_; ++i)
	{
		result[i] = this->data_[i];
	}
	for (int i = 0; i < this->dim_; ++i)
	{
		result[i + this->dim_] = v2[i];
	}
	return result;
}
