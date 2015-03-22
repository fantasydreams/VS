#include "Point.h"
#include <iostream>
void Point::Point_set(double x, double y)
{
	this->x = x;
	this->y = y;
}


void Point::Dis_Point()
{
	std::cout << "x:" << x << std::endl
		<< "y:" << y << std::endl;
}