#include "Postuplenie_tovarov.h"

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int main()
{

	vector<Postuplenie_tovarow> tovars;
	Postuplenie_tovarow pos;
	setlocale(LC_ALL, "rus");

	ifstream ist("in.txt");
	try {
		if (ist.is_open()) 
		{
			vector<Postuplenie_tovarow> tovars;
			Postuplenie_tovarow pos;
			pos.funcia_tovar(ist, tovars);
			pos.print(tovars, std::cout);
		}
	}
	catch (std::runtime_error& Message) {
		cout << Message.what();
	}
	
	ist.close();
}

