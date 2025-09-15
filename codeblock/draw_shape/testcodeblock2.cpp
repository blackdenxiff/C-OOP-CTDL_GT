#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
class Graphics{
    private:

    public:
        std::vector<sf::Texture> textures;
        std::vector<sf::Sprite> sprites;
    void test();
};

void Graphics::test(){
    textures.reserve(6);
    sprites.reserve(6);

    for (int j = 0; j < 6; j++) {
        sf::Texture tex;
        std::string file_name = "assets/9e6087a9d24c441cbedd06392a19b9558SVPi3jHAsTQizvm-"+ std::to_string(j) +".png";

        if (!tex.loadFromFile(file_name)){
            std::cout <<"khong the tai anh: "<< file_name <<"\n";
        }
        textures.push_back(std::move(tex));

        sf::Sprite spr(textures.back());
        spr.setPosition(sf::Vector2f(100.f + j * 200.f, 200.f));
        sprites.push_back(std::move(spr));
    }

}
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Array Texture & Sprite SFML 3.0.0");
    Graphics G;
    G.test();
    // 3. Game loop
    while (window.isOpen()) {
        while(auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        for (auto &sprite : G.sprites) {
            window.draw(sprite);
        }
       // window.draw(G.sprites[0]);
        window.display();
    }

    return 0;
}
  /* // 1. Tạo mảng texture
    std::vector<sf::Texture> textures(3);
    if (!textures[0].loadFromFile("C:\\Users\\AT\\Pictures\\graphcis\\level_askd.png") ||
        !textures[1].loadFromFile("C:\\Users\\AT\\Pictures\\graphcis\\level_4fsfs.png") ||
        !textures[2].loadFromFile("C:\\Users\\AT\\Pictures\\graphcis\\pixil-leve_3.png")){
        std::cerr << "Không thể tải ảnh!\n";
        return -1;
    }

    // 2. Tạo mảng sprite (truyền texture ngay khi tạo)
    std::vector<sf::Sprite> sprites;
    for (int i = 0; i < 3; i++) {
        sprites.emplace_back(textures[i]); // truyền texture vào constructor
        sprites[i].setPosition(sf::Vector2f(100.f + i * 200.f, 200.f));
    }*/
