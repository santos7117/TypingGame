//#ifndef TYPEAREA_H
//#define TYPEAREA_H
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <sstream>
//
///* Macros for Keystrokes */
//#define DELETE_KEY 8
//#define ENTER_KEY 13
//#define ESCAPE_KEY 27
//
//
//class TypeArea
//{
//private:
//    sf::Text textbox;
//	std::ostringstream text;
//	bool is_selected = false;
//	const unsigned limit = 20;
//
//	void inputLogic(int);
//	void deleteLastChar();
//
//public:
//    TypeArea(bool);
//    ~TypeArea();
//
//    void setFont(sf::Font& font);
//	void setPosition(sf::Vector2f position);
//	void setSelected(bool selection = false);
//	std::string getText();
//	void drawTo(sf::RenderWindow& window);
//	void typedOn(sf::Event input);
//};
//
//#endif // TYPEAREA_H
