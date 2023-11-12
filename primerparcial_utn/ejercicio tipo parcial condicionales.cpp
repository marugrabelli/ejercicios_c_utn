
#include <iostream>

using namespace std;

int main()
{
    int i =10;
    do {
        if(( !(i%2)&& i <20)  || (i >20 && ( i%3))) {
            cout <<i<<"";
            i++;
        }
    }

    while (i <=30);

    return 0;
}
