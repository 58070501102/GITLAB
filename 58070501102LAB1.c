#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
/*void swap(char buff[])  //Switching from the back to the front because answer of SumBit is back to front
{
	char test[100]="",toot[100];
	int i,j;
	for(i=strlen(buff)+1;i>0;i--)
	{
		toot[0]=buff[i-1];
		strcat(test,toot);
	}
	strcpy(buff,test);
}*/
int checkbit(char x[],char y[]) //the function check Bit1 And Bit2
{
	char test1[200],test2[200];
	int j,k;
	for(j=0,k=0;k<strlen(x);k++,j++)
	{
	test1[0]=x[k];
	test2[0]=y[j];
	//printf("%c,%c",test1[0],test2[0]);
	if(strcmp(test1,"1")==0)
	{
		if(strcmp(test2,"1")==0)
		return 1;
	}
	}
	return 0;
}
int main()
{
	float X1=0,X2=0,Y1=0,Y2=0; //Variable of Two End Point
	float ymin=0,ymax=0,xmin=0,xmax=0; //Variable of Window
	char Select[3]; //For loop of program
	char Bit1[200],Bit2[200],SumBit[200]="";
	int count1,count2,i=0,j=0,k=0;
	char test1[100],test2[100];
do	{	
	i=0;
	printf("Select two point!!!\n");
	printf("Point X1 on:");  //Input point of X1
	scanf("%f",&X1);
	printf("Point Y1 on:");	//Input point of Y1
	scanf("%f",&Y1);
	printf("Point X2 on:");	//Input point of X2
	scanf("%f",&X2);
	printf("Point Y2 on:");	//Input point of Y2
	scanf("%f",&Y2);
	printf("Now!,Select the window\n");
	printf("Point xmin on:");	//Input point of xmin
	scanf("%f",&xmin);
	printf("Point xmax on:");	//Input point of xmax
	scanf("%f",&xmax);
	printf("Point ymin on:");	//Input point of ymin
	scanf("%f",&ymin);
	printf("Point ymax on:");	//Input point of ymax
	scanf("%f",&ymax);
		if(Y1>ymax)		//Check case of point1 in Cohen-Sutherland
		{
			if(X1>xmax)
			{	strcpy(Bit1,"1010");}
			else if(X1<xmin)
			{	strcpy(Bit1,"1001");}
			else
			{	strcpy(Bit1,"1000");}
		}
		else if(Y1<ymin)
		{
			if(X1>xmax)
			{	strcpy(Bit1,"0110");}
			else if(X1<xmin)
			{	strcpy(Bit1,"0101");}
			else
			{	strcpy(Bit1,"0100");}
		}
		else
		{
			if(X1>xmax)
			{	strcpy(Bit1,"0010");}
			else if(X1<xmin)
			{	strcpy(Bit1,"0001");}
			else
			{	strcpy(Bit1,"0000");}
		}
		if(Y2>ymax)		//Check case of point2 in Cohen-Sutherland
		{
			if(X2>xmax)
				strcpy(Bit2,"1010");
			else if(X1<xmin)
				strcpy(Bit2,"1001");
			else
				strcpy(Bit2,"1000");
		}
		else if(Y2<ymin)
		{
			if(X2>xmax)
				strcpy(Bit2,"0110");
			else if(X1<xmin)
				strcpy(Bit2,"0101");
			else
				strcpy(Bit2,"0100");
		}
		else
		{
			if(X2>xmax)
				strcpy(Bit2,"0010");
			else if(X1<xmin)
				strcpy(Bit2,"0001");
			else
			{	strcpy(Bit2,"0000");}
		}
			for(k=0;k<strlen(Bit1);k++) //testcase to see Bit1 And Bit2 
			{
			printf("%c",Bit1[k]);
			}
			printf("\n");
		
			for(k=0;k<strlen(Bit2);k++)
			{
			printf("%c",Bit2[k]);
			}
			printf("\n");
			
			for(k=strlen(Bit1);k>0;k--) //check points of two End point are the Line not pass the window
			{
				printf("%d\n",k); //I don't know when I didn't print k, program was bug???
			i=checkbit(Bit1,Bit2);
			if(i==1)
			{
				k=0;
			}
			}
			if((strcmp(Bit1,"0000")==0)&&(strcmp(Bit2,"0000")==0)) //Visible is only point in 0000
			printf("Visible\n");
			else if(i==1)	//Invisible is Bit1 And Bit2 !=0000
			printf("Invisible\n");
			else //othercase
			printf("Clipping Candidate\n");
			
		/*for(count1=strlen(Bit1),count2=strlen(Bit2);count1>0;count1--,count2--)	//Plus Bit1 And Bit2
		{
			test1[0]=Bit1[count1-1];
			test2[0]=Bit2[count2-1];
			if(strcmp(test1,test2)==0) //1+1 or 0+0
			{
				if(strcmp(test1,"1")==0) //1+1
				{
					if(i==0) //1+1+0
					{
						strcat(SumBit,"0");
						i=1;
					}
					else	//1+1+1
					{
						strcat(SumBit,"1");
					}
				}
				else	//0+0 
				{
					if(i==0)	//0+0+0
					{
						strcat(SumBit,"0");
					}
					else		//0+0+1
					{
						strcat(SumBit,"1");
						i=0;
					}
				}
			}
			else	//0+1 or 1+0
			{
				if(i==0) //1+0+0
				{
					strcat(SumBit,"1");
				}
				else	//1+0+1
				{
					strcat(SumBit,"0");
					i=0;
				}
			}
		}
		swap(SumBit);
		if((strcmp(SumBit,"0000")==0)&&(i==0))  //SumBit has 4 Bit but some cases have 5bit, i=1when bit4 plus bit4 (ex.1000+1000=10000,but sumbit has 0000) 
		{
			printf("Visible\n");
		}
		else if((i==1)||(strcmp(SumBit,"1010")==0)||(strcmp(SumBit,"1110")==0)||(strcmp(SumBit,"0010")==0)
				||(strcmp(SumBit,"0110")==0)||(strcmp(SumBit,"1001")==0)||(strcmp(SumBit,"1011")==0)
				||(strcmp(SumBit,"1000")==0)||(strcmp(SumBit,"1100")==0)||(strcmp(SumBit,"0100")==0)
				)  //Total results of plus place line out of window
		{
			printf("Invisible\n");
		}
		else //other case
			printf("Clipping Candidate\n");*/
		/*if((X1<=xmax)&&(X2<=xmax)&&(X1>=xmin)&&(X2>=xmin)&&(Y1>=ymin)&&(Y2>=ymin)&&(Y1<=ymax)&&(Y2<=ymax)) //check point of two end points are in the area of window
			printf("Visible\n");
		else if(((Y1>ymax)&&(Y2>ymax))||((X1>xmax)&&(X2>xmax))||((X1<xmin)&&(X2<xmin))||((Y1<ymin)&&(Y2<ymin))) //check point of two end points are out the area of window
			printf("Invisible\n");
		else		//other
			printf("Clipping Candidate\n");*/
	printf("Do you want use program again?(Yes,No)\n"); //For loop
	scanf("%s",&Select);
	strlwr(Select);
	}
	while(strcmp(Select,"no")==1);
	printf("Thank of testing\n");
}