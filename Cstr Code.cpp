#include <iostream>
#include <string>
using namespace std;

char* deepCopy(const char *);
class Cstr
{
private:
	char *str;
public:
	Cstr(const char * = nullptr); //default parameterized constructor
	Cstr(const Cstr &); //copy constructor
	~Cstr() { if (str != nullptr){ delete[] str; str = nullptr; } } //destructor
	char* getStr()const { return deepCopy(str); } //getter
	void setStr(const char* v){ if (str != nullptr) { delete[] str; } str = deepCopy(v); } //setter

	Cstr operator+(const Cstr &); // append two Cstrings
	const Cstr & operator=(const Cstr &); //assignment operator
	bool operator==(const Cstr &); //comparison 
	Cstr & operator +(); // converts all charcaters to UPEERCASE
	Cstr & operator -(); // converts all charcaters to lowercase
};

istream &operator >> (istream &, Cstr &);
ostream &operator << (ostream &, const Cstr &);

int main()
{
	Cstr a;
	cin >> a;
	cout << a << endl;
	cout << "After doing - unary = " << -a << endl;
	cout << "After doing + unary : " << +a << endl;
	Cstr b("Qarib");
	a = b;
	cout << "a+ b = " << a + b << endl;
	system("pause");
	return 0;
}

istream &operator >> (istream &rd, Cstr &a)
{
	if (&rd == &cin)
	{
		cout << "Enter the words: ";
	}
	char temp[256];
	rd.getline(temp, 256);
	a.setStr(temp);
	return rd;
}
ostream &operator << (ostream &wr, const Cstr &a)
{
	wr << a.getStr();
	return wr;
}

Cstr::Cstr(const char *a)
{
	if (a != nullptr)
	{
		int length = 0;
		for (int i = 0; a[i] != '\0'; i++)
		{
			length++;
		}
		str = new char[length++];
		this->str = deepCopy(a);
	}
}
Cstr::Cstr(const Cstr &a)
{
	this->str = deepCopy(a.getStr());
}
bool Cstr::operator== (const Cstr &a)
{
	bool result = false;
	result = (this->str == a.getStr());
	return result;
}
Cstr Cstr::operator +(const Cstr &a)
{
	int length = 0;
	int length2 = 0;
	for (int i = 0; this->str[i] != '\0'; i++)
	{
		length++;
	}
	length++; //null terminator adding
	char *temppp = a.getStr();
	for (int i = 0;temppp[i] != '\0'; i++)
	{
		length2++;
	}
	length2++; //null terminator adding

	char *temp = new char[length + length2 - 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = this->str[i];
	}

	for (int i = 0; i < length2; i++)
	{
		temp[length + i] = temppp[i];
	}

	Cstr result(temp);

	return result;
}

Cstr & Cstr::operator -() // Convert to lowercase
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32; // Convert to lowercase by adding 32
		}
	}
	return *this;
}
Cstr & Cstr::operator +() //doing -32 for uppercase
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
	return *this;
}

Cstr const & Cstr::operator= (const Cstr &a)
{
	if (this != &a)
	{
		if (str != nullptr)
		{
			delete[] str;
			str = deepCopy(a.getStr());
		}
	}
	return *this;
}
char* deepCopy(const char *abc)
{
	char* result = nullptr;
	if (abc != nullptr)
	{
		int count = 0;
		for (int i = 0; abc[i] != '\0'; i++)
		{
			count++;
		}
		count++; //due to null terminator
		result = new char[count];
		for (int i = 0; i < count; i++)
		{
			result[i] = abc[i];
		}
	}
	return result;
}