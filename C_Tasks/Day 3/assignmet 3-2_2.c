#include <stdio.h>

float CAL_add(float x, float y)
{
	return x + y;
}
float CAL_subtract (float x, float y)
{
	return x - y;
}
float CAL_multiply(float x, float y)
{
	return x * y;
}
float CAL_divide (float x, float y)
{
	return x / y;
}
int CAL_and (int x, int y)
{
	return x & y;
}
int CAL_or  (int x, int y)
{
	return x | y;
}
int CAL_not (int x)
{
	return ~x;
}
int CAL_xor (int x, int y)
{
	return x ^ y;
}
int CAL_rem (int x, int y)
{
	return x % y;
}
int CAL_inc (int x)
{
	return ++x;
}
int CAL_dec (int x)
{
	return --x;
}