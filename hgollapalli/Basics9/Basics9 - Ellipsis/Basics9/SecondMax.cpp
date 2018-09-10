#include <stdio.h>
#include<algorithm>
#include <cstdarg>
#include<vector>

// Add functions and includes as needed

#define UNUSED_VAR(v) ((void *)v)

int SecondMax(int count, ...)
{
	va_list args;
	va_start(args,count);
	std::vector<int> vec;
	int tmp = 0;

	// Do your magic here:
	for (int i = 0; i < count; i++)
	{
		 tmp=va_arg(args, int);
		 vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec[vec.size()-2];
}