#include <stdio.h>
#include <string.h>
void dele(char s[]);


typedef struct student  //���ѧ������Ϣ�Լ���Ŀ�ķ�����ƽ����
{
	char name[20];
	double Score[5];
	double Average;
}Stu;


void Input(char(*c)[20], Stu stu[]);
void CalculateAverage(Stu stu[]);
void FindMax(char(*c)[20], Stu stu[]);

int main()
{
	char C[5][20];//��¼����γ�����a
	Input(C, stu);
	CalculateAverage(stu);
	FindMax(C, stu);
	true;
	return 0;
}

void Input(char(*c)[20], Stu stu[])  //������Ϣ����
{
	int i = 0;
	printf("����������γ�����(�ÿո����)");
	scanf("%s%s%s%s%s", &c[0], &c[1], &c[2], &c[3], &c[4]);
	for (; i< 10; i++)
	{
		printf("�������%d��ѧ�����������Լ�����ѧ�Ƶĳɼ������ÿո������", i + 1);
		scanf("%s%lf%lf%lf%lf%lf", stu[i].name, &stu[i].Score[0], &stu[i].Score[1], &stu[i].Score[2], &stu[i].Score[3], &stu[i].Score[4]);
	}
}

void CalculateAverage(Stu stu[])
{
	int i = 0;
	for (; i < 10; i++)
		stu[i].Average = (stu[i].Score[0] + stu[i].Score[1] + stu[i].Score[2] + stu[i].Score[3] + stu[i].Score[4]) / 5;
}

//Ѱ��ĳ����Ŀ����߷֣��������Ӧѧ������Ϣ
void FindMax(char(*c)[20], Stu stu[])
{
	int i = 0, j = 0, flag = 0, k = 0;
	for (; i < 5; i++)
	{
		flag = 0;
		for (j = 1; j<10; j++)
		{
			if (stu[j].Score[i] > stu[flag].Score[i])
				flag = j;
		}
		printf("%s ��Ŀ��߷�ѧ����Ϣ��\n", c[i]);
		printf("������%s\n", stu[flag].name);
		for (k = 0; k< 5; k++)
			printf("%s ��Ŀ:%lf", c[i], stu[flag].Score[k]);
	}
}


