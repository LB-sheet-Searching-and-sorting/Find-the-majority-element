//A majority element is one which occurs more than half of the array size
//I am using Moore's voting algo here

#include<stdio.h>

//possible majority element nikalega ye function.
int findCandidate(int a[],int n)
{
	int majority_index=0,count=1,i;  //count is used as marker
	
	//yaha majority element first element ko maan liya and second se start karre
	//isse count karne me aasani hoti hai in case elements non-contiguous locations par hai to
	for(i=1;i<n;i++)
	{
		if(a[i]==a[majority_index])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			majority_index=i;
			count=1; //reseting the count	
		}
	}
	return a[majority_index];//returning our candidate
}

//checks if the candidate is the majority element
//returns 1 if it gets majority element
int isMajority(int a[],int n, int candidate)
{
	int i,count=0; //yaha count count hi karra hai
	
	for(i=0;i<n;i++)
	{
		if(a[i]==candidate)
		{
			count++;
		}
	}
	if(count>n/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//returns majority element
void majority(int a[],int n)
{
	int candidate=findCandidate(a,n);
	int result=isMajority(a,n,candidate);
	
	if(result==1)
	{
		printf("\nThe majority element is => %d",candidate);
	}
	else
	{
		printf("\nThere is no majority element.");
	}
}

int main()
{
	int a[100],i,n;
	
	printf("\t\t\nHow many elements do you want? => ");
	scanf("%d",&n);
	printf("\t\nPlz start filling your elements one by one.");

	//feeding the array
	for(i=0;i<n;i++)
	{
		printf("\n\nElement no %d ",i+1);
		scanf("%d",&a[i]);
	}
	
	//calling our function
	 majority(a,n);
	
return 0;
}
