#include <iostream>
#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace std;

typedef struct{
    int x;
    int y;
}coordinate;

class Graphics{
    private:
        int window_width_x = 410;
        int window_height_y = 648;

    public:
        sf::Clock   moveClock;// bộ đếm thời gian;
        random_device rd;

        int kt = 0; // tam thooi lay gia tri
        int kt_make_Shape = 1;
        int total_array = 0;
        int kt_collision_left = 0;
        int kt_collision_left1 = 0;
        int kt_collision_right = 0;
        int kt_collision_shape = 0;
        float falling = 0;


        sf::RenderWindow Window;

        sf::RectangleShape Shape;
        vector<coordinate> coordinate_Shape;

        sf::RectangleShape Shape_main;
        vector<coordinate> coordinate_Shape_main;


        void window();
        void hinh();
        void draw_frame();
        int kt_frame();
        void main_draw();
        void shape();
        void shape_main();
        void random_kt();

        void make_shape();

};

class System : public Graphics{ //
    public:
        void falling_object();
        int object_touches_the_ground();
        int collision_shape();
        int straight_line();
        void save_position();
        void function_system_main();
};

void Graphics::window(){
   Window.create(sf::VideoMode({window_width_x, window_height_y}), "puzzle_game");
   Window.setFramerateLimit(60);
}

void Graphics::draw_frame(){
    sf::RectangleShape frame(sf::Vector2f(10.f, 640.f));
    sf::RectangleShape frame_down(sf::Vector2f(410.f, 8.f));
    frame.setFillColor(sf::Color::Red);
    frame_down.setFillColor(sf::Color::Blue);

    frame.setPosition(sf::Vector2f(0.f, 0.f));
    Window.draw(frame);

    frame.setPosition(sf::Vector2f(400.f, 0.f));
    Window.draw(frame);

    frame_down.setPosition(sf::Vector2f(0.f, 640.f));
    Window.draw(frame_down);
}

void Graphics::shape(){
    Shape.setSize(sf::Vector2f(30.f, 30.f));
    coordinate_Shape.resize(4);
    coordinate_Shape[0] = {160, 0};
    Shape.setFillColor(sf::Color::Green);
    Shape.setPosition(sf::Vector2f(coordinate_Shape[0].x, coordinate_Shape[0].y));
}

void Graphics::shape_main(){
    Shape_main.setSize(sf::Vector2f(30.f, 30.f));
    Shape_main.setFillColor(sf::Color::Cyan);
}

void Graphics::random_kt(){
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(1, 5);
    kt = dis(gen);
}

void Graphics::make_shape(){
   // if(kt == 0){return;)
   int i = 0;
    if(moveClock.getElapsedTime().asSeconds() > 0.15f){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
                if(kt_make_Shape == 4){kt_make_Shape = 0;}
                kt_make_Shape += 1;
                moveClock.restart();
                i = 1;
            }

    }


    if(kt == 1){// cylindrical shape;
        if(coordinate_Shape[0].x < 70 || coordinate_Shape[0].x > 340)
             kt_make_Shape = 1;

        if(kt_make_Shape%2 != 0){
            for(int i = 0; i < 3; i++){
                coordinate_Shape[i + 1].y = coordinate_Shape[i].y - 30;
                coordinate_Shape[i + 1].x = coordinate_Shape[i].x;
            }
        }
        else {
            for(int i = 0; i < 3; i++){
                coordinate_Shape[i + 1].y = coordinate_Shape[i].y;
                coordinate_Shape[i + 1].x = coordinate_Shape[i].x - 30;
            }
            coordinate_Shape[3].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[3].y = coordinate_Shape[0].y;
        }
    }
    else if(kt == 2){//square shape;
        coordinate_Shape[1].x = coordinate_Shape[0].x + 30;
        coordinate_Shape[1].y = coordinate_Shape[0].y;
        coordinate_Shape[2].x = coordinate_Shape[1].x;
        coordinate_Shape[2].y = coordinate_Shape[1].y - 30;
        coordinate_Shape[3].x = coordinate_Shape[0].x;
        coordinate_Shape[3].y = coordinate_Shape[0].y - 30;
    }
    else if(kt == 3){//triangluar;
        if((coordinate_Shape[0].x < 40 || coordinate_Shape[0].x > 340)&& i == 1){
            if(kt_make_Shape == 1){
                kt_make_Shape = 4;
            }
            else{
                kt_make_Shape -= 1;
            }
        }
        if(kt_make_Shape == 1){
            coordinate_Shape[1].x = coordinate_Shape[0].x;
            coordinate_Shape[1].y = coordinate_Shape[0].y + 30;
            coordinate_Shape[2].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[2].y = coordinate_Shape[0].y;
            coordinate_Shape[3].x = coordinate_Shape[0].x;
            coordinate_Shape[3].y = coordinate_Shape[0].y - 30;
        }
        else if(kt_make_Shape == 2){
            coordinate_Shape[1].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[1].y = coordinate_Shape[0].y;
            coordinate_Shape[2].x = coordinate_Shape[0].x;
            coordinate_Shape[2].y = coordinate_Shape[0].y - 30;
            coordinate_Shape[3].x = coordinate_Shape[0].x - 30;
            coordinate_Shape[3].y = coordinate_Shape[0].y;
            }
        else if(kt_make_Shape == 3){
            coordinate_Shape[1].x = coordinate_Shape[0].x;
            coordinate_Shape[1].y = coordinate_Shape[0].y - 30;
            coordinate_Shape[2].x = coordinate_Shape[0].x - 30;
            coordinate_Shape[2].y = coordinate_Shape[0].y;
            coordinate_Shape[3].x = coordinate_Shape[0].x;
            coordinate_Shape[3].y = coordinate_Shape[0].y + 30;
            }
        else if(kt_make_Shape == 4){
            coordinate_Shape[1].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[1].y = coordinate_Shape[0].y;
            coordinate_Shape[2].x = coordinate_Shape[0].x - 30;
            coordinate_Shape[2].y = coordinate_Shape[0].y;
            coordinate_Shape[3].x = coordinate_Shape[0].x;
            coordinate_Shape[3].y = coordinate_Shape[0].y + 30;
        }
    }
    else if(kt == 4){
        if(coordinate_Shape[0].x < 40 || coordinate_Shape[0].x > 340)
             kt_make_Shape = 1;

        if(kt_make_Shape%2 != 0){
            coordinate_Shape[1].x = coordinate_Shape[0].x;
            coordinate_Shape[1].y = coordinate_Shape[0].y + 30;
            coordinate_Shape[2].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[2].y = coordinate_Shape[0].y;
            coordinate_Shape[3].x = coordinate_Shape[2].x;
            coordinate_Shape[3].y = coordinate_Shape[2].y - 30;
        }
        else{
            coordinate_Shape[1].x = coordinate_Shape[0].x - 30;
            coordinate_Shape[1].y = coordinate_Shape[0].y;
            coordinate_Shape[2].x = coordinate_Shape[0].x;
            coordinate_Shape[2].y = coordinate_Shape[0].y + 30;
            coordinate_Shape[3].x = coordinate_Shape[2].x + 30;
            coordinate_Shape[3].y = coordinate_Shape[2].y;
        }
    }
    else if(kt == 5){
        if(coordinate_Shape[0].x < 40 || coordinate_Shape[0].x > 340)
             kt_make_Shape = 1;

        if(kt_make_Shape%2 != 0){
            coordinate_Shape[1].x = coordinate_Shape[0].x;
            coordinate_Shape[1].y = coordinate_Shape[0].y + 30;
            coordinate_Shape[2].x = coordinate_Shape[0].x - 30;
            coordinate_Shape[2].y = coordinate_Shape[0].y;
            coordinate_Shape[3].x = coordinate_Shape[2].x;
            coordinate_Shape[3].y = coordinate_Shape[2].y - 30;
        }
        else{
            coordinate_Shape[1].x = coordinate_Shape[0].x + 30;
            coordinate_Shape[1].y = coordinate_Shape[0].y;
            coordinate_Shape[2].x = coordinate_Shape[0].x;
            coordinate_Shape[2].y = coordinate_Shape[0].y + 30;
            coordinate_Shape[3].x = coordinate_Shape[2].x - 30;
            coordinate_Shape[3].y = coordinate_Shape[2].y;
        }
    }

}

int Graphics::kt_frame(){
    for(int i = 0; i < 4; i ++){
        if(coordinate_Shape[i].x <= 10) return 1;
        if(coordinate_Shape[i].x >= 370) return 2;
    }
    return 0;
}


