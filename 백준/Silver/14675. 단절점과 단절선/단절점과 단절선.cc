#include<iostream>
using namespace std;int arr[100001];int main(){int N,A,B;cin.tie(0);cin.sync_with_stdio(0);cin>>N;while(--N){cin>>A>>B;++arr[A];++arr[B];}cin>>N;while(N--){cin>>A>>B;if(A==1&&arr[B]==1){cout<<"no"<<"\n";continue;}cout<<"yes"<<"\n";}}