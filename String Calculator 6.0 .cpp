#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
using namespace std;

long double caldnm(string &ch);
long double calpnm(string &ch);
double ctn(char);
long double stn(string &ch);

int main()
{
system("cls");

int x=0,y=0,z=0,no_of_terms,no_of_operators;
long double number[1000],res;
char operators[10000],number_character[1000][1000];
string ch,number_string[1000];

//cout<<"Enter the password : ";
//getline(cin,ch);

cout<<"Enter the mathematical operation : ";
getline(cin,ch);

for(x=0,y=0,z=0;ch[x]!='\0';++x,++z)
{
if(ch[x-1]=='+'||ch[x-1]=='-')
    z=0;
if(ch[x]!='+'||ch[x]!='-')
{
    number_character[y][z]=ch[x];
}
if(ch[x]=='+'||ch[x]=='-')
{
    operators[y]=ch[x];
    number_character[y][z]='\0';
    ++y;
}
}
number_character[y][z]='\0';

no_of_terms=y+1;
no_of_operators=y;

for(z=0;z<no_of_terms;++z)
{
    number_string[z]=number_character[z];
    number[z]=caldnm(number_string[z]);
}
for(z=0;z<no_of_terms;++z)
//cout<<endl<<z<<" = "<<number[z];
res=number[0];
for(int j=0;j<no_of_operators;++j)
{
    if(operators[j]=='+')
    {
        res=res+number[j+1];
    }
    else if(operators[j]=='-')
    {
        res=res-number[j+1];
    }
}

cout.setf(ios::right);
cout.setf(ios::showpoint);
cout.setf(ios::fixed);
cout<<"\n\n\nThe result of the function is : "<<res;
cout<<"\n\n\nThe entered string is : " ;
cout<<ch;

getch();
return 0;
}

long double caldnm(string &ch)
{
int x=0,y=0,z=0,no_of_terms,no_of_operators;
long double number[100],res;
char operators[100],number_character[100][100];
string number_string[100];

for(x=0,y=0,z=0;ch[x]!='\0';++x,++z)
{
if(ch[x-1]=='*'||ch[x-1]=='/')
    z=0;
if(ch[x]!='*'&&ch[x]!='/')
{
    number_character[y][z]=ch[x];
}
if(ch[x]=='*'||ch[x]=='/')
{
    operators[y]=ch[x];
    number_character[y][z]='\0';
    ++y;
}
}
number_character[y][z]='\0';

no_of_terms=y+1;
no_of_operators=y;

for(z=0;z<no_of_terms;++z)
{
    number_string[z]=number_character[z];
    number[z]=calpnm(number_string[z]);
}

res=number[0];
for(int j=0;j<no_of_operators;++j)
{
    if(operators[j]=='*')
    {
        res=res*number[j+1];
    }
    else if(operators[j]=='/')
    {
        res=res/number[j+1];
    }
}
return res;
}
long double calpnm(string &ch)
{
int x=0,y=0,z=0,no_of_terms,no_of_operators;
long double number[100],res;
char operators[100],number_character[100][100];
string number_string[100];

for(x=0,y=0,z=0;ch[x]!='\0';++x,++z)
{
if(ch[x-1]=='^'||ch[x-1]=='%')
    z=0;
if(ch[x]!='^'||ch[x]!='%')
{
    number_character[y][z]=ch[x];
}
if(ch[x]=='^'||ch[x]=='%')
{
    operators[y]=ch[x];
    number_character[y][z]='\0';
    ++y;
}
}
number_character[y][z]='\0';

no_of_terms=y+1;
no_of_operators=y;

for(z=0;z<no_of_terms;++z)
{
    number_string[z]=number_character[z];
    number[z]=stn(number_string[z]);
}

res=number[0];
for(int j=0;j<no_of_operators;++j)
{
    if(operators[j]=='^')
    {
        res=pow(res,number[j+1]);
    }
    else if(operators[j]=='%')
    {
        res=fmod(res,number[j+1]);
    }
}

return res;
}
double ctn(char ch1)
{
    double x;

    if(ch1==48)
    {
        x=0;
    }
    else if(ch1==49)
    {
        x=1;
    }
    else if(ch1==50)
    {
        x=2;
    }
    else if(ch1==51)
    {
        x=3;
    }
    else if(ch1==52)
    {
        x=4;
    }
    else if(ch1==53)
    {
        x=5;
    }
    else if(ch1==54)
    {
        x=6;
    }
    else if(ch1==55)
    {
        x=7;
    }
    else if(ch1==56)
    {
        x=8;
    }
    else if(ch1==57)
    {
        x=9;
    }
    return x;
}
long double stn(string &str)
{
int flag=0,temp=0;
long double num=0;

for(int i=0;str[i]!='\0';++i)
{
    if(str[i]=='.')
    {
        flag=1;
        continue;
    }

    if(flag==0)
    {
        if(str[i]>='0'&&str[i]<='9')
            num=num*10+ctn(str[i]);
    }
    if(flag==1)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            --temp;
            num=num+ctn(str[i])*pow(10,temp);
        }
    }
}

return num;
}
