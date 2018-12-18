#pragma once
class Vystup
{
private:
	char *menoSuboru = nullptr;
public:
	Vystup(const char *pMenoSuboru = nullptr);
	Vystup(const Vystup &zdroj);
	Vystup &operator =(const Vystup &zdroj);
	~Vystup();
	void Zapis(const unsigned char *text);
};

