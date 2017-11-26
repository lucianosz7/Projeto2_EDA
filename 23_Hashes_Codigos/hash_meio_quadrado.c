#include <math.h>

unsigned long hash_meio_quadrado(int K)
{
	unsigned long s = K*K;
	
	return (s & 0x00FFFF00) >> 8;
}
