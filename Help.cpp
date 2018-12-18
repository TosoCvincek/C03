#include "Help.h"
#include "Vystup.h"

void Help::Vypis()
{
	Vystup konzola("");
	konzola.Zapis((unsigned char *)
		"Cvicenie03Sifrator CINNOST VSTUP_SUBOR HESLO [TYP_VYSTUPU VYSTUP_SUBOR] \n"
		"   CINNOST:\n"
		"      s...sifrovanie\n"
		"      d...desifrovanie\n"
		"      h...help\n"
		"   TYP_VYSTUP:\n"
		"      s...subor\n"
		"      c...konzola\n"
	);
}
