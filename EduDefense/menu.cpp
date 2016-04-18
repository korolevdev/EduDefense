#include "menu.h"
#include <exceptions.h>
#include <gameview.h>
static const char *FONT = "fonts/9711.otf";
static const char *BG_IMG = "images/back.jpg";
static const char *MUSIC = "music/MenuMusic.ogg";

Menu::Menu(double width, double height) {
    if (!font.loadFromFile(FONT)) {
        throw(file_load_error());
    }
    menuItemsCount = 4;
    FontSize = 60;
    for (size_t i = 0; i < menuItemsCount; i++)
        menu[i].setCharacterSize(FontSize);

    menu[PLAY].setFont(font);
    menu[PLAY].setColor(sf::Color::Black);
    menu[PLAY].setString("   Play   ");
    menu[PLAY].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 1 + 85));

    menu[OPTIONS].setFont(font);
    menu[OPTIONS].setColor(sf::Color::White);
    menu[OPTIONS].setString("  Options  ");
    menu[OPTIONS].setPosition(sf::Vector2f(
        width / 2.75 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 2 + 85));

    menu[STATS].setFont(font);
    menu[STATS].setColor(sf::Color::White);
    menu[STATS].setString("Statistics");
    menu[STATS].setPosition(sf::Vector2f(
        width / 2.8 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 3 + 85));

    menu[QUIT].setFont(font);
    menu[QUIT].setColor(sf::Color::White);
    menu[QUIT].setString("   Exit   ");
    menu[QUIT].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 4 + 85));

    selectedItemIndex = PLAY;


    if (!texture.loadFromFile(BG_IMG)) {
        throw(file_load_error());
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile(MUSIC)) {
        throw(file_load_error());
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}

Menu::Menu() {}

Menu::~Menu() {}

void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Black);
    }
}

void Menu::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Black);
    }
}

MenuItem Menu::process(sf::RenderWindow &window, GameView &gameview) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    moveUp();
                    break;
                case sf::Keyboard::Down:
                    moveDown();
                    break;
                case sf::Keyboard::Return:
                    return (MenuItem)selectedItemIndex;
                default:
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        gameview.drawMainMenu(window, *this);
    }
    return QUIT;
}
LevelMenu::LevelMenu(double width, double height): Menu(width, height) {
    if (!font.loadFromFile(FONT)) {
        throw(file_load_error());
    }
    menuItemsCount = 4;
    FontSize = 60;
    for (size_t i = 0; i < menuItemsCount; i++)
        menu[i].setCharacterSize(FontSize);

    levelMenu[0].setFont(font);
    levelMenu[0].setColor(sf::Color::Red);
    levelMenu[0].setString("   level 1   ");
    levelMenu[0].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 1 + 85));

    levelMenu[1].setFont(font);
    levelMenu[1].setColor(sf::Color::White);
    levelMenu[1].setString("   level 2   ");
    levelMenu[1].setPosition(sf::Vector2f(
        width / 2.75 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 2 + 85));

    levelMenu[2].setFont(font);
    levelMenu[2].setColor(sf::Color::White);
    levelMenu[2].setString("   level 3   ");
    levelMenu[2].setPosition(sf::Vector2f(
        width / 2.8 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 3 + 85));

    levelMenu[3].setFont(font);
    levelMenu[3].setColor(sf::Color::White);
    levelMenu[3].setString("   level 4   ");
    levelMenu[3].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 4 + 85));

    levelMenu[4].setFont(font);
    levelMenu[4].setColor(sf::Color::White);
    levelMenu[4].setString("   level 5   ");
    levelMenu[4].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 5 + 85));

    selectedItemIndex = 0;

    if (!texture.loadFromFile(BG_IMG)) {
        throw(file_load_error());
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile(MUSIC)) {
        throw(file_load_error());
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}
