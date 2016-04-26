#include <iostream>
#include <vector>

using namespace std;

typedef enum {BLACK,WHITE,RED} Color;

void DutchFlags(vector<Color> &flags, Color equal){
  //Every element before 'less' is BLACK
  //Every element after 'greater' is RED
  int less = -1, greater = flags.size();
  int currentIndex = 0;
  while (currentIndex < greater) {
    switch (flags.at(currentIndex)) {
	//If current element is BLACK, move it to left and inc 'less' and 'currentIndex'.
      case BLACK:
	less++;
	flags.at(less) = BLACK;
	currentIndex += 1;
	break;
	//If current element is WHITE, just ignore it and inc 'currentIndex'.
      case WHITE:
	currentIndex += 1;
	break;
	//If current element is RED, swap it with 'greater', dec 'greater', but keep 'currentIndex' the same.
      case RED:
	greater--;
	swap(flags.at(currentIndex),flags.at(greater));
	break;
    }
  }
  //Elements between 'less' and 'greater' should be WHITE.
  for (int i=less+1; i<greater; i++) flags.at(i) = WHITE;
}

int main(){
  vector<Color> flags = {BLACK,WHITE,RED,BLACK,WHITE,RED,BLACK,BLACK,RED};
  DutchFlags(flags, WHITE);
  for (int i=0; i<flags.size(); i++) {
    cout<<flags.at(i);
  }
  cout<<endl;
}
