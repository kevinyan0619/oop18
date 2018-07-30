//============================================================================
// Name        : Shucheng
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void simple_error() {
	cout << "the age you entered is very suspicious!!!";
}

int main() {
	cout << "This is my submission for hw1 of OOP course:\n";
	cout << "Enter the name of the person you want to write to:\n";
	string first_name; // variable of type string
	cin >> first_name; // read characters into first name
	cout << "Dear " << first_name << '\n';

	string friend_name;
	cout << "Enter the name of your friend:\n";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?" << '\n';

	int age;
	cout << "Enter the age of the recipient:\n";
	cin >> age;
	cout << "I hear you had a birthday and you are now " << age << " years old!"
			<< '\n';

	if (age < 0 || age > 100)
		simple_error();
	else {
		if (age < 17)
			cout << "You are young to be at NYU!" << '\n';
		else if (age > 65)
			cout << "It's great to see senior students around campus!" << '\n';
	}

	return 0;
}
