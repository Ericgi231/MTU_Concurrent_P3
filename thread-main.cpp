// ----------------------------------------------------------- 
// NAME : Eric Grant                    User ID: ewgrant 
// DUE DATE : 03/17/2021                                       
// The Even-Odd Sorting Algorithm                                        
// FILE NAME : thread-main.cpp        
// PROGRAM PURPOSE :                                           
//      Take unsorted array of ints from file and print
//      sorted array.
//      Sort via even odd sort using threads
// ----------------------------------------------------------- 
#include <iostream>
#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int swapped;
int *nums;

// ----------------------------------------------------------- 
// FUNCTION  main :                         
//      Take unsorted array of ints from file and print
//      sorted array.
//      Sort via even odd sort using threads                     
// PARAMETER USAGE :                                           
//    argv, argc          
// ----------------------------------------------------------- 
int main(int argv, char* argc[])
{
    //vars
    //
	int i, total, created;
	char buf[1000], build[1000];
	
    //read total nums and set array sizes
	cin >> total;
    nums = new int[total];
    int maxThreads = total / 2;
	SwapThread* threads[maxThreads];

    //print main info
    //
	printf("Concurrent Even-Odd Sort\n\n");
	printf("Number of input data = %d\n", total);

	printf("Input Array:\n");
	for (i = 0; i < total; i++)
	{
		cin >> nums[i];
        if (i != 0 && i % 20 == 0){
            printf("\n");
        }
        printf("%4d", nums[i]);
	}
	printf("\n\n");

    //begin main loop
    //
    int iteration = 1;
    swapped = 1;
	while(swapped)
	{
        swapped = 0;

        //print iteration start
    	sprintf(buf, "Itearation %d:\n", iteration);
	    write(1, buf, strlen(buf));

        //run even pass
        created = 0;
		sprintf(buf, "    Even Pass:\n");
	    write(1, buf, strlen(buf));
        for(i = 0; i < maxThreads && 2*i + 1 < total; i++){
            threads[i] = new SwapThread(2*i + 1, i+1);
            threads[i] -> Begin();
            created++;
        }

        //wait for end of even pass
        for(i = 0; i < created; i++){
            threads[i]->Join();
        }

        //run odd pass
        created = 0;
		sprintf(buf, "    Odd Pass:\n");
	    write(1, buf, strlen(buf));
        for(i = 0; i < maxThreads && 2*(i+1) < total; i++){
            threads[i] = new SwapThread(2*(i+1), i+1);
            threads[i] -> Begin();
            created++;
        }

        //wait for end of odd pass
        for(i = 0; i < created; i++){
            threads[i]->Join();
        }

        //print end of iteration results
        sprintf(buf, "Result after iteration %d:\n", iteration);
	    write(1, buf, strlen(buf));

        for (i = 0; i < total; i++)
	    {
            if (i != 0 && i % 20 == 0){
                sprintf(buf, "\n");
	            strcat(build, buf);
            }
            sprintf(buf, "%4d", nums[i]);
	        strcat(build, buf);
	    }
        strcat(build, "\n\n");
        write(1, build, strlen(build));
        strcpy(build, "");

        iteration++;
	}

    //print final results
    //
	printf("Final result after iteration %d:\n", iteration - 1);
    for (i = 0; i < total; i++)
    {
        if (i != 0 && i % 20 == 0){
            printf("\n");
        }
        printf("%4d", nums[i]);
    }
    printf("\n");
}