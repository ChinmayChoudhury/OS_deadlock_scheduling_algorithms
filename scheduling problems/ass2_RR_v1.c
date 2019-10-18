//ROUND ROBIN

#include<stdio.h>
#include<conio.h>
#define max 30

int patient_id[max];  // pool of ids
int arr[max];  //arrival time  (pool)
int BurstTime[max]; //burst time (pool)
int CmpTime[max]; //completion time
int WaitTime[max]; // wait time
int TrnArndTime[max]; //turn around time
int patient_id[max];  // pool of ids
int arr[max];  //arrival time  (pool)
int BurstTime[max]; //burst time (pool)
int CmpTime[max]; //completion time
int WaitTime[max]; // wait time
int TrnArndTime[max]; //turn around time
int RemTime[max]; //stores the remaining time for the processes
int ready_id[max];
int ready_burst[max];
int ready_arr[max];

void updateBurst(int ind, int quanta){
	RemTime[ind]-=quanta;
}



int main(){
	int i,j, total_time=0;
	int counter=0;
	//taking processes
	printf("enter number of patients:");
	int num_of_patients;
	scanf("%d",&num_of_patients);
	int quanta;         //time slot/quanta
	printf("enter length of time slot(quanta): ");
	scanf("%d",&quanta);
	
	for(i=0; i< num_of_patients; i++){
		printf("enter the patient id : ");
		scanf("%d",&patient_id[i]);
		printf("enter the arrival time: ");
		scanf("%d",&arr[i]);
		printf("enter the burst time: ");
		scanf("%d",&BurstTime[i]);
		total_time+= BurstTime[i];
		RemTime[i]=BurstTime[i];   //initial remaining time
	}
	// ready queues
	
	int flag=0;      // initially flag is empty
	
	// arranging
	j=0;
    for(i = 0 ; i< num_of_patients; i++){
    	for ( j=0; j< num_of_patients-1-i; j++){
    		if(arr[j] > arr[j+1]){
    			int temp = arr[j];
    			arr[j]=arr[j+1];
    			arr[j+1]=temp;
    			
    			temp = BurstTime[j];
    			BurstTime[j]=BurstTime[j+1];
    			BurstTime[j+1]=temp;
    			
    			temp=patient_id[j];
    			patient_id[j]=patient_id[j+1];
    			patient_id[j+1]=temp;
			
				temp=RemTime[j];
				RemTime[j]=RemTime[j+1];
				RemTime[j+1]=temp;
			}
		}
	}
	int r_ind=0;
	int curr=0;
	static int k=1;
	for(counter=0;counter<total_time;counter+=quanta){   // counter runs till total time
		//--------- all the process---------------
		if(r_ind==0)
		if(RemTime[curr] > quanta){        //decreasing remaining time
			RemTime[curr]-=quanta;     
		}
		else{
			RemTime[curr] = 0; 
		}
		// insert incoming processes in ready
			
		while(arr[i] < counter && k<num_of_patients){
			ready_burst[r_ind] = BurstTime[k];
			ready_arr[r_ind] = arr[k];
			ready_id[r_ind] = patient_id[k];
			k++;
			r_ind++;
		}
		
		ready_burst[k]=BurstTime[curr];
		ready_id[k]=patient_id[curr];
		ready_arr[k] = arr[curr];
		curr++;
		k++;
	}
	
	
	
	         
	
	
	
	//debug part
	
	for(i=0;i<=r_ind;i++){
		printf("id : %d\n",ready_id[i]);
	}
	
	return 0;
	
	
}
