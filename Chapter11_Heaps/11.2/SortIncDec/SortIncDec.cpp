#include <queue>
#include <vector>
#include <cassert>
#include <iostream>
#include <cstdint>

using namespace std;

enum MONOTONICITY {INC, CONST, DEC};

struct MonoInterval{
public:
  int32_t begin;
  int32_t end;
  MONOTONICITY mono;
};

MONOTONICITY getMono(const vector<int32_t>& inpVec, const int32_t& index){
  assert(index < inpVec.size() - 1);
  if (inpVec[index] < inpVec[index + 1]) return INC;
  else if (inpVec[index] == inpVec[index + 1]) return CONST;
  else return DEC;
}

void SortIncDec(const vector<int32_t>& inpVec, vector<int32_t>& resultVec){
  resultVec.clear();
  if (inpVec.empty()) return;
  //Convert input into monotone intervals.
  vector<MonoInterval> intervals;
  int32_t newIntervalBegin = 0;
  while (newIntervalBegin < inpVec.size()){
    MonoInterval interval;
    interval.begin = newIntervalBegin;
    //Check if at the end of input.
    if (interval.begin == inpVec.size() - 1){
      interval.end = interval.begin;
      interval.mono = INC;
      intervals.push_back(interval);
      break;
    } else {
      //Determine monotonicity.
      interval.end++;
      interval.mono = getMono(inpVec,interval.begin);
    }
    //Find the full range of each monotone interval.
    while (interval.end < inpVec.size() - 1){
      //Get monotonicity at the end of interval.
      MONOTONICITY localMono = getMono(inpVec,interval.end);
      //Check if monotonicity has changed. If yes, start a new interval, else, extend interval end.
      bool sameMonotonicity = true;
      if (interval.mono == CONST) interval.mono = localMono;
      else if (localMono != CONST && localMono != interval.mono) sameMonotonicity = false;//Note interval.mono is not CONST either.

      if (sameMonotonicity) interval.end++;
      else {
	//Monotonicity changed. Save current interval to break to start a new interval. 
	intervals.push_back(interval);
	newIntervalBegin = interval.end + 1;
	break;
      }      
    }//end of current interval
    //Insert the last interval.
    if (interval.end == inpVec.size() - 1){
      if (interval.mono == CONST) interval.mono = INC;
      intervals.push_back(interval);      
      newIntervalBegin = inpVec.size();//This will end the while loop.
    }
  }//end of all intervals

  //test intervals
  for (int i = 0; i < intervals.size(); i++){
    cout<<"begin:"<<intervals[i].begin<<" end:"<<intervals[i].end<<endl;
    for (int j = intervals[i].begin; j <= intervals[i].end; j++){
      cout<<inpVec[j]<<" ";
    }
    cout<<endl;
  }

  //Create heap using monotone intervals.

  //Merge sort and output.
  /*
    Since heap nodes (intervals) are indices rather than real data, for comparison,
    we will need the input data. Thus, we may have to use customized heap instead
    of priority_queue.
    This implementation is better in resource usage, but will incur a lot of additional
    coding. I will stop here. It will be much easier to use vector of vectors.
   */
}

int main(){
  vector<int32_t> inputs = {1,4,4,7,6,4,4,2,2,3,4,5,6,7,6};
  vector<int32_t> results;
  SortIncDec(inputs,results);
}
