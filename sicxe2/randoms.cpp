#include "pch.h"
#include "randoms.h"

#define setdbg false
#define dbg if(setdbg)
#define msize 12287//2FFF
#define pgsize 4000//4k
randoms::randoms()
{/*不要呼叫這個，叫(int)的多載*/
	cout << "[ERROR@randoms.cpp::randoms()]" << endl;
	exit(1);
}

randoms::randoms(int progsize)
{/*叫了我後，請叫int load_addr(屬性)*/
	min = 1024;
	max = msize - progsize * 125 / 100;
	pages = (max - min) / pgsize;
	dbg cout << max << endl;
	dbg cout << pages << endl;
	random_device generator;
	uniform_int_distribution<int> distribution(0, pages);
	//uniform_int_distribution<int> distribution2(0, 6);
	//dbg cout << distribution2(generator) << endl;
	pnum = distribution(generator);
	load_addr = min + pnum * pgsize;
}


randoms::~randoms()
{
}
