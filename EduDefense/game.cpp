#include "map.h"
#include <game.h>
#include <iostream>
using namespace std;
Game::Game(size_t width, size_t height)
    : window(sf::VideoMode(width, height), GAME_TITLE), window_width(width),
      window_height(height), menu(width, height), m_Exit(false) {}

void Game::run() {
    while (window.isOpen() && !m_Exit) {
        sf::Event event;
       /* switch (event.type) {
        case sf::Event::Closed:
            window.close();
        }*/
        switch (menu.process(window)) {
        case PLAY: {
            window.clear();
            Waiter waiter;
            UsualMapBuilder umap(window, "maps/map.png");
            waiter.SetMapBuilder(&umap);
            waiter.ConstructPizza();
            break;
        }
        case OPTIONS:
            cout << "OPTIONS";
            break;
        case STATS:
            cout << "STATS";
            break;
        case QUIT:
            cout << "QUIT";
            return;
        default:
            cout << "This should not happen";
            break;
        }
    }
}