#include "Test.h"
#include <iostream>
using namespace std;

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    int x, padre, izq, der;
    for(x = 0; x < min_heap.size(); x++)
        if(replaced_value == min_heap[x]) {
            min_heap[x] = replacement;
            break;
    }
    if(x % 2 == 0)
        padre = (x - 2) / 2;
    else
        padre = (x -1 ) / 2;
    izq = 1 + 2*x ;
    der = x*2;

    if(min_heap[padre] > min_heap[x] ){
        while(padre >= 0 && min_heap[x] < min_heap[padre] )
        {
            int h = min_heap[x];
            min_heap[x] = min_heap[padre];
            min_heap[padre] = h;
            x = padre;
            if(x % 2 == 0)
                padre = (x - 2) / 2;
            else
                padre = (x -1 ) / 2;
        }
    }
    else if(min_heap[x] > min_heap[izq] || min_heap[x] > min_heap[der])
    {
        while(der+1 < min_heap.size() && (min_heap[x] > min_heap[der]  || min_heap[x] > min_heap[izq]) )
        {
            int smallest = min_heap[der] > min_heap[izq] ? izq : der;
            int child = min_heap[smallest];
            min_heap[smallest] = min_heap[x];
            min_heap[x] = child;
            x = smallest;
            der = x*2;
            izq = 1 + 2*x ;
        }
    }
    return min_heap;
}

int main ()
{
    test();
    return 0;
}
