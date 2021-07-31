#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include "pubsub.h"
#include "gamebar.h"

namespace Life
{
    static constexpr char gameTitle[] = "Life 0.2";

    class GameWindow : public EventPublisher
    {
    public:
        GameWindow();
        virtual ~GameWindow();
        void setupBaseWindow();
        void setupGameBar();
        void setupBackground();
        sf::Vector2f getBaseWindowSize(){return baseWinSize;}

    protected:

    private:
        sf::RenderWindow window;
        sf::RectangleShape backdrop;
        sf::Vector2f baseWinSize{0., 0.};
    };
}
#endif // GAMEWINDOW_H
