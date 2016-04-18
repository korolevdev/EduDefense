#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <statemanger.h>
class GameView {
    // GameView(std::shared_ptr<StateManager>& temp);
    // std::shared_ptr<StateManager> m_statemanager;
  public:
    void drawMainMenu(sf::RenderWindow &windo, const Menu &menu);
    void drawMap();
    void drawLevelChoose();
    void drawSettings();
    void drawStats();
};
/*
enum state{
    MenuMain,
    Levelchoose,
    LevelRun,
    Options,
    Stats,
    Quit
};
*/
#endif // GAMEVIEW_H