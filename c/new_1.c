#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 7
void day_calender()
{
	int f=5,n=31,i,j=1,a=1;
	printf("=========================\n");
	printf(" sun mon tue wed thu fri sat\n");
	while(a<=4*f)
	{
		printf(" ");
		a++;
	}
	for(i=1;i<N;i++)
	{
		printf("%4d",i);
		if(i==7*j-f)
		{
			printf("\n");
			j++;
		}
	}
	printf("  *%d*",N);
	if(i==7*j-f)
		{
			printf("\n");
			j=j+1;
		}
	for(i=N+1;i<n;i++)
	{
		printf("%4d",i);
		if(i==7*j-f)
		{
			printf("\n");
			j++;
		}
	}
	printf("\n");
}
int judge(int month,int year)//判断一个月有多少天
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		return 31;
    else  if(month==4||month==6||month==9||month==11)
		return 30;
	else if(month==2&&((year%4==0&&year%100!=0)||year%400==0))
		return 29;
	else return 28;
}
void month_calender()
{
	int a=1,i,j,d=0,f,n,m,y,k,b=1;
	printf("please int the year and month:\n");
	scanf("%d %d",&y,&m);
	for(i=1;i<m;i++)
	{
		j=judge(i,y);
		d=d+j;
	}//判断某月第一天是该年第多少天
	f=(y+(y-1)/4-(y-1)/100+(y-1)/400+d)%7;//判断某月第一天是星期几
	n=judge(m,y);//判断某月有多少天
	printf("%d年%d月\n",y,m);
    printf("======================================\n");
    printf(" sun mon tue wed thu fri sat\n");
	if(f==0)
	{
		for(k=1;k<=n;k++)
		{ 
			printf("%4d",k);
			if(k%7==0)
				printf("\n");
		}
	}
	if(f!=0)
    {
		while(a<=4*f)
		{
		printf(" ");
		a++;
		}
	for(k=1;k<=n;k++)
	{
		printf("%4d",k);
		if(k==7*b-f)
		{
			printf("\n");
			b++;
		}
	}
	}
	printf("\n");
}
void year_calender()
{
	int a,m,n,i,j,k,year;
	char**p;
	char*week[]={"sun","mon","tue","wed","thu","fri","sat"};
	char*month[]={"january","february","march","april","may","june","july","august","setember","october","noveber","december"};
	printf("please int the year(2000--3000):\n");
	scanf("%d",&year);
	printf("\n");
	a=(year+(year-1)/4-(year-1)/100+(year-1)/400)%7;
	for(m=0;m<12;m++)
	{
		n=judge(m+1,year);
		  p=month+m;
		  printf("%s\n",*p);
          printf("=======================================");
		   printf("\n");
          for(i=0;i<7;i++)
		  {
			  p=week+i;
			  printf("%6s",*p);
		  }
		  printf("\n");
		  for(k=0;k<a;k++)
			  printf("      ");//六个空格
          for(j=1;j<32;j++)
		  {
			  printf("%6d",j);
			  if((a+j)%7==0)
				  printf("\n");
			  if(j==n)break;
		  }
		  a=(a+j)%7;//计算下个月第一天是星期几
		  printf("\n");
		   printf("=======================================");
		   printf("\n");
	}
}
int main()
{   
	int i; 
	int x;
	char s1[10]={"ycy"},s2[10]={"111"},s3[10],s4[10]; 
	for(i=1;i<=3;i++)
	{
            printf("请输入账号\n");
            gets(s3);
            printf("请输入密码\n");
			gets(s4);
            system("cls");
            if(strcmp(s1,s3)!=0||strcmp(s2,s4)!=0)
				printf("账号或密码错误请重新输入\n");
			else break;
	}
            system("cls");
			if(i==4)
			printf("你已输错三次密码\a\n");
			if(i<=3)
			{
              
	           printf("======欢迎使用万年历系统======\n");
	           while(1)
			   {
	             	printf("1返回菜单 2退出程序 3年历 4月历 5当前月份信息\n");
	                scanf("%d",&x);
	                printf("\n");
	               	if(x==2)
		          	break;
                    system("cls");
	              	switch(x)
					{
	                	case 1: break;
                        case 3: year_calender();break;
	                  	case 4:month_calender();break;
                        case 5:   day_calender();break;
		                default: printf("errow\n");
			            break;
					}
			   }
			}
            
	return 0;
}

