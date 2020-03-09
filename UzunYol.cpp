/*Exception Handling mekanizmalarý burada kullanýlmýþtýr*/
/*Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
07.06.2019 Cuma */
#include "UzunYol.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <fstream>

#include <locale>

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

unsigned int dosyadanOku(const string & filename, list<Arac*> araclar)
{
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile("bil122_hw08.xml");

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");

	// Iterate over the Vehicles
	cout << "Parsing Vehicles.xml..." << endl;

	int i = 0;
	for (auto * vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{
		cout << "Arac-" << ++i << "\t" << vehicle_node->first_node("Turu")->value()
			<< "\t" << vehicle_node->first_node("Plaka")->value();

		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon")) 
			cout << "\t\"" << vehicle_node->first_node("OzluSoz")->value() << "\"";
	
		cout << endl;

		auto * drivers_root_node = vehicle_node->first_node("Suruculer");
		int j = 0;
		for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
		{
			cout << "\tSurucu-" << ++j << "\t" << "\t" << driver_node->first_node("Adi")->value()
				<< "\t" << driver_node->first_node("Yasi")->value()
				<< "\t" << driver_node->first_node("EhliyetSinifi")->value() << endl;
		}

		cout << endl;
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon")) {
			auto * loads_root_node = vehicle_node->first_node("Yukler");
			int k = 0;
			for (auto * load_node = loads_root_node->first_node("Yuk"); load_node; load_node = load_node->next_sibling())
			{
				cout << "\tYuk-" << ++k << "\t" << "\t" << "Icerik: " << load_node->first_node("Icerik")->value()
					<< "\t" << "Agirlik: " << load_node->first_node("Agirlik")->value()
					<< "\t" << "Hacim: " << load_node->first_node("Hacim")->value()
					<< "\t" << "Alici: " << load_node->first_node("Alici")->value()
					<< "\t" << "BinisNoktasi: " << load_node->first_node("BinisNoktasi")->value()
					<< "\t" << "InisNoktasi: " << load_node->first_node("InisNoktasi")->value() << endl;
			}
		}

		cout << endl;
		if (strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon")) {
			auto * passengers_root_node = vehicle_node->first_node("Yolcular");
			int m = 0;
			for (auto * passenger_node = passengers_root_node->first_node("Yolcu"); passenger_node; passenger_node = passenger_node->next_sibling())
			{
				cout << "\tYolcu-" << ++m << "\t" << "\t" << "Adi: " << passenger_node->first_node("Adi")->value()
					<< "\t" << "BinisNoktasi: " << passenger_node->first_node("BinisNoktasi")->value()
					<< "\t" << "InisNoktasi: " << passenger_node->first_node("InisNoktasi")->value() << endl;
			}
		}
	}
	return 0;
}

ostream & operator<<(ostream & out, const Surucu & s)
{

	out << "Surucunun ismi: ";
		for (unsigned i = 0; i < strlen(s.Ad); ++i)
		{
			out << s.Ad[i];
		}
		out << endl;
		out << "Surucunun yasi: " << 30 + s.xx.yas1 << endl;
		out << "Ehliyetsinifi : " << (static_cast<char>('B' + s.ehliyet)) << endl;
	
	return out;
}

ostream & operator<<(ostream & out, const Yolcu & s)
{
	out << "Yolcunun ismi: ";
	for (unsigned i = 0; i < strlen(s.YolcuAd); ++i)
	{
		out << s.YolcuAd[i];
	}
	out << endl;
	out << "Binis noktasi: ";
	for (unsigned i = 0; i < strlen(s.binisNoktasi); ++i)
	{
		out << s.binisNoktasi[i];
	}
	out << endl;
	out << "Inis noktasi: ";
	for (unsigned i = 0; i < s.inisNoktasi.size(); ++i)
	{
		out << s.inisNoktasi[i];
	}
	return out;
}

ostream & operator<<(ostream & out, const Yuk & s)
{
	
	out << "Yukun cinsi: ";
	for (unsigned i = 0; i < strlen(s.icerik); ++i)
	{
		out << s.icerik[i];
	}
	out << endl;
	out << "Yukun agirligi: ";
	out << s.agirlik << endl;
	out << "Yukun hacmi: ";
	out << s.hacim << endl;
	out << "Yuku alacak kisi: ";
	for (unsigned i = 0; i < s.Alici.size(); ++i)
	{
		out << s.Alici[i];
	}
	out << endl;
	out << "Yolcunun binecegi yer: ";
	for (unsigned i = 0; i < s.binisNoktasi.size(); ++i)
	{
		out << s.binisNoktasi[i];
	}
	out << endl;
	out << "Yolcunun inecegi yer: ";
	for (unsigned i = 0; i < s.inisNoktasi.size(); ++i)
	{
		out << s.inisNoktasi[i];
	}
	return out;
}

