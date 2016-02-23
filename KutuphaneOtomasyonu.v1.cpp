// KutuphaneOtomasyonu.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
using namespace std;
const int max = 15;
class yayin
{
protected:
	string ad;
	int oduncteki_sure;
	bool odunctemi;
public:
	yayin()
	{
		ad = "";
		oduncteki_sure = 0;
		odunctemi = false;
	}
	yayin(string ad)
	{
		this->ad = ad;
	}
	virtual void deger_al()
	{
		char gcc;
		cout << "Yayin adi giriniz:"<<endl;
		cin.ignore();
		getline(cin,ad);
		cout << "oduncte mi? (e/h)";
		cin >> gcc;
		gcc == 'e' ? odunctemi = 1 : odunctemi = 0;
	if(odunctemi)
	{
		cout << "ne kadar zamandir oduncte oldugunu giriniz:";
		cin >> oduncteki_sure;
	}
	}
	void goster()
	{
		cout << "Yayin adi:" << ad << endl;
		if (odunctemi)
			cout <<"Oduncteki sure:"<< oduncteki_sure << endl;
		else cout << "odunc verilmemistir." << endl;

	}
	double ceza_hesapla()
	{
		if (oduncteki_sure>max)
			return(oduncteki_sure - max) * 0.5;
		else return 0;

	}
 void operator ++()
 {
	 oduncteki_sure++;
 }

 virtual void odunc_ver() = 0;
 virtual void gun_ata(int) = 0;
 virtual void iade()=0;
 



	

};
class kitap :public yayin
{
private:
	long ISBN_numarasi;
	void deger_al()
	{
		yayin::deger_al();
		cout << "ISBN numarasini giriniz:";
		cin >> ISBN_numarasi;

	}


	void iade()
	{
		if (odunctemi)
			cout << ceza_hesapla() << endl;

	}
	void odunc_ver()
	{
		if (!odunctemi)
			odunctemi = true;
	}
	void gun_ata(int gun)
	{
		oduncteki_sure = gun;
	}

};
class dvd : public yayin
{
private:
	long DVD_numarasi;

	void deger_al()
	{
		yayin::deger_al();
		cout << "DVD numarasini giriniz:";
		cin >> DVD_numarasi;
	}

	void iade()
	{
		if (odunctemi)
			cout <<ceza_hesapla() <<"TL CEZANIZ BULUNMAKTADIR."<< endl;

	}
	void odunc_ver()
	{
		if (!odunctemi)
			odunctemi = true;
	}
	void gun_ata(int gun)
	{
		oduncteki_sure = gun;
	}


};


int main()
{

	yayin *yyn[10];

	char secim;

	
	for (int i = 1; i <= 2; i++)
	{
		cout << "Secim yapiniz , Kitap mi? yoksa DVD mi? (k/d): ";
		cin >> secim;
		if (secim == 'k') //put new student
			yyn[i] = new kitap; // in array
		else //put new professor
			yyn[i] = new dvd; // in array
		yyn[i]->deger_al(); //get data for person
	
	}
	yyn[1]->odunc_ver();/*
	yyn[3]->odunc_ver();
	yyn[5]->odunc_ver();
	yyn[1]->gun_ata(10);
	yyn[3]->gun_ata(14);
	yyn[5]->gun_ata(50);
	yyn[3]->operator++();
	yyn[3]->operator++();
	yyn[3]->operator++();*/
	yyn[2]->operator++();
	for (int i = 1; i <= 2; i++)
	{
		yyn[i]->iade();

	}



	for (int i = 1; i <= 2; i++)
	{
		yyn[i]->goster();

	}
	
	system("pause");
    return 0;
}

