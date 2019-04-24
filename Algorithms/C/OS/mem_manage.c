#include <stdio.h>

int mem[14] = {200, 300, 300, 400, 200, 500, 200, 400, 200, 500, 300, 200, 200, 100};

int process[9] = {100, 300, 200, 100, 400, 300, 300, 200, 100};

void firstFit(int arr1[], int n1, int arr[], int n2)
{
    int arr2[n2];
    for (int iip = 0; iip < n2; iip++)
    {
        arr2[iip] = arr[iip];
    }

    int track[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    //alocate the first available
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] <= arr2[j])
            {
                track[i] = j;
                arr2[j] = arr2[j] - arr1[i];
                break;
            }
        }
    }
    /*
	for(int p=0;p<9;p++){
		printf("%d",track[p]);
	}
	printf("\n");
	*/
    //print
    printf("%s", "First Fit ");

    for (int k = 0; k < 14; k++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (track[o] == k)
            {
                printf("%d", o);
            }
        }
        //printf("\n");
    }
    printf("\n");
}

void bestFit(int arr1[], int n1, int arr[], int n2)
{
    int arr2[n2];
    for (int iip = 0; iip < n2; iip++)
    {
        arr2[iip] = arr[iip];
    }
    //allocate the best available
    int track[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n1; i++)
    {
        int c = 301;
        int ii = -1;
        int jj = -1;
        for (int j = 0; j < n2; j++)
        {
            if (arr2[j] - arr1[i] < c && arr2[j] - arr1[i] >= 0)
            {
                c = arr2[j] - arr1[i];
                ii = i;
                jj = j;
            }
        }
        track[ii] = jj;
        arr2[jj] = arr2[jj] - arr1[ii];
    }

    printf("%s", "Best Fit ");

    for (int k = 0; k < 14; k++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (track[o] == k)
            {
                printf("%d", o);
            }
        }
        //printf("\n");
    }
    printf("\n");
}

void worstFit(int arr1[], int n1, int arr[], int n2)
{
    int arr2[n2];
    for (int iip = 0; iip < n2; iip++)
    {
        arr2[iip] = arr[iip];
    }
    int track[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n1; i++)
    {
        int c = -1;
        int ii = -1;
        int jj = -1;
        for (int j = 0; j < n2; j++)
        {
            if (arr2[j] - arr1[i] > c && arr2[j] - arr1[i] >= 0)
            {
                c = arr2[j] - arr1[i];
                ii = i;
                jj = j;
            }
        }
        track[ii] = jj;
        arr2[jj] = arr2[jj] - arr1[ii];
    }

    printf("%s", "Worst Fit ");

    for (int k = 0; k < 14; k++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (track[o] == k)
            {
                printf("%d", o);
            }
        }
        //printf("\n");
    }
    printf("\n");
}

int main()
{
    firstFit(process, 9, mem, 14);
    bestFit(process, 9, mem, 14);
    worstFit(process, 9, mem, 14);
}