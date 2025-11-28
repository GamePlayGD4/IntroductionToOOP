#include"String.h"
// -----------------------------------------------


/////////////////////////////////////////////////
//////////////      Class defenition (определение класса)

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
// constructors
String::String(int size) :size(size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*/
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	/*this->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;

	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

// operators 
String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
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
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
// methods
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

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


/////////// Class definition end (конец определения класса)
///////////////////////////////////////////////////
