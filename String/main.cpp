#include <iostream>
#include <Windows.h>
using namespace std;

#define tab "\t"
#define delimiter "\n------------------\n"

//class String
//{
//	int length;
//	//char string[length];
//public:
//	int get_length()const
//	{
//		return length;
//	}
//	void set_length(int integer)
//	{
//		this->length = length;
//	}
//	// constructors
//	String()
//	{
//		length = 0;
//		cout << "constructor" << endl;
//	}
//	~String()
//	{
//		cout << "Destructor" << endl;
//	}
//};

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToUpper(char str[])
{
	/*for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}*/
	for (int i = 0; str[i]; i++)
	{
		/*if(str[i]>='a' && str[i] <= 'z')str[i] -= 32;
		if(str[i]>='а' && str[i] <= 'я')str[i] -= 32;
		if (str[i] == 'ё') str[i] -= 16;*/
		str[i] = toupper(str[i]);
	}
	return str;
}

char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
	/*	if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
		if (str[i] == 'ё') str[i] += 16;*/
		str[i] = tolower(str[i]);
	}
	return str;
}


//#define LINES_BASICS_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef LINES_BASICS_1
	//String A("Hello");
//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;
#endif // LINES_BASICS_1

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl;
	/*ToUpper(str);
	cout << str << endl;*/
	cout << ToUpper(str) << endl;
	cout << ToLower(str) << endl;
}