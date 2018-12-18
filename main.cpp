#define START_TESTY
#ifdef START_TESTY
#include "Testy.h"
#endif
#include "Vystup.h"
#include "Sifrator.h"


int main(int argc, char*argv[]) {
	bool testyOk = true;
#ifdef START_TESTY
	Testy test;
	testyOk = test.Run();
#endif

	if (testyOk) {
		char cinnost = 'h';
		char *heslo = nullptr;
		char *vstupsubor = nullptr;
		char typvystup = 'c';
		char *vystupsubor = nullptr;
		if (argc > 1)
			cinnost = argv[1][0];
		if (argc > 2)
			vstupsubor = argv[2];
		if (argc > 3)
			heslo = argv[3];
		if (argc > 4)
			typvystup = argv[4][0];
		if (argc > 5)
			vystupsubor = argv[5];
		Sifrator(cinnost, vystupsubor, heslo, typvystup, vystupsubor).Start();
	}
	else {
		Vystup konzola;
		konzola.Zapis((unsigned char *)"Chyba v programe, nepresli testy.\n");
	}
}
