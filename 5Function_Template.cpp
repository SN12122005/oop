#include<iostream>
using namespace std;


template<typename T>
void show(T arr[], int size)
{
    int i;
    cout<<"Elements of the array:\n"<<endl;
    for(i=0; i<size;i++)
    {
        cout<<" "<<arr[i];
        
        
    }
}
template<typename T>
void sort(T arr[],int size)
{
    int i,j,k;
    T l;
    for(i=0;i<size-1;i++)
    {
        k=i;
        for(j=i+1; j<size;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        l=arr[i];
        arr[i]=arr[k];
        arr[k]=l;
    }
}
int main()
{
    int arr1[]={5,3,6,4,7,2,1};
    float arr2[]={3.4,3.2,4.6,1.2,2.4};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    
    sort(arr1,n);
    sort(arr2,m);
    
    show(arr1,n);
    show(arr2,m);
    
    
    return 0;
}
