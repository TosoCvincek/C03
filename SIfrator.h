#pragma once
class Sifrator
{
public:
	Sifrator(char pCinnost, const char *pMenoVstupSubor, const char *pHeslo = nullptr, 
		char pTypVystup = 'c', const char *pMenoVystupSubor = nullptr);
	Sifrator & operator = (const Sifrator &zdroj);
	Sifrator(const Sifrator &zdroj);
	void Start();

	~Sifrator();
private:
	char cinnost = 'h';
	char *heslo = nullptr;
	char *vstupnySubor = nullptr;
	bool konzola = true;
	char *vystupnySubor = nullptr;
	void Kopiruj(const Sifrator & zdroj);
	void VypisHelp();
	
};

