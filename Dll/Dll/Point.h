#define DLL_API __declspec(dllexport)  
#define _Point

class Point
{
private:
	double x, y;
public:
	void Point_set(double, double);
	void Dis_Point();
};
