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
