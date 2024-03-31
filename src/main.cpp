#include <iostream>
#include "Automata.h"

int main() {
  Automata CoffeMachine
  CoffeMachine.on();
  CoffeMachine.getMenu();
  CoffeMachine.coin(100);
  CoffeMachine.choice(8);
  std::cout << std::endl;

  std::cout << std::endl;
  CoffeMachine.coin(100);
  CoffeMachine.choice(7);
  CoffeMachine.coin(25);
  CoffeMachine.choice(7);

  std::cout << std::endl;
  CoffeMachine.cancel();
  std::cout << CoffeeMachine.getState() << std::endl;
  CoffeMachine.off();
  return 0;
}
