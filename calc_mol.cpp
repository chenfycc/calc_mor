#include<stdio.h>
 
int t=1;
int j=0;
char *p;
int function(char *string);
int main()
{
	int a[t];
	char string[t][100];
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%s",&string[i]);
 		a[i]=function(string[i]);
	}
	for(int i=0;i<t;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;	
}
 
int function(char *string)
{
	p=string;
	int mol=0,sum=0;
	while(*p!='\0')
	{
		int d=0,count=0;
		switch(*p)
		{
			case 'C':{
				if(*(p+1)=='l'){
					mol=35;
					p++;
				}else if(*(p+1)=='a'){
					mol=40;
					p++;
				}else{
					mol=12;
				}
				break;
			}
			case 'N':{
				if(*(p+1)=='a'){
					mol=23;
					p++;
				}else{
					mol=14;
				}
				break;
			}
			case 'O':{
				mol=16;
				break;
			}
			case 'S':{
				mol=32;
				break;
			}
			case 'H':{
				mol=1;
				break;
			}
			case 'A':{
				mol=27;
				p++;
				break;
			}
			case 'Z':{
				mol=65;
				p++;
				break;
			}
			case '(':{
				mol=function(p+1);
				break;
			}
			case ')':{
				return sum;
			}
				
		}
		p++;
		while ('0' <=*p && *p <= '9')
		{
			d=d*10+(*p-'0');
			p++;
			count++;
		}
		if(count==0)
		{
			d=1;
		}
		sum=sum+(d*mol);
	}
	return (sum);
}
