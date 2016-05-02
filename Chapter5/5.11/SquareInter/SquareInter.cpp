#include <iostream>

using namespace std;

struct Interval{
  int begin,end;
};

struct Rectangle{
  Interval h_side, v_side;
};

Interval intervalIntersection(Interval a, Interval b){
  Interval result;
  if (a.begin > b.begin) swap(a,b);
  result.begin = b.begin;
  result.end = min(a.end, b.end);

  //result.end <= result.begin implies no intersection.
  return result;
}

bool HasIntersection(const Rectangle& A, const Rectangle& B, Rectangle& rectIntersection){
  rectIntersection.h_side = intervalIntersection(A.h_side,B.h_side);
  rectIntersection.v_side = intervalIntersection(A.v_side,B.v_side);
  if ( (rectIntersection.h_side.end - rectIntersection.h_side.begin <= 0)||(rectIntersection.v_side.end-rectIntersection.v_side.begin <= 0) ){
    return false;
  } else {
    return true;
  }
}  

int main(){
  Rectangle A, B, C;
  A.h_side.begin = 1, A.h_side.end = 10, A.v_side.begin = 1, A.v_side.end = 15;
  B.h_side.begin = 11, B.h_side.end = 15, B.v_side.begin =10, B.v_side.end = 20;
  
  if (HasIntersection(A,B,C)) {
    cout<<C.h_side.begin<<" "<<C.h_side.end<<" "<<C.v_side.begin<<" "<<C.v_side.end<<endl;
  }else{
    cout<<"No intersection."<<endl;
  }
}
