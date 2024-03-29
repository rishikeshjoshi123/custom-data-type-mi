#include <iostream>


#define P 998244353
#define mod(X) X % P

template< typename type>
class mdt // mod done data type
{

public:
	//constructors overloads
	mdt()
	{
		value = 0;
	}
	mdt(mdt<type> &_rhs)
	{
		this->value = mod(_rhs.GetVal());
	}
	mdt(type _val)
	{
		this->value = mod(_val);
	}

	mdt<type>(const mdt<type>& _other)// copy constructor
	{
		this->value = mod(_other.value);
	}

public:
	//functions
	type GetVal()
	{
		return mod(value);
	}
	type mul_mod(type a = 1, type b = 1, type c = 1, type d = 1)
	{
		return mod( 1ll * mod(a) * mod(b) * mod(c) * mod(d));
	}
	type power(type base, type pwr)
	{
		if (pwr == 1)
			return base;
		if (pwr == 0)
			return 1;

		if (pwr & 1) //is odd
			return mod(mod(base) * mod(power(mul_mod(base, base), (pwr - 1) / 2)));
		else
			return mod(power(mul_mod(base, base), pwr / 2));
	}
	type ModuloInverse(type value)
	{
		return mod(power(value, P - 2));
	}

public :
	//IO overloads
	//output
	friend std::ostream& operator<<(std::ostream& out, const mdt<type>& var)
	{
		out << var.value;
		return out;
	}
	//input
	friend std::istream& operator>>(std::istream& in, mdt<type>& var)
	{
		in >> var.value;
		return in;
	}



public:
	//maths functions

	//addition overloads
	mdt<type> operator + (mdt<type>& _rhs)
	{
		return mod(mod(this->value) + mod(_rhs.GetVal()));
	}
	mdt<type> operator + (type _val)
	{
		return (mod(mod(this->value) + mod(_val)));
	}

	//subtraction overloads
	mdt<type> operator - (mdt<type>& _rhs)
	{
		return mod(mod(this->value) - mod(_rhs.GetVal()));
	}
	mdt<type> operator - (type _val)
	{
		return (mod(mod(this->value) - mod(_val)));
	}

	//multiplication overloads
	mdt<type> operator * (mdt<type>& _rhs)
	{
		return mod(mod(this->value) * mod(_rhs.GetVal()));
	}
	mdt<type> operator * (type _val)
	{
		return (mod(mod(this->value) * mod(_val)));
	}

	//division overloads
	mdt<type> operator / (mdt<type>& _rhs)
	{
		return mod(mod(this->value) * ModuloInverse(_rhs.GetVal()));
	}
	mdt<type> operator / (type _val)
	{
		return mod(mod(this->value) * ModuloInverse(_val));
	}

	//equal to
	void operator = (mdt<type> &_rhs)
	{
		*this->value = _rhs.GetVal();
	}

private:
	//data
	type value;
};


int main()
{
	mdt<int> a = 5, b = 10;
	std::cout << a * b;

}