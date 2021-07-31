#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "pubsub.h"
#include "gamebar.h"
#include "Assets/resourcemanager.h"

namespace Life
{
    static constexpr char gameTitle[] = "Life 0.2";

    class GameWindow : public EventPublisher
    {
    public:
        GameWindow(std::shared_ptr<Assets::ResourceManager> resourceManager);
        virtual ~GameWindow();
        void setupBaseWindow();
        void setupGameBar(std::shared_ptr<Assets::ResourceManager> resourceManager);
        void setupBackground();
        sf::Vector2f getBaseWindowSize(){return baseWinSize;}
        void run();

    protected:

    private:
        sf::RenderWindow window;
        sf::RectangleShape backdrop;
        sf::Vector2f baseWinSize{0., 0.};
        std::shared_ptr<Gamebar> gamebar;
        std::shared_ptr<Assets::ResourceManager> resourceMgr;
    };
}
#endif // GAMEWINDOW_H
