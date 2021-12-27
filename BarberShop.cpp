#include<iostream>

using namespace std;
#define chairs 5

void delay()                                        //delay function
{
    for(int i=0; i<10000; i++)
    {

        for(int i=0; i<100000; i++)
        {

        }
    }
}
int main()
{

    int customer=0; //No of waiting Customer
    int barber=1;   // if value 1 barber is free else busy
    int waiting=0;  //total waiting seats
    int mutex=1;    //for mutual exclusion
    int cust=0;
    int ans=0,i=1;

    cout<<"\nBarber is idle ";

    cout<<"\nEnter the Max Waiting Chairs :";
    cin>>waiting;
    cout<<"\nEnter the Current Waiting Customer :";
    cin>>customer;


    while(1)
    {
        if(customer>0 && ans!=0){       //if there are waiting customer available
           cout<<"\nBarber is idle ";
        }
        else if(customer<1)             //if there are no waiting customer
        {
            cout<<"\n\nNo waiting Customer ";
            cout<<"\nBarber is idle";
        }
        ans=1;
        cout<<"\n\nCustomer Arrived : ";cin>>cust;    //checking if new customer arrived thus taking the input
        if((customer+cust)>=waiting)                            //if Customer == waiting chairs do not take new customer
        {
            cout<<"No more waiting seats available :";
            customer=waiting;
        }
        else
        {
        customer=customer+cust;
        }
        cout<<"\n\nWaiting Customers : "<<customer;     //Displaying waiting customers after adding new to it

        if(customer>0)                          //if there are waiting customer
        {
            delay();
            if(mutex)                        //if there is no customer inside send waiting customer
            {
                mutex=0;                        //customer is inside no close the gate for other customers
                delay();
                cout<<"\nBarber Awakes ";       //seeing the customer entered barber awakes
                customer--;                     //reducing one waiting customer
                barber=1;                      //seeing the customer entered barber awakes
                delay();
                cout<<"\nAccess granted for the customer "<<i;
            }
            if(barber)                              //if barber awakes he is busy cutting hairs
            {
                delay();
                cout<<"\nBarber is Busy Cutting Hair ";
                delay();
                delay();
                cout<<"\nCustomer "<<i<<" Released";    //customer released
                i++;
                delay();
                barber=0;                               //barber is idle
                mutex=1;                                //gate opened fro waiting customer to come inside

            }
        }
        else                                           //if no waiting customer end program
        {
            break;
        }

    }

}
