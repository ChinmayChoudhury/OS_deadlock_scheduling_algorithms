#include<stdio.h>
#include<conio.h>
#define max 30

int patient_id[max];  	// pool of ids
int arr[max];  			//arrival time  (pool)
int Priority[max];		//priority of processess
int BurstTime[max];		//burst time (pool)
int CmpTime[max]; 		//completion time
int WaitTime[max]; 		// wait time
int TrnArndTime[max]; 	//turn around time

void display( int num_of_patients){        // displaying table
	int i;
	printf("======ORDER OF PROCESSING==========");
	printf("\n ID | AT | PR | BT | TAT | WT |");
    for(i=0;i<num_of_patients;i++){
          printf("\n %d  | %d  | %d  | %d  | %d  | %d  |\n",patient_id[i], arr[i], Priority[i], BurstTime[i],TrnArndTime[i],WaitTime[i]);
    }
}

void FindWaitTime(int num_of_patients){
	int j,i;
	int start_time=0;
    int wait_time;
    
	printf("===========CALCULATING WT AND TAT=========\n");
    WaitTime[0] = 0;        // wait time for first process is always 0;
    for(i = 1; i< num_of_patients; i++){
    	wait_time=0;
    	start_time=0;
    	for( j=0; j<i;j++){
    	start_time = start_time + BurstTime[j];
    		
		}
		wait_time = start_time - arr[i];
		WaitTime[i] = wait_time;
	}
}

void FindTurnAroundTime(int num_of_patients){
	int j,i;
	int tat;
	for(i=0; i< num_of_patients; i++){
		TrnArndTime[i]=BurstTime[i]+WaitTime[i];
	}
}

int main(){
	printf("=======PRIORITY[HIGHER NUMBER IS HIGHER PRIORITY]=======\n");
	int num_of_patients;
    printf("enter the number of patients:");
    scanf("%d", &num_of_patients);
    
    int i;
    int ready_id[max];
    int ready_burst[max];
    int ready_arr[max];
    int ready_flag=0;
    int ready_prio[max];
    // taking inputs
	//    printf("\nenter the patient as they arrived(in the sequence of their arrival)");
    for(i=0;i<num_of_patients;i++){
        printf("enter the patient id arrived:");
        scanf("%d", &patient_id[i]);
        printf("enter the arrival time: ");
        scanf("%d", &arr[i]);
        printf("enter the burst time: ");
        scanf("%d", &BurstTime[i]);
        printf("enter the priority: ");
        scanf("%d", &Priority[i]);
    }
    // showing initial table
    printf("\n=======initial table========\n");
    printf("\n ID | AT | BT | PR |");
    for(i=0;i<num_of_patients;i++){
        printf("\n %d  | %d  | %d  | %d  |\n",patient_id[i], arr[i], BurstTime[i], Priority[i]);
    }
    
    // doing fcfs first
    int j=0;
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
			}
		}
	}
    
    // arranging the table
    int k=0; int m,n,x;
    for( i = 1; i< num_of_patients; i++){
    	int k=0;
    	int curr=j;
    	ready_flag=0;
		while(BurstTime[j]>=arr[i] && i<num_of_patients){
			printf("added to ready queue: %d\n",patient_id[i]);
			ready_id[k]= patient_id[i];
			ready_burst[k]=BurstTime[i];
			ready_arr[k]=arr[i];
			ready_prio[k]=Priority[i];
			k++;
			i++;
			ready_flag=1;
		} 
        // all the process arriving while the cpu is busy is added to ready.
		if(ready_flag){							// ready must be sorted
			for(m = 0 ; m< k; m++){
    			for ( n=0; n< k-1-m; n++){
    				if(ready_prio[n] > ready_prio[n+1]){
		    			int temp = ready_burst[n];
		    			ready_burst[n]=ready_burst[n+1];
		    			ready_burst[n+1]=temp;
		    			
		    			temp = ready_arr[n];
		    			ready_arr[n]=ready_arr[n+1];
		    			ready_arr[n+1]=temp;
		    			
		    			temp=ready_id[n];
		    			ready_id[n]=ready_id[n+1];
		    			ready_id[n+1]=temp;
		    			
		    			temp=ready_prio[n];
		    			ready_prio[n]=ready_prio[n+1];
		    			ready_prio[n+1]=temp;
		    			
					}
				}
			}
			printf("========SORTED READY QUEUE=========\n");
			//shifting processes from ready queue
			for(x=num_of_patients-k-1; x<k ;x++ ){
				arr[x+1] = ready_arr[x];
				BurstTime[x+1] = ready_burst[x];
				patient_id[x+1] = ready_id[x];
				Priority[x+1] = ready_prio[x];
				printf("id: %d\n",ready_id[x]);
			}
		}                                        
	}
	FindWaitTime(num_of_patients);
	FindTurnAroundTime(num_of_patients);
	display(num_of_patients);
    
    return 0;
}
