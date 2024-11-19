#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QString>

// Animation duration in ms
const int animationDuration = 700;

// Size of card in width
const int cardSizeWidth = 125;

// Size of card in height
const int cardSizeHeight= 200;

// Gap between cards on screen
const int shiftCardX = 30;

// Initial position of dealer's cards on screen on X axis
const int dealerCardInitialPositionX = 500;

// Initial position of dealer's cards on screen on Y axis
const int dealerCardInitialPositionY = 100;

// Initial position of human's cards on screen on X axis
const int humanCardInitialPositionX = 500;

// Initial position of human's cards on screen on Y axis
const int humanCardInitialPositionY = 400;

// shift betLabel from human hand on X axis
const int shiftBetLabelX = 100;

// shift betLabel from human hand on Y axis
const int shiftBetLabelY = 240;

// shift cashLabel from human hand on X axis
const int shiftCashLabelX = 60;

// shift cashLabel from human hand on Y axis
const int shiftCashLabelY = 240;

// font size of betLabel and cashLabel;
const int fontSizeCashAndBet = 18;

// shift between human hand and setOver label on X axis
const int shiftSetOverX = 25;

// shift between human hand and setOver label on Y axis
const int shiftSetOverY = 185;

// font size of betLabel and cashLabel;
const int fontSizeSetOver = 20;

// starting balance of human
const int startingBalance = 500;

// initial position of backs of cards on screen on X axis
const int deckInitialPositionX = 100;

// initial position of backs of cards on screen on Y axis
const int deckInitialPositionY = 75;

// Gap between backs of cards on screen on X axis
const int shiftDeckX = 5;

// Gap between backs of cards on screen on Y axis
const int shiftDeckY = 5;

// distance from cards to label
const int cardLabelShift = 40;

// game point to achieve
const int gamePoint = 21;

// distance of label "win" or "bust" from cards
const int cardLabelStatusLabelShift = 50;

// size of text label "win" or "bust"
const int cardLabelStatusLabelSize = 18;

// color of label "win"
const QString colorWinLabel = "green";

// color of label "bust"
const QString colorBustLabel = "red";

// amount of initial bet
const int initialBet = 5;

// initial value of background music volume
const float initialVolume = 0.1;

// path to file with background music
const QString pathToBackgroundMusic = "qrc:/sounds/background-music.mp3";

// path to file with card drop sound
const QString pathToCardDropSound = "qrc:/sounds/carddrop.mp3";

// path to file with restarting game sound
const QString pathToRestartGameSound = "qrc:/sounds/shuffleandbridge.mp3";

// color of bet label
const QString colorBetLabel = "white";

// color of Cash label
const QString colorCashLabel = "white";

// path to sound icon
const QString pathToSoundIcon = "url(:/images/sound.png)";

// path to no sound icon
const QString pathToNoSoundIcon = "url(:/images/noSound.png)";

// cards to be first initialized
const QString initialCardPath = ":/images/cards/child";

// path to directory with different decks
const QString pathToCardDirectory = "/images/cards";




#endif // CONSTANTS_H
