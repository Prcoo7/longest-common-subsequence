/**objective: Write a C program to determine longest common subsequence of two sequences**
***@uthor: Prasanta Roy Choudhury********************************************************/

#include<stdio.h>
#include<conio.h>

main()
{
	int i,j, size1, size2;
	char seqn1[20], seqn2[20];
	
	int matrix[30][30];
	
	printf("\n\n      ***Determination of Longest Common Subsequence of Two Sequences***        \n\n\n");
	
	/*Sequence 1 starts*/
	
	printf("Enter size of the sequence 1:");
	scanf("%d",&size1);
	
	printf("\nEnter elements for sequence 1:\n\n");
	for(i = 1; i< size1 + 1; i++)
	{
		scanf("%c",&seqn1[i]);
		scanf("%[^\n]",&seqn1[i]);
	}
	
	/*Sequence 2 starts*/
	
	printf("\n\nEnter size of the sequence 2:");
	scanf("%d",&size2);
	
	printf("\nEnter elements for sequence 2:\n\n");
	for(i = 1; i< size2 + 1; i++)
	{
		scanf("%c",&seqn2[i]);
		scanf("%[^\n]",&seqn2[i]);
	}
	
	/*Prints Sequence 1*/
	printf("\n\nsequence 1:");
	for(i = 1; i< size1 + 1; i++)
	{
		printf("%c",seqn1[i]);
	}
	
	/*Prints Sequence 2*/
	printf("\n\nsequence 2:");
	for(i = 1; i< size2 + 1; i++)
	{
		printf("%c",seqn2[i]);
	}
	
	/*-----calculation starts-----*/
	for(i = 0; i< size2 + 1; i++)
	{
		matrix[i][0]=0;
	}
	for(j = 0; j< size1 + 1; j++)
	{
		matrix[0][j] = 0;
	}

	printf("\n\n");
	
	for(i = 1; i< size2 + 1 ; i++)
	{
		for(j = 1; j< size1 + 1 ; j++)
		{
			if(seqn1[j] == seqn2[i])
			{
				matrix[i][j] = (matrix[i - 1][j - 1] + 1);		//1st condition
			}
			else
			{
				if(matrix[i - 1][j]> matrix[i][j - 1])
				{
					matrix[i][j] = matrix[i - 1][j];				//2nd condition
				}
				else
				{
					matrix[i][j] = matrix[i][j - 1];				//3rd condition
				}
			}
		}
	}

	/*prints matrix*/
	
	printf("\n\n");
		
	for(i = 0; i< size2 + 1; i++)
	{
		for(j = 0; j< size1 + 1; j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n\n");
	}
	
	printf("the longest common subsequence of sequence 1 and sequence 2 is: %d", matrix[size2][size1]);
	
	getch();
}
