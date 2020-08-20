// Problem name: THRBL - Catapult that ball
// Problem statement @: https://www.spoj.com/problems/THRBL/

#include <bits/stdc++.h>
using namespace std;
# define ll  long long  int
# define ld  long double
#define fin0(i,a,b,c) for(int i=a;i<b;i+=c)
#define fin1(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fde0(i,a,b,c) for(int i=a;i>b;i-=c)
#define fde1(i,a,b,c) for(int i=a;i>=b;i-=c)
#define vi vector<int>
#define vll vector<ll>
#define vboo vector<bool>
#define all(a) a.begin(),a.end()
# define pb push_back
# define pp pop_back
# define ff first
# define ss second
# define mp make_pair
# define ac accumulate
# define mod 1000000007
# define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define t     \
    int t;    \
    cin >> t; \
    while (t--)
# define trace1(x)                cerr << #x << ": " << x << "\n";
# define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
# define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
# define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
const ll INF= 1e18;
const int MAX= 25;
void create_sparsetable(long long int st[][MAX],long long int arr[],int n,int k){
    fin0(i,0,n,1){
        st[i][0]= arr[i];
    }
    for(int j=1;j<=k;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            st[i][j]= max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

bool return_min(int l,int r, long long int st[][MAX],int n,int k,long long int arr[]){
   int range= log2(r-l+1);
   long long int max_height= max(st[l][range],st[r-(1<<range)+1][range]);
//   auto x= arr.find(a);
   if( max_height <= arr[l] )
    return true;
   return false;
}

int main(){
  IOS;
  int n,m;
  cin>>n>>m;
  long long int arr[n];

  fin0(i,0,n,1){
     cin>>arr[i];
  }
  int k= (int)log2(n);
  long long int sparse_table[n][MAX];
  create_sparsetable(sparse_table,arr,n,k);
  int count_cat=0;
  while(m--){
    long long int a,b;
    cin>>a>>b;
    --a;
    b -= 2;
    if(return_min(a,b,sparse_table,n,k,arr))
         count_cat++;

  }
  cout<<count_cat;
  return 0;
}
