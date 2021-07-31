#include "gamewindow.h"

namespace Life
{
    GameWindow::GameWindow()
    {
        setupBaseWindow();
        setupGameBar();
        setupBackground();
    }

    GameWindow::~GameWindow()
    {
        //dtor
    }

    void GameWindow::setupBaseWindow()
    {
        std::vector<sf::VideoMode> vmodes = sf::VideoMode::getFullscreenModes( );
        if ( vmodes.size( ) > 0 )
        {
            window.create( vmodes[0], gameTitle, sf::Style::Fullscreen );
            baseWinSize.x = vmodes[0].width;
            baseWinSize.y = vmodes[0].height;
        }
        else
        {
            window.create( sf::VideoMode( 640, 480, sf::VideoMode::getDesktopMode().bitsPerPixel ), "Life 1.0", sf::Style::None );
            baseWinSize.x = 640.;
            baseWinSize.y = 480.;
        }
    }

    void GameWindow::setupBackground()
    {
        backdrop.setSize( sf::Vector2f( baseWinSize.x, baseWinSize.y - Gamebar::GAMEBAR_HEIGHT ) );
        backdrop.setPosition( sf::Vector2f( 0.f, Gamebar::GAMEBAR_HEIGHT ) );
        backdrop.setFillColor( sf::Color2::Rich_Black );
    }

    void GameWindow::setupGameBar()
    {
        gamebar.updateSizeAndTitle( baseWinSize.x, gameTitle );
    }
}
