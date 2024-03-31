// Copyright 2024 katione
#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = {
    "Hot chocolate",
    "Espresso",
    "Americano",
    "Cappuchino",
    "Latte",
    "Raspberry tea",
    "Green tea"};
    prices = {150, 180, 185, 189, 210, 110, 100};
}
Automata::~Automata() {
}
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The machine is on" << std::endl;
    } else {
        std::cout << "The machine is already on" << std::endl;
    }
}
void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "The machine is off" << std::endl;
    } else {
        std::cout << "It is impossible to turn off the machine" << std::endl;
    }
}
void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ") " << menu[i]
                << " - " << prices[i] << ";" << std::endl;
        }
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        std::cout << "Deposited money" << cash << std::endl;
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(int choice) {
    if (state == ACCEPT) {
        if (choice < 1 || choice > menu.size()) {
            std::cout << "Invalid number" << std::endl;
        } else {
            state = CHECK;
            if (check(choice)) {
                cook(choice);
            }
        }
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
bool Automata::check(int choice) {
    if (cash >= prices[choice - 1]) {
        return true;
    }
    std::cout << "The amount deposited is not enough" << std::endl;
    state = ACCEPT;
    return false;
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash = 0;
        std::cout << "Cancel" << std::endl;
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
void Automata::cook(int choice) {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[choice - 1];
        std::cout << "Your drink is being prepared.Expect" << std::endl;
        finish(choice);
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
void Automata::finish(int choice) {
    if (state == COOK) {
        std::cout << "Change: " << cash << std::endl;
        std::cout << "Your drink is ready.Take it away" << std::endl;
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "The operation is impossible" << std::endl;
    }
}
