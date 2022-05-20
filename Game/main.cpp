#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/Snake.h"

#define Board_Height = 20
#define Board_Width = 30


//Khoảng thời gian giữa 2 lần delay
sf::Time elapsedTime = sf::Time::Zero;
sf::Time deltaTime = sf::seconds(1.0f/60.0f);
// Tên ngắn cho hàm lấy thời gian hiện tại
// Kiểu đại diện cho khoảng thời gian (tính theo giây)

// class Gallery
// {       
// private:
//         std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
//         // std::map<int, std::unique_ptr<sf::Font>> m_fonts;
//        m_textures[BOARD] = 
// public:
        
// }
sf::Vector2f snake_direction = sf::Vector2f (32.0f , 0.0f);

int main() {
        
        sf::RenderWindow window(sf::VideoMode(1280, 640), "Snake Game");

        sf::Texture BOARD;
        if (BOARD.loadFromFile("include/back_ground.png")) std::cout << "";
        BOARD.setRepeated(true);

        sf::Texture FOOD;
        if (FOOD.loadFromFile("include/apple2.png",sf::IntRect(0,0,32,32))) std::cout << "";
        FOOD.setSmooth(true);
        
        sf::Texture SNAKE;
        if (SNAKE.loadFromFile("include/circle-32.png")) std::cout << "";
        SNAKE.setSmooth(true);
// Các đối tượng rắn, quả, tường, nền
        sf::Sprite board;
        board.setTexture(BOARD);
        sf::Sprite food;
        food.setTexture(FOOD);
        Snake snake;
        snake.Init(SNAKE);
        // Snake m_snake;

        food.setPosition(sf::Vector2f(window.getSize().x / 2 ,window.getSize().y / 2));
        window.setPosition(sf::Vector2i(43,50));
        board.setTextureRect(sf::IntRect(0,0,960,640));
        // sf::Text scoreText;
        // int score;
        
        // sf::Vector2f snakeDirection;
        // sf::Time elapsedTime;
        window.setVerticalSyncEnabled(true);

        while (window.isOpen())
{
        sf::Event event;
        while (window.pollEvent(event))
        {   
                
            sf::Vector2f newDirection = sf::Vector2f (0.0f,32.0f);
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                        case sf::Keyboard::A:
                                newDirection = {-32.0f, 0.0f}; break;

                        case sf::Keyboard::W: 
                                newDirection = {0.0f, -32.0f}; break;

                        case sf::Keyboard::S:
                                newDirection = {0.0f, 32.0f}; break;

                        case sf::Keyboard::D:
                                newDirection = {32.0f, 0.0f}; break;
                        
                }
            snake_direction = newDirection;
        }
        
        elapsedTime += deltaTime;
        if (elapsedTime.asSeconds() > 0.2)     
        {
                snake.Move(snake_direction);
                elapsedTime = sf::Time::Zero;
        }
        window.clear();
        window.draw(board);
        window.draw(food);
        window.draw(snake);
        window.display();
    }
        return 0;
}
        
