/*
Carol 2014-12-01
*/
#include "header.h"
bool state[1000] = { 0 };//用于标记接收文件状态
Coord rStand[4];//标准路由的坐标
double stand[1000] = { 0 };
const double AF[2][3] = { { 1, -1, 2 }, { 1, 2, -1 } };
const double AH = 60.0;
using namespace std;

void Calcu(unsigned int tote)//计算位置坐标
{
	unsigned int i = 0;
	unsigned int si = 0;
	double RSSI[4] = { 0 };
	double Distance[4];
	char* fgdata = new char[7];
	FILE* fp = NULL;
	fopen_s(&fp, "Data.txt", "r");
	for (si; si < 1000; si++)
	{
		fseek(fp, 3, SEEK_CUR);
		if (((si % 9) == 0) && (si != 0))
		{
			fseek(fp, 2, SEEK_CUR);
			//cout<<"go\n";
		}
		fread(fgdata, 7, 1, fp);

		double stz = (fgdata[0] - '0') * 10 + (fgdata[1] - '0');
		stand[si] = stz + (fgdata[3] - '0') / 10.0 + (fgdata[4] - '0') / 100.0 +
			(fgdata[5] - '0') / 1000.0 + (fgdata[6] - '0') / 10000.0;
		//cout << stand[si];
	}
	fclose(fp);
	
	delete[] fgdata;
	for (i;; i++)
	{
		if (state[i])
		{
			char fgetNo[5];
			cout << "get rSSI" << endl;
			GetRSSI(i, RSSI, fgetNo);//得到RSSI值
			
			state[i] = 0;
			
			GetDistance(Distance, RSSI, fgetNo);//将RSSI转换成距离
			Coord get;
			get = CalPoint(Distance, fgetNo);
			cout << "NO:" << i<<endl;
			cout << "X:" << get.x << endl << "Y:" << get.y << " " << endl;
		}
		if (i == tote)
			i = 0;
	}
}

void GetRSSI(unsigned int i, double* RSSI, char* fgetNo){
	char fdata[8];
	char fdname[5];
	unsigned int itemp = i;//得到对应的记录文件
	fdname[0] = itemp % 10 + '0'; itemp /= 10;
	fdname[1] = itemp % 10 + '0'; itemp /= 10;
	fdname[2] = itemp % 10 + '0'; itemp /= 10;
	fdname[3] = itemp % 10 + '0'; 
	fdname[4] = '\0';
	FILE* dfp = NULL;
	cout << "fileName is " <<fdname << endl;
	
	bool fRState[4] = { 0 };
	unsigned char fni = 0;
	if (fopen_s(&dfp, fdname, "r"))
		cout << "Open is ok";
	for (char dj = 0; dj<4; dj++){//得到对应的RSSI值
		fread(fdata, sizeof(char), 7, dfp);
		int RouNo = (fdata[0] - '0') + (fdata[1] - '0') * 10 + (fdata[2] - '0') * 100 + (fdata[3] - '0') * 1000;
		RSSI[RouNo] = fdata[5];
		if (!fRState[RouNo])
		{
			fni++;
			fgetNo[fni] = RouNo;
			fRState[RouNo] = 1;
		}

	}
	fclose(dfp);
	fopen_s(&dfp, fdname, "w+");
	//cout << "清空" << endl;
	fclose(dfp);
	fgetNo[0] = fni;
}

void GetDistance(double* Distance, double* RSSI, char* fgetNo){//RSSI转换成距离
	for (char i = 1; i<=fgetNo[0]; i++){
		Distance[fgetNo[i]] = RSSIToD(RSSI[fgetNo[i]]);
	}
}
double RSSIToD(double RSSI){//将RSSI转换成distance
	double fRssi = (RSSI*-1);
	double fD = fRssi - stand[0];
	unsigned int i = 0;
	for (; i<1000; i++){
		double sd = fRssi - stand[i];
		if (sd>fD)
			break;
		fD = sd;
	}
	return (i - 1) / 100.0;
}

