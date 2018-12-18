#pragma once
class Vstup
{
private:
	char *menoSuboru = nullptr;
	int DajDlzkuSuboru();

public:
	Vstup(const char *pMenoSuboru);
	Vstup(const Vstup &zdroj);
	Vstup &operator =(const Vstup &zdroj);
	~Vstup();
	unsigned char * Citaj();

};

