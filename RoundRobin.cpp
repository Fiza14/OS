#include<iostream>
using namespace std;

void findWaitingTime( int n,int bt[], int wt[], int quantum)
{
	
	int rem_bt[n];
	
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0; 

	
	while (1)
	{
		bool done = true;

		for (int i = 0 ; i < n; i++)
		{
			
			if (rem_bt[i] > 0)
			{
				done = false; 
				if (rem_bt[i] > quantum)
				{
					
					t += quantum;
					rem_bt[i] -= quantum;
				}

				else
				{
					
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}

		if (done == true)
		break;
	}
}

void findTurnAroundTime( int n,int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime( int n, int bt[],	int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime( n, bt, wt, quantum);

	findTurnAroundTime( n, bt, wt, tat);

	// Display processes along with all details
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// process id's
	int n;
	cout<<"Enter the number of processes : \n";
	cin>>n;
	
	int bt[n];
	cout<<"Enter Burst Time of each process  \n";
	for(int i=0;i<n;i++){
		cout<<"Enter burst time for Process P "<<i<<" :";
		cin>>bt[i];
	}
	
	int quantum;
	cout<<"\nEnter Quantum time for Round Robin Algorithm : ";
	cin>>quantum;

	
	findavgTime( n, bt, quantum);
	
	return 0;
}

