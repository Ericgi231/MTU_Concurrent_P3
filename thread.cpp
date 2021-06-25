// ----------------------------------------------------------- 
// NAME : Eric Grant                    User ID: ewgrant 
// DUE DATE : 03/17/2021                                       
// The Even-Odd Sorting Algorithm                                        
// FILE NAME : thread.cpp            
// PROGRAM PURPOSE :                                           
//    Edits a global array of ints, swap values i and i-1 
//    such that they are in order     
// ----------------------------------------------------------- 
#include "thread.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

extern int swapped;
extern int *nums;

// ----------------------------------------------------------- 
// FUNCTION  ThreadFunc :                   
//    Edits a global array of ints, swap values i and i-1 
//    such that they are in order      
// ----------------------------------------------------------- 
void SwapThread::ThreadFunc()
{
	Thread::ThreadFunc();

	char buf[1000];
	int temp;

	//print thread header
	sprintf(buf, "        Thread %d Created \n", index);
	write(1, buf, strlen(buf));
	
	//compare two values in array
	sprintf(buf, "        Thread %d compares x[%d] and x[%d]\n", index, i-1, i);
	write(1, buf, strlen(buf));
	if(nums[i-1] > nums[i]){
		//swap if value i-1 is greater than i
		sprintf(buf, "        Thread %d swaps x[%d] and x[%d]\n", index, i-1, i);
		write(1, buf, strlen(buf));
		temp = nums[i];
		nums[i] = nums[i-1];
		nums[i-1] = temp;	
		swapped = 1;
	}

	//print thread exit
	sprintf(buf, "        Thread %d exits\n", index);
	write(1, buf, strlen(buf));

	Exit();
}