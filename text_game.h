#ifndef TEXT_GAME_H
#define TEXT_GAME_H

#include "text_gallows.h"
#include "word.h"
#include "wordlist.h"

enum struct GameState
{
    PLAYING,
    SUCCESS,
    FAILURE,
    COMPLETE,
};

class Game
{
  public:
    Game(size_t min_length);
    ~Game() = default;

    void run();

  private:
    void updatePlaying();
    void updateEnding();

    void drawPlaying() const;
    void drawSuccess() const;
    void drawFailure() const;
    void drawEnding() const;

    GameState state_;
    Wordlist words_;
    size_t min_length_;
    Word word_;
    TextGallows gallows_;
};

#endif // TEXT_GAME_H
