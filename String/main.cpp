#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------\n"

class String
{
	char* str;
	int size;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	// constructors
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		/*this->size = size;
		this->str = new char[size] {};*/
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[]) :String(strlen(str) + 1)
	{
		/*this->size = strlen(str) + 1;
		this->str = new char[size] {};*/
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	// operators 
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		// Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssighment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;

		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;

		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	// methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define BASE_CHECK
#define OPERATORS_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	String str(12);
	//str.print();
	cout << str << endl;

	String str1 = "Hello";
	str1 = str1;
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;

	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // BASE_CHECK

#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	//String str3 = str1 + str2; // MoveConstructor
	String str3;
	str3 = str1 + str2;			// MoveAssignment
	cout << delimiter << endl;

	cout << str3 << endl;
#endif // OPERATORS_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;		// default constructor
	str1.print();

	String str2(5);		// Single-argument Constructor int (explicit)
	str2.print();

	String str3 = "Hello"; // Single-argument Constructor 'char'
	str3.print();

	String str4();  //NOT default constructor
	//str4().print(); 
	String str5{};
	str5.print();

	String str6{ 7 };
	str6.print();

	String str7("World");
	String str8("World");

	String str9 = str3;
	String str10(str9);
	String str11{ str9 };
	str11.print();

	String str12 = str3 + str7;
	str12.print();

	String str13(str3 + str7);
	str13.print();

	String str14{ str3 + str7 };
	str14.print();
#endif // CALLING_CONSTRUCTORS

	
}
