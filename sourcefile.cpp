#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool game[101][101];


int solution(int n, vector<vector<int>> results) {
  int answer = 0;
  for(int i=0;i<results.size();i++){
    game[results[i][0]][results[i][1]]=1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(game[j][i]==1){
        for(int k=1;k<=n;k++){
          if(game[i][k]==1) game[j][k]=1;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int w=0,l=0;
      if(game[i][j]==1) w++;
      if(game[j][i]==1) l++;
    }
    if((w+l)==(n-1)) answer++;
  }
  return answer;
}

int main(){
  int n=5;
  vector<vector<int>> test={{1,3},{3,2},{2,4},{4,5}};
  solution(5,test);
}