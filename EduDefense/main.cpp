#include "menu.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <game.h>

int main() {
    //sf::RenderWindow window(sf::VideoMode(1024, 768), "Edu Defense");
    //Menu menu(window.getSize().x, window.getSize().y);
    Game TheGame(1024, 768);
    TheGame.run();
    return 0;
}
