#include "Vstup.h"
#include <cstring>
#include <cstdio>
#include "Funkcie.h"
//int x;

int Vstup::DajDlzkuSuboru()
{
	int dlzka = 0;
	if (menoSuboru) {
		FILE *f = fopen(menoSuboru, "rb");
		if (f)
		{
			fseek(f, 0, SEEK_END);
			dlzka = ftell(f);
			fclose(f);
		}
		return dlzka;
	}
}
Vstup::Vstup(const char *pMenoSuboru)
{
	//int x;
	//x = 5;
	//::x = 10; //o uroven vyssie
	/*if (pMenoSuboru != nullptr && *pMenoSuboru != '\0') { // if(pMenoSuboru && *pMenoSuboru) - rovnaky zapis
		int dlzka = strlen(pMenoSuboru);
		menoSuboru = new char[dlzka + 1];
		strcpy(menoSuboru, pMenoSuboru);
	}*/ 
	menoSuboru = KopirujRetazec(pMenoSuboru);
}

Vstup::Vstup(const Vstup & zdroj)
{
	/*if (zdroj.menoSuboru != nullptr && *zdroj.menoSuboru != '\0') { // if(pMenoSuboru && *pMenoSuboru) - rovnaky zapis
		int dlzka = strlen(zdroj.menoSuboru);
		menoSuboru = new char[dlzka + 1];
		strcpy(menoSuboru, zdroj.menoSuboru);
	}*/
	menoSuboru = KopirujRetazec(zdroj.menoSuboru);
}

Vstup & Vstup::operator=(const Vstup & zdroj)
{	
	if (this != &zdroj) {
		if (menoSuboru) delete[] menoSuboru;
		menoSuboru = KopirujRetazec(zdroj.menoSuboru);
	}
	return *this;
}

Vstup::~Vstup()
{
	delete[] menoSuboru; //vymaže sa celé pole 
}


unsigned char * Vstup::Citaj()
{
	if (menoSuboru) {
		int dlzkaSuboru = DajDlzkuSuboru();
		unsigned char *text = new unsigned char[dlzkaSuboru + 1];
		if (text) {
			FILE *f = fopen(menoSuboru, "rb");
			if (f) {
				fread(text, dlzkaSuboru, 1 ,f);
				text[dlzkaSuboru] = '\0';
				fclose(f);
				return text;
			}
		}
	}
	return nullptr;
}