Coord CalPoint(double* distance, char* fgetNo){//计算出点的坐标
	Coord Get;
	if (fgetNo[0] == 4)
		Get = CalPoin4(distance);
	if (fgetNo[0] == 3)
		Get = CalPoin3(distance, fgetNo);
	if (fgetNo[0] == 2){
		Get.x = (rStand[fgetNo[1]].x + rStand[fgetNo[2]].x) / 2;
		Get.y = (rStand[fgetNo[1]].y + rStand[fgetNo[2]].y) / 2;
	}
	if (fgetNo[0] == 1){
		Get.x = rStand[fgetNo[1]].x;
		Get.y = rStand[fgetNo[1]].y;
	}
	return Get;
}

Coord CalPoin4(double* distance){
	double B[3];
	double x3 = rStand[3].x;
	double y3 = rStand[3].y;
	for (char i = 0; i<3; i++){
		B[i] = (distance[i] * distance[i]) - (rStand[i].x*rStand[i].x)
			- (rStand[i].y*rStand[i].y) + (x3*x3) + (y3*y3);
	}
	Coord Get;
	Get.x = AF[0][0] * B[0] + AF[0][1] * B[1] + AF[0][2] * B[2];
	Get.y = AF[1][0] * B[0] + AF[1][1] * B[1] + AF[1][2] * B[2];
	Get.x = Get.x / AH;
	Get.y = Get.y / AH;
	return Get;
}

Coord CalPoin3(double* distance, char* fgetNo){
	double A3[2][2] = { { (rStand[fgetNo[1]].x - rStand[fgetNo[3]].x), (rStand[fgetNo[1]].y - rStand[fgetNo[3]].y) },
	{ (rStand[fgetNo[2]].x - rStand[fgetNo[3]].x), (rStand[fgetNo[2]].y - rStand[fgetNo[3]].y) } };
	double A3Mod = A3[0][0] * A3[1][1] - A3[0][1] * A3[1][0];
	double temp = A3[0][0];
	A3[0][0] = A3[1][1];
	A3[0][1] = -A3[0][1];
	A3[1][0] = -A3[1][0];
	double b1 = pow(distance[fgetNo[1]], 2) - pow(distance[fgetNo[3]], 2) - pow(rStand[fgetNo[1]].x, 2) - pow(rStand[fgetNo[1]].y, 2) + pow(rStand[fgetNo[3]].x, 2) + pow(rStand[fgetNo[3]].y, 2);
	double b2 = pow(distance[fgetNo[2]], 2) - pow(distance[fgetNo[3]], 2) - pow(rStand[fgetNo[2]].x, 2) - pow(rStand[fgetNo[2]].y, 2) + pow(rStand[fgetNo[3]].x, 2) + pow(rStand[fgetNo[3]].y, 2);
	Coord get;
	get.x = A3[0][0] * b1 + A3[0][1] * b2;
	get.x = get.x / (2 * A3Mod);
	get.y = A3[1][0] * b1 + A3[1][1] * b2;
	get.y = get.y / (2 * A3Mod);
	return get;
}

/*

DWORD WINAPI Comm::MyThread2(LPVOID pParam)
{
	while (hComm != INVALID_HANDLE_VALUE)              // 串口已被成功打开
	{
		unsigned char d;
		d = _getch();
		printf("%c", d);
		//system("pause");
		WriteChar(&d, 1);
	}
	return 0;
} */

DWORD WINAPI MyThread1(LPVOID pParam)
{
	Comm* Com = (Comm*)pParam;
	Com->ReceiveChar();
	return 0;
}

void main(int argv, char *argc[])
{
	
	rStand[0].x = 0;
	rStand[0].y = 0;
	rStand[1].x = 0;
	rStand[1].y =10;
	rStand[2].x = 10;
	rStand[2].y = 0;
	rStand[3].x = 10;
	rStand[3].y = 10;
	/*std::cout << argv;
	int i = 0;
	while (i < argv)
	{
	std::cout << argc[i] << std::endl;
	i++;
	}*/

	Comm Communica(_T("com3"),state);
	
	HANDLE hThread1 = CreateThread(NULL, 0, MyThread1, &Communica, 0, NULL);  //读线程
	//HANDLE hThread2 = CreateThread(NULL, 0, MyThread2, 0, 0, NULL);  //写线程
	//state[1] = true;
	Calcu(4);
	CloseHandle(hThread1); 
	//CloseHandle(hThread2);

	Sleep(100000000);
	
	system("pause");
}