#include "menu.h"
#include <exceptions.h>
#include <gameview.h>
static const char *FONT = "fonts/9711.otf";
static const char *BG_IMG = "images/back.jpg";
static const char *MUSIC = "music/MenuMusic.ogg";

Menu::Menu(double width, double height) {
    if (!font.loadFromFile(FONT)) {
        throw(fileLoadError());
    }
    menuItemsCount = 4;
    FontSize = 60;
    for (size_t i = 0; i < menuItemsCount; i++) {
        menu[i].setCharacterSize(FontSize);
        menu[i].setFont(font);
    }

    menu[PLAY].setFont(font);
    menu[PLAY].setColor(sf::Color::White);

    menu[PLAY].setString("   Play   ");
    menu[PLAY].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 1 + 85));

    menu[OPTIONS].setColor(sf::Color::White);
    menu[OPTIONS].setString("  Options  ");
    menu[OPTIONS].setPosition(sf::Vector2f(
        width / 2.75 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 2 + 85));

    menu[STATS].setColor(sf::Color::White);
    menu[STATS].setString("Statistics");
    menu[STATS].setPosition(sf::Vector2f(
        width / 2.8 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 3 + 85));

    menu[QUIT].setColor(sf::Color::White);
    menu[QUIT].setString("   Exit   ");
    menu[QUIT].setPosition(sf::Vector2f(
        width / 2.6 + 10, height / (MAX_NUMBER_OF_ITEMS + 5) * 4 + 85));

    selectedItemIndex = -1;

    if (!texture.loadFromFile(BG_IMG)) {
        throw(fileLoadError());
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile(MUSIC)) {
        throw(fileLoadError());
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}

Menu::Menu() {}

Menu::~Menu() {}

void Menu::moveUp(sf::Text *menu1) {
    if (selectedItemIndex - 1 >= 0) {
        menu1[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu1[selectedItemIndex].setColor(sf::Color::Black);
    }
}

void Menu::moveDown(sf::Text *menu1, int max_number) {
    if (selectedItemIndex + 1 < max_number) {
        menu1[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu1[selectedItemIndex].setColor(sf::Color::Black);
    }
}

void Menu::setselectedItemIndex(sf::Text *menu1, int index_num,
                                int max_number) {
    if (index_num > -1 and index_num <= max_number) {
        if (selectedItemIndex > -1)
            menu1[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex = index_num;
        menu1[selectedItemIndex].setColor(sf::Color::Black);
    }
}
void Menu::clearselectedItemIdex(sf::Text *menu1, int index_num,
                                 int max_number) {
    if (selectedItemIndex > -1 and selectedItemIndex <= max_number) {
        menu1[selectedItemIndex].setColor(sf::Color::White);
    }
}

LevelMenu::LevelMenu(double width, double height) : Menu(width, height) {
    if (!font.loadFromFile(FONT)) {
        throw(fileLoadError());
    }
    menuItemsCount = 6; // 5 пунктов + кнопочка назад
    FontSize = 60;
    for (size_t i = 0; i < menuItemsCount; i++) {
        levelMenu[i].setCharacterSize(FontSize);
        levelMenu[i].setFont(font);
    }

    levelMenu[0].setColor(sf::Color::White);
    levelMenu[0].setString("   Level 1   ");
    levelMenu[0].setPosition(sf::Vector2f(
        width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 5) * 1 + 85));

    levelMenu[1].setColor(sf::Color::White);
    levelMenu[1].setString("   Level 2   ");
    levelMenu[1].setPosition(sf::Vector2f(
        width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 5) * 2 + 85));

    levelMenu[2].setColor(sf::Color::White);
    levelMenu[2].setString("   Level 3   ");
    levelMenu[2].setPosition(sf::Vector2f(
        width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 5) * 3 + 85));

    levelMenu[3].setColor(sf::Color::White);
    levelMenu[3].setString("   Level 4   ");
    levelMenu[3].setPosition(sf::Vector2f(
        width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 5) * 4 + 85));

    levelMenu[4].setColor(sf::Color::White);
    levelMenu[4].setString("   Level 5   ");
    levelMenu[4].setPosition(sf::Vector2f(
        width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 5) * 5 + 85));
    //кнопочка назад

    levelMenu[5].setColor(sf::Color::White);
    levelMenu[5].setString(" < Back ");
    levelMenu[5].setPosition(sf::Vector2f(10, 20));

    selectedItemIndex = -1;

    if (!texture.loadFromFile(BG_IMG)) {
        throw(fileLoadError());
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile(MUSIC)) {
        throw(fileLoadError());
    }
    sound.stop();
    // sound.setBuffer(buffer);
    // sound.play();
    // sound.setLoop(true);
}
int LevelMenu::process(sf::RenderWindow &window, GameView &gameview) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    moveUp(levelMenu);
                    break;
                case sf::Keyboard::Down:
                    moveDown(levelMenu, MAX_NUMBER_OF_LEVEL_ITEMS);
                    break;
                case sf::Keyboard::Return:
                    return selectedItemIndex;
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
        // gameview.drawLevelChoose(window, *this);
        gameview.drawLevelChoose(*this);
    }
    return 0;
}
