// Ver. 22.1.27
// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <math.h>
#include <stdarg.h>

int ifeven(int a)
{
	return (!(a % 2)) ? 1 : 0;
}

int ifleapyear(int year)
{
	if (!(year % 400))
		return 1;
	else
	{
		if (!(year % 100))
			return 0;
		else
		{
			if (!(year % 4))
				return 1;
			else
				return 0;
		}
	}
}

int ifncst(int a)
{
	int b100, b10, b1;
	b100 = a / 100;
	b10 = (a - b100 * 100) / 10;
	b1 = a % 10;
	if (a == b100 * b100 * b100 + b10 * b10 * b10 + b1 * b1 * b1)
		return 1;
	else
		return 0;
}

int ifodd(int a)
{
	return (a % 2) ? 1 : 0;
}

int ifprime(int a)
{
	int i;
	for (i = 2; i < a; i++)
		if (!(a % i))
			return 0;
	if (a == i)
		return 1;
}

double whomax(int n, ...)
{
	va_list valist;
	va_start(valist, n);
	double max = va_arg(valist, double);
	for (int i = 0; i < n - 1; i++)
	{
		double temp = va_arg(valist, double);
		if (temp > max)
			max = temp;
	}
	va_end(valist);
	return max;
}

double whomin(int n, ...)
{
	va_list valist;
	va_start(valist, n);
	double min = va_arg(valist, double);
	for (int i = 0; i < n - 1; i++)
	{
		double temp = va_arg(valist, double);
		if (temp < min)
			min = temp;
	}
	va_end(valist);
	return min;
}

double absl(double a)
{
	return (a > 0) ? a : -a;
}

double bmi(double w, double h)
{
	return w / (h * h);
}

double heron(double a, double b, double c)
{
	double p = (a + b + c) * 0.5;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double p2pd(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double pi()
{
	return 4 * (4 * atan(1.0 / 5) - atan(1.0 / 239));
}

double tocels(double fahr)
{
	return 5 * (fahr - 32) / 9;
}

double tofahr(double cels)
{
	return 9 * cels / 5 + 32;
}

int ftrs(int n)
{
	int a = 1, b = 1, sum = 0;
	do
	{
		a = a * b++;
		sum = sum + a;
	} while (b <= n);
	return sum;
}

int gcd2(int a, int b)
{
	int i = a;
	if (a < b)
		i = b;
	if (!a && !b)
		return 0;
	else if (!a || !b)
		return a + b;
	else
		for (; i <= a || i <= b; i--)
			if (!(a % i) && !(b % i))
				return i;
}

int gcd(int n, ...)
{
	va_list valist;
	va_start(valist, n);
	int gcd = gcd2(va_arg(valist, int), va_arg(valist, int));
	for (int c = 0; c < n - 2; c++)
		gcd = gcd2(gcd, va_arg(valist, int));
	va_end(valist);
	return gcd;
}

int ivs(int a)
{
	int ion = 0, ifnega = 0;
	if (a < 0)
	{
		a = -a;
		ifnega = 1;
	}
	while (a > 0)
	{
		ion = ion * 10 + a % 10;
		a = a / 10;
	}
	if (ifnega)
		ion = -ion;
	return ion;
}

int lcm2(int a, int b)
{
	if (!a || !b)
		return 0;
	else
		for (int i = 1; i <= a * b; i++)
			if (!(i % a) && !(i % b))
				return i;
}

int lcm(int n, ...)
{
	va_list valist;
	va_start(valist, n);
	int lcm = lcm2(va_arg(valist, int), va_arg(valist, int));
	for (int c = 0; c < n - 2; c++)
		lcm = lcm2(lcm, va_arg(valist, int));
	va_end(valist);
	return lcm;
}

void layfbnc(int n)
{
	int a = 1, b = 1;
	while (n--)
	{
		if (!(n % 2))
		{
			printf("%d ", b);
			b = a + b;
		}
		else
		{
			printf("%d ", a);
			a = b + a;
		}
	}
}

void layftr(int n)
{
	int a = 1, b = 1;
	do
	{
		a = a * b++;
		printf("%d ", a);
	} while (b <= n);
}

void layncst(int lb, int ub)
{
	int b100, b10, b1;
	for (int num = lb; num <= ub; num++)
	{
		b100 = num / 100;
		b10 = (num - b100 * 100) / 10;
		b1 = num % 10;
		if (num == b100 * b100 * b100 + b10 * b10 * b10 + b1 * b1 * b1)
			printf("%d ", num);
	}
}

void layprime(int lb, int ub)
{
	for (int n = lb; n <= ub; n++)
	{
		int b = 1;
		for (int m = 2; m <= n - 1; m++)
			if (!(n % m))
				b = 0;
		if (b)
			printf("%d ", n);
	}
}
