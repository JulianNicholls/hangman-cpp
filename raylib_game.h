#ifndef RAYLIB_GAME_H
#define RAYLIB_GAME_H

#include "raylib.h"

#include "graphic_gallows.h"
#include "images.h"
#include "letter_grid.h"
#include "window.h"
#include "wordlist.h"

enum struct GameState
{
    STARTING,
    PLAYING,
    SUCCESS,
    FAILURE,
    COMPLETE
};

class Game
{
  public:
    Game(const Window &window, size_t min_length);
    ~Game() = default;

    void run();

  private:
    void updateNothing()
    {
    }
    void updateStarting();
    void updatePlaying();
    void updateEnding();

    void drawNothing() const
    {
    }
    void drawStarting() const;
    void drawPlaying() const;
    void drawEnding() const;

    void say_click_to_continue() const;
    void show_guessed() const;

    const Window &window_;
    GameState state_;
    Wordlist words_;
    Word word_;
    GraphicGallows gallows_;
    LetterGrid letter_grid_;
    Font font_;
    ImageLoader images_;

    const static std::unordered_map<GameState, void (Game::*)()> updates_;
    const static std::unordered_map<GameState, void (Game::*)() const> draws_;
};

#endif // RAYLIB_GAME_H
