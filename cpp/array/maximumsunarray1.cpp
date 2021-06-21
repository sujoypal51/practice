#include <iostream>
using namespace std;
void subArray(int a[], int n)
{
    int currentsum=0;
    int maxisum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            currentsum=0;
            for(int k=i;k<=j;k++){
                currentsum+=a[k];
            }
            if (currentsum>maxisum)
            {
                maxisum=currentsum;
            }
            }
        }
        cout<<"maximum sum is"<<maxisum<<endl;
    }
int main()
{
    int a[] = {34,56,-23,-56,2,190};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "All Non-empty Subarrays\n";
    subArray(a, n);
    return 0;
}