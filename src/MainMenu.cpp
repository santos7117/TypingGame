//#include "MainMenu.h"
//#include <iostream>
//
//#define Y_COR 100
//
//using namespace std;
//MainMenu::MainMenu(): window(sf::VideoMode(1600, 900), "TYPE JUMPER") {
//
//    state = State ::MAINMENU;
//
//    m_sprite.setTexture(gallery.main_menu);
//    m_sprite.setScale(0.4, 0.3);
//
//    state_leave.setFillColor(sf::Color::Cyan);
//    std::string aboutText = "A project of object oriented programming programming.\n\n Project Builders::\n\n SURAJ POKHREL 075BCT091\n\n SANTOS SHRESTHA 075BCT081.\n\n\n While playing this game you have to type a word that is moving and you will gain score if you type correct a string.";
//    textureText(m_textstartgame, "START GAME", 50, 90.0 , gallery,   true);
//    textureText(m_textlanguage, "LANGUAGE", 50, 220.0 , gallery,   true);
//    textureText(m_textabout, "ABOUT", 50, 280.0 , gallery,  true);
//    textureText(m_textexit, "EXIT", 50, 340.0 , gallery, true);
//
//    textureText(m_aboutText, aboutText, 25, 0 , gallery,  false);
//    textureText(state_leave, "LEAVE", 50, 400.0 , gallery,  false);
//
//    //playSound.openFromFile("sounds/Treehouse_SPRING_noMel_Loop.mp3");
//    //playSound.setLoop(true);
//    //playSound.play();
//}
//
//
//void MainMenu::Run() {
//    while (window.isOpen()) {
//        ProcessEvents();
//        Update();
//        Draw();
//    }
//}
//
//void MainMenu::ProcessEvents() {
//    sf::Event event;
//
//    while (window.pollEvent(event)) {
//        switch (event.type) {
//            case event.Closed:
//                window.close();
//                break;
//
//            case (sf::Event::KeyPressed):
//                if(event.key.code == sf::Keyboard::Escape)
//                    window.close();
//
//                break;
//
//        }
//
//    }
//}
//
//void MainMenu::Update() {
//    mouse_x = sf::Mouse::getPosition(window).x;
//    mouse_y = sf::Mouse::getPosition(window).y;
//
//    if(state == State::MAINMENU)
//    {
//
//        if (m_textstartgame.getGlobalBounds().contains(mouse_x, mouse_y)) {
//            m_textstartgame.setFillColor(sf::Color::Blue);
//                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//                {
//                    Game game;
//                    game.run();
//                }
//        } else {
//            m_textstartgame.setFillColor(sf::Color::Black);
//        }
//
//        if (m_textlanguage.getGlobalBounds().contains(mouse_x, mouse_y)) {
//            m_textlanguage.setFillColor(sf::Color::Blue);
//        } else {
//            m_textlanguage.setFillColor(sf::Color::Black);
//        }
//        if (m_textabout.getGlobalBounds().contains(mouse_x, mouse_y)) {
//            m_textabout.setFillColor(sf::Color::Blue);
//        } else {
//            m_textabout.setFillColor(sf::Color::Black);
//        }
//
//        if (m_textexit.getGlobalBounds().contains(mouse_x, mouse_y)) {
//            m_textexit.setFillColor(sf::Color::Blue);
//        } else {
//            m_textexit.setFillColor(sf::Color::Black);
//        }
//
//        // doing state management
//        if (m_textexit.getGlobalBounds().contains(mouse_x, mouse_y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            window.close();
//
//        }
//        if (m_textabout.getGlobalBounds().contains(mouse_x, mouse_y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            state = State::ABOUT;
//
//        }
//        if (m_textlanguage.getGlobalBounds().contains(mouse_x, mouse_y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//
//        }
//        if (m_textstartgame.getGlobalBounds().contains(mouse_x, mouse_y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//
//        }
//
//    }
//
//     else if (state == State::ABOUT)
//    {
//
//        if (state_leave.getGlobalBounds().contains(mouse_x, mouse_y)) {
//            state_leave.setFillColor(sf::Color::Blue);
//
//            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//                state = State::MAINMENU;
//            }
//        }
//        else {
//            state_leave.setFillColor(sf::Color::Red);
//        }
//    }
//
//    else if (state == State::START)
//    {
//
//    }
//
//}
//
//void MainMenu::Draw() {
//    window.clear();
//   if(state == State::MAINMENU)
//       DrawGallery();
//   else if (state == State::ABOUT)
//       DrawAbout();
////    else if (state == State::START)
////    {
////        Game game;
////        game.run();
////    }
//    window.display();
//}
//
//void MainMenu::DrawGallery() {
//    window.draw(m_sprite);
//    window.draw(m_textstartgame);
//    window.draw(m_textlanguage);
//    window.draw(m_textabout);
//    window.draw(m_textexit);
//}
//
//void MainMenu::DrawAbout() {
//    window.draw(state_leave);
//    window.draw(m_aboutText);
//}
//
//void MainMenu::textureText(sf::Text& text, std::string content, int size, float position, ResourceHolder& gallery,  bool isMenu)
//{
//    text.setString(content);
//    if(isMenu == true)
//        text.setFont(gallery.main_menu_font);
//    else
//        text.setFont(gallery.main_menu_font);
//    text.setCharacterSize(size);
//    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2, Y_COR + position);
//
//}
//