ostream & operator<<(ostream & out, Arac & s)
{
	s.print(out);
	return out;

}

ostream & operator<<(ostream & out, Otobus & s)
{
	s.print(out);
	return out;
}

ostream & operator<<(ostream & out, Kamyon & s)
{
	s.print(out);
	return out;
}

Surucu::Surucu()
{
	Ad = nullptr;
}

Surucu::Surucu(const char * str, unsigned int yasi, EhliyetSinifi x)
{
	xx.yas1 = yasi;
	ehliyet = x;
	Ad = new char[strlen(str)+1];
	try {
		if (Ad == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < strlen(Ad); ++i) {
		Ad[i] = str[i];
	}
}

Surucu::~Surucu()
{
	
	if (Ad != nullptr)
		delete[] Ad;
}

Surucu::Surucu(const Surucu & other)
{
	

	Ad = nullptr;
	if (strlen(other.Ad) != 0)
	{
	
		Ad = new char[strlen(other.Ad)+1];
		try {
			if (Ad == nullptr) throw bad_alloc();
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		setad(other.Ad);
	}
	ehliyet = other.ehliyet;
	xx.yas1 = other.xx.yas1;
}

const Surucu & Surucu::operator=(const Surucu & other)
{
	if (this == &other)
		return *this;

	if (Ad != nullptr)
		delete[] Ad;

	ehliyet = other.ehliyet;
	xx.yas1 = other.xx.yas1;

	Ad = new char[strlen(other.Ad)+1];
	try {
		if (Ad == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned i = 0; i < strlen(Ad); ++i)
	{
		Ad[i] = other.Ad[i];
	}
	return *this;

}

void Surucu::setad(char * isim)
{
	for (unsigned i = 0; i < strlen(isim)+1; ++i)
	{
		Ad[i] = isim[i];
	}
}

void Surucu::setYas(unsigned int yasi)
{
	xx.yas1 = yasi;
}

void Surucu::setEhliyet(EhliyetSinifi ehliyeti)
{
	ehliyet = ehliyeti;
}

Yolcu::Yolcu()
{
	YolcuAd = nullptr;
	binisNoktasi = nullptr;
	inisNoktasi = '\0';
}

Yolcu::Yolcu(const char * YolcuAdi,const char * binisNokta, string inisNokta)
{
	YolcuAd = new char[strlen(YolcuAdi)+1];
	binisNoktasi = new char[strlen(binisNokta)+1];
	inisNoktasi = inisNokta;
	try {
		if (YolcuAd == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < strlen(YolcuAd); ++i) {
		YolcuAd[i] = YolcuAdi[i];
	}
	for (unsigned int i = 0; i < strlen(binisNoktasi); ++i) {
		binisNoktasi[i] = binisNokta[i];
	}
}

Yolcu::~Yolcu()
{
	if (YolcuAd != nullptr && binisNoktasi != nullptr)
		delete[] YolcuAd;
		delete[] binisNoktasi;
}

Yolcu::Yolcu(const Yolcu & other)
{
	YolcuAd = nullptr;
	binisNoktasi = nullptr;
	if (strlen(other.YolcuAd) != 0)
	{
		YolcuAd = new char[strlen(other.YolcuAd)+1];
		binisNoktasi = new char[strlen(other.binisNoktasi)+1];
		try {
			if (YolcuAd == nullptr) throw bad_alloc();//binis noktasi icinde denettirebilirim
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		for (unsigned i = 0; i < strlen(YolcuAd); ++i)
		{
			YolcuAd[i] = other.YolcuAd[i];
		}
		for (unsigned i = 0; i < strlen(binisNoktasi); ++i)
		{
			binisNoktasi[i] = other.binisNoktasi[i];
		}
	}
	inisNoktasi = other.inisNoktasi;
}

const Yolcu & Yolcu::operator=(const Yolcu & other)
{
	if (this == &other)
		return *this;

	if (YolcuAd != nullptr && binisNoktasi != nullptr)
		delete[] YolcuAd;
		delete[] binisNoktasi;

		inisNoktasi = other.inisNoktasi;

	YolcuAd = new char[strlen(other.YolcuAd)+1];
	binisNoktasi = new char[strlen(other.binisNoktasi)+1];
	try {
		if (YolcuAd == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned i = 0; i < strlen(YolcuAd); ++i)
	{
		YolcuAd[i] = other.YolcuAd[i];
	}
	for (unsigned i = 0; i < strlen(binisNoktasi); ++i)
	{
		binisNoktasi[i] = other.binisNoktasi[i];
	}
	return *this;
}

void Yolcu::setYolcuAd(char * YolcuAdi)
{
	for (unsigned i = 0; i < strlen(YolcuAdi); ++i)
	{
		YolcuAd[i] = YolcuAdi[i];
	}
}

void Yolcu::setbinisNoktasi(char * binisNokta)
{
	for (unsigned i = 0; i < strlen(binisNokta); ++i)
	{
		binisNoktasi[i] = binisNokta[i];
	}
}

void Yolcu::setinisNoktasi(string inisNokta)
{
	inisNoktasi = inisNokta;
}

Yuk::Yuk()
{
	icerik = nullptr;
	agirlik = 0;
	hacim = 0;
	Alici = '\0';
	binisNoktasi = '\0';
	inisNoktasi = '\0';
}

Yuk::Yuk(const char * icerigi, double agirligi, double hacim, string Alici, string binisNokta, string inisNokta)
{
	agirlik = agirligi;
	this->hacim = hacim;
	this->Alici = Alici;
	binisNoktasi = binisNokta;
	inisNoktasi = inisNokta;
	icerik = new char[strlen(icerigi)+1];
	try {
		if (icerik == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < strlen(icerik); ++i) {
		icerik[i] = icerigi[i];
	}
}

Yuk::~Yuk()
{
	if (icerik != nullptr)
		delete[] icerik;
}

Yuk::Yuk(const Yuk & other)
{
	agirlik = other.agirlik;
	hacim = other.hacim;
	Alici = other.Alici;
	binisNoktasi = other.binisNoktasi;
	inisNoktasi = other.inisNoktasi;
	icerik = nullptr;
	if (strlen(other.icerik) != 0)
	{
		icerik = new char[strlen(other.icerik)+1];
		try {
			if (icerik == nullptr) throw bad_alloc();
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		seticerik(other.icerik);
	}
	
}

const Yuk & Yuk::operator=(const Yuk & other)
{
	if (this == &other)
		return *this;

	if (icerik != nullptr)
		delete[] icerik;

	agirlik = other.agirlik;
	hacim = other.hacim;
	Alici = other.Alici;
	binisNoktasi = other.binisNoktasi;
	inisNoktasi = other.inisNoktasi;

	icerik = new char[strlen(other.icerik)+1];
	try {
		if (icerik == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	seticerik(other.icerik);
	return *this;
}

void Yuk::setinisNoktasi(string inisNokta)
{
	inisNoktasi = inisNokta;
}

void Yuk::setbinisNoktasi(string binisNokta)
{
	binisNoktasi = binisNokta;
}

void Yuk::setAlici(string Alici)
{
	this->Alici = Alici;
}

void Yuk::seticerik(char * icerigi)
{
	for (unsigned i = 0; i < strlen(icerigi)+1; ++i)
	{
		icerik[i] = icerigi[i];
	}
}

void Yuk::setagirlik(double agirligi)
{
	agirlik = agirligi;
}

void Yuk::sethacim(double hacim)
{
	this->hacim = hacim;
}

Arac::Arac()
{
	plaka = nullptr;

}

Arac::Arac(const list<Surucu>& listesi,const char * plakasi)
{
	
	Suruculer.clear();
	plaka = new char[strlen(plakasi)+1];
	try {
		if (plaka == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}

	Suruculer = listesi;
	for (unsigned int i = 0; i < strlen(plaka); ++i) {
		plaka[i] = plakasi[i];
	}
}

Arac::~Arac()
{
	if (plaka != nullptr)
		delete[] plaka;
}

Arac::Arac( Arac & other)
{
	plaka = nullptr;
	if (strlen(other.plaka) != 0)
	{
		plaka = new char[strlen(other.plaka)+1];
		try {
			if (plaka == nullptr) throw bad_alloc();
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		for (unsigned int i = 0; i < strlen(plaka); ++i) {
			plaka[i] = other.plaka[i];
		}
		for (Surucu i : other.Suruculer) {
			Suruculer.push_back(i);
		}
	}
}

Arac & Arac::operator=(Arac & other)
{
	Suruculer.clear();
	if (this == &other)
		return *this;

	if (plaka != nullptr)
		delete[] plaka;

	for (Surucu a : other.Suruculer) {
		Suruculer.push_back(a);
	}

	plaka = new char[strlen(other.plaka) + 1];
	try {
		if (plaka == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < strlen(plaka); ++i) {
		plaka[i] = other.plaka[i];
	}
	return *this;
}

void Arac::setplaka(const char * plakasi)
{
	for (unsigned i = 0; i < strlen(plakasi)+1; ++i)
	{
		plaka[i] = plakasi[i];
	}
}

void Arac::setSuruculer(const list<Surucu>& listesi)
{
	for (Surucu a : listesi) {
		Suruculer.push_back(a);
	}
}

void Arac::print(ostream & out)
{
	out << "Aracin plakasi: ";
	for (unsigned i = 0; i < strlen(plaka); ++i) {
		out <<plaka[i];
	}
	out << endl;
	out << "Aracin soforu/soforleri: " << endl;
	for (Surucu a : Suruculer) {
		out << a << endl;
	}
}

void Otobus::print(ostream & out) 
{
	out << "Aracin plakasi: ";
	out << Arac::getplaka() << endl;
	out << endl;
	out << "Aracin soforu/soforleri: " << endl;
	for (Surucu a : Arac::getSuruculer()) {
		out << a << endl;
	}
	out << " Yolcular : " << endl;
	for (unsigned i = 0; i < Yolcular.size(); ++i) {
		out << Yolcular[i];
	}
}

Otobus::Otobus() : Arac()
{
}

Otobus::Otobus(const list<Surucu>& listes,const char * plak, const vector<Yolcu>& Yolculari) : Arac(listes,plak)
{
	setYolcular(Yolculari);
}

Otobus::~Otobus()
{
}

vector<Yolcu>& Otobus::getYolcular()
{
	return Yolcular;
}

void Otobus::setYolcular(const vector<Yolcu>& Yolculari)
{
	
	for (unsigned i = 0; i < Yolculari.size(); ++i) {
		Yolcular.push_back(Yolculari[i]);
	}
}

void Kamyon::print(ostream & out)
{
	
	out << "Aracin plakasi: ";
	out << Arac::getplaka() << endl;
	out << endl;
	out << "Aracin soforu/soforleri: " << endl;
	for (Surucu a :getSuruculer()) {
		out << a << endl;
	}
	out << " Ozlu soz : ";
	for (unsigned i = 0; i < strlen(OzluSoz)+1; ++i) {
		out << OzluSoz[i];
	}
	out << endl;
	out << " Kamyonda tasinan yukler : " << endl;
	for (unsigned i = 0; i < Yukler.size(); ++i) {
		out << Yukler[i];
	}
}

Kamyon::Kamyon()
{
	OzluSoz = nullptr;
}

Kamyon::Kamyon(const list<Surucu>& listesi,const char * plaka,const char * OzluSozu, const vector<Yuk>& Yukleri) : Arac(listesi, plaka)
{
	OzluSoz = new char[strlen(OzluSozu) + 1];
	try {
		if (OzluSoz == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < strlen(OzluSoz); ++i) {
		OzluSoz[i] = OzluSozu[i];
	}
	setYukler(Yukleri);
}

Kamyon::~Kamyon()
{
	if (OzluSoz != nullptr)
		delete[] OzluSoz;
}

Kamyon::Kamyon(Kamyon & other) : Arac(other)
{
	OzluSoz = nullptr;
	if (strlen(other.OzluSoz) != 0)
	{
		OzluSoz = new char[strlen(other.OzluSoz)+1];
		try {
			if (OzluSoz == nullptr) throw bad_alloc();
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		for (unsigned i = 0; i < strlen(OzluSoz); ++i) {
			OzluSoz[i] = other.OzluSoz[i];
		}
		setYukler(other.Yukler);
	}
}

Kamyon & Kamyon::operator=(Kamyon & other) 
{
	Yukler.clear();
	if (this == &other)
		return *this;

	if (OzluSoz != nullptr)
		delete[] OzluSoz;

	setYukler(other.Yukler);

	OzluSoz = new char[strlen(other.OzluSoz)+1];
	try {
		if (OzluSoz == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned i = 0; i < strlen(OzluSoz); ++i) {
		OzluSoz[i] = other.OzluSoz[i];
	}
	return *this;
}

void Kamyon::setOzluSoz(const char * OzluSozu)
{
	for (unsigned i = 0; i < strlen(OzluSozu)+1; ++i) {
		OzluSoz[i] = OzluSozu[i];
	}
}

void Kamyon::setYukler(const vector<Yuk>& Yukleri)
{
	for (unsigned i = 0; i < Yukleri.size(); ++i) {
		Yukler.push_back(Yukleri[i]);
	}
}
