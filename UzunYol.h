/*Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
07.06.2019 Cuma */
#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
//Sürücünün ehliyet türünü verir
enum EhliyetSinifi
{
	B, C, D, E
};
//Sürücü sýnýfý bir aracý kullanan kiþiyi ifade eder
class Surucu {
	//Surucunun adýný,yaþýný,ehliyetini basar
	friend ostream & operator<<(ostream & out, const Surucu & s);
public:
	//Sürücünün yaþý en az 30 en çok 62 olabilir.Bunu tutabilecek en küçük veri tipi.
	struct Yas
	{
		unsigned int yas1 : 5;
	};
	Yas xx;
	Surucu(); //Default constructor
	Surucu(const char * str, unsigned int yasi, EhliyetSinifi x); //Surucunun adýný,yaþýný,ehliyetini oluþturan constructor
	~Surucu(); //Destructor
	Surucu(const Surucu & other); //copy constructor
	const Surucu & operator=(const Surucu & other); //assignment operator
	char getEhliyet() { return ehliyet; };
	char * getad() { return Ad; };
	unsigned int getYas() { return xx.yas1; }
	void setad(char * isim);
	void setYas(unsigned int yasi);
	void setEhliyet(EhliyetSinifi ehliyeti);
private:
	EhliyetSinifi ehliyet;
	//Sürücünün adýný ve soyadýný C tarzý string olarak tutar.
	char * Ad;

};
class Yolcu {
	//Yolcunun adýný,indiði/bindiði yeri basar
	friend ostream & operator<<(ostream & out, const Yolcu & s);
public:
	Yolcu();//Default constructor
	 //Yolcunun adýný,indiði/bindiði yeri oluþturan constructor
	Yolcu(const char * YolcuAdi,const char * binisNokta, string inisNokta);
	~Yolcu(); //Destructor
	Yolcu(const Yolcu & other); //copy constructor
	const Yolcu & operator=(const Yolcu & other); //assignment operator
	char * getad() { return YolcuAd; };
	char * getbinisNoktasi() { return binisNoktasi; };
	string getinisNoktasi() { return inisNoktasi; };
	void setYolcuAd(char * YolcuAdi);
	void setbinisNoktasi(char * binisNokta);
	void setinisNoktasi(string inisNokta);
private:
	char * YolcuAd; //Yolcunun adýný ve soyadýný C tarzý string olarak tutar
	char * binisNoktasi; // Yolcunun bineceði yeri C tarzý string olarak tutar.
	string inisNoktasi; //Yolcunun ineceði yeri C++ tarzý string nesnesi olarak tutar
};
class Yuk {
	//Yukun içeriðini,aðýrlýðýný,hacmini,alicisini ve bindiði/indiði yeri basar
	friend ostream & operator<<(ostream & out, const Yuk & s);
public:
	Yuk();//Default constructor
	//Yukun içeriðini,aðýrlýðýný,hacmini,alicisini ve bindiði/indiði yeri oluþturan constructor
	Yuk(const char * icerigi, double agirligi, double hacim, string Alici, string binisNokta, string inisNokta);
	~Yuk(); //Destructor
	Yuk(const Yuk & other);//copy constructor
	const Yuk & operator=(const Yuk & other); //assignment operator
	char * geticerik() { return icerik; };
	string getinisNoktasi() { return inisNoktasi; };
	string getAlici() { return Alici; };
	string getbinisNoktasi() { return binisNoktasi; };
	double getagirlik() { return agirlik; };
	double gethacim() { return hacim; };
	void setinisNoktasi(string inisNokta);
	void setbinisNoktasi(string binisNokta);
	void setAlici(string Alici);
	void seticerik(char * icerigi);
	void setagirlik(double agirligi);
	void sethacim(double hacim);
private:
	char * icerik; //Yükün cinsini C tarzý string olarak tutar.
	double agirlik; //Yükün aðýrlýðýný tutar
	double hacim; //Yükün hacmini tutar.
	string Alici; //Yükü alacak kiþinin adýný ve soyadýný C++ tarzý string nesnesi olarak tutar
	string binisNoktasi; //Yolcunun bineceði yeri C++ tarzý string nesnesi olarak tutar.
	string inisNoktasi; //Yolcunun ineceði yeri C++ tarzý string nesnesi olarak tutar.
};
class Arac {
	/*Kendinden türetilmiþ sýnýflarda otobüsse yolcularý, kamyonsa yükleri ekrana basacak þekilde
	Aracýn plakasýný ve þoförlerini ekrana yazdýrýr*/
	friend ostream & operator<<(ostream & out, Arac & s); 
public:
	Arac();//Default constructor
	Arac(const list<Surucu> & listesi,const char * plakasi);//Aracýn plakasýný ve þoförlerini  oluþturan constructor
	virtual ~Arac(); // Destructor
	Arac( Arac & other);//copy constructor
	 Arac & operator=( Arac & other); //assignment operator
	char * getplaka()  { return plaka; };
	list<Surucu> & getSuruculer()  { return Suruculer; };
	void setplaka(const char * plakasi);
	void setSuruculer(const list<Surucu> & listesi);
protected:
	virtual void print(ostream& out); // Ekrana yazdýrma fonksiyonu
private:
	list<Surucu>  Suruculer; // Aracýn sürücü nesnelerini STL listesi içinde tutar
	char * plaka; // Aracýn plakasýný C tarzý string olarak tutar.
};
class Otobus : public Arac {
	friend ostream & operator<<(ostream & out,  Otobus & s); //Ekrana yazdýrma
protected:
	void print(ostream& out); // Ekrana yazdýrma fonksiyonu
public:
	Otobus();//Default constructor
	//Ana sýnýfa ek olarak yolcularýný olusturan constructor
	Otobus(const list<Surucu> & listes,const char * plak,const vector<Yolcu> & Yolculari); 
	~Otobus(); //Destructor
	vector<Yolcu>& getYolcular();
	void setYolcular(const vector<Yolcu> & Yolculari);
private:
	vector<Yolcu> Yolcular; //Otobüste yolculuk eden yolcular bir stl vektör içinde tutulmaktadýr
};
class Kamyon : public Arac {
	friend ostream & operator<<(ostream & out, Kamyon & s); //Ekrana yazdýrma
protected:
	void print(ostream& out) ; // Ekrana yazdýrma fonksiyonu
public:

	Kamyon();//Default constructor
	//Ana sýnýfa ek olarak ozlü söz ve yüklerini olusturan constructor
	Kamyon(const list<Surucu> & listesi,const char * plaka,const char * OzluSozu, const vector<Yuk> & Yukleri);
	~Kamyon(); //Destructor
	Kamyon(Kamyon & other);//copy constructor
	Kamyon & operator=(Kamyon & other); //assignment operator
	char * getOzluSoz() { return OzluSoz; };
	vector<Yuk>& getYukler() { return Yukler; };
	void setOzluSoz(const char * OzluSozu);
	void setYukler(const vector<Yuk>& Yukleri);
private:
	char * OzluSoz;//Kamyonun üzerine yazýlý aydýnlatýcý, özlü sözdür, C tarzý string olarak tutulur
	vector<Yuk> Yukler; //Kamyonda taþýnan yükler bir stl vektör içinde tutulmaktadýr.
};
//xml dosyasýndan araçlarý okuyan ve listeyi dolduran bir global fonksiyondur
unsigned int dosyadanOku(const string& filename, list<Arac*> araclar);