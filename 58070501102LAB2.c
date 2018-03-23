#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
float xmin=1,xmax=0,ymin=0,ymax=0;
int check_point(int fun,float a1,float a2,float b1,float b2)
//This function does it 4 times(xmin,xmax,ymin,ymax)
//Function check 2 points to case in-in,in-out,out-in or out-out
{
	if(fun==0)//xmin
	{
		if(a1>=xmin)//point1 is in
			{
			if(a2>=xmin) //point2 is in, it in-in
				{return 1;}
			else  // in-out
				{return 2;}
		    }
		else {//point1 is out
			if(a2>=xmin)//point2 is in, it out-in
				{return 3;}
			else // out-out
				{return 4;}
			}
	}
	else if(fun==1)//ymin
	{
		if(b1>=ymin)//point1 is in
		{
			if(b2>=ymin)//point2 is in, it in-in
			{return 1;}
			else // in-out
			{return 2;}
		}
		else //point1 is out
		{
			if(b2>=ymin)//point2 is in, it out-in
			{return 3;}
			else // out-out
			{return 4;}
		}
	}
	else if(fun==2)//xmax
	{
		if(a1<=xmax)//point1 is in
		{
			if(a2<=xmax)//point2 is in, it in-in
			{return 1;}
			else // in-out
			{return 2;}
		}
		else //point1 is out
		{
			if(a2<=xmax)//point2 is in, it out-in
			{return 3;}
			else // out-out
			{return 4;}
		}
	}
	else if(fun==3)//ymax
	{
		if(b1<=ymax)//point1 is in
		{
			if(b2<=ymax)//point2 is in, it in-in
			{return 1;}
			else // in-out
			{return 2;}
		}
		else //point1 is out
		{
			if(b2<=ymax)//point2 is in, it out-in
			{return 3;}
			else // out-out
			{return 4;}
		}
	}
	else
	printf("Sorry,I think The Program has .... or bug (-m-)\n");
}
int main()
{
	float m=0,c=0;
	float *A,*B,*C,*D;
	//float A[100],B[100],C[100],D[100];
	int know[100],maxpoint=0,i=0,j=0,k=0,line=0;
	char SeeMax[10]="";
	int Check=0,size=100,X,Y;
	printf("::::Welcome:::::\n");
	printf(":::::::To:::::::\n");
	printf("::::Program:::::\n");
	printf("Select Size of Window\n");
	printf("Xmin:");
	scanf("%f",&xmin);
	printf("Xmax:");
	scanf("%f",&xmax);
	printf("Ymin:");
	scanf("%f",&ymin);
	printf("Ymax:");
	scanf("%f",&ymax);
	printf("Selet Point\n");
	printf("If you select all point press 'y' to exit\n");
	A = (float*)malloc(size*sizeof(int));
	B = (float*)malloc(size*sizeof(int));
	C = (float*)malloc(size*sizeof(int));
	D = (float*)malloc(size*sizeof(int));
	while(strcmp(SeeMax,"y")!=0)
	{
		maxpoint=maxpoint+1;
		printf("X%d:",maxpoint);
		scanf("%f",&A[i]);
		printf("Y%d:",maxpoint);
		scanf("%f",&B[i]);
		gets(SeeMax);
		strlwr(SeeMax);
		i++;
		printf("\n");
	}
	maxpoint=maxpoint-1; //Delete data y
	i=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<maxpoint;j++)
		{
			line=0;
			printf("Size:%d,Line:%d is",i+1,j+1);
			if(j!=(maxpoint-1))
			{
				printf("(%g,%g)to(%g,%g)",A[j],B[j],A[j+1],B[j+1]);
				if(A[j]!=A[j+1])
				{
				m=(B[j+1]-B[j])/(A[j+1]-A[j]);
				c=B[j]-(m*A[j]);
				}
				else
				{
					line=1;
				}
			Check=check_point(i,A[j],A[j+1],B[j],B[j+1]); //1->2,2->3,...,(n-1)->n
			}
			else //last point
			{
			
				printf("(%g,%g)to(%g,%g)",A[j],B[j],A[0],B[0]);
				if(A[j]!=A[0])
				{
				m=(B[j]-B[0])/(A[j]-A[0]);
				c=B[j]-(m*A[j]);
				}
				else
				{
					line=1;
				}
			Check=check_point(i,A[j],A[0],B[j],B[0]); //n->1
			}
		//We can see case in-in,out-out,etc from check
		//See case x,y-min,max from i
		//i=0 xmin,1 ymin,2 x max,3 y max
			if(Check==1)//in-in
			{
				printf("Visible\n");
				if(j!=maxpoint-1)
				{
				C[k]=A[j+1];
				D[k]=B[j+1];
				k=k+1;
				}
				else
				{
				C[k]=A[0];
				D[k]=B[0];
				k=k+1;
				}
			}
			else if(Check==2)//in-out
			{
				printf("Clipping Candidate\n");
				if(i==0)//xmin
				{
					Y=(m*xmin)+c;
					C[k]=xmin;
					D[k]=Y;
					k=k+1;
				}
				else if(i==1)//ymin
				{
					if(line==0)
					{
						X=(ymin-c)/m;
						C[k]=X;
						D[k]=ymin;
						k=k+1;
					}
					else //X1=X2
					{
						C[k]=A[j];
						D[k]=ymin;
						k=k+1;
					}
				}
				else if(i==2)//xmax
				{
					Y=(m*xmax)+c;
					C[k]=xmax;
					D[k]=Y;
					k=k+1;
				}
				else if(i==3)
				{
					if(line==0)
					{
						X=(ymax-c)/m;
						C[k]=X;
						D[k]=ymax;
						k=k+1;
					}
					else //X1=X2
					{
						C[k]=A[j];
						D[k]=ymax;
						k=k+1;
					}	
				}
			}
			else if(Check==3) //out-in
			{
				printf("Clipping Candidate\n");
				if(i==0)//xmin
				{
					Y=(m*xmin)+c;
					C[k]=xmin;
					D[k]=Y;
					k=k+1;
					if(j!=maxpoint-1)
					{
					C[k]=A[j+1];
					D[k]=B[j+1];
					k=k+1;
					}
					else
					{
					C[k]=A[0];
					D[k]=B[0];
					k=k+1;	
					}
				}
				else if(i==1)//ymin
				{
					if(line==0)
					{
						X=(ymin-c)/m;
						C[k]=X;
						D[k]=ymin;
						k=k+1;
						if(j!=maxpoint-1)
						{
						C[k]=A[j+1];
						D[k]=B[j+1];
						k=k+1;
						}
						else
						{
						C[k]=A[0];
						D[k]=B[0];
						k=k+1;	
						}
					}
					else //X1=X2
					{
						C[k]=A[j];
						D[k]=ymin;
						k=k+1;
						if(j!=maxpoint-1)
						{
						C[k]=A[j+1];
						D[k]=B[j+1];
						k=k+1;
						}
						else
						{
						C[k]=A[0];
						D[k]=B[0];
						k=k+1;	
						}
					}
				}
				else if(i==2)//xmax
				{
					Y=(m*xmax)+c;
					C[k]=xmax;
					D[k]=Y;
					k=k+1;
					if(j!=maxpoint-1)
					{
					C[k]=A[j+1];
					D[k]=B[j+1];
					k=k+1;
					}
					else
					{
					C[k]=A[0];
					D[k]=B[0];
					k=k+1;	
					}
				}
				else if(i==3)//ymax
				{
					if(line==0)
					{
						printf("!!!\n");
						X=(ymax-c)/m;
						C[k]=X;
						D[k]=ymax;
						k=k+1;
						if(j!=maxpoint-1)
						{
						C[k]=A[j+1];
						D[k]=B[j+1];
						k=k+1;
						}
						else
						{
						C[k]=A[0];
						D[k]=B[0];
						k=k+1;	
						}
					}
					else //X1=X2
					{
						C[k]=A[j];
						D[k]=ymax;
						k=k+1;
						if(j!=maxpoint-1)
						{
						C[k]=A[j+1];
						D[k]=B[j+1];
						k=k+1;
						}
						else
						{
						C[k]=A[0];
						D[k]=B[0];
						k=k+1;	
						}
					}
				}
			}
			else if(Check==4)//out-out
			{
				printf("Invisible\n");
			}
		}
		maxpoint=k;
		k=0;
		//Give data to run agian
		for(j=0;j<maxpoint;j++)
		{
			A[j]=C[j];
			B[j]=D[j];
		}
	}
	printf("The point in the window is:\n");
	for(j=0;j<maxpoint;j++)
	{
		printf("(%g,%g)\n",A[j],B[j]);
	}
}
