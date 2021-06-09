#ifndef GAME_CPP_H
#define GAME_CPP_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "CannonsAndBalls.h"
#include "TextBox.h"
#include "Animation.h"
//#include <windows.h>


/* Screen Resolution */
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

enum State {MAIN_MENU, IN_GAME, GAME_OVER};




class Game
{

    private:
        // Variables

        sf::RenderWindow window;
        sf::Event event;
        sf::Text text;
        sf::Font font;
        sf::Clock clock;

        float delta_time;
        float multiplier = 60;
        float speed;

//        sf::Texture texture_background;
//        sf::Font font;
        sf::RectangleShape text_box;
        sf::RectangleShape inputArea;
        sf::Text live_score;
        sf::Text live_score_label;
        sf::Text player_misses_label;
        sf::Text player_misses;
        sf::Vector2f cannon_center;
        sf::Vector2f aim_direction;
        sf::Vector2f unit_aim_direction;
        sf::Vector2f word_position;
        sf::Sprite exploder;
        sf::Sound boom;

        std::vector <CannonBalls> balls;
        std::vector <sf::Text> words;

        Textbox input_handler;
        Cannon cannon;
        CannonBalls cannon_ball;

        unsigned player_lives = 0;
        unsigned words_count = 0;
        unsigned player_score = 0;





        // Functions

        void initGame();


    public:

        ResourceHolder resources;
        Animation explosion;


        Game();

        // Functions

        void initializePath();

        void update();
        void drawInputArea();
        void checkPollEvents();
        void draw();
        void run();



        sf::RectangleShape setPath(unsigned i)
        {
        // Initializes transparent paths for words to move onto. Each upper path is relative to the upper paths.

            sf::RectangleShape Path[6];

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

            return Path[i];
        }




        void setStringBox(sf::Text text)
        {
            text_box.setPosition(text.getPosition().x - 10, text.getPosition().y - 5);
            text_box.setSize(sf::Vector2f(text.getGlobalBounds().width + 30, 45.f));
            text_box.setOutlineColor(sf::Color::Black);
            text_box.setOutlineThickness(1);
            text_box.setFillColor(sf::Color::Transparent);
            text_box.setOutlineColor(sf::Color::Black);
        }




        void highlightStringBox(sf::RectangleShape &text_box, sf::Text &text, sf::Color color)
        {
            text_box.setOutlineThickness(10);
            //text.setColor(color);
            text_box.setOutlineColor(color);
        }



        std::string extractWords()
        {
            std::string word, temp;
            std::ifstream randomWordsFile;

            std::vector <std::string> words;

            srand(time(0));

            randomWordsFile.open("text/randomtext.txt");

            if (!randomWordsFile)
            {
                std::cout << "Error while opening file" << std::endl;
            }

            else if (randomWordsFile.is_open())
            {
                while (getline(randomWordsFile, word))
                {
                    words.push_back(word);
                }

                temp = words[rand() % words.size()];

                return temp;

                randomWordsFile.close();
            }
        }


        bool isInputCorrect()
        {
            if (input_handler.getText() != words[words_count].getString())
                return false;

            else
                return true;
        }


        void displayGameOver()
        {
            window.clear();

            sf::Sprite gameover;
            gameover.setTexture(resources.game_over);
            gameover.setScale(0.9, 0.8);

            window.draw(gameover);
            window.display();
        }

    };

#endif // GAME_CPP_H
