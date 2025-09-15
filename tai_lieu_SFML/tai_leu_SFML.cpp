#include <SFML/Graphics.hpp>
1. Tạo cửa sổ & vòng lặp sự kiện{
cpp
Sao chép
Chỉnh sửa
sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
sf::RenderWindow: tạo cửa sổ có thể vẽ (render)
sf::VideoMode(width, height): đặt kích thước cửa sổ

Vòng lặp chính:
cpp
Sao chép
Chỉnh sửa
while (window.isOpen()) {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close(); // Đóng cửa sổ
    }

    window.clear();     // Xóa màn hình
    // window.draw(...) // Vẽ vật thể ở đây
    window.display();   // Hiển thị hình ảnh đã vẽ
}
}

whindow{
    1. opening and managing an SFML window (mở và quả lý cửa sổ SFML);

        a. opening a window (mở 1 cửa sổ)

            #include <SFML/Window.hpp>
            int main(){
                sf::Window window(sf::VideoMơde({690, 900}), "helo SFML of worlk"); // . Ở đây, chúng ta tạo một cửa sổ có kích thước 800x600 pixel;
            }
            - Hàm tạo này chấp nhận một đối số tùy chọn thứ ba: một kiểu (style),
            cho phép bạn chọn kiểu trang trí và tính năng bạn muốn.
             Bạn có thể sử dụng bất kỳ sự kết hợp nào trong các kiểu sau:
                    Phong cách	Sự miêu tả;
                    sf::Style::None	//Không trang trí gì cả (hữu ích cho màn hình chào mừng, ví dụ)
                                     //Phong cách này không thể kết hợp với các phong cách khác
                    sf::Style::Titlebar	//Cửa sổ có thanh tiêu đề
                    sf::Style::Resize	//Cửa sổ có thể thay đổi kích thước và có nút phóng to
                    sf::Style::Close	Cửa sổ có nút đóng
                    sf::Style::Default	Phong cách mặc định, là một phím tắt choTitlebar | Resize | Close

            -Đối số thứ tư xác định trạng thái cửa sổ cho phép bạn chọn giữa cửa sổ nổi hoặc cửa sổ toàn màn hình.

            sf::state::Windowed //cửa sổ nổi;
            sf::state::fillscreen //cửa sổ toàn màn hình;

            -đối số tùy chọn thứ năm, dùng để xác định các tùy chọn cụ thể của OpenGL được giải thích trong hướng dẫn OpenGL chuyên dụng.
                Nếu bạn muốn tạo cửa sổ sau khi xây dựng phiên sf::Window bản, hoặc tạo lại nó với chế độ video hoặc tiêu đề khác
                , bạn có thể sử dụng create hàm này. Hàm này sử dụng cùng các đối số như hàm khởi tạo.vd;
                #include <SFML/Window.hpp>
                int main(){
                    sf::Window window;
                    Window.create(sf::VideoMode({800, 600}), "create");
                }
                vd
                #include <SFML/Window.hpp>
                    int main()
                    {
                        sf::Window window(sf::VideoMode({800, 600}), "My window");

                        // run the program as long as the window is open
                        while (window.isOpen())
                        {
                            // check all the window's events that were triggered since the last iteration of the loop
                            while (const std::optional event = window.pollEvent())
                            {
                                // "close requested" event: we close the window
                                if (event->is<sf::Event::Closed>())
                                    window.close();
                            }
                        }
                    }








}

keyboard_mouse_joystick{
    chat gpt;
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

int main()
{
    // SFML 3.0: sf::VideoMode nhận sf::Vector2u
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0 Input Example");

    sf::CircleShape character(25.f); // bán kính
    character.setFillColor(sf::Color::Green);
    character.setPosition(sf::Vector2f(400.f, 300.f)); // sf::Vector2f(x, y)

    float speed = 5.0f;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent()) // SFML 3.0 dùng optional
        {
            if (event->is<sf::Event::Closed>()) // nếu đóng cửa sổ
                window.close();
        }

        // --- BÀN PHÍM ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            character.move(sf::Vector2f(-speed, 0.f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            character.move(sf::Vector2f(speed, 0.f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            character.move(sf::Vector2f(0.f, -speed));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            character.move(sf::Vector2f(0.f, speed));

        // --- CHUỘT ---
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            std::cout << "Chuột trái đang được nhấn\n";

        // --- JOYSTICK ---
        if (sf::Joystick::isConnected(0))
        {
            float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
            float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
            character.move(sf::Vector2f(x / 100.f * speed, y / 100.f * speed));

            if (sf::Joystick::isButtonPressed(0, 0))
                std::cout << "Bắn bằng joystick nút 0\n";
        }

        window.clear();
        window.draw(character);
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "test code::block two");

    //create circle shape character: tạo nhân vật hình tròn;
    sf::CircleShape character(30.f);
    character.setFillColor(sf::Color::Green);// màu hình tròn; circle
    character.setPosition(sf::Vector2f({0.f, 0.f}));

    float speed = 2.0f; //Đây là một hằng số vận tốc cho việc di chuyển nhân vật.

    while(window.isOpen()){
      //  sf::Event event; //  Tạo một biến event để chứa các sự kiện như: đóng cửa sổ, nhấn chuột, gõ phím v.v.

        while(auto event = window.pollEvent()){
            // kiểm tra để đóng window;
            if(event->is<sf::Event::Closed>()){
                window.close();
            }

            // bàn phím ;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                character.move(sf::Vector2f(-speed, 0.f));
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                character.move(sf::Vector2f(speed, 0.f));
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                character.move(sf::Vector2f(0.f, -speed));
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                character.move(sf::Vector2f(0.f, speed));

            // mouse
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                std::cout<< "mouse left: shoot"<<std:: endl;
            }

            // Joystick
            if(sf::Joystick::isConnected(0)){//Kiểm tra xem joystick số 0 (tay cầm đầu tiên) có được kết nối không.
                float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);//Lấy vị trí trục X và Y của joystick số 0 (trong khoảng -100 đến +100).
                float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);//Lấy vị trí trục X và Y của joystick số 0 (trong khoảng -100 đến +100).
                character.move(sf::Vector2f(x/100.f * speed,y/100.f * speed));//Chuyển đổi giá trị joystick thành tốc độ và di chuyển nhân vật

                if(sf::Joystick::isButtonPressed(0, 0))
                    std::cout << "ban bang joystick" <<std::endl; // Nếu nút 0 (thường là nút A trên tay cầm) được nhấn → thông báo.
            }

            window.clear();//Xóa khung hình cũ (clear màn hình trước khi vẽ mới).
            window.draw(character);//Vẽ hình tròn character lên cửa sổ.
            window.display();//Hiển thị khung hình mới đã vẽ ra.
        }
    }

    return 0;
}


}



