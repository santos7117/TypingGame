#ifndef STRINGS_H
#define STRINGS_H

/* Screen Resolution */
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

#include <SFML/Graphics.hpp>

class Strings
{
    public:

        // Members

        sf::Text text;
        sf::Texture texture_text;


        // Constructors

        Strings()
        {
            initializeText();

        }

        virtual ~Strings();


        // Member Functions

        void initializeText()
        {
            font.loadFromFile("fonts/SourceCodePro-Regular.ttf");
            text.setFont(font);

            // Initializes transparent paths for words to move onto. Each upper path is relative to the upper paths.

            Path[0].setFillColor(sf::Color::Transparent);
            Path[0].setPosition(0, 0);
            Path[0].setSize(sf::Vector2f(SCREEN_WIDTH, 55));

            Path[1].setFillColor(sf::Color::Transparent);
            Path[1].setPosition(0, Path[0].getGlobalBounds().height);
            Path[1].setSize((sf::Vector2f(SCREEN_WIDTH, 65)));

            Path[2].setFillColor(sf::Color::Transparent);
            Path[2].setPosition(0, (Path[0].getGlobalBounds().height + Path[1].getGlobalBounds().height));
            Path[2].setSize((sf::Vector2f(SCREEN_WIDTH, 63)));

            Path[3].setFillColor(sf::Color::Transparent);
            Path[3].setPosition(0, (Path[0].getGlobalBounds().height + Path[1].getGlobalBounds().height) + Path[2].getGlobalBounds().height);
            Path[3].setSize((sf::Vector2f(SCREEN_WIDTH, 63)));

            Path[4].setFillColor(sf::Color::Transparent);
            Path[4].setPosition(0, (Path[0].getGlobalBounds().height + Path[1].getGlobalBounds().height) + Path[2].getGlobalBounds().height + Path[3].getGlobalBounds().height);
            Path[4].setSize((sf::Vector2f(SCREEN_WIDTH, 70)));

            Path[5].setFillColor(sf::Color::Transparent);
            Path[5].setPosition(0, (Path[0].getGlobalBounds().height + Path[1].getGlobalBounds().height) + Path[2].getGlobalBounds().height + Path[3].getGlobalBounds().height + Path[4].getGlobalBounds().height);
            Path[5].setSize((sf::Vector2f(SCREEN_WIDTH, 57)));

            srand(time(0));
            text.setPosition(1600, Path[int(rand() % 6)].getGlobalBounds().top + 5);
        }



        void moveText(float offsetX)
        {
            text.move(-offsetX, 0);
        }

        void setString(std::string _passed_string)
        {
            text.setString(_passed_string);
        }

        sf::Vector2f getPosition()
        {
            return text.getPosition();
        }


    private:

        // Members

        sf::Font font;
        sf::RectangleShape Path[6];



};

#endif // STRINGS_H
