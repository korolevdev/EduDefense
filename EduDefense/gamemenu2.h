#ifndef GAMEMENU2_H
#define GAMEMENU2_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class GameMenu {
  public:
    GameMenu(String filename) : File(filename) {}
    GameMenu() {}
    hc state=empty;
    Sprite sprite_temp;
    Sprite sprite_tower;
    Sprite sprite_gui;

    Texture texture;
    void setImage(String filename) { image.loadFromFile(filename); }
    void setFilename(String filename) { File = filename; }
    void setHeight(int height) { HEIGHT_MENU = height; }
    void setWidth(int width) { WIDTH_MENU = width; }
    void textureWork() {
        image.loadFromFile(File); //загружаем файл для меню
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_temp.setTexture(texture); //заливаем текстуру спрайтом
    }

    void towersIconsWork(String filename) {
        image.loadFromFile(filename);
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_tower.setTexture(texture); //заливаем текстуру спрайтом
    }

    void statsIconsWork() {
        image.loadFromFile("images/GUI/stats1.png");
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_gui.setTexture(texture); //заливаем текстуру спрайтом
    }

    void playIconsWork() {
        image.loadFromFile("images/GUI/play.png");
        texture.loadFromImage(image); //заряжаем текстуру картинкой
        sprite_temp.setTexture(texture); //заливаем текстуру спрайтом
    }
Image image;
  private:

    int HEIGHT_MENU;
    int WIDTH_MENU;
    String File; //файл с картинками для создания текстуры
};
class UsualGameMenuBuilder : public GameMenuBuilder {
  public:
    UsualGameMenuBuilder(RenderWindow &window, String mapsname)
        : GameMenuBuilder(mapsname) {
        window2 = &window;
    }

    virtual void buildParams() {
        mymenu->setHeight(11);
        mymenu->setWidth(13);
    }

    virtual void buildTexture() {
        mymenu->textureWork();

        for (int i = 0; i < 500; i += 240) {
            mymenu->sprite_temp.setTextureRect(IntRect(0, 0, 240, 240));
            mymenu->sprite_temp.setPosition(780, i);
            window2->draw(mymenu->sprite_temp);
        }
        switch(mymenu->state){
        case empty:
            mymenu->towersIconsWork("images/GUI/towers.png");
            break;
        case tower1:
            mymenu->towersIconsWork("images/GUI/towers2.png");
            break;
        }



        mymenu->sprite_tower.setTextureRect(IntRect(0, 0, 100, 100));
        mymenu->sprite_tower.setPosition(792, 136);
        window2->draw(mymenu->sprite_tower);

        mymenu->sprite_tower.setTextureRect(IntRect(101, 0, 100, 100));
        mymenu->sprite_tower.setPosition(908, 136);
        window2->draw(mymenu->sprite_tower);

        mymenu->sprite_tower.setTextureRect(IntRect(203, 0, 100, 100));
        mymenu->sprite_tower.setPosition(792, 279);
        window2->draw(mymenu->sprite_tower);

        mymenu->sprite_tower.setTextureRect(IntRect(305, 0, 100, 100));
        mymenu->sprite_tower.setPosition(908, 279);
        window2->draw(mymenu->sprite_tower);

        mymenu->statsIconsWork(); //потом переделать под правильные спрайты

        mymenu->sprite_gui.setTextureRect(IntRect(0, 0, 35, 35));
        mymenu->sprite_gui.setPosition(786, 3);
        window2->draw(mymenu->sprite_gui);

        mymenu->sprite_gui.setTextureRect(IntRect(70, 0, 35, 35));
        mymenu->sprite_gui.setPosition(978, 3);
        window2->draw(mymenu->sprite_gui);

        mymenu->sprite_gui.setTextureRect(IntRect(36, 0, 35, 35));
        mymenu->sprite_gui.setPosition(786, 46);
        window2->draw(mymenu->sprite_gui);

        mymenu->sprite_temp.setTextureRect(IntRect(70, 0, 35, 35));
        mymenu->sprite_temp.setPosition(978, 46);
        window2->draw(mymenu->sprite_gui);

        mymenu->playIconsWork();

        mymenu->sprite_temp.setTextureRect(IntRect(0, 0, 221, 130));
        mymenu->sprite_temp.setPosition(790, 527);
        window2->draw(mymenu->sprite_temp);

        // window2->display(); // это вызывает мигания
    }

  private:
    RenderWindow *window2;
};
#endif // GAMEMENU2_H
