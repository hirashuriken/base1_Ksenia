#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "baza.h";
#include <cstring>
using namespace std;


Mountain::Mountain(string sname,string slocation,int shigh):
    name(sname),location(slocation),high(shigh){}

string Mountain::getName()
{
    return name;
}

string Mountain::getLocation()
{
    return location;
}

int Mountain::getHigh()
{
    return high;
}


void Mountain::setName(string strname)
{
    name=strname;
}

void Mountain::setLocation(string strlocation)
{
    location=strlocation;
}

void Mountain::setHigh(int strhigh)
{
    high=strhigh;
}

std::ostream &operator<<(std::ostream &out,const Mountain &org)
{
    out.width(4);
    out<<org.name<<"\t\t"<<org.location<<"\t\t"<<org.high<<endl;
    out<<"________________________________________________";
    return out;
}

int cmp_name (Mountain a, Mountain b)
{
    return a.getName()<b.getName()?-1:(a.getName()>b.getName()?1:0);
}

int cmp_location ( Mountain a, Mountain b)
{
    return a.getLocation()<b.getLocation()?-1:(a.getLocation()>b.getLocation()?1:0);
}

int cmp_high (Mountain a, Mountain b)
{
    if (a.getHigh()<b.getHigh()) return -1;
    else
        if (a.getHigh()==b.getHigh()) return 0;
    else
        if (a.getHigh()>b.getHigh()) return 1;
}

int comparison(Mountain m1, Mountain m2,int column,int order,Ptf cmp){

    int res;

    switch(column){
    case 1:
    {
        res = cmp_name(m1, m2);
    } break;

    case 2:
    {
        res = cmp_location(m1, m2);
    } break;

    case 3:
    {
        res = cmp_high(m1, m2);
    } break;

    //if(order) res *= -1;

    }
    return res;
}

void qStrSort(Mountain *A, int low, int high, int column, int order,Ptf cmp)
{
    int i = low;
    int j = high;
    Mountain x = A[(low+high)/2];

    do {
        while(comparison(A[i],x,column,order,cmp) < 0){ ++i;}
        while(comparison(A[j],x,column,order,cmp) > 0) {--j;}

        if(i <= j)
        {
            Mountain temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++; j--;
        }
    } while(i < j);

    if(low < j) qStrSort(A, low, j,column, order,cmp);
    if(i < high) qStrSort(A, i, high,column,order,cmp);
}

Mountain &Mountain::operator=(const Mountain &org)
{
    name=org.name;
    location=org.location;
    high=org.high;
    return *this;
}

void readfile(Mountain *array, int N)
{
    string name,location, str, str2,str3;
    int high;

    fstream inBaseFile;
    inBaseFile.open("moun.txt", ios::in);

    if(!inBaseFile)
    {
        cerr<<"ERROR"<<endl;
        exit(1);
    }

    inBaseFile>>N;

    for(int i=0; i<N && !inBaseFile.eof(); ++i)
    {
        inBaseFile>>name;
        cout<<name<<"\t\t";
        array[i].setName(name);

        inBaseFile>>location;
        cout<<location<<"\t\t\t";
        array[i].setLocation(location);

        inBaseFile>>high;
        cout<<high<<endl;
        array[i].setHigh(high);

        //cout<<str<<"\t\t"<<str2<<"\t\t"<<str3<<endl;
        //cout<<endl<<endl;
        }
        inBaseFile.close();
}
