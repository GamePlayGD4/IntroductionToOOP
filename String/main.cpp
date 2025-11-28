#include"String.h"
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
