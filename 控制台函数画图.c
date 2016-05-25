#include<iostream>
#include<stdio.h>
int main()
{
	double a, b, c, x = 0, y = 0;
	char ch;
	while (1)
	{
		printf("请输入一元二次函数的系数（以空格隔开）：");
		scanf("%lf%lf%lf", &a, &b, &c);
		printf("你输入的函数为y=%gx^2%+gx%+g\n图像如下\n", a, b, c);
		do            //外层循环控制Y坐标的象限
		{
			if (y == 40)
			{
				printf("|---------|---------|---------|---------|---------|---------|---------|---------");
			}          //控制很坐标的输出
			else
			do                    //内层循环控制点的输入输出及X的象限
			{
				if (x == 40 && (int)y % 10 == 0)
					printf("-");      //控制纵坐标的刻度
				else if (x == 40 && (int)y % 10 != 0)
					printf("|");      //控制纵坐标的刻度线
				else if ((4 - y / 10) + 0.08 >= a*(x / 10 - 4)*(x / 10 - 4) + b*(x / 10 - 4) + c 
					 && (4 - y / 10) - 0.08 <= a*(x / 10 - 4)*(x / 10 - 4) + b*(x / 10 - 4) + c)      //4-y/10以及x/10-4将循环次数像坐标值的转换
					printf("|");      //当横纵坐标的值符合输入的函数，输出图像点
				else
					printf(" ");      //当没有坐标系和函数点时输出空格
				x++;
			} while (x < 80);
			y++;
			printf("");      //控制每行的换行
			x = 0;
		} while (y < 80);
		printf("还想画吗？（Y/N）:");
		getchar();
		scanf("%c", &ch);
		if (ch == 'N' || ch == 'n')
			break;
		x = 0;
		y = 0;
	} 
	system("pause");
	return 0;
}