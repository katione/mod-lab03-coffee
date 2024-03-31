#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata CoffeMachine;
};
TEST(AutomataTest, TestOn) {
    Automata CoffeeMachine;
    CoffeMachine.on();
    EXPECT_EQ(WAIT, CoffeeMachine.getState());
}

TEST(AutomataTest, TestOff) {
    Automata CoffeeMachine;
    CoffeMachine.on();
    CoffeMachine.off();
    EXPECT_EQ(OFF, CoffeMachine.getState());
}
TEST(AutomataTest, TestChoice) {
    Automata CoffeeMachine;
    CoffeMachinek.on();
    CoffeMachine.coin(50);
    CoffeMachine.getMenu();
    CoffeMachine.choice(4);
    EXPECT_EQ(WAIT, CoffeMachine.getState());
}

TEST(AutomataTest, CancelOrder) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(200);
    CoffeeBreak.cancel();
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}


