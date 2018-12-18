#include "Sifrator.h"
#include <cctype>
#include "Funkcie.h"
#include "Vstup.h"
#include "Koder.h"
#include "Vystup.h"
#include "Help.h"

Sifrator::Sifrator(char pCinnost, const char * pMenoVstupSubor, const char * pHeslo, 
	char pTypVystup, const char * pMenoVystupSubor)
{
	cinnost = tolower(pCinnost);
	if (cinnost != 's' && cinnost != 'd') cinnost = 'h';	
	vstupnySubor = KopirujRetazec(pMenoVstupSubor);
	if (!vstupnySubor) cinnost = 'h';
	heslo = KopirujRetazec(pHeslo);
	konzola = pTypVystup=='s' ? false : true;
	vystupnySubor = KopirujRetazec(pMenoVystupSubor);
	if (!vystupnySubor) konzola = true;
}

Sifrator::Sifrator(const Sifrator & zdroj)
{
	Kopiruj(zdroj);
}

void Sifrator::Kopiruj(const Sifrator & zdroj) {
	cinnost = zdroj.cinnost;
	vstupnySubor = KopirujRetazec(zdroj.vstupnySubor);
	heslo = KopirujRetazec(zdroj.heslo);
	konzola = zdroj.konzola;
	vystupnySubor = KopirujRetazec(zdroj.vstupnySubor);
	konzola = zdroj.konzola;
}

void Sifrator::VypisHelp()
{
	Help().Vypis();
}

void Sifrator::Start()
{
	if (cinnost == 'h') {
		VypisHelp();
	}
	else {
		unsigned char *zdrojText = Vstup(vstupnySubor).Citaj();
		if (zdrojText) {
			unsigned char *cielText = (cinnost == 's') ? Koder().Koduj(heslo,zdrojText) : Koder().Dekoduj(heslo, zdrojText);
			if (cielText) {
				Vystup(vystupnySubor).Zapis(cielText);
				delete[] cielText;
			}
			delete[] zdrojText;
		}
	}
}

Sifrator & Sifrator::operator = (const Sifrator &zdroj) {
	if (this != &zdroj) {
		Sifrator::~Sifrator();
		Kopiruj(zdroj);
	}
	return *this;
}

Sifrator::~Sifrator()
{
	delete[] vystupnySubor;
	delete[] vstupnySubor;
	delete[] heslo;
}
