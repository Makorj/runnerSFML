#include "View.h"
#include "Model.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

int main(){
  srand(time(NULL));

  Model model(SCREEN_WIDTH, SCREEN_HEIGHT);
  View view(SCREEN_WIDTH, SCREEN_HEIGHT);
  view.setModel(&model);

  while(view.treatEvents()){
    model.nextStep();
    view.synchronize();
    view.draw();
  }


  return EXIT_SUCCESS;
}
