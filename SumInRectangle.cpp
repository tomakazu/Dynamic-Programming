#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,m;
	cin>>n>>m;
	int **rectangle = new int*[n];
	for(int i=0;i<n;i++){
		rectangle[i] = new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			cin>>rectangle[i][j];
		}
	}
	int Max = rectangle[0][0];
	int *dp = new int[n];
    for(int j=1;j<n;j++){
        Max = max(Max,rectangle[j][0]);
    }
	for(int left=0;left<n;left++){
		for(int i = 0;i<n;i++){
			dp[i] = rectangle[i][left];
        }
		for(int right = left+1;right<m;right++){
			int k=0;
			while(k<n){
				dp[k] += rectangle[k][right];
				k++;
			}
			int curr_sum = 0 ,ans = INT_MIN;
			for(int i=0;i<k;i++){
				curr_sum+=dp[i];
				if(curr_sum>ans){
					ans = curr_sum;
				}
				if(curr_sum<0){
					curr_sum = 0;
				}
				
			}
			if(ans>Max)
				Max = ans;	
		}
	}
	cout<<Max;
	return 0;
}
