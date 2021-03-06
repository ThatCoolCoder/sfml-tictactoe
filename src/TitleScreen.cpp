#include "TitleScreen.hpp"
#include <iostream>

void TitleScreen::setup()
{
    m_title = std::make_shared<sf::Text>();
    m_title->setString("Tic Tac Toe");
    m_title->setFont(shared::font);
    m_title->setCharacterSize(50);
    m_drawables.push_back(m_title);

    // m_playButton = std::make_shared<miniengine::Button>();
    // m_playButton->setSize(sf::Vector2f(90.0f, 50.0f));
    // m_playButton->setFillColor(sf::Color(40, 40, 40));
    // m_playButton->setCharacterSize(30);
    // m_playButton->setFont(shared::font);
    // m_playButton->setString("Play");
    // m_drawables.push_back(m_playButton);
}

void TitleScreen::update()
{
    // m_title->setPosition(gameManager->width / 2, 100);
    // miniengine::utils::centerAlignText(*m_title);
    // m_playButton->setPosition(gameManager->width / 2, gameManager->height / 2);
}

void TitleScreen::handleEvent(sf::Event& event)
{
    if (m_playButton->isPressed(event))
    {
        gameManager->queueLoadScene("TicTacToeGame");
    }
    std::cout << gameManager->frameCount << std::endl;
}