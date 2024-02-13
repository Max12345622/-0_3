#include "Postuplenie_tovarov.h"

std::string Postuplenie_tovarow::getTovar() 
{
	return tovar;
};

int Postuplenie_tovarow::getKolichestwo() 
{
	return kolichestwo;
};

Date Postuplenie_tovarow::getDate() 
{
	return data;
};

void Postuplenie_tovarow::setTovar(std::string tvr) 
{
	tovar = tvr;
};

void Postuplenie_tovarow::setKolichestwo(int klch) 
{
	correctKolichestwo(klch);
	kolichestwo = klch;
};

void Postuplenie_tovarow::setDate(Date D) 
{
	D.correctDate(D.getDay(), D.getMonth(), D.getYear());
	data = D;
};

void Postuplenie_tovarow::createTovars(std::istream& ist) 
{
	std::string tvr;
	int klch = 0;
	ist >> tvr;
	ist >> klch;
	correctKolichestwo(klch);

	tovar = tvr;
	kolichestwo = klch;
};

void Postuplenie_tovarow::print(std::vector<Postuplenie_tovarow>& tovars, std::ostream& out)
{
	for (size_t i = 0; i < tovars.size(); i++)
	{
		tovars.at(i).data.printDate(out);
		tovars.at(i).printTovar(out);
	}
};
void Postuplenie_tovarow::correctKolichestwo(int kolch) 
{
	if (kolch <= 0) throw std::runtime_error{"Error! Incorrect kolichestwo was entered "};
};
void Postuplenie_tovarow::printTovar(std::ostream& out)
{
	out << " " << tovar << " " << kolichestwo;
	out << std::endl;
};

void Postuplenie_tovarow::funcia_tovar(std::ifstream& ist,std::vector<Postuplenie_tovarow>& tovars) {
	while (!ist.eof()) {
		Postuplenie_tovarow one;
		one.data.funcia_date(ist);
		one.createTovars(ist);
		tovars.push_back(one);
	}
}
