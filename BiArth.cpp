/*
Binary Arithmetic Calculator - 16bit
Note: This code works only in Turbo C++ 3.0
*/


#include<iostream.h>
#include<conio.h>
#include<process.h>
const int l=100;
char a[l],b[l],o[l],len;
int qwer(char no[]);
void display(char var[], int a);
int dtrmine(char var[],int l);
int equate(char in[],int l,int zero);
int equateD(char in[],int l,int zero);
void main()
{       textmode(C4350);
	clrscr();
	int i,j,f,len1,len2,dec1,dec2;
	cout<<"1 ";
	f=qwer(a);
	len1=len;
	if(f==1)
	{       getch();
		exit(0);
	}
	display(a,len1);
	cout<<"\n\n2 ";
	f=qwer(b);
	len2=len;
	if(f==1)
	{       getch();
		exit(0);
	}
	display(b,len2);
	dec1=dtrmine(a,len1);
	cout<<"\n\n"<<dec1;
	dec2=dtrmine(b,len2);
	cout<<"\n\n"<<dec2;
	cout<<"\n\n";
	if(dec1>dec2)
		len2=equate(b,len2,dec1-dec2);
	else if(dec2>dec1)
		len1=equate(a,len1,dec2-dec1);
	int tmp1=len1-dec1;
	int tmp2=len2-dec2;
	if(tmp1>tmp2)
		len2=equateD(b,len2,tmp1-tmp2);
	else if(tmp2>tmp1)
		len1=equateD(a,len1,tmp2-tmp1);
	display(a,len1);
	display(b,len2);
	getch();

}
int qwer(char no[])
{       int i,f;
	f=0;
	for(i=0;i<l-1;i++)
	{	no[i]='\0';
	}
	for(i=0;i<l-1;i++)
	{       no[i]=getche();
		if(no[i]=='\r')
			break;
		if(no[i]=='\b')
		{	no[i]='\0';
			i-=1;
			continue;
		}
		//[i]-=48;
		if(no[i]!='0' && no[i]!='1' && no[i]!='.')
			f=1;
	}
	if(f==1)
	{	cout<<"\nIt is not a binary no";
	}
	no[i]='\0';
	len=i;
	return f;
}
void display(char var[], int a)
{	cout<<"\n\nNo  ";
	int i;
	for(i=0;i<a;i++)
	{	cout<<var[i];//<<'\n';
	}
}
int dtrmine(char var[],int l)
{       int out=-1;
	for(int i=0;i<l;i++)
		if(var[i]=='.')
			out=i;
	return out;
}
int equate(char in[],int l,int zero)
{       int size=l+zero+1;
	char tmp[::l];
	int i,out,j;
	for(i=0;i<size;i++)
		tmp[i]=in[i];
	for(i=0;i<zero;i++)
		in[i]='0';
	for(j=0;j<size;i++,j++)
		in[i]=tmp[j];
	if(zero!=0)
		out=i;
	else
		out=l;
	return out;
}
int equateD(char in[],int l,int zero)
{       int out=-1;
	for(int i=0;i<zero;i++)
		in[l+i]='0';
	cout<<"\n\n"<<zero<<"\n\n";
	if(zero!=0)
		out=i;
	else
		out=l;
	return out;
}
