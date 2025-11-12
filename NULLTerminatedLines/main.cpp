#define _CRT_SECURE_NO_WARNINGS
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

char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + i] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
char* RemoveSymbol(char str[], char symbol = ' ')
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
bool IsPalindrome(const char str[])
{
	int size = StringLength(str);
	char* buffer = new char[size + 1] {};
	strcpy(buffer, str);
	//strcpy(dst, src); - Эта функция копирует содержимое строки 'src' (Source - Источник) в строку 'dst' (Destination - получатель)
	ToLower(buffer);
	RemoveSymbol(buffer);
	size = StringLength(buffer);
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
	}
	return true;
}

int bin_to_dec(const char str[])
{
	if (!is_bin_number(str)) return INT_MIN;
	int decimal = 0;
	int weight = 1;
	int length = StringLength(str);
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ' ')continue;
		decimal += (str[i] - '0') * weight;
		weight *= 2;
	}
	return decimal;
}

bool is_hex_number(const char str[])
{
	bool prefix = false;
	if (str[0] == '0' && str[1] == 'x')prefix = true;
	for (int i = prefix ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			) return false;
	}
	return true;
}

int hex_to_dec(const char str[])
{
	int decimal = 0;
	int weight = 1;
	int length = StringLength(str);
	bool prefix = false;
	if (str[0] == '0' && str[1] == 'x')prefix = true;
	for (int i = length - 1; i >= (prefix ? 2 : 0); i--)
	{
		int digit;
		if (str[i] >= '0' && str[i] <= '9')digit = str[i] - 48;
		if (str[i] >= 'A' && str[i] <= 'F')digit = str[i] - 55;
		if (str[i] >= 'a' && str[i] <= 'f')digit = str[i] - 87;
		decimal += digit * weight;
		weight *= 16;
	}
	return decimal;
}

bool isMACaddress(const char str[])
{
	if (strlen(str) != 17)return false;
	for (int i = 0; str[i]; i++)
	{
		if ((i + 1) % 3 == 0 && (str[i] == '-' || str[i] == ':'))continue;
		else if ((i + 1) % 3 == 0)return false;
		if (!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F')) return false;
	}
	return true;
}

//#define LINES_BASICS_1
//#define LINES_BASICS_2
//#define NUMERICS

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

#ifdef LINES_BASICS_2
	const int SIZE = 256;
	//char str[SIZE] = "Хорошо	живёт	  на	свете	Винни	  Пух";
	char str[SIZE] = "Аргентина манит негра";

	//cout << "Введите строку: ";
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
	cout << Shrink(str) << endl;
	cout << "Строка " << (IsPalindrome(str) ? "" : "не ") << "является палиндромом" << endl;
#endif // LINES_BASICS_2

#ifdef NUMERICS
	const int SIZE = 48;
	char str[SIZE] = "0xC8";

	cout << "Строка " << (is_bin_number(str) ? "" : "не ") << "является двоичным числом" << endl;
	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;

	cout << "Строка " << (is_hex_number(str) ? "" : "не ") << "является шестнадцатиричным числом" << endl;
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)" << endl;
#endif // numerics

	cout << isMACaddress("2C-F0-5D-71-AD-16") << endl;

}
