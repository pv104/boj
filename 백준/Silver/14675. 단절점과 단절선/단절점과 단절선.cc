#include<iostream>
using namespace std;int a[100001];int main(){int N,A,B;cin.tie(0);cin.sync_with_stdio(0);cin>>N;while(--N){cin>>A>>B;++a[A];++a[B];}cin>>N;while(N--){cin>>A>>B;(A==1&&a[B]==1)?cout<<"no":cout<<"yes";cout<<"\n";}}