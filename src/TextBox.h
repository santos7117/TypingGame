#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"

// Define keys:
#define BACKSPACE_KEY 8
#define SPACE_KEY 32



class Textbox {

public:
	Textbox()
    {
		textbox.setCharacterSize(35);
		//textbox.setColor(sf::Color::Black);
		isSelected = true;

		// Check if the textbox is selected upon creation and display it accordingly:
		if(isSelected)
			textbox.setString("_");
		else
			textbox.setString("");
	}


	void setFont(sf::Font &font)
	{
	    textbox.setFont(font);
	}

	void setPosition(sf::Vector2f point) {
		textbox.setPosition(point);
	}

	// Set char limits:
	void setLimit(bool ToF) {
		hasLimit = ToF;
	}

	void setLimit(bool ToF, unsigned lim) {
		hasLimit = ToF;
		limit = lim - 1;
	}

	// Change selected state:
	void setSelected(bool sel) {
		isSelected = sel;

		// If not selected, remove the '_' at the end:
		if (!sel) {
			std::string t = text.str();
			std::string newT = "";
			for (unsigned i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}

	std::string getText() {
		return text.str();
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(textbox);
	}

	// Function for event loop:
	void typedOn(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;

			// Only allow normal inputs:
			if (charTyped < 128) {
				if (hasLimit) {
					// If there's a limit, don't go over it:
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					// But allow for char deletions:
					else if (text.str().length() > limit && charTyped == BACKSPACE_KEY) {
						deleteLastChar();
					}

				}
				// If no limit exists, just run the function:
				else {
					inputLogic(charTyped);
				}
			}

//			else if (charTyped == 20)
//            {
//
//            }
		}
	}

    // Delete the last character of the text:
	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (unsigned i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str() + "_");
	}



	void clearText()
	{
		text.str("");
	}


private:
	sf::Text textbox;

	std::ostringstream text;

	ResourceHolder resources_for_font;

	bool isSelected = true;
	bool hasLimit = true;
	unsigned limit = 20;



	// Get user input:
	void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (charTyped != BACKSPACE_KEY && charTyped != SPACE_KEY) {
			text << static_cast<char>(charTyped);
		}
		// If the key is delete, then delete the char:
		else if (charTyped == BACKSPACE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
        else if (charTyped == SPACE_KEY) {
			if (text.str().length() > 0) {
				clearText();
			}
        }
		// Set the textbox text:
		textbox.setString(text.str() + "_");
	}
};

