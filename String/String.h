#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------\n"

/////////////////////////////////////////////////
//////////////      Class declaration (объ€вление класса)

class String
{
	char* str;
	int size;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// constructors
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	// operators 
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);
	// methods
	void print()const;
};

/////////// Class declaration end (конец объ€влени€ класса)
///////////////////////////////////////////////////
