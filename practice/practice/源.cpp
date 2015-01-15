#include <stdio.h>
#include <string.h>
void dele(char s[]);


typedef struct student  //存放学生的信息以及科目的分数和平均分
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
	char C[5][20];//记录五个课程名；a
	Input(C, stu);
	CalculateAverage(stu);
	FindMax(C, stu);
	true;
	return 0;
}

void Input(char(*c)[20], Stu stu[])  //输入信息函数
{
	int i = 0;
	printf("请输入五个课程名：(用空格隔开)");
	scanf("%s%s%s%s%s", &c[0], &c[1], &c[2], &c[3], &c[4]);
	for (; i< 10; i++)
	{
		printf("请输入第%d名学生的姓名，以及五门学科的成绩：（用空格隔开）", i + 1);
		scanf("%s%lf%lf%lf%lf%lf", stu[i].name, &stu[i].Score[0], &stu[i].Score[1], &stu[i].Score[2], &stu[i].Score[3], &stu[i].Score[4]);
	}
}

void CalculateAverage(Stu stu[])
{
	int i = 0;
	for (; i < 10; i++)
		stu[i].Average = (stu[i].Score[0] + stu[i].Score[1] + stu[i].Score[2] + stu[i].Score[3] + stu[i].Score[4]) / 5;
}

//寻找某个科目的最高分，并输出对应学生的信息
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
		printf("%s 科目最高分学生信息：\n", c[i]);
		printf("姓名：%s\n", stu[flag].name);
		for (k = 0; k< 5; k++)
			printf("%s 科目:%lf", c[i], stu[flag].Score[k]);
	}
}


