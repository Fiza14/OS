#include<bits/stdc++.h>

using namespace std;

int main()
{
     cout<<"\nPage Replacement Algorithm :\n\n";
    int l=20;
    list<int> gqlist1, gqlist2;
    list<int>::iterator it1;

    int pf=0,ph=0,flag1=0,flag2=0,flag3=0,count1=0,count2=0,count3=0;
    int a=-1,b=-1,c=-1,d=0,i=0,f1=0,f2=1,f3=1,ch;

     cout<<"\nEnter the Reference String:\n";       //input of input string
    /* for(int i=0;i<l;i++)
     {
         cout<<"-> ";
         cin>>arr[i];2 1  3
     }*/
     int arr[20] = {7,2,3,1,2,5,3,4,6,7,7,1,0,5,4,6,2,3,0,1};
    cout<<endl;
    do{
    cout<<"1.FIFO\t2.LRU\t3.Optimal\t4.Exit\nEnter Choice :";
    cin>>ch;
    ph=0;
    pf=0;
    i=0;
    a=-1;
    b=-1;
    c=-1;

        //switch case start


    switch(ch)
    {
    case 1:                                     //case 1 : FIFO
    {

        while(i<l)
    {
        d=arr[i];                       //here a,b,c are the frames
                                        //d= next value from reference string
                                        //frames values = -1 means frames are empty
        if(a==-1)
        {
            a=d;
            pf++;                       //giving first value of reference string to frame a and increasing page fault

        }
        else if(b==-1)
        {
            b=d;                         //giving first value of reference string to frame b and increasing page fault
            pf++;

        }
        else if(c==-1)
        {
            c=d;                         //giving first value of reference string to frame c and increasing page fault
            pf++;

        }
        if(i>2){                        //all frames are filled try to switch values

            if(d==a || d==b || d==c)    //check for page hits
            {
                ph++;                   //if page hit occur increment its value

            }
            else                        //if no page hit occur try to switch values using FIFO

                                        //here f1 , f2 , f3 are flag respectively for frames a , b , c
            {

                if(f1==0)              //f1 =0 means frame is not replaced proceed to replacement
                {
                    a=d;                //next frame value is replaced to frame a
                    f1=1;               //f1 =1 frame replaced

                    f2=0;               //set frame b flag to 0 so that it will be used for replacement next time
                    pf++;               //increase page fault


                }
                else if(f2==0)          //f2 =0 means frame is not replaced proceed to replacement
                {
                    b=d;                 //next frame value is replaced to frame b
                    f2=1;               //f2 =1 frame replaced
                    f3=0;                //set frame c flag to 0 so that it will be used for replacement next time
                    pf++;
                }
                else if(f3==0)          //f3 =0 means frame is not replaced proceed to replacement
                {
                    c=d;                //next frame value is replaced to frame c
                    f3=1;                  //f3 =1 frame replaced
                    f1=0;               //set frame a flag to 0 so that it will be used for replacement next time
                    pf++;
                }

            }


        }
         i++;

    }
    cout<<"\nFIFO Page Replacement\n";
    cout<<"\nPage Faults :"<<pf;
    cout<<"\nPage Hits :"<<ph<<endl<<endl;
    }
    break;
    case 2:                                //case 2 LRU
    {
        while(i<l)
        {
                                        //here a,b,c are the frames
                                        //frames values = -1 means frames are empty
                                        //using list concept for LRU
            d=arr[i];                   //d= next value from reference string
            if(a==-1)
            {                               //giving first value of reference string to frame a and increasing page fault
                a=d;
                pf++;
                cout<<a<<endl;
                gqlist2.push_front(a);    //push the frame value used
            }
            else if(b==-1)
            {
                b=d;                            //giving first value of reference string to frame b and increasing page fault
                pf++;

                gqlist2.push_front(b);      //push the frame value used
            }
            else if(c==-1)
            {
                c=d;
                pf++;

                gqlist2.push_front(c);      //push the frame value used
            }
            if(i>2)                             //all frames are filled try to switch values
            {
                if(d==a || d==b || d==c)        //check for page hits
                {
                    ph++;                          //increment page hit
                    for(it1 = gqlist2.begin(); it1 != gqlist2.end(); ++it1)
                    {
                        int e=*it1;       //erase the value from list for which the page hit occur put and the value in front of list
                        if(e==d)
                        {
                            gqlist2.erase(it1);
                            break;
                        }

                    }
                    gqlist2.push_front(d);
                }
                else                        //no page hit go for page replacement
                {
                    int lu=gqlist2.back();
                    gqlist2.pop_back();     //pop the least recently used value of frame
                                            //check which frame consists the pop value and replace it with next frame value
                    if(a==lu)               //check for frame a
                    {
                        a=d;                    //replace next value from reference string
                        gqlist2.push_front(a);      //push value in front
                        pf++;                       //increment page fault
                    }
                    else if(b==lu)
                    {
                        b=d;
                        gqlist2.push_front(b);
                        pf++;
                    }
                    else if(c==lu)
                    {
                        c=d;
                        gqlist2.push_front(c);
                        pf++;
                    }


                }
            }
            cout<<a<<"\t"<<b<<"\t"<<c<<endl;
            i++;
        }
        cout<<"\nLRU Page Replacement\n";
        cout<<"\nPage Faults :"<<pf;
        cout<<"\nPage Hits :"<<ph<<endl<<endl;

    }
    break;
    case 3:                 //case 3 Optimal Page Replacement
    {
        while(i<l)
                                //here a,b,c are the frames
                                        //frames values = -1 means frames are empty
                                        //using list concept for LRU
    {
        d=arr[i];
        if(a==-1)           //giving first value of reference string to frame a and increasing page fault
        {
            a=d;
            pf++;                   //increment page fault

        }
        else if(b==-1)      //giving first value of reference string to frame b and increasing page fault
        {
            b=d;
            pf++;

        }
        else if(c==-1)
        {                       //giving first value of reference string to frame c and increasing page fault
            c=d;
            pf++;

        }
        if(i>2)                         //all frames are filled try to switch values
        {
            if(d==a || d==b || d==c)    //check for page hits
            {
                ph++;                       //increment page hit

            }
            else
            {
                flag1=0,flag3=0,flag2=0;
                count1=0,count2=0,count3=0;
                for(int k=i; k<l; k++)      //checking the next occurrence of every frame value
                {
                    if(arr[k]==a && flag1==0)        //if find the first next occurrence of frame a value
                    {
                        flag1=1;                  //set flag to 1 as we have calculated its occurrence
                    }
                    else if(arr[k]==b && flag2==0)  //if find the first next occurrence of frame b value
                    {
                        flag2=1;                    //set flag to 1 as we have calculated its occurrence
                    }
                    else if(arr[k]==c && flag3==0)  //if find the first next occurrence of frame b value
                    {
                        flag3=1;
                    }


                    if(flag1==0)              //till value not find ,increment the count for frame a value
                    {
                        count1++;
                    }
                    if(flag2==0)            //till value not find ,increment the count for frame b value
                    {
                        count2++;
                    }
                    if(flag3==0)             //till value not find ,increment the count for frame c value
                    {
                        count3++;
                    }

                    if(flag1==1 && flag2==1 && flag3==1)        //if all the next occurrence are find for all frame break the loop
                    {
                        break;
                    }
                                            //calculate the max count from all the three and replace it with next reference string value

                }
                if(count1>count2 && count1>count3)        //if count 1 id > than count2 & count3 replace next frame value with frame a
                {
                    a=d;
                    pf++;                                       //increment page fault
                }
                else if(count2>count1 && count2>count3) //if count 1 id > than count2 & count3 replace next frame value with frame a
                {
                    b=d;
                    pf++;                               //increment page fault
                }
                else if(count3>count2 && count3>count1) //if count 1 id > than count2 & count3 replace next frame value with frame a
                {
                    c=d;
                    pf++;                               //increment page fault
                }
            }

        }

        i++;

    }
    cout<<"\nOptimal Page Replacement\n";
    cout<<"\nPage Faults :"<<pf;
    cout<<"\nPage Hits :"<<ph<<endl<<endl;

    }
    }
    }while(ch!=4);
}

