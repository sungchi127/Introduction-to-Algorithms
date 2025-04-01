#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

void mul(int A[2][2], int B[2][2], int C[2][2]) {
    static int tmp[2][2];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                tmp[i][j] += A[i][k] * B[k][j] % mod;
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            C[i][j] = tmp[i][j] % mod;
        }
    }
}

void mul1(int a[2][2],int b[2],int c[2])
{
    static int tmp[2];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            tmp[i]+=a[i][j]*b[j] % mod;
        }
    for(int i=0;i<2;i++)
    {
        c[i]=tmp[i] % mod;
    }
}

int m[64][2][2],c[2],f[2][2];
int a,b,n,ans,x;

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>a>>b>>n; b = (b % mod + mod) % mod;
    m[0][0][0]=a,m[0][0][1]=1,m[0][1][0]=0,m[0][1][1]=1;
    for(int i = 1 ;i < 64 ; i++ )
    {
        mul(m[i-1],m[i-1],m[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin>>x;
        x-=1;
        c[0]=1,c[1]=b;
        for(int j=0;j<64;j++)
        {
            if(x % 2 == 1)
            {
                // for(int q=0;q<2;q++)
                // {
                //     for(int k=0;k<2;k++)
                //         cout<<m[j][q][k]<<" ";
                //     cout<<endl;
                // }
                // cout<<endl;
                mul1(m[j],c,c);
            }
            x/=2;
        }
        // for(int i = 0; i < 2; i++){
        //     for(int j = 0; j < 2; j++){
        //     cout<<c[i]<<" ";
        // }
        cout<<c[0];
        cout<<"\n";
    }
    return 0;
}