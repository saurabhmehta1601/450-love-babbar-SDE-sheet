// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

//You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time. 

#include "bits/stdc++.h"
using namespace std ;

// returns number of activities 
int solution(vector<pair<int,int>> intervals){
  int n = intervals.size() ;
  if( n == 0) return 0 ;

  int i = 0 , j  ;
  int ans = 1 ;

  for(int j = 1 ; j < n ; j++ ){
    if(intervals[j].first >= intervals[i].second){
      ans++ ;
      i = j ;
    }
  }
return ans ;
}


bool compare(pair<int , int >  a , pair<int , int >  b){
  return a.second < b.second ;
}

int main(){
  int n ;
  cin >> n ;
  int start[n] , end[n] ;
  for(int i =0 ; i< n; i++) { cin >> start[i] ;}
  for(int i =0 ; i< n; i++) { cin >> end[i] ;}

  vector<pair<int, int>> intervals  ;
  for(int i = 0 ; i < n ; i++){
    intervals.push_back({start[i] , end[i]}) ;
  }

  sort(intervals.begin(), intervals.end() , compare);

  cout<<solution(intervals)<<endl ;

  return 0 ;
}
