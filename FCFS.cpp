#include<iostream>
using namespace std;

int main()
{

    int arr[100],no,wt=0,tat=0,avg1=0,avg2=0;
    char name[100];
    cout<<"Enter the number of the process :";
    cin>>no;

    for(int i=0;i<no;i++)
    {

        cout<<"\nEnter the Name of the Process "<<i+1<<" :";
        cin>>name[i];
        cout<<"\nEnter the Burst Time for the Process :";
        cin>>arr[i];

    }

    cout<<"\nProcess\tBT\tWT\tAT\n";
    for(int i=0;i<no;i++)
    {
        int curr = wt+arr[i];
        cout<<name[i]<<"\t"<<arr[i]<<"\t"<<wt<<"\t"<<curr;
        wt=wt+arr[i];
        cout<<endl;
    }



}
