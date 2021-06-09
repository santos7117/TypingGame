#include "Game.h"



Game::Game()
{
    text.setFont(resources.string_font);
    //text.setPosition(1600, 40);

    live_score_label.setFont(resources.score_font);
    live_score.setFont(resources.score_font);

    player_misses_label.setFont(resources.score_font);
    player_misses.setFont(resources.score_font);

    boom.setBuffer(resources.boom_buffer);
}



void Game::initGame()
{

    // rendering background
    sf::Sprite background;
    background.setTexture(resources.texture_background);
    background.setTextureRect(sf::IntRect(0, 55, 320, 220));
    background.setPosition(0.f, 0.f);
    background.setScale(5.f, 3.18f);


    live_score_label.setString("SCORE:");
    live_score_label.setCharacterSize(30);
    live_score_label.setPosition(inputArea.getPosition().x + 30, inputArea.getPosition().y + 10);

    live_score.setCharacterSize(90);
    live_score.setPosition(live_score_label.getPosition().x, live_score_label.getPosition().y + 20);

    player_misses_label.setString("MISSES:");
    player_misses_label.setCharacterSize(30);
    player_misses_label.setPosition(inputArea.getPosition().x + 1450, inputArea.getPosition().y + 10);

    player_misses.setCharacterSize(90);
    player_misses.setPosition(player_misses_label.getPosition().x + 20, player_misses_label.getPosition().y + 20);

    window.draw(background);
}



void Game::update()
{

    cannon_center = sf::Vector2f(cannon.getPosition());


    text.setString(extractWords());


        for(unsigned i=0; i<words.size(); ++i)
        {
            word_position.x = SCREEN_WIDTH - words[i].getGlobalBounds().width;
            word_position.y = setPath(int(rand() % 6)).getGlobalBounds().top + 15;

            setStringBox(words[i]);
            words[i].move(- 5 * speed, 0);

            if (words[i].getPosition().x <= 0)
            {
                player_lives++;
                std::cout << player_lives << std::endl;
                highlightStringBox(text_box, words[i], sf::Color::Red);
                words[i].setPosition(word_position);
            }

            aim_direction = words[i].getPosition() - cannon_center;
            unit_aim_direction.x = aim_direction.x / sqrt(pow(aim_direction.x, 2) + pow(aim_direction.y, 2));
            unit_aim_direction.y = aim_direction.y / sqrt(pow(aim_direction.x, 2) + pow(aim_direction.y, 2));

            cannon_ball.bullet.setPosition(cannon_center.x + 80 , cannon_center.y);
            cannon_ball.currentVelocity = unit_aim_direction * cannon_ball.maxSpeed;

            words_count = i;
        }

        //////////////////////////////////////////////// Tracking target /////////////////////////////////////////////
        cannon.move(5 * delta_time* (aim_direction.x - 95), 0);
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////


        /////////////////////////////////////// Loading Bullets ///////////////////////////////////////////////
        player_misses.setString(std::to_string(player_lives - 1));

        if (isInputCorrect())
        {
            balls.push_back(cannon_ball);

            highlightStringBox(text_box, words[words_count], sf::Color::Green);
            boom.play();

            live_score.setString(std::to_string(player_score));
            player_score += 1;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


        /////////////////////////////////////// Shooting Correct Words ////////////////////////////////////////////////
        for (unsigned i=0; i<balls.size(); ++i)
        {
            balls[i].bullet.move(balls[i].currentVelocity * speed);

            // Collision Detection
            if((balls[i].bullet.getPosition().y <= (text_box.getLocalBounds().height + text_box.getPosition().y)))
            {
                balls.erase(balls.begin() + i);
                words.pop_back();

                words.push_back(text);

            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}




















void Game::draw()
{

    window.clear();

    initGame();
    drawInputArea();
    cannon.drawTo(window);

    for(unsigned i=0; i<words.size(); ++i)
    {
        window.draw(words[i]);
    }
    window.draw(text_box);

    for(unsigned i=0; i<balls.size(); ++i)
    {
        window.draw(balls[i].bullet);
    }

    window.draw(exploder);

    window.draw(live_score_label);
    window.draw(live_score);

    window.draw(player_misses_label);
    window.draw(player_misses);

    window.display();
}



void Game::drawInputArea()
{
    inputArea.setSize(sf::Vector2f(1600, 300));
    inputArea.setFillColor(sf::Color::Cyan);
    inputArea.setPosition(0.f, 700.f);

    input_handler.setFont(resources.user_input_font);
    input_handler.setPosition(sf::Vector2f(inputArea.getPosition().x + 600, inputArea.getPosition().y + 10));
    input_handler.setLimit(true, 20);

    window.draw(inputArea);
    input_handler.drawTo(window);

}




void Game::checkPollEvents()
{
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::TextEntered)
        {
            input_handler.typedOn(event);
        }
    }
}


void Game::run()
{
        window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Typing Game");

        window.setFramerateLimit(100);

        text.setPosition(SCREEN_WIDTH - text.getGlobalBounds().width, setPath(int(rand() % 6)).getGlobalBounds().top + 15);
        words.push_back(text);


        while (window.isOpen())
        {
            delta_time = clock.restart().asSeconds();
            speed = delta_time * multiplier;



            if (player_lives <= 3)
            {
                checkPollEvents();
                update();
                draw();
            }

            else
            {
                checkPollEvents();

                displayGameOver();
            }




        }


}


