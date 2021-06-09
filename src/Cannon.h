#ifndef CANNONBALLS_H
#define CANNONBALLS_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include "Strings.h"
#include "ResourceHolder.hpp"



class CannonBalls
{

private:

    // Variables


public:

    // Variables

    sf::CircleShape bullet;
    sf::Vector2f currentVelocity;
    float maxSpeed = 50;

    // Constructor

    CannonBalls()
    {
        bullet.setFillColor(sf::Color::Black);
        bullet.setRadius(25.f);
    }

};







class Cannon
{
    private:
    sf::Texture cannon_texture;
    sf::Sprite cannon_sprite;
    sf::Vector2f cannon_position;



    sf::Vector2f aim_direction;

    public:

        // Functions

        Cannon()
        {
            setSprite();
            setPosition();
        }


        // Functions

        void setPosition()
        {
            cannon_position = sf::Vector2f(0.f, 670.f);
            cannon_sprite.setPosition(cannon_position);
        }



        void setSprite()
        {

            cannon_texture.loadFromFile("resources/images/cannon.png");

            cannon_sprite.setTexture(cannon_texture);
            cannon_sprite.setScale(.4f, .4f);
            cannon_sprite.rotate(300);
        }

        sf::Sprite getSprite()
        {
            return cannon_sprite;
        }



        sf::Vector2f getPosition()
        {
            return cannon_sprite.getPosition();
        }




        void drawTo(sf::RenderWindow &window)
        {
            window.draw(cannon_sprite);
        }



        void move(float _x_position, float _y_position)
        {
            cannon_sprite.move(_x_position, 0);

        }

};







#endif // CANNONBALLS_H
