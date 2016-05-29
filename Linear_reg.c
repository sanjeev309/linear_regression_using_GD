/*-----------------Linear Regression using gradient descent In C!--------------------*/
/*     SANJEEV     */


#include <stdio.h>
#include <string.h>
#include <conio.h>


 float theta[]={1.0,1.0};                   //Fitting parameters
 float x[50],y[50],err[50];                 //Data arrays
 float n,sumerr0,sumerr1,sumsqerr;                   //Useful variables
 float alpha=0.1;                                  //Adjust learning rate alpha here

 void grad_descent();
 void cost();
 float costfunction();                      
 float resolver(float);

void main(){
    
	float tempx=0,tempy=0;
	float data;
	int i,ch,epoch=0;
	float cost_prev=10000000,cost_now;                           // Starting up with an arbitirarily high cost 
	printf("Enter the number of training Samples:");
	scanf("%f",&n);
	
	for(i=0;i<n;i++)
	{  printf("Enter data %d:",i+1);
	    scanf("%f %f",&tempx,&tempy);
		x[i]=tempx;
		y[i]=tempy;
	}

	printf("\n\n\n\n\n \tTraining the Machine!");

	cost_now=costfunction();
	while(cost_now< cost_prev){
		cost_prev=cost_now;
		grad_descent();
		cost_now=costfunction();
		printf("cost: %f   t0: %f   t1: %f \n",cost_now,theta[0],theta[1]);
		epoch++;
	}

	printf("\n System Trained after %d iterations",epoch);
	printf("\n Enter Input to perform regression:");
	
	while(getch()){
	scanf("%f",&tempx);                  //Re-using variables
	tempy=resolver(tempx);
	printf("     %f",tempy);
	}
}


void cost(){
	int i;
	for(i=0;i<n;i++){
	err[i]=resolver(x[i]) - y[i];
	}
}

void grad_descent(){
theta[0]=theta[0] - ((alpha/n)*sumerr0);
theta[1]=theta[1] - ((alpha/n)*sumerr1);
}

float costfunction(){
	int i; 
	sumsqerr=0,sumerr0=0,sumerr1=0;
	 cost();                            //Calling Cost to calculate error between expected and obtained output
     	for(i=0;i<(int)n;i++){
			sumsqerr+=(err[i]*err[i]);
			sumerr0+=  err[i];
			sumerr1+= (err[i]*x[i]);
			}
	sumsqerr=sumsqerr/(2*n);
	return sumsqerr;
}


float resolver(float data){
return (theta[0] + data*theta[1]);
}
