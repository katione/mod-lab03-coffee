// Copyright 2024 katione
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
    CoffeMachine.coin(150);
    CoffeMachine.getMenu();
    CoffeMachine.choice(1);
    EXPECT_EQ(WAIT, CoffeMachine.getState());
}

TEST(AutomataTest, TestCancel) {
    Automata CoffeMachine;
    CoffeMachine.on();
    CoffeMachine.coin(200);
    CoffeMachine.cancel();
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}
TEST(AutomataTest, TestInvalidNumber) {
    Automata CoffeMachine;
    CoffeMachine.on();
    CoffeMachine.coin(50);
    CoffeMachine.choice(8);
    EXPECT_EQ(ACCEPT, CoffeMachine.getState());
}

TEST(AutomataTest, TestNoMoney) {
    Automata CoffeMachine;
    CoffeMachine.on();
    CoffeMachine.choice(3);
    EXPECT_EQ(WAIT, CoffeMachine.getState());
}
TEST(AutomataTest, TestTwoCycles) {
    Automata CoffeMachine;
    CoffeMachine.on();
    CoffeMachine.coin(200);
    CoffeMachine.coin(20);
    CoffeMachine.coin(30);
    CoffeMachine.choice(1);
    CoffeMachine.coin(0);
    CoffeMachine.choice(8);
    EXPECT_EQ(ACCEPT, CoffeMachine.getState());
}


