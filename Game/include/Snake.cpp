#include "snake.h"

Snake:: Snake() : body(std::list <sf::Sprite> (4))
{
    
    head = --body.end();
    tail = body.begin();
};
Snake:: ~Snake()
{
};

    void Snake::Init(const sf::Texture &texture)
    {
        float x = 0.0f;
        for (auto& piece : body)
            {   
                piece.setTexture(texture);
                piece.setPosition(sf::Vector2f(x,0.0f));
                x+=32;
            }
    }
    void Snake::Move(const sf::Vector2f &direction)
    {
        tail->setPosition(sf::Vector2f(head->getPosition()+direction));
        head = tail;
        tail++;
        if (tail == body.end())
            {
                tail = body.begin();
            }
    }
    bool Snake::IsOn(const sf::Sprite &other)
    {

    }
    void Snake::Grow(const sf::Vector2f &direction)
    {

    }

    void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const 
    {
        for (auto& piece : body)
            {
                target.draw(piece);
            }
    }