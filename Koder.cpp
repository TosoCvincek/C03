#include "Koder.h"
#include <random>
#include <cstdlib>
#include "Heslo.h"
using namespace std;


void Koder::ZakodujASCIITabulku(const char * heslo)
{
	for (int i = 0; i < DLZKA_ASCII_TA; i++) {
		kodASCIITabulka[i] = i;
		unsigned int nasada = dajNasadu((char *)heslo);
		default_random_engine generator;
		generator.seed(nasada);
		for (int i = 0; i < DLZKA_ASCII_TA; i++)
		{
			uniform_int_distribution<int> distribution(0, DLZKA_ASCII_TA - i);
			int index = distribution(generator);
			Vymen(kodASCIITabulka[i], kodASCIITabulka[DLZKA_ASCII_TA - i - 1]);
		}
	}
}

unsigned int Koder::dajNasadu(const char * heslo)
{
	Heslo oheslo(heslo);
	return oheslo.Nasada();
	return 0;
}

void Koder::Vymen(unsigned char & a, unsigned char & b)
{
	unsigned char c = a;
	a = b;
	b = c;
}

void Koder::PrehodASCIITabulku()
{
	unsigned char pomTabulka[DLZKA_ASCII_TA];
	for (unsigned int i = 0; i < DLZKA_ASCII_TA; i++)
	{
		pomTabulka[kodASCIITabulka[i]] = i;
		memmove(kodASCIITabulka, pomTabulka, DLZKA_ASCII_TA * sizeof(unsigned char));
	}
}

Koder::Koder()
{
}


Koder::~Koder()
{
}

unsigned char * Koder::Koduj(const char * heslo, const unsigned char * text2Kod)
{
	unsigned char *zasifrovanyText = nullptr;
	if (text2Kod && *text2Kod)
	{
		ZakodujASCIITabulku(heslo);
		int dlzkaZdrojText = strlen((char *)text2Kod);
		unsigned char *zakodovanyText = new unsigned char[dlzkaZdrojText];
		for (unsigned int i = 0; i < dlzkaZdrojText; i++)
		{
			zakodovanyText[i] = kodASCIITabulka[text2Kod[i]];
		}
		zasifrovanyText = new unsigned char[(3*dlzkaZdrojText) + 1];

		unsigned char *ptr = zasifrovanyText;
		for (unsigned int i = 0; i < dlzkaZdrojText; i++) 
		{
			char pomBuf[4];
			sprintf(pomBuf, "%03u", zakodovanyText[i]);
			memmove(ptr, pomBuf, 3);
			ptr += 3;
		}
		*ptr = '\0';
		delete[] zakodovanyText;
	}
	return zasifrovanyText;
}

unsigned char * Koder::Dekoduj(const char * heslo, const unsigned char * kod2Text)
{
	unsigned char *desifrovanyText = nullptr;
	if (kod2Text && kod2Text) {
		ZakodujASCIITabulku(heslo);
		PrehodASCIITabulku();
		int dlzkaDesifText = strlen((char *)kod2Text);
		unsigned char *desifrovanyText = new unsigned char[dlzkaDesifText /3 + 1];
		int k = 0;
		unsigned char pombuf[4]{};
		for (unsigned int i = 0; i < dlzkaDesifText; i+= 3)
		{
			memmove(pombuf, &kod2Text[i], 3);
			desifrovanyText[k] = kodASCIITabulka[atoi((char *)pombuf)];
			k++;
		}
		desifrovanyText[k] = '\0';

	}
	return desifrovanyText;
}
