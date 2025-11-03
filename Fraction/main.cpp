#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

#define tab "\t"
#define delimiter "\n-----------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer; 
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	// constructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	explicit Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	// Increment/Decrement:
	
	Fraction& operator++() //prefix
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int) //postfix
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}
	Fraction& operator--() // prefix
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int) // postfix
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}

	// type-cast-operators:
	explicit operator int()const
	{
		return integer + numerator / denominator;
	}
	explicit operator double()const
	{
		return integer + double(numerator) / double(denominator);
	}

	// methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		if (less == 0) return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // Greatest common divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

	/*Fraction result
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	};
	result.to_proper();
	return result;*/

	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator <= (const Fraction& left, Fraction& right)
{
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;	
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 32;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer, SIZE);
	cout << buffer << endl;
	int numbers[3] = {};
	const char delimiters[] = "+()/";
	int n = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		numbers[n++] = std::atoi(pch);
		//cout << pch << "\t";
	} 
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << "\t";
	}
	cout << endl;
	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj = Fraction(integer, numerator, denominator);*/
	return is;
}

//#define CONSTRUCTORS_CHECK
//ctrl + shift + U
//#define ARITHMETICAL_OPERATORS_CHECK 
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define INCREMENTO_DECREMENTO
//#define STREAMS_CHECK_1
//#define STREAMS_CHECK_2
//#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK 
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper();
	A.print();
	A.to_proper();
	A.print();
	cout << delimiter << endl;
	Fraction C = A / B;
	cout << delimiter << endl;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK 

#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;
	A.print();

	A /= B;
	A.print();
#endif // COMPOUND_ASSIGNMENTS_CHECK

#ifdef INCREMENTO_DECREMENTO
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}

#endif // INCREMENTO_DECREMENTO

#ifdef STREAMS_CHECK_1
	//cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;

	Fraction A(2, 3, 4);
	cout << "¬ведите простую дробь: ";

	cin >> A;

	cout << A << endl;
#endif // STREAMS_CHECK_1

#ifdef STREAMS_CHECK_2
	Fraction A, B, C;
	cout << "¬ведите 3 простых дроби: ";
	cin >> A >> B >> C;
	cout << A << tab << B << tab << C << endl;

#endif // STREAMS_CHECK_2
	

#ifdef HOME_WORK
	//Fraction A = (Fraction)3.3333;
	int a(2);
	cout << a << endl;
	Fraction A(3.3333);
	cout << A << endl;

	//Fraction B = (Fraction)8;
	double b{3};
	cout << b << endl;
	Fraction B{8};
	cout << B << endl;

#endif // HOME_WORK

	Fraction A(2, 33, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;	
	double b = (double)A;
	cout << b << endl;

}	