void System::falling_object(){
    int speed = 30;
    falling = 2.5;

    Shape.move(sf::Vector2f(0, falling));
    coordinate_Shape[0].y += falling;

    if(moveClock.getElapsedTime().asSeconds() > 0.15f){
        if(kt_collision_left == 0){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && kt_frame() != 1){
                Shape.move(sf::Vector2f(-speed, 0));
                coordinate_Shape[0].x -= speed;
                moveClock.restart();
            }
        }
        if(kt_collision_right == 0){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)&& kt_frame() != 2){
                Shape.move(sf::Vector2f(speed, 0));
                coordinate_Shape[0].x += speed;
                moveClock.restart();
            }
        }
    }

    make_shape();
}

int System::object_touches_the_ground(){
    for(int i = 0; i < 4; i++){
        if(coordinate_Shape[i].y == 610){

            return 1;
        }
    }
return 0;
}

int System::collision_shape(){
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < coordinate_Shape_main.size(); i++){
            if(coordinate_Shape_main[i].y - coordinate_Shape[j].y <= 29 && coordinate_Shape_main[i].y - coordinate_Shape[j].y >= -30 && coordinate_Shape_main[i].x  - coordinate_Shape[j].x == -30){
                kt_collision_left = 1;
            }

            if(coordinate_Shape_main[i].y - coordinate_Shape[j].y <= 29 && coordinate_Shape_main[i].y - coordinate_Shape[j].y >= -30 && coordinate_Shape_main[i].x  - coordinate_Shape[j].x == 30){
                kt_collision_right = 1;
            }

          /*  if(coordinate_Shape_main[i].y - coordinate_Shape[j].y <= 29 && coordinate_Shape_main[i].y - coordinate_Shape[j].y >= -32 && coordinate_Shape_main[i].x  - coordinate_Shape[j].x == -60){
                kt_collision_left1 = 2;
            }*/

            if(coordinate_Shape_main[i].y - coordinate_Shape[j].y == 30 && coordinate_Shape[j].x == coordinate_Shape_main[i].x){
                kt_collision_shape = 1;
            }
        }
    }
return 0;
}

int System::straight_line(){
    int Min = 1000;
    int kt = 0;

    for(int i = 0; i < coordinate_Shape_main.size(); i++){
        if(coordinate_Shape_main[i].y < Min)
            Min = coordinate_Shape_main[i].y;
    }

    for(int i = 640; i >= Min; i -= 30){
        for(int j = 0; j < coordinate_Shape_main.size(); j++){
            if(coordinate_Shape_main[j].y == i)
                kt += 1;
        }
    }

    if(kt == 13){return 1;}
    return 0;
}

void System::save_position(){
    for(int i = 0; i < 4; i++){
        coordinate_Shape_main.push_back(coordinate_Shape[i]);
    }
}

void System::function_system_main(){
    collision_shape();
    if(object_touches_the_ground() == 1 || kt_collision_shape == 1){
        save_position();
        random_kt();
        shape();
    }

}







void Graphics::main_draw(){
    Window.clear();
    draw_frame();
    for(int i = 0; i < 4; i++){
        Shape.setPosition(sf::Vector2f(coordinate_Shape[i].x, coordinate_Shape[i].y));
        Window.draw(Shape);
    }
    for(int i = 0; i < coordinate_Shape_main.size(); i++){
        Shape_main.setPosition(sf::Vector2f(coordinate_Shape_main[i].x, coordinate_Shape_main[i].y));
        Window.draw(Shape_main);
    }
    Window.display();
}


void run_game(){
    System S;

    S.window();
    S.shape();
    S.shape_main();
    S.random_kt();

    int i = 0;
    while(S.Window.isOpen()){
        while(auto event = S.Window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                S.Window.close();
        }

    S.falling_object();

    S.kt_collision_left = 0;
    S.kt_collision_left1 = 0;
    S.kt_collision_right = 0;
    S.kt_collision_shape = 0;

    S.function_system_main();



    i += 1;
 //   cout << S.kt_collision_left << "  "<< S.kt_collision_right << endl;
    cout << S.coordinate_Shape[0].x << "   " << S.coordinate_Shape[0].y  <<"      " << S.kt_make_Shape << "  "<< S.kt << "   "<< i <<endl;
    S.main_draw();
    }
}


int main(){
    run_game();

return 0;
}
