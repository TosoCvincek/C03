#pragma once
const int DLZKA_HESLA = 8;

class Heslo
{
private:
	union {
		char heslo[DLZKA_HESLA];
		long long nasada;
	};
public:
	Heslo(const char *heslo);
	~Heslo();
	unsigned int Nasada();
};


