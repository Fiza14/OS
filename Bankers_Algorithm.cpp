#include<iostream>

using namespace std;

int main()
{
    int t,A1[10],B1[10],C1[10],D1[10],A2[10],B2[10],C2[10],D2[10],A3[10],B3[10],C3[10],D3[10],A=0,B=0,C=0,D=0,a=0,b=0,c=0,d=0,s1=0,s2=0,s3=0,s4=0,count=0;
    char Name[10],state[10];

    cout<<"Enter the Number of Processes :";
    cin>>t;

    cout<<"\nEnter the Total Resource :";
        cout<<"\nA :";cin>>a;
        cout<<"B :";cin>>b;
        cout<<"C :";cin>>c;
        cout<<"D :";cin>>d;

    for(int i=0;i<t;i++)
    {
        cout<<"\nEnter the ProcessName :";
        cin>>Name[i];
        cout<<"\nEnter the Allocation :";               //Allocation value
        cout<<"\nA :";
        cin>>A1[i];
        cout<<"\nB :";
        cin>>B1[i];
        cout<<"\nC :";
        cin>>C1[i];
        cout<<"\nD :";
        cin>>D1[i];
        cout<<"\nEnter the Max Need :";                 //Max need value
        cout<<"\nA :";
        cin>>A2[i];
        cout<<"\nB :";
        cin>>B2[i];
        cout<<"\nC :";
        cin>>C2[i];
        cout<<"\nD :";
        cin>>D2[i];
        s1=s1+A1[i];                                    //Calculating total allocated resource
        s2=s2+B1[i];
        s3=s3+C1[i];
        s4=s4+D1[i];

        A3[i]=A2[i]-A1[i];                              //calculating need
        B3[i]=B2[i]-B1[i];
        C3[i]=C2[i]-C1[i];
        D3[i]=D2[i]-D1[i];

        state[i]='F';


    }
    A=a-s1;                                     //Remaining resource after the allocation
    B=b-s2;
    C=c-s3;
    D=d-s4;

    cout<<"\nProcess\tAllocation\tMax\t\tAvailable\tNeed";
    cout<<"\n\tA B C D\t\tA B C D\t\tA B C D\t\tA B C D\n";
    for(int i=0;i<t;i++)
    {
        cout<<Name[i]<<"\t"<<A1[i]<<" "<<B1[i]<<" "<<C1[i]<<" "<<D1[i]<<"\t\t"<<A2[i]<<" "<<B2[i]<<" "<<C2[i]<<" "<<D2[i]<<"\t\t"<<A<<" "<<B<<" "<<C<<" "<<D<<"\t\t"<<A3[i]<<" "<<B3[i]<<" "<<C3[i]<<" "<<D3[i];
        cout<<endl;
    }
    int i=0;
    while(count<=2)
    {
        if(A3[i]<=A && B3[i]<=B && C3[i]<=C && D3[i]<=D && state[i]=='F')  //if remaining is greater than need
        {
            A=A+A1[i];                                    //add allocated resource to remaining resource
            B=B+B1[i];
            C=C+C1[i];
            D=D+D1[i];
            state[i]='T';
        }
        else                                        //if remaining is less than need
        {
            state[i]='F';
        }
        if(i==t-1)                                  //after every loop print the status
        {
            cout<<"\nProcess\tAllocation\tMax\t\tAvailable\tNeed\t\tState";
            cout<<"\n\tA B C D\t\tA B C D\t\tA B C D\t\tA B C D\n";
            for(int i=0;i<t;i++)
            {
            cout<<Name[i]<<"\t"<<A1[i]<<" "<<B1[i]<<" "<<C1[i]<<" "<<D1[i]<<"\t\t"<<A2[i]<<" "<<B2[i]<<" "<<C2[i]<<" "<<D2[i]<<"\t\t\t\t"<<A3[i]<<" "<<B3[i]<<" "<<C3[i]<<" "<<D3[i]<<"\t\t"<<state[i];
            cout<<endl;
            }
            cout<<"\nAvailable Resource :\nA\tB\tC\tD\n"<<A<<"\t"<<B<<"\t"<<C<<"\t"<<D<<endl<<endl;
            count++;
            i=0;
        }
        else
            i++;
    }
}
