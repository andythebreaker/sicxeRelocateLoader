#include "pch.h"
#include "SekaiTekiNi.h"


SekaiTekiNi::SekaiTekiNi()
{
	this->name.s = "";
	this->porgstart.s = "";
	this->porglength.s = "";
	this->name.d = 0;
	this->porgstart.d = 0;
	this->porglength.d = 0;
}

int SekaiTekiNi::print() {
	cout<< this->name.s <<" | "<< this->name.d<<endl;
	cout << this->porgstart.s << " | " << this->porgstart.d << endl;
	cout << this->porglength.s << " | " << this->porglength.d << endl;
	return 0;
}

unsigned int SekaiTekiNi::set(hexd *s,string i) {
	(*s).s = i;
	(*s).d = stoul("0x"+i, nullptr, 16);
	return (*s).d;
}

SekaiTekiNi::~SekaiTekiNi()
{
}
