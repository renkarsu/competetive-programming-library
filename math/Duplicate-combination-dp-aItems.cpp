/*
n種類の品物があり、i番目の品物はa[i]個ある。異なる種類は区別できる。
これらの中からm個選ぶ組み合わせの総数は？

蟻本p67
*/
vector<vector<int>> get_nHm(){
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
 
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j-1-a[i] >= 0){
                dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+MOD)%MOD;
            }
            else{
                dp[i+1][j] = (dp[i+1][j-1]+dp[i][j])%MOD;
            }
        }
    }
    return dp;
}

//a[i]はi番目の品物の個数
/*
int n,m;

int main(){
cin >> n >> m;
cout << get(n,m) << endl;
}
*/
//https://atcoder.jp/contests/abc021/submissions/6877827
