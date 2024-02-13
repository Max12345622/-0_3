#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include "date.h"
class Postuplenie_tovarow
{
	Date data;
	std::string tovar;
	int kolichestwo = 0;
public:
	std::string getTovar();
	int getKolichestwo();
	Date getDate();
	void setTovar(std::string tvr);
	void setKolichestwo(int klch);
	void setDate(Date D);
	
	void funcia_tovar(std::ifstream& ist, std::vector<Postuplenie_tovarow>& tovars);
	void createTovars(std::istream& ist);
	void print(std::vector<Postuplenie_tovarow>& tovars, std::ostream& out);
	void correctKolichestwo(int kolch);
	void printTovar(std::ostream& out);
};

