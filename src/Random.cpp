#include "../include/Random.h"
#include <stdlib.h>
#include <time.h>

int random_int_between(int a, int b)
{
	return rand() % b + a;
}
