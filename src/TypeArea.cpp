//#include "TypeArea.h"
//
//TypeArea::TypeArea(bool is_selected)
//{
//    bool is_selected = initial_selection;
//    if (initial_selection)
//        TextArea.setString("_");
//    else
//        TextArea.setString("");
//
//}
//
//TypeArea::~TypeArea()
//{
//
//}
//
//void TextArea::inputLogic(int char_typed)
//{
//    if (char_typed != DELETE_KEY && char_typed != ESCAPE_KEY && char_typed != ENTER_KEY)
//    {
//        text << static_cast<char>(char_typed);
//    }
//    else if (char_typed == DELETE_KEY)
//    {
//        if (text.str().length() > 0)
//            deleteLastChar();
//    }
//    TextArea.setString(text.str() + "_");
//}
//
//void TextArea::deleteLastChar()
//{
//    std::string string_text = text.str();
//    std::string new_string_text = "";
//    for (int i = 0; i < string_text.length() - 1; ++i)
//    {
//        new_string_text += string_text[i];
//    }
//    text.str("");
//    text << new_string_text;
//
//    TextArea.setString(string_text.c_str());
//}
//
//void TextArea::setFont(sf::Font& font)
//{
//    TextArea.setFont(font);
//}
//
//void TextArea::setPosition(sf::Vector2f position)
//{
//    TextArea.setPosition(position);
//}
//
//void TextArea::setSelected(bool selection)
//{
//    is_selected = selection;
//    if (!selection)
//    {
//        std::string string_text = text.str();
//        std::string new_string_text = "";
//        for (int i = 0; i < string_text.length(); ++i)
//        {
//            new_string_text += string_text[i];
//        }
//        TextArea.setString(new_string_text);
//    }
//}
//
//void TextArea::drawTo(sf::RenderWindow& window)
//{
//    window.draw(TextArea);
//}
//
//void TextArea::typedOn(sf::Event input)
//{
//    if (is_selected)
//    {
//        int char_typed = input.text.unicode;
//        if (char_typed < 128)
//        {
//            if (has_limit)
//            {
//                if (text.str().length() <= limit)
//                    inputLogic(char_typed);
//                else if (text.str().length() >= limit && char_typed == DELETE_KEY)
//                    deleteLastChar();
//            }
//            else
//                inputLogic(char_typed);
//        }
//    }
//}
//
