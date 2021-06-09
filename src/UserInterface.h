//#pragma once
//
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <sstream>
//
///* Macros for Keystrokes */
//#define DELETE_KEY 8
//#define ENTER_KEY 13
//#define ESCAPE_KEY 27
//#define SPACE_BAR 32
//
//
//
//class TextArea
//{
//private:
//
//    // Variables
//
//    sf::Text textArea;
//    sf::Font font;
//	std::ostringstream text;
//	bool is_selected = true;
//	const unsigned limit = 30;
//
//	// Functions
//
//	void inputLogic(int);
//	void deleteLastChar();
//
//
//public:
//
//    // Constructors & Destructors
//
//	TextArea();
//	TextArea(bool initial_selection);
//
//
//	// Functions
//
//	void setPosition(sf::Vector2f position);
//	void setSelected(bool selection);
////	std::string getText();
//	void drawTo(sf::RenderWindow& window);
//	void typedOn(sf::Event input);
//
//};
//
//
//
////class Box
////{
////private:
////
////    // Variables
////    sf::RectangleShape box;
////	sf::Font font;
////	sf::Text text;
////
////public:
////
////    // Variables
////
////
////
////    // Constructors & Destructors
////
////    Box(){}
////	Box(std::string Box_string, int char_size, sf::Vector2f size, sf::Color Box_color);
////	void setBackColor(sf::Color back_color);
////	void setPosition(sf::Vector2f Box_pos);
////	void drawTo(sf::RenderWindow& window);
////	bool isMouseOver(sf::RenderWindow& window);
////
////
////
////};
//
