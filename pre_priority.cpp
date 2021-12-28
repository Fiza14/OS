#include<iostream>
#include<stdlib.h>
using namespace std;

void input()//without arrival time
{
    int n=0, at[10],bt[10],wt[10],ta[10],sumbt=0,smallest,count=0,temp[10],p[10];
    double sumw=0,sumt=0,endtime=0;
    float avg_wt,avg_tt;
    cout<<"Enter the number of processes:";
    cin>>n;

    //arrival time
    cout<<"Enter the arrival time for "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>at[i];
    }
    //burst time
    cout<<"Enter the burst time for "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
        temp[i]=bt[i];
    }
    cout<<"Enter the priority  for "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
   
    for(int i=0;i<n;i++)
    {
        cout<<temp[i];
    }
    //at is sorted so 1st will start
    p[9]=999;
    cout<<"\n\nprocess \t Burst time \t priority \t wait time \t Turn around time"<<endl;
    for(int i=0;i<n;i++)
    for(int time=0;count!=n;time++)
    {
        smallest=9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && p[i]<p[smallest] && bt[i]>0)
            {
                smallest=i;
            }
           
        }
        bt[smallest]--;
        if(bt[smallest]==0)
        {
            count++;
            endtime=time+1;
            cout<<"P"<<smallest+1<<" \t\t"<<bt[smallest]<<"\t\t"<<p[smallest]<<"\t\t"<<endtime-at[smallest]-temp[smallest]<<"\t\t\t"<<endtime-at[smallest]<<endl;
            sumw=sumw+endtime-at[smallest]-temp[smallest];
            sumt=sumt+endtime-at[smallest];
        }
        // cout<<"hii"<<endl;
    }
    
    avg_wt=sumw/n;
    avg_tt=sumt/n;
    cout<<"\nAverage Waiting time: "<<avg_wt<<endl;
    cout<<"\nAverage Turnaround time: "<<avg_tt<<endl;
}


int main()
{

input();

return 0;
}
