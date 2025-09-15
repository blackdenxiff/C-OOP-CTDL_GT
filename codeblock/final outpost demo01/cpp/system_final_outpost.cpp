#include <C:\\Users\\AT\\Desktop\\codeblock\\final outpost demo01\\h\\system_final_outpost.h>
#include <iostream>
#include <cmath>

using namespace std;

void System::cannon_move() {
    sf::Vector2i mouseWindow = sf::Mouse::getPosition(Window);
    sf::Vector2f mouseWorld = Window.mapPixelToCoords(mouseWindow);

    for (int i = 0; i < 7; i++) {
        sf::Vector2f cannonPos = cannon_S[i].getPosition();
        float dx = mouseWorld.x - cannonPos.x;
        float dy = mouseWorld.y - cannonPos.y;
        float angle = atan2(dy, dx); // radian

        cannon_S[i].setRotation(sf::radians(angle));
    }
}







void System::Run_game(){
    window();
    texture_assets();

    while(Window.isOpen()){
        while(auto event = Window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                Window.close();
        }

        cannon_move();



        draw_main();
    }
}
