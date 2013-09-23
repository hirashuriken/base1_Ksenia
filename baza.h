#ifndef BAZA_H_INCLUDED
#define BAZA_H_INCLUDED

#include <cstring>
using namespace std;
class Mountain
{
    public:
    Mountain (){};
        Mountain(string sname,string slocation,int shigh);
        ~Mountain(){};

        void setName(string strname);
        void setLocation(string strlocation);
        void setHigh (int high);

        string getName();
        string getLocation();
        int getHigh();
        friend std::ostream &operator<<(std::ostream &out,const Mountain &org);
        Mountain &operator=(const Mountain &org);


    private:
    int N;
        string *array;
        string name;
        string location;
        int high;
};

typedef int (*Ptf)(Mountain,Mountain);

int comparison(Mountain m1, Mountain m2,int column,int order,Ptf cmp);
void qStrSort(Mountain *A, int low, int high, int column, int order,Ptf cmp);

int cmp_name (Mountain a, Mountain b);
int cmp_location ( Mountain a, Mountain b);
int cmp_high (Mountain a, Mountain b);

void readfile(Mountain *array, int N);


#endif  //BAZA_H_INCLUDED
