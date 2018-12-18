#include "Heslo.h"
#include <cstring>



Heslo::Heslo(const char *pheslo)
{
	if (pheslo && *pheslo) {
		int dlzkaHesla = strlen(pheslo);
		dlzkaHesla = dlzkaHesla > DLZKA_HESLA ? DLZKA_HESLA : dlzkaHesla;
		memmove(heslo, pheslo, dlzkaHesla);
	}
}


Heslo::~Heslo()
{
}

unsigned int Heslo::Nasada() 
{
	unsigned int nasada1 = nasada & 0x00000000ffffffff;
	unsigned int nasada2 = (nasada >> 32) & 0x00000000ffffffff;
	return nasada1 + nasada2;
}
