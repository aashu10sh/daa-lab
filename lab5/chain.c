#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 10
#define INF INT_MAX
int main()
{
	int i, j, k,l;
	int p[MAX],m[MAX][MAX];
	int n,q;
	printf("enter the number of matrices: ");
	scanf("%d",&n);
	printf("enter the dimensions of the matrices: \n");
	for(i=0;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(i=1;i<=n;i++){
		m[i][i] = 0;
	}
	for(l =2; l<=n;l++){
		for(i =1; i<=n-l+1;i++){
			j=i+l-1;
			m[i][j] = INF;
			for(k=i;k<=j-1;k++){
				q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j] = q;
				}
			}
		}
	}
	printf("Minimum number of multiplications: %d\n", m[1][n]);
	getch();
	return 0;
}