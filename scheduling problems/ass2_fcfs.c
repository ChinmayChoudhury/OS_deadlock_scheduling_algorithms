// REG NO: 18BIT0097
//FCFS

#include<stdio.h>
#include<conio.h>

#define max 20

//TODO:calculate wait time, turnaround time and completion time

void showall(int arr[max], int BurstTime[max], int patient_id[max], int num){
	printf("===========printing table==============\n");
	printf(" ID | AT | BT |\n ");
	int i;
	for( i=0; i < num; i++){
		printf(" %d  | %d  | %d  |\n", patient_id[i], arr[i], BurstTime[i]);
	}
	return;
}

int main(){
    int num_of_patients;
    printf("enter the number of patients:");
    scanf("%d", &num_of_patients);
    int patient_id[max];
    int arr[max];  //arrival time
    int BurstTime[max]; //burst time
    int CmpTime[max]; //completion time
    int WaitTime[max]; // wait time
    int TrnArndTime[max]; //turn around time
    int i;
    // taking inputs
    for(i=0;i<num_of_patients;i++){
          printf("enter the patient id arrived:");
          scanf("%d", &patient_id[i]);
          printf("enter the arrival time: ");
          scanf("%d", &arr[i]);
          printf("enter the burst time: ");
          scanf("%d", &BurstTime[i]);
          
    }
    // showing initial table
    printf("=======initial table========\n");
    printf("ID | AT | BT |\n");
    for(i=0;i<num_of_patients;i++){
          printf("%d  | %d  | %d  |\n",patient_id[i], arr[i], BurstTime[i]);
    }
    int j;
    // arranging them in order of arrival time
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
	// printing table after arranging the patients
	showall(arr, BurstTime, patient_id, num_of_patients);
	
	//printf("press any key to exit..........");
	getch();
    return 0;
}