sprite_and_texures{
    #include <SFML/Graphics.hpp>
    #include <iostream>

        int main() {
            // Tạo cửa sổ
            sf::RenderWindow window(sf::VideoMode({800, 600}), "Sprite Demo");

            // Tải texture
            sf::Texture texture;
            texture.setSmooth(true);
            if (!texture.loadFromFile("test.png")) {
                std::cout << "ko the downloat tai nguyen:\n";
                return -1;
            }

            // Tạo sprite từ texture
            sf::Sprite sprite(texture);
            sprite.setPosition({400.f, 300.f}); // giữa màn hình
            sprite.setOrigin({texture.getSize().x / 2.f, texture.getSize().y / 2.f}); // xoay quanh tâm

            // Game loop
            while (window.isOpen()) {
                while (auto event = window.pollEvent()) {
                    if(event->is<sf::Event::Closed>())
                        window.close();
                }

                // Điều khiển bằng bàn phím
                float speed = 2.f;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                    sprite.move({-speed, 0.f});
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                    sprite.move({speed, 0.f});
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                    sprite.move({0.f, -speed});
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                    sprite.move({0.f, speed});

                // Xoay sprite
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    sprite.rotate(sf::degrees(-1.f));
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    sprite.rotate(sf::degrees(1.f));

                // Vẽ
                window.clear(sf::Color::Black);
                window.draw(sprite);
                window.display();
            }

            return 0;
        }

}
snake_game_test{
#include <SFML/Graphics.hpp>
#include <deque>
#include <cstdlib>
#include <ctime>

// Kích thước mỗi ô và màn hình
const int cellSize = 20;
const int width = 800;
const int height = 600;
const int cols = width / cellSize;
const int rows = height / cellSize;

enum Direction { Up, Down, Left, Right };

struct SnakeGame {
    sf::RenderWindow window;
    std::deque<sf::Vector2i> snake;
    sf::Vector2i food;
    Direction dir;
    sf::Clock clock;
    float moveDelay = 0.1f; // thời gian giữa mỗi bước di chuyển

    SnakeGame() : window(sf::VideoMode({width, height}), "Snake Game"), dir(Right) {
        snake.push_back({cols / 2, rows / 2});
        placeFood();
    }

    void placeFood() {
        food = {rand() % cols, rand() % rows};
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            if (clock.getElapsedTime().asSeconds() >= moveDelay) {
                update();
                clock.restart();
            }
            render();
        }
    }

    void processEvents() {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && dir != Down)
            dir = Up;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && dir != Up)
            dir = Down;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && dir != Right)
            dir = Left;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && dir != Left)
            dir = Right;
    }

    void update() {
        sf::Vector2i head = snake.front();

        switch (dir) {
            case Up:    head.y--; break;
            case Down:  head.y++; break;
            case Left:  head.x--; break;
            case Right: head.x++; break;
        }

        // kiểm tra va chạm với tường
        if (head.x < 0 || head.y < 0 || head.x >= cols || head.y >= rows) {
            reset();
            return;
        }

        // kiểm tra va chạm với thân rắn
        for (auto& segment : snake) {
            if (segment == head) {
                reset();
                return;
            }
        }

        snake.push_front(head);

        // kiểm tra ăn mồi
        if (head == food) {
            placeFood();
        } else {
            snake.pop_back(); // không ăn thì rắn không dài ra
        }
    }

    void reset() {
        snake.clear();
        snake.push_back({cols / 2, rows / 2});
        dir = Right;
        placeFood();
    }

    void render() {
        window.clear();

        // vẽ rắn
        sf::RectangleShape rect({(float)cellSize, (float)cellSize});
        rect.setFillColor(sf::Color::Green);
        for (auto& segment : snake) {
            rect.setPosition(sf::Vector2f(segment.x * cellSize, segment.y * cellSize));
            window.draw(rect);
        }

        // vẽ mồi
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(sf::Vector2f(food.x * cellSize, food.y * cellSize));
        window.draw(rect);

        window.display();
    }
};
}

vẽ_văn_bản_drawing_text{
    Vẽ văn bản
sf::Font font("arial.ttf"); // Throws sf::Exception if an error occurs

// OR

sf::Font font;
if (!font.openFromFile("arial.ttf"))
{
    // error...
}
Để vẽ văn bản, bạn sẽ sử dụng sf::Textlớp này. Cách sử dụng rất đơn giản:
sf::Text text(font); // a font is required to make a text object

// set the string to display
text.setString("Hello world");

// set the character size
text.setCharacterSize(24); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::Red);

// set the text style
text.setStyle(sf::Text::Bold | sf::Text::Underlined);

...

// inside the main loop, between window.clear() and window.display()
window.draw(text)
}



