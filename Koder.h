#pragma once
const unsigned int DLZKA_ASCII_TA = 256;

class Koder
{
private:
	unsigned char kodASCIITabulka[DLZKA_ASCII_TA];
	void ZakodujASCIITabulku(const char *heslo);
	unsigned int dajNasadu(const char *heslo);
	void Vymen(unsigned char &a, unsigned char &b);
	void PrehodASCIITabulku();
public:
	Koder();
	~Koder();
	unsigned char *Koduj(const char *heslo, const unsigned char *text2Kod);
	unsigned char *Dekoduj(const char *heslo, const unsigned char *kod2Text);
};

