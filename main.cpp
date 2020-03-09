/*Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
07.06.2019 Cuma */
#include "UzunYol.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

int main() {
	cout << "\t\t\tSurucu Sinifi" << endl;
	cout << "  << operatoru ve uc parametreli constructor calismaktadir" << endl;
	Surucu a1("yusuf yalcin", 19, EhliyetSinifi::B);
	Surucu a2("sebahattin yalcin", 30, EhliyetSinifi::E);
	cout << a1; 
	cout << "####################" << endl;
	cout << " Surucu  copy constructor calismaktadir" << endl;
	Surucu copy = a1;
	cout << copy << endl;
	cout << "####################" << endl;
	cout << " Surucu  assignment operator test edilmekte" << endl; 
	copy = a2;
	cout << copy << endl;
	cout << "####################" << endl;
	list<Surucu>sur;
	list<Surucu>sur2;
	sur.push_back(a1);
	sur2.push_back(a2);
	string inla = "goztepe";
	string inla2 = "unalan";
	cout << "\t\t\tYolcu Sinifi" << endl;
	Yolcu yolcu1("sinan yalcin", "tuzla", inla);
	Yolcu yolcu2("filiz yalcin", "gebze", inla2);
	cout << yolcu1 << endl;
	cout << "####################" << endl;
	cout << " Yolcu copy constructor calismaktadir" << endl;
	Yolcu copy2 = yolcu1;
	cout << copy2 << endl;
	cout << "####################" << endl;
	cout << " Yolcu assignment operator test edilmekte" << endl;
	copy2 = yolcu2;
	cout << copy2 << endl;
	cout << "####################" << endl;
	cout << "\t\t\tYuk Sinifi" << endl;
	string alc = "mehmet";
	string alc2 = "ahmet";
	Yuk yuk1("cam", 5, 8, alc, inla, inla2);
	Yuk yuk2("pencere", 13, 81, alc2, inla2, inla);
	cout << yuk1 << endl;
	cout << "####################" << endl;
	cout << " Yuk copy constructor calismaktadir" << endl;
	Yuk copy3 = yuk1;
	cout << copy3 << endl;
	cout << "####################" << endl;
	cout << " Yuk assignment operator test edilmekte" << endl;
	copy3 = yuk2;
	cout << copy3 << endl;
	cout << "####################" << endl;
	cout << "\t\t\tOtobus Sinifi" << endl;
	vector<Yolcu>yolcuvektor;
	yolcuvektor.push_back(yolcu1);
	Otobus otobus1(sur, "34SM0496", yolcuvektor);
	cout << otobus1 << endl;
	cout << "####################" << endl;
	cout << "\t\t\tKamyon Sinifi" << endl;
	vector<Yuk>kamyonvektor;
	vector<Yuk>kamyonvektor2;
	kamyonvektor.push_back(yuk1);
	kamyonvektor2.push_back(yuk2);
	Kamyon kamyon1(sur, "34UP2497", "Sollama beni sollarim seni",kamyonvektor);
	Kamyon kamyon2(sur2, "37YU3434", "Babam sagolsun", kamyonvektor2);
	cout << kamyon1 << endl;
	cout << "####################" << endl;
	cout << " Kamyon copy constructor calismaktadir" << endl; 
	Kamyon copy4 = kamyon1;
	cout << copy4 << endl;
	cout << "####################" << endl;
	cout << " Kamyon assignment operator test edilmekte" << endl;
	copy4 = kamyon2;
	cout << copy4 << endl;
	cout << "####################" << endl;
	list<Arac*> araclar;
	dosyadanOku("bil122hw_08.xml", araclar);
	cout << "############################################################" << endl;
	return 0;
}