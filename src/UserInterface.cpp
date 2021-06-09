//
//
//
///*------------------------------------------------------- TextArea Class ------------------------------------------------------------*/
//
//// Private Member Functions
//
//void TextArea::inputLogic(int char_typed)
//{
//    if (char_typed != DELETE_KEY)
//    {
//        text << static_cast<char>(char_typed);
//    }
//    else if (char_typed == DELETE_KEY)
//    {
//        if (text.str().length() > 0)
//            deleteLastChar();
//    }
//
//    textArea.setString(text.str() + "_");
//}
////
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
//    textArea.setString(string_text.c_str());
//}
//
//
//// Constructors & Destructors
//
//TextArea::TextArea(bool initial_selection = true)
//{
//    font.loadFromFile("fonts/SourceCodePro-Regular.ttf");
//    textArea.setFont(font);
//
//    is_selected = initial_selection;
//    if (initial_selection)
//        textArea.setString("_");
//    else
//        textArea.setString("");
//}
//
//void TextArea::setPosition(sf::Vector2f position)
//{
//    textArea.setPosition(position);
//}
//
//void TextArea::setSelected(bool selection)
//{
//    is_selected = selection;
//    if (selection)
//    {
//        std::string string_text = text.str();
//        std::string new_string_text = "";
//        for (int i = 0; i < string_text.length(); ++i)
//        {
//            new_string_text += string_text[i];
//        }
//        textArea.setString(new_string_text);
//    }
//}
//
//void TextArea::typedOn(sf::Event input)
//{
//    if (is_selected)
//    {
//        int char_typed = input.text.unicode;
//        if (char_typed < 128)
//        {
//            if (text.str().length() <= limit)
//                inputLogic(char_typed);
//            else if (text.str().length() >= limit && char_typed == DELETE_KEY)
//                deleteLastChar();
//        }
//    }
//}
//
//void TextArea::drawTo(sf::RenderWindow& window)
//{
//    window.draw(textArea);
//}
//
///*------------------------------------------------- End of TextArea Class ----------------------------------------------------*/
//
//
//
//
///*----------------------------------------------------- Box Class ------------------------------------------------------------*/
//
////Box::Box(std::string Box_string, int char_size, sf::Vector2f size, sf::Color Box_color)
////{
////    font.loadFromFile("/fonts/SourceCodePro-Regular.ttf");
////    text.setFont(font);
////    text.setString(Box_string);
////    text.setCharacterSize(char_size);
////
////    box.setSize(size);
////    box.setFillColor(Box_color);
////}
////
////void Box::setBackColor(sf::Color back_color)
////{
////    box.setFillColor(back_color);
////}
////
////void Box::setPosition(sf::Vector2f Box_pos)
////{
////    box.setPosition(Box_pos);
////
////    float x_pos = (Box_pos.x + box.getLocalBounds().width / 2) - (text.getGlobalBounds().width / 2);
////    float y_pos = (Box_pos.y + box.getLocalBounds().height / 2) - (text.getGlobalBounds().height / 2);
////
////    text.setPosition(x_pos, y_pos);
////}
////
////void Box::drawTo(sf::RenderWindow& window)
////{
////    window.draw(box);
////}
////
////bool Box::isMouseOver(sf::RenderWindow& window)
////{
////    float mouse_x_pos = sf::Mouse::getPosition(window).x;
////    float mouse_y_pos = sf::Mouse::getPosition(window).y;
////
////    float Box_x_pos = box.getPosition().x;
////    float Box_y_pos = box.getPosition().y;
////
////    float Box_x_pos_width = Box_x_pos + box.getLocalBounds().width;
////    float Box_y_pos_width = Box_y_pos + box.getLocalBounds().height;
////
////    if (mouse_x_pos < Box_x_pos_width && mouse_x_pos > Box_x_pos&& mouse_y_pos > Box_x_pos)
////        return true;
////    else
////        return false;
////}
//
///*------------------------------------------------ End of Box Class ------------------------------------------------------*/
