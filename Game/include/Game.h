#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.cpp"

class Game
{
    private:
        const sf::Time timeFrame = sf::seconds(1.0f/60.0f);
    public:
        Game();
        ~Game();
    
    void Run();
    void Update();
    void Draw();

}