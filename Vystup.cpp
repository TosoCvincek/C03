#include "Funkcie.h"
#include "Vystup.h"
#include <cstdio>
#include <cstring>
#include <iostream>



Vystup::Vystup(const char *pMenoSuboru)
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

Vystup::Vystup(const Vystup & zdroj)
{
	/*if (zdroj.menoSuboru != nullptr && *zdroj.menoSuboru != '\0') { // if(pMenoSuboru && *pMenoSuboru) - rovnaky zapis
		int dlzka = strlen(zdroj.menoSuboru);
		menoSuboru = new char[dlzka + 1];
		strcpy(menoSuboru, zdroj.menoSuboru);
	}*/
	menoSuboru = KopirujRetazec(zdroj.menoSuboru);
}

Vystup & Vystup::operator=(const Vystup & zdroj)
{
	if (this != &zdroj) {
		if (menoSuboru) delete[] menoSuboru;
		menoSuboru = KopirujRetazec(zdroj.menoSuboru);
	}
	return *this;
}

Vystup::~Vystup()
{
	delete[] menoSuboru; //vymaže sa celé pole 
}

void Vystup::Zapis(const unsigned char * text)
{
	if (text && *text) {
		if (menoSuboru) {
			int dlzka = strlen((char *)text);
			FILE *f = fopen(menoSuboru, "wb");
			if (f) {
				fwrite(text, dlzka, 1, f);
				fclose(f);
			}
		} else {
			std::cout << text << '\n';
		}
	}
}

