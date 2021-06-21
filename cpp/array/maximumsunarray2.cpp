#include <iostream>
using namespace std;
int subArray(int a[], int n){
    int csum=a[0];
    int osum=a[0];
    for(int i=1;i<n;i++){
        if(csum>=0){
            csum+=a[i];
        }
        else
        {
            csum=a[i];
        }
        if (csum>osum)
        {
            osum=csum;
        }
    }
    return osum;
}
int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 19, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = subArray(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
}