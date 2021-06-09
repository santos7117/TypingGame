#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourceHolder
{
    public:

        // Resources

        // Fonts
        sf::Font main_menu_font;
        sf::Font string_font;
        sf::Font user_input_font;
        sf::Font score_font;
        sf::Font exit_font;

        // Textures
        sf::Texture texture_background;
        sf::Texture cannon;

        sf::Texture explosion;

        sf::Texture main_menu;
        sf::Texture game_over;


        // Sound
        sf::SoundBuffer boom_buffer;

        // Constructors

        ResourceHolder();
};

#endif // RESOURCEHOLDER_H

