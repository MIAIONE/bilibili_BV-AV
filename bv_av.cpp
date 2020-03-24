// powered by Lothlorien
// From Python_Ver : https://gist.github.com/abc1763613206/b8afbb88849835f064f74e652fdb16c5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned long long uint64;

unsigned int search(char in);
uint64 bvTOav(char *read);
void avTObv(uint64 read);

const char table[59] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
const unsigned int s[6] = {11, 10, 3, 8, 4, 6};
const unsigned long long _xor = 177451812, _add = 8728348608;
char BV[13] = {'B', 'V', '1', '0', '0', '4', '0', '1', '0', '7', '0', '0', '\0'};

int main()
{
	char a[13] = "BV17x411w7KC";
	uint64 t;
	t = bvTOav(&a[0]);
	printf("%s\n", a);
	printf("RESULT: av%lld\n", t);
	printf("%lld\n", t);
	avTObv(t);
	printf("RESULT: %s\n", BV);
	return 0;
}

unsigned int search(char in)		//Lookup dictionary
{
	for (int i = 0; i < 58; i++)
	{
		if (table[i] == in)
			return i;
	}
}

uint64 bvTOav(char *read)		//change bv to av,the parameter passed in is address at the beginning of the string
{
	uint64 r = 0;
	for (int i = 0; i < 6; i++)
	{
		char c = *(read + s[i]);
		unsigned int p;
		p = search(c);
		r += p * pow(58, i);
	}
	return ((r - _add) ^ _xor);
}

void avTObv(uint64 read)		//change bv to av,the parameter passed in is av number(no "av"!)
{
	read = (read ^ _xor) + _add;
	for (int i = 0; i < 6; i++)
	{
		BV[s[i]] = table[((uint64)(read / pow(58, i))) % 58];
	}
}

