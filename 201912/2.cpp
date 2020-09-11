#include<stdio.h>
int main()
{
	long long int a[1000][2];
	int b[1000]={0},c[5]={0};
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld%lld",&a[i][0],&a[i][1]);//数组的值为坐标 
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i][0]==a[j][0]&&a[i][1]==a[j][1]+1)||(a[i][0]==a[j][0]&&a[i][1]==a[j][1]-1)||	(a[i][0]==a[j][0]-1&&a[i][1]==a[j][1])||(a[i][0]==a[j][0]+1&&a[i][1]==a[j][1]))
			{
				b[i]++;
				b[j]++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		int count=0;//对角线上有几个 
		if(b[i]==4)
		{
			for(j=0;j<n;j++)
			{
				if((a[i][0]==a[j][0]+1&&a[i][1]==a[j][1]+1)||(a[i][0]==a[j][0]+1&&a[i][1]==a[j][1]-1)||
				(a[i][0]==a[j][0]-1&&a[i][1]==a[j][1]+1)||(a[i][0]==a[j][0]-1&&a[i][1]==a[j][1]-1))
					count++;
			}
			c[count]++;
		} 
	}
	for(i=0;i<=4;i++)
		printf("%d\n",c[i]);
	return 0;
}
