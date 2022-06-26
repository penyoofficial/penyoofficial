// Ver. 21.12.21
// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int arr[])
{
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len - 1; i++)
		for (int j = 0, temp; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void selection(int arr[])
{
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void insertion(int arr[])
{
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; i++)
	{
		int key = arr[i], j = i - 1;
		while ((j >= 0) && (arr[j] > key))
			arr[j-- + 1] = arr[j];
		arr[j + 1] = key;
	}
}
