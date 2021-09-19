/*
 *  Matrix.cpp
 *
 *  Created on: 
 *  Author: thawatchai yango SE COMP B
 *  Roll No:203074 BATCH E
 *  Assignment 3
 *  Problem Statement: Write C/C++ program for storing matrix. Write functions for 
 *  a) Check whether given matrix is upper triangular or not 
 *  b) Compute summation of diagonal elements 
 *  c) Compute transpose of matrix 
 *  d) Add, subtract and multiply two matrices
 */
#include<iostream>
#include<cstdio>
void Upper_Triangular(int a[10][10],int n,int m)
{
	for(int i=0;i<n;i++){
	      printf("\n");
	      for(int j=0;j<m;j++)
	           if(i>=j)
	             printf(" %d ",a[i][j]);
	           else
	             printf(" %d ",0);
	  }


}
void Addition(int a[10][10],int b[10][10],int m,int n)
{
int c[10][10],i,j;
for(i=0;i<m;++i)
{
    for(j=0;j<n;++j)
    {
        c[i][j]=0;
        c[i][j]+=a[i][j]+b[i][j];
    }
}
printf("\nAddition Of two Matrix is : \n");
for(i=0;i<m;++i)
{
    for(j=0;j<n;++j)
    {
        printf(" %d ",c[i][j]);
    }
    printf("\n");
}
}
void Difference(int a[10][10],int b[10][10],int n,int m)
{
	int c[10][10]={0,};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("Difference of two matrix is : \n");
	for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				printf(" %d ",c[i][j]);
			}
			printf("\n");
		}
}
void Multiplication(int a[10][10],int b[10][10],int m,int n)
{
int c[10][10],i,j,k;
for(i=0;i<m;++i)
{
    for(j=0;j<n;++j)
    {
        c[i][j]=0;
        for(k=0;k<m;++k)
        {
          c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
    }
}
printf("\nThe multiplication of Matrix is : \n");
for(i=0;i<m;++i)
{
    for(j=0;j<n;++j)
    {
        printf(" %d ",c[i][j]);
    }
    printf("\n");
  }
}

void Transpose(int a[10][10],int b[10][10],int m,int n)
{
    int i,j;
    printf("Enter Which You want to find the Transpose(1 or 2) : \n");
    int ch;
    printf("Enter your choice : \n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
printf("The transpose of the Matrix1 is : \n");
for(j=0;j<n;++j)
{
    for(i=0;i<m;++i)
    {
        printf(" %d ",a[i][j]);
    }
    printf("\n");
}
break;
    case 2:
        printf("The transpose of the Matrix2 is : \n");
for(j=0;j<n;++j)
{
    for(i=0;i<m;++i)
    {
        printf(" %d ",b[i][j]);
    }
    printf("\n");
}
break;
    default:
        printf("Sorry your choice did not Match!!!\n");
        break;
}
}
void Diagonal_sum(int a[10][10],int n,int m)
{
	int sum1=0,sum2=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(i==j)
			{
				sum1+=sum1+a[i][j];
			}
		}
	}
	int k=m-1;
	for(int i=0;i<n;++i)
	{
		sum2+=sum2+a[i][k];
		k--;
	}
   printf("The Diagonal Sum of the matrix is : %d and %d respectivelly.\n",sum1,sum2);;
}


int main()
{
    int n,m,a[10][10],b[10][10],i,j;
    int ch;
    int choi;
    printf("Enter rows and column of matrix : \n");
    scanf("%d%d",&m,&n);
    printf("Enter elements in First Matrix : \n");
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter elements in second Matrix : \n");
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            scanf("%d",&b[i][j]);
        }
    }
    do{
        printf("\n\tMain Menu\n");
        printf("1.Matrix Addition\n2.Substraction\n3.Matrix Multiplication\n4.Transpose of Matrix\n5.Diagonal Sum\n6.Upper Triangular\n");

        printf("Enter your choice!!!\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            Addition(a,b,m,n);
            break;
        case 2:
        	Difference(a,b,m,n);
        	break;
        case 3:
            Multiplication(a,b,m,n);
            break;
        case 4:
            Transpose(a,b,m,n);
            break;
        case 5:
            printf("Which matrix you want to Diagonal Sum!\n");
            printf("1.Matrix A\n2.Matrix B\n");
            printf("Enter Your choice : ");
            scanf("%d", & choi);
            switch(choi)
            {
            case 1:
            	Diagonal_sum(a,m,n);
            	break;
            case 2:
            	Diagonal_sum(b,m,n);
            	break;
            default:
            	printf("Your choice not found!\n");
            	//exit(0);
            	break;
            }
            break;

            case 6:
            	printf("Which matrix you want \n");
            	  printf("1.Matrix A\n2.Matrix B\n");
            	printf("Enter Your choice : ");
            	  scanf("%d", & choi);
            	switch(choi)
            	 {
              case 1:
        	   Upper_Triangular(a,m,n);
            	   break;
              case 2:
        	   Upper_Triangular(b,m,n);
            	   break;
           default:
             printf("Your choice not found!\n");
            	        //exit(0);
            	break;
        }
         break;
    }
    }
    while(ch!=7);
}
