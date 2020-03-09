/*Yusuf YAL�IN taraf�ndan yaz�lm��t�r
18120205032
07.06.2019 Cuma */
#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
//S�r�c�n�n ehliyet t�r�n� verir
enum EhliyetSinifi
{
	B, C, D, E
};
//S�r�c� s�n�f� bir arac� kullanan ki�iyi ifade eder
class Surucu {
	//Surucunun ad�n�,ya��n�,ehliyetini basar
	friend ostream & operator<<(ostream & out, const Surucu & s);
public:
	//S�r�c�n�n ya�� en az 30 en �ok 62 olabilir.Bunu tutabilecek en k���k veri tipi.
	struct Yas
	{
		unsigned int yas1 : 5;
	};
	Yas xx;
	Surucu(); //Default constructor
	Surucu(const char * str, unsigned int yasi, EhliyetSinifi x); //Surucunun ad�n�,ya��n�,ehliyetini olu�turan constructor
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
	//S�r�c�n�n ad�n� ve soyad�n� C tarz� string olarak tutar.
	char * Ad;

};
class Yolcu {
	//Yolcunun ad�n�,indi�i/bindi�i yeri basar
	friend ostream & operator<<(ostream & out, const Yolcu & s);
public:
	Yolcu();//Default constructor
	 //Yolcunun ad�n�,indi�i/bindi�i yeri olu�turan constructor
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
	char * YolcuAd; //Yolcunun ad�n� ve soyad�n� C tarz� string olarak tutar
	char * binisNoktasi; // Yolcunun binece�i yeri C tarz� string olarak tutar.
	string inisNoktasi; //Yolcunun inece�i yeri C++ tarz� string nesnesi olarak tutar
};
class Yuk {
	//Yukun i�eri�ini,a��rl���n�,hacmini,alicisini ve bindi�i/indi�i yeri basar
	friend ostream & operator<<(ostream & out, const Yuk & s);
public:
	Yuk();//Default constructor
	//Yukun i�eri�ini,a��rl���n�,hacmini,alicisini ve bindi�i/indi�i yeri olu�turan constructor
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
	char * icerik; //Y�k�n cinsini C tarz� string olarak tutar.
	double agirlik; //Y�k�n a��rl���n� tutar
	double hacim; //Y�k�n hacmini tutar.
	string Alici; //Y�k� alacak ki�inin ad�n� ve soyad�n� C++ tarz� string nesnesi olarak tutar
	string binisNoktasi; //Yolcunun binece�i yeri C++ tarz� string nesnesi olarak tutar.
	string inisNoktasi; //Yolcunun inece�i yeri C++ tarz� string nesnesi olarak tutar.
};
class Arac {
	/*Kendinden t�retilmi� s�n�flarda otob�sse yolcular�, kamyonsa y�kleri ekrana basacak �ekilde
	Arac�n plakas�n� ve �of�rlerini ekrana yazd�r�r*/
	friend ostream & operator<<(ostream & out, Arac & s); 
public:
	Arac();//Default constructor
	Arac(const list<Surucu> & listesi,const char * plakasi);//Arac�n plakas�n� ve �of�rlerini  olu�turan constructor
	virtual ~Arac(); // Destructor
	Arac( Arac & other);//copy constructor
	 Arac & operator=( Arac & other); //assignment operator
	char * getplaka()  { return plaka; };
	list<Surucu> & getSuruculer()  { return Suruculer; };
	void setplaka(const char * plakasi);
	void setSuruculer(const list<Surucu> & listesi);
protected:
	virtual void print(ostream& out); // Ekrana yazd�rma fonksiyonu
private:
	list<Surucu>  Suruculer; // Arac�n s�r�c� nesnelerini STL listesi i�inde tutar
	char * plaka; // Arac�n plakas�n� C tarz� string olarak tutar.
};
class Otobus : public Arac {
	friend ostream & operator<<(ostream & out,  Otobus & s); //Ekrana yazd�rma
protected:
	void print(ostream& out); // Ekrana yazd�rma fonksiyonu
public:
	Otobus();//Default constructor
	//Ana s�n�fa ek olarak yolcular�n� olusturan constructor
	Otobus(const list<Surucu> & listes,const char * plak,const vector<Yolcu> & Yolculari); 
	~Otobus(); //Destructor
	vector<Yolcu>& getYolcular();
	void setYolcular(const vector<Yolcu> & Yolculari);
private:
	vector<Yolcu> Yolcular; //Otob�ste yolculuk eden yolcular bir stl vekt�r i�inde tutulmaktad�r
};
class Kamyon : public Arac {
	friend ostream & operator<<(ostream & out, Kamyon & s); //Ekrana yazd�rma
protected:
	void print(ostream& out) ; // Ekrana yazd�rma fonksiyonu
public:

	Kamyon();//Default constructor
	//Ana s�n�fa ek olarak ozl� s�z ve y�klerini olusturan constructor
	Kamyon(const list<Surucu> & listesi,const char * plaka,const char * OzluSozu, const vector<Yuk> & Yukleri);
	~Kamyon(); //Destructor
	Kamyon(Kamyon & other);//copy constructor
	Kamyon & operator=(Kamyon & other); //assignment operator
	char * getOzluSoz() { return OzluSoz; };
	vector<Yuk>& getYukler() { return Yukler; };
	void setOzluSoz(const char * OzluSozu);
	void setYukler(const vector<Yuk>& Yukleri);
private:
	char * OzluSoz;//Kamyonun �zerine yaz�l� ayd�nlat�c�, �zl� s�zd�r, C tarz� string olarak tutulur
	vector<Yuk> Yukler; //Kamyonda ta��nan y�kler bir stl vekt�r i�inde tutulmaktad�r.
};
//xml dosyas�ndan ara�lar� okuyan ve listeyi dolduran bir global fonksiyondur
unsigned int dosyadanOku(const string& filename, list<Arac*> araclar);