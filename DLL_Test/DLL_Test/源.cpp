#include "Point.h"
#include <cstdlib>
#define DLL_API __declspec(dllimport)
#pragma comment(lib,"DLL.dll")

int main()
{
	Point a;
	a.Point_set(1, 2);
	a.Dis_Point();
	system("pause");
	return 0;
}