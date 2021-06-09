#include "ResourceHolder.hpp"




ResourceHolder::ResourceHolder()
{

    // Fonts

    main_menu_font.loadFromFile("resources/fonts/mainmenu.ttf");
    string_font.loadFromFile("resources/fonts/normal.ttf");
    user_input_font.loadFromFile("resources/fonts/normal.ttf");
    score_font.loadFromFile("resources/fonts/score.ttf");
    exit_font.loadFromFile("resources/fonts/exit.ttf");


    // Textures

    main_menu.loadFromFile("resources/images/mainmenu.jpg");
    texture_background.loadFromFile("resources/images/background.gif");
    cannon.loadFromFile("resources/images/cannon.png");
    explosion.loadFromFile("resources/images/greenexplosion.png");
    game_over.loadFromFile("resources/images/gameover.jpg");

    // Sound

    boom_buffer.loadFromFile("resources/audio/Cannon.wav");
}

