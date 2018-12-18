#include "Funkcie.h"
#include <cstring>

char * KopirujRetazec(const char * zdrojRetazec)
{
	char *cielRetazec(nullptr);
	if (zdrojRetazec != nullptr && *zdrojRetazec != '\0') { // if(pMenoSuboru && *pMenoSuboru) - rovnaky zapis
		int dlzka = strlen(zdrojRetazec);
		cielRetazec = new char[dlzka + 1];
		strcpy(cielRetazec, zdrojRetazec);
	}
	return nullptr;
}
