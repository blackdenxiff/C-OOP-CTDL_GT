#include <C:\\Users\\AT\\Desktop\\codeblock\\final outpost demo01\\h\\graphics_final_outpost.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Mouse.hpp>
void Graphics::window(){
    Window.create(sf::VideoMode({800, 600}), "final outpost demo");
}
void Graphics::texture_assets(){
    cannon_T.reserve(7);
    cannon_S.reserve(7);
    sf::Texture test_T;
    for(int i = 0; i < 7; i++){
        string namefile = "assets/9e6087a9d24c441cbedd06392a19b9558SVPi3jHAsTQizvm-"+ to_string(i) +".png";
        if(!test_T.loadFromFile(namefile)){
            cout <<"ko the load file: "<< namefile<< endl;
            continue;
        }
        cannon_T.push_back(move(test_T));

        sf::Sprite test_S(cannon_T.back());
        test_S.setPosition(sf::Vector2f(400, 400));
      //  test_S.setOrigin(sf::Vector2f(22.5f,22.5f));
        cannon_S.push_back(move(test_S));
    }
}

void Graphics::draw_main(){

    if(time_kt.getElapsedTime().asSeconds() > 0.5f){
        Window.clear();
        Window.draw(cannon_S[kt_cannon]);
        kt_cannon += 1; if(kt_cannon == 7)kt_cannon=0;
         Window.display();
    time_kt.restart();
    }
}






//
