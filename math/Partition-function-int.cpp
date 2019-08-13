/*how many ways of integer partition
  ==
  how many ways is that unlabeled n is divided into less than or equal to m groups
  n個以下の区別できない品物を,m個以下に分割する方法の総数

  ! if you use MODint as T, you can get AC.
  ! もし,int型ではなく,MODint使っても正しく解答が得られます.（それはそう）
  intでよろ

  解説
　分割方法の総数を求めるのは,分割数と形が一緒なので分割数(Partition function)と同じ議論でok

  regulation
  1 <= m <= n <= 1000

  参考
  蟻本P66

  validation
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=jp
*/
//T == int
template<typename T>
vector<vector<T>> get_partition(int n, int m){
 
    vector<vector<T>> dp(n + 1, vector<T>(m + 1));
 
    dp[0][0] = 1;
    for(int i = 0; i <= n; ++i){
      for(int j = 1; j <= m; ++j){

        if(i-j >= 0) dp[i][j] = (dp[i][j-1] + dp[i-j][j])%MOD;
        else         dp[i][j] = dp[i][j-1];

      }
    }
    return dp;
}
//nのm分割==iのj分割
/*
int main() {
  int n, m;
  cin >> n >> m;
  cout << get_partition< int >(n, m)[n][m] << endl;
}
*/