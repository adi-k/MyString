#include<iostream>
using namespace std;

class MyString {
	char * text;
public:
	MyString(char*);
	MyString(MyString &);
	~MyString();

	MyString operator+(const MyString & right) {

		char*tmp = new char[strlen(text) + strlen(right.text) + 1];

		strcpy_s(tmp, strlen(text) + 1, text);
		strcat_s(tmp, strlen(text) + strlen(right.text) + 1, right.text);

		MyString rtrn(tmp);
		delete[]tmp;
		tmp = nullptr;

		return rtrn;
	}
	friend ostream & operator<<(ostream &, MyString &);
	friend istream & operator>>(istream &, MyString &);


	MyString & operator=(const MyString& original) {
		if (this != &original)
		{
			delete[] text;
			text = nullptr;
			text = new char[strlen(original.text) + 1];
			strcpy_s(text, strlen(original.text) + 1, original.text);
			return *this;
		}

	}
	MyString operator+=(const MyString & right) {

		char* temp = new char[strlen(text) + 1];
		strcpy_s(temp, strlen(text) + 1, text);
		delete[] text; text = nullptr;
		text = new char[strlen(temp) + strlen(right.text) + 1];
		strcpy_s(text, strlen(temp) + 1, temp);
		strcat_s(text, strlen(temp) + strlen(right.text) + 1, right.text);
		delete[]temp; temp = nullptr;
		return *this;
	}

	char & operator[](int n) {
		char x = text[n-1];
		return x;
	}
};

istream & operator>>(istream & CIN, MyString & obj) {
	delete[] obj.text;
	char*tmp =new char[100];
	CIN >> tmp;
	obj.text = new char[strlen(tmp) + 1];
	strcpy_s(obj.text, strlen(tmp) + 1, tmp);
	delete[]tmp;
	tmp = nullptr;
	return CIN;
}
ostream & operator<<(ostream & COUT, MyString & obj) {
	COUT << obj.text;
	return COUT;
}

MyString::MyString(char* s = "---") {
	text = new char[strlen(s) + 1];
	strcpy_s(text, strlen(s) + 1, s);
}
MyString::MyString(MyString & org) {
	int temp = strlen(org.text) + 1;
	text = new char[temp];
	strcpy_s(text, temp, org.text);
}
MyString::~MyString() {

	delete[] text;
	text = nullptr;
}

void main()
{
	MyString a("jumbo");
	MyString b("coco");
	MyString c;

	cin >> c;
	cout << endl << endl;
	cout << c[2];
}
