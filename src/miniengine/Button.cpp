#include "Button.hpp"

namespace miniengine
{

    bool Button::isPressed(sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            sf::Vector2f clickPosition(event.mouseButton.x, event.mouseButton.y);
            return (m_backgroundRect.getGlobalBounds().contains(clickPosition));
        }
        else
        {
            return false;
        }
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states)
    {
        m_backgroundRect.setPosition(m_position);
        m_backgroundRect.setSize(m_size);
        m_text.setPosition(m_position + m_size / 2.0f);
        utils::centerAlignText(m_text);

        target.draw(m_backgroundRect, states);
        target.draw(m_text, states);
    }
    
    // Global SFML stuff

    void Button::setPosition(sf::Vector2f position)
    {
        m_position = position;
    }

    // Text stuff

    void Button::setFont(sf::Font& font)
    {
        m_text.setFont(font);
    }

    void Button::setString(std::string string)
    {
        m_text.setString(string);
    }

    void Button::setCharacterSize(unsigned int size)
    {
        m_text.setCharacterSize(size);
    }

    // Background stuff

    void Button::setFillColor(sf::Color& color)
    {
        m_backgroundRect.setFillColor(color);
    }

    void Button::setSize(sf::Vector2f size)
    {
        m_size = size;
    }
}