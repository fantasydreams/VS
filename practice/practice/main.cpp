#include <iostream>
using namespace std;
#include <string.h>
class data
{
public:
	data(int nyear = 2015, int nmouth = 4, int nday = 6)
	{
		year = nyear;
		mouth = nmouth;
		day = nday;
	};
	data(data &d)
	{
		year = d.year;
		mouth = d.mouth;
		day = d.day;
	}
	void setdata()
	{
		cin >> year;
		cin >> mouth;
		cin >> day;

	}
	void showdata()
	{
		cout << year << ",";
		cout << mouth << ",";
		cout << day << endl;
	}

	~data(){}

private:
	int year;
	int mouth;
	int day;
};
class People
{
public:
	People(int Nnum, char Nsex, int y,int m,int d, long int Nid);
	/*{
	num =Nnum;
	sex =Nsex;
	birthday=Nbirthday;
	id=Nid;
	}*/
	People(People &p)
	{
		num = p.num;
		sex = p.sex;
		birthday = p.birthday;
		id = p.id;
	}
	~People(){}
	void setpeople()
	{
		cin >> num;
		cin >> sex;
		birthday.setdata();
		cin >> id;
		/*	num =newnum;
		sex =newsex;
		birthday=newbirthday;
		id=newid;*/
	}
	void showpeople()
	{
		cout << "编号：" << num << endl;
		cout << "性别" << sex << endl;
		cout << "出生日期";
		birthday.showdata();
		cout << "身份证：" << id << endl;
	}
private:
	int num;
	char sex;
	data birthday;
	long int id;
};
People::People(int Nnum, char Nsex, int y,int m,int d , long int Nid) :birthday(y,m,d)
{

	num = Nnum;
	sex = Nsex;
	id = Nid;
}
int main()
{
	//data Nb(1994,3,27);//这是后来加的再把下面那个位置改成Nb就对了，
	People p1(1, 'm', 1994, 3, 27/*后来改成Nb就好了*/, 211111111);//这里不能这样吗？
	p1.showpeople();
	cout << "set:";
	p1.setpeople();
	p1.showpeople();
	system("pause");
	return 0;
}
