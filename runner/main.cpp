#include "View.h"
#include "Model.h"
#include "iostream"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

int main(){
  srand(time(NULL));

  Model model(SCREEN_WIDTH, SCREEN_HEIGHT);
  View view(SCREEN_WIDTH, SCREEN_HEIGHT);

  std::vector<int> vect{10,5,8};
  for(auto i=vect.begin();i<vect.end();++i)
  {
      if(*i==5)
          vect.erase(i);
      else
          std::cout << *i << std::endl;
  }

  view.setModel(&model);

  while(view.treatEvents()){
    model.nextStep();
    view.synchronize();
    view.draw();
  }


  return EXIT_SUCCESS;
}
