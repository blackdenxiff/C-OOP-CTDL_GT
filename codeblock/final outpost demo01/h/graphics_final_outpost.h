#ifndef GRAPHICS_FINAL_OUTPOST_H
#define GRAPHICS_FINAL_OUTPOST_H
#include "iostream"
#include <cmath>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Mouse.hpp>


using namespace std;

class Graphics{
    private:
    public:
        sf::RenderWindow Window;//(800, 600);

        vector<sf::Texture> cannon_T;// S = tong
        vector<sf::Sprite> cannon_S;
        int kt_cannon = 0;

        sf::Clock time_kt;

            void window();
            void texture_assets();




                void draw_main();

};
#endif // GRAPHICS_FINAL_OUTPOST_H
