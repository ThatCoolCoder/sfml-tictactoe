#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

namespace miniengine
{
    class GameManager;

    class Scene
    {
    public:
        Scene();
        Scene(std::string i_name);
        Scene(std::string i_name, sf::Color backgroundColor);

        std::string name = "";
        // Yes pointers are not very modern but it's annoying typing '.get()' on the alternatives (todo: use shared_ptr or unique_ptr)
        GameManager* gameManager = nullptr;

        void managerSetup();
        void managerUpdate();
        void managerHandleEvent(sf::Event& event);

    private:
        virtual void setup();
        virtual void update();
        virtual void handleEvent(sf::Event& event);

        sf::Color m_backgroundColor = sf::Color::Black;
    protected:
        std::vector<std::shared_ptr<sf::Drawable>> m_drawables;
    };
}