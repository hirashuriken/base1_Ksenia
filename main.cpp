#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>

#include "baza.h";

using namespace std;

int main()
{
    int N=11,m=1;

    int column;
    int order;

    Ptf cmp_ar[3]= {cmp_name,cmp_location,cmp_high};

    Mountain  *array = new Mountain[N];

    while(m)
    {

        cout<<"NAME"<<"\t\t"<<"LOCATION"<<"\t\t"<<"HIGH"<<endl<<endl;
        readfile(array,N*3);
        cout<<endl;
        cout<<"enter column:(1-3)";
        cin>>column;

        qStrSort(array,0,N-1,column,order,cmp_ar[column-1]);
        cout<<endl<<endl;
        system("clear");

        cout<<"NAME"<<"\t\t"<<"LOCATION"<<"\t"<<"HIGH"<<endl<<endl;
        for (int i=1; i<N; ++i)
        {
            cout<<array[i]<<endl;
        }
        system("pause");
        system("clear");
    }
    delete []array;
    return 0;
}
