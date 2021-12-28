#include<iostream>

using namespace std;

int main()
{
    int bt[10],pt[10],wt[10],wt1=0,ta[10],ta1;
    char arr4[100];
    int a,b,c;

    cout<<"Enter the No of Processes :";
    cin>>a;

    for(int i=0;i<a;i++)
    {
        cout<<"\nEnter the Name of the Process :";
        cin>>arr4[i];
        cout<<"Enter the Burst Time :";
        cin>>bt[i];
        cout<<"Enter the Priority of the Process ";
        cin>>pt[i];
    }

    cout<<"\nName\tB.T\tPriority\t";
    for(int i=0;i<a;i++)
    {
        cout<<endl<<arr4[i]<<"\t"<<bt[i]<<"\t"<<pt[i];
    }
    for(int i=1;i<a;i++)
    {
        int j=i-1;
        int c=pt[i];
        int d=bt[i];
        char e=arr4[i];
        while(j>=0 && pt[j]>c)
        {
            bt[j+1]=bt[j];
            pt[j+1]=pt[j];
            arr4[j+1]=arr4[j];
            j--;
        }
          bt[j+1]=d;
            pt[j+1]=c;
            arr4[j+1]=e;
    }
     cout<<"\n\nName\tB.T\tPriority\t";
    for(int i=0;i<a;i++)
    {
        cout<<endl<<arr4[i]<<"\t"<<bt[i]<<"\t"<<pt[i];
    }
    int i=0;
    while(i<a)
    {
        if(i==0){
            wt[i]=0;
            ta[i]=bt[i];
        }
        else
        {
            wt[i]=ta[i-1];
            ta[i]=wt[i]+bt[i];
        }
        i++;
    }
     cout<<"\n\nName\tB.T\tPriority\tW.T\tT.A";
    for(int i=0;i<a;i++)
    {
        cout<<endl<<arr4[i]<<"\t"<<bt[i]<<"\t"<<pt[i]<<"\t\t"<<wt[i]<<"\t"<<ta[i];
    }



}
