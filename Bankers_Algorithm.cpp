// Banker's Algorithm
#include <iostream>
using namespace std;

int main()
{


	int n, m, i, j, k;

	cout<<"\nEnter the number of processes : ";
	cin>>n;
	
	cout<<"\nEnter the number of resources : ";
	cin>>m;

//n = 5; // Number of processes
//m = 3; // Number of resources
	
	int alloc[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"\nEnter allocation for process "<<i<<" and resource "<<j<<endl;
			cin>>alloc[i][j];
		}
	}
	
	


	int max[n][m];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"\nEnter max for process "<<i<<" and resource "<<j<<endl;
			cin>>max[i][j];
		}
	}


	//find sum_of_allocated resources 
	// avial = total_resources - sum_of_allocated 
	// update here Available Resources accordingly 
	int avail[3] = { 3, 3, 2 }; // Available Resources
	
	//making all false
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		need[i][j] = max[i][j] - alloc[i][j];
	}
	
	cout<<"\nNeed Matrix\n ";
	for (i = 0; i < n; i++) {
		
		for (j = 0; j < m; j++){
		cout<<need[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
		if (f[i] == 0) {
	
			int flag = 0;
			for (j = 0; j < m; j++) {
			if (need[i][j] > avail[j]){
				flag = 1;
				break;
			}
			}
	
			if (flag == 0) {
			ans[ind++] = i;
			for (y = 0; y < m; y++)
				avail[y] += alloc[i][y];
			f[i] = 1;
			}
		}
		}
	}

	cout << "Following is the SAFE Sequence" << endl;
	for (i = 0; i < n - 1; i++)
		cout << " P" << ans[i] << " ->";
	cout << " P" << ans[n - 1] <<endl;

	return (0);
}




//Take Input As Allocation : 0 1 0 2 0 0 3 0 2  2 1 1 0 0 2
//Take Input As MAX need  :7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
