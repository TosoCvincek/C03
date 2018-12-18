#include "Testy.h"
#include "Vstup.h"
#include "Vystup.h"
#include "Koder.h"


/*Testy::Testy()
{
}


Testy::~Testy()
{
}
*/
bool Testy::Run()
{
	const char *menoSuboru = "xxx.txt";
	//Vstup V(*menoSuboru);
	Vstup v("main.cpp");
	unsigned char *text = v.Citaj();
	Vystup vyst("main.copy");
	vyst.Zapis(text);
	Vystup konzola;
	konzola.Zapis(text);
	delete[] text;
	Koder koder;
	unsigned char *sifrtext = koder.Koduj("abc", (unsigned char*)"Tomas");
	unsigned char *desifrtext = koder.Koduj("abc", sifrtext);
	delete[] desifrtext;
	delete[] sifrtext;
	return true;
}
