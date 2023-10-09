#include "SBDL.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
SDL_Rect backgroundmenurect={0,0,500,500};
SDL_Rect playrect={200,50,100,100};
SDL_Rect muterect={200,50,100,100};
SDL_Rect changerect={200,170,100,100};
SDL_Rect playagainrect={200,220,100,100};
SDL_Rect mainrect={200,320,100,100};
SDL_Rect exitrect={200,400,100,100};
SDL_Rect backrect={200,300,100,100};
SDL_Rect continuerect={200,20,100,100};
SDL_Rect chancerect={300,220,100,100};
SDL_Rect settingrect={200,200,100,100};
SDL_Rect arrowrect ={250,250,20,20};
SDL_Rect backgroundgamerect={0,0,500,500};
SDL_Rect blockrectright1[10];
SDL_Rect follow[20];
SDL_Rect pauserect={0,450,50,50};
SDL_Rect blockrectright2[10];
SDL_Rect blockrectleft1[10];
SDL_Rect blockrectleft2[10];
SDL_Rect gem_purple[5];
SDL_Rect gem_yellow={240,-50,10,10};
bool game=false;
bool initialize3=false;
bool initialize1= false;
bool initialize2= false;
bool initialize4=false;
bool initialize5=false;
int fps=0;
int highscore=0;
int arrowangle=0;
int main(int argc, char *argv[])
{


    fstream f1("highscore.txt", ios::in);
    f1 >> highscore;
    f1.close();
    const int window_width = 500;
    const int window_height = 500;

    SBDL::InitEngine("Aminsaveh", window_width, window_height);
    for (int k = 0; k <10; ++k) {
        blockrectright1[k]={0,-500,50,50};
        blockrectright2[k]={0,-1000,50,50};
        blockrectleft1[k]={280,-500,280,50};
        blockrectleft2[k]={280,-1000,280,50};
        follow[k]={0,0,20,20};
    }
    for (int i = 0; i <5 ; ++i) {
        gem_purple[i]={240,-200,10,10};
    }

    int widthmenux=400;
    int widthmenuw=100;
    int score=0;
    int velocity =1;
    int velocitymenu=5;
    bool firstmenu= true;
    const int FPS = 60; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame
     Texture arrowy= SBDL::loadTexture("assets/img/arrow.png");
    Texture arrowb= SBDL::loadTexture("assets/img/arrowblue.png");
    Texture change= SBDL::loadTexture("assets/img/change.png");
    Texture mute= SBDL::loadTexture("assets/img/mute.png");
    Sound *catchsound = SBDL::loadSound("assets/sounds/unicorn.wav");
    Sound *crash = SBDL::loadSound("assets/sounds/die.wav");
    Music *music = SBDL::loadMusic("assets/sounds/music.wav");
     Texture block = SBDL::loadTexture("assets/img/box.png");
    Texture bblock = SBDL::loadTexture("assets/img/bbox.png");
    Texture backgroundgame = SBDL::loadTexture("assets/img/ground_4.png");
    Texture backgroundmenu = SBDL::loadTexture("assets/img/ground_1.png");
    Texture setting = SBDL::loadTexture("assets/img/setting.png");
    Texture play = SBDL::loadTexture("assets/img/play.png");
    Texture continueb= SBDL::loadTexture("assets/img/continue.png");
    Texture main = SBDL::loadTexture("assets/img/main.png");
    Texture exit = SBDL::loadTexture("assets/img/exit.png");
    Texture pause = SBDL::loadTexture("assets/img/pause.png");
    Texture playagain = SBDL::loadTexture("assets/img/playagain.png");

    Texture scoretexture,losetexture;
    Texture gemp = SBDL::loadTexture("assets/img/gem.png");
    Texture gemy = SBDL::loadTexture("assets/img/gem2.png");
    Font *font = SBDL::loadFont("assets/fonts/CenturyGothic.ttf", 50);
    bool bluearrow=false;
    int counterf=0;
    int fpsrecord=0;
    bool settingb =false;
    bool pauseb =false;
    bool playingb=true;
    srand(time(NULL));
    SBDL::playMusic(music,20);
    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();

        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        //Game logic code

        ////////////////////////////////menu\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\?
        if (game == false) {
            if (firstmenu == true) {
                if (settingb == false) {

                    score = 0;
                    SBDL::showTexture(backgroundmenu, backgroundmenurect);
                    SBDL::showTexture(setting, settingrect);
                    SBDL::showTexture(play, playrect);
                    SBDL::showTexture(exit, exitrect);
                    /////////////////////////////////////////////////////////////menu background\\\\\\\\\\\\\\\\\\\\?
                    if (blockrectleft1[0].y >= 500) {
                        initialize5 = false;
                        blockrectleft1[0].y = -500;
                        blockrectright1[0].y = -500;
                    }
                    blockrectleft1[0].y += (velocitymenu);
                    blockrectright1[0].y += (velocitymenu);

                    if (initialize5 == false) {
                        if (widthmenux == 400) {
                            for (int i = 0; i < 10; ++i) {
                                blockrectright1[i].w = widthmenuw;
                                blockrectleft1[i].x = widthmenux;
                                widthmenux -= 10;
                                widthmenuw += 10;
                            }
                            initialize5 = true;
                        } else {
                            widthmenux = 400;
                            widthmenuw = 100;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright1[i].w = widthmenuw;
                                blockrectleft1[i].x = widthmenux;
                                widthmenux += 10;
                                widthmenuw -= 10;
                            }
                            initialize5 = true;
                        }
                    }
                    for (int i = 0; i < 10; ++i) {
                        blockrectright1[i].y = blockrectright1[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectright1[i]);
                        blockrectleft1[i].y = blockrectleft1[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectleft1[i]);
                    }

                    if (blockrectleft2[0].y >= 500) {
                        initialize4 = false;
                        blockrectleft2[0].y = -500;
                        blockrectright2[0].y = -500;
                    }

                    blockrectright2[0].y += (velocitymenu);
                    blockrectleft2[0].y += (velocitymenu);

                    if (initialize4 == false) {
                        if (widthmenux == 300) {
                            widthmenux = 500;
                            widthmenuw = 0;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright2[i].w = widthmenuw;
                                blockrectleft2[i].x = widthmenux;
                                widthmenux -= 10;
                                widthmenuw += 10;
                            }
                            widthmenux = 500;
                            widthmenuw = 0;
                            initialize4 = true;
                        } else {
                            widthmenux = 300;
                            widthmenuw = 200;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright2[i].w = widthmenuw;
                                blockrectleft2[i].x = widthmenux;
                                widthmenux += 10;
                                widthmenuw -= 10;
                            }
                            widthmenuw = 100;
                            widthmenux = 400;
                            initialize4 = true;

                        }
                    }
                    for (int i = 0; i < 10; ++i) {
                        blockrectright2[i].y = blockrectright2[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectright2[i]);
                        blockrectleft2[i].y = blockrectleft2[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectleft2[i]);
                    }

                    //////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\?
                    if (SBDL::mouseInRect(playrect)) {
                        if (SBDL::Mouse.clicked(1)) {
                            fpsrecord=0;
                            game = true;
                            arrowrect = {250, 250, 20, 20};

                            for (int k = 0; k < 10; ++k) {
                                blockrectright1[k] = {0, -500, 50, 50};
                                blockrectright2[k] = {0, -1000, 50, 50};
                                blockrectleft1[k] = {280, -500, 280, 50};
                                blockrectleft2[k] = {280, -1000, 280, 50};

                            }
                            for (int i = 0; i < 5; ++i) {
                                gem_purple[i] = {240, -200, 10, 10};
                            }
                            initialize1 = false;
                            initialize2 = false;
                            initialize3 = false;
                            counterf = 0;
                        }
                    }
                }
                if(SBDL::mouseInRect(exitrect)){
                    if(SBDL::Mouse.clicked(1))
                        return 0;

                }
                if (SBDL::mouseInRect(settingrect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        settingb = true;
                    }
                }
                if (settingb == true) {
                    SBDL::showTexture(backgroundmenu, backgroundmenurect);
                    SBDL::showTexture(change, changerect);
                    SBDL::showTexture(exit, backrect);
                    SBDL::showTexture(mute, muterect);
                    if (SBDL::mouseInRect(muterect)) {
                        if (SBDL::Mouse.clicked(1)) {
                            if (playingb) {
                                SBDL::stopMusic();
                                playingb = false;
                            } else {
                                SBDL::playMusic(music, 20);
                                playingb = true;
                            }
                        }
                    }
                    if (SBDL::mouseInRect(changerect)) {
                        if (SBDL::Mouse.clicked(1)) {
                            if (bluearrow == false) {
                                bluearrow = true;

                            } else {
                                bluearrow = false;

                            }
                        }
                    }




                    ///////////////////////////////////////////////setting background\\\\\\\\\\\\\\\\\\\\\\\\?
                    if (blockrectleft1[0].y >= 500) {
                        initialize5 = false;
                        blockrectleft1[0].y = -500;
                        blockrectright1[0].y = -500;
                    }
                    blockrectleft1[0].y += (velocitymenu);
                    blockrectright1[0].y += (velocitymenu);

                    if (initialize5 == false) {

                        if (widthmenux == 400) {
                            for (int i = 0; i < 10; ++i) {
                                blockrectright1[i].w = widthmenuw;
                                blockrectleft1[i].x = widthmenux;
                                widthmenux -= 10;
                                widthmenuw += 10;
                            }
                            initialize5 = true;
                        } else {
                            widthmenux = 400;
                            widthmenuw = 100;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright1[i].w = widthmenuw;
                                blockrectleft1[i].x = widthmenux;
                                widthmenux += 10;
                                widthmenuw -= 10;
                            }
                            initialize5 = true;
                        }
                    }
                    for (int i = 0; i < 10; ++i) {
                        blockrectright1[i].y = blockrectright1[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectright1[i]);
                        blockrectleft1[i].y = blockrectleft1[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectleft1[i]);
                    }

                    if (blockrectleft2[0].y >= 500) {
                        initialize4 = false;
                        blockrectleft2[0].y = -500;
                        blockrectright2[0].y = -500;
                    }

                    blockrectright2[0].y += (velocitymenu);
                    blockrectleft2[0].y += (velocitymenu);

                    if (initialize4 == false) {
                        if (widthmenux == 300) {
                            widthmenux = 500;
                            widthmenuw = 0;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright2[i].w = widthmenuw;
                                blockrectleft2[i].x = widthmenux;
                                widthmenux -= 10;
                                widthmenuw += 10;
                            }
                            widthmenux = 500;
                            widthmenuw = 0;
                            initialize4 = true;
                        } else {
                            widthmenux = 300;
                            widthmenuw = 200;
                            for (int i = 0; i < 10; ++i) {
                                blockrectright2[i].w = widthmenuw;
                                blockrectleft2[i].x = widthmenux;
                                widthmenux += 10;
                                widthmenuw -= 10;
                            }
                            widthmenuw = 100;
                            widthmenux = 400;
                            initialize4 = true;

                        }
                    }
                    for (int i = 0; i < 10; ++i) {
                        blockrectright2[i].y = blockrectright2[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectright2[i]);
                        blockrectleft2[i].y = blockrectleft2[0].y + (50 * i);
                        SBDL::showTexture(bblock, blockrectleft2[i]);
                    }




                    ///////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\?
                    if (SBDL::mouseInRect(backrect)) {
                        if (SBDL::Mouse.clicked(1)) {
                            settingb = false;
                        }
                    }
                    if (bluearrow == false) {
                        Texture changetexture = SBDL::createFontTexture(font, "YELLOW", 255, 255, 0);
                        SBDL::showTexture(changetexture, 160, 0);
                    } else {
                        Texture changetexture = SBDL::createFontTexture(font, "BLUE", 0, 0, 255);
                        SBDL::showTexture(changetexture, 200, 0);
                    }
                }
            } else if (pauseb == true) {
                SBDL::showTexture(backgroundgame, backgroundgamerect);
                SBDL::showTexture(playagain, playagainrect);
                SBDL::showTexture(main, mainrect);
                SBDL::showTexture(continueb, continuerect);

                if (SBDL::mouseInRect(continuerect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        game = true;
                        pauseb = false;

                    }

                }
                if (SBDL::mouseInRect(playagainrect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        fpsrecord=0;
                        counterf = 0;
                        velocity = 1;
                        pauseb = false;
                        score = 0;
                        game = true;
                        arrowrect = {250, 250, 20, 20};
                        for (int k = 0; k < 10; ++k) {
                            blockrectright1[k] = {0, -500, 50, 50};
                            blockrectright2[k] = {0, -1000, 50, 50};
                            blockrectleft1[k] = {280, -500, 280, 50};
                            blockrectleft2[k] = {280, -1000, 280, 50};

                        }
                        for (int i = 0; i < 5; ++i) {
                            gem_purple[i] = {240, -200, 10, 10};
                        }
                        initialize1 = false;
                        initialize2 = false;
                        initialize3 = false;
                    }
                }
                if (SBDL::mouseInRect(mainrect)) {

                    if (SBDL::Mouse.clicked(1)) {
                        counterf = 0;
                        for (int k = 0; k < 10; ++k) {
                            blockrectright1[k] = {0, -500, 50, 50};
                            blockrectright2[k] = {0, -1000, 50, 50};
                            blockrectleft1[k] = {280, -500, 280, 50};
                            blockrectleft2[k] = {280, -1000, 280, 50};

                        }
                        initialize5 = false;
                        initialize4 = false;
                        firstmenu = true;
                        pauseb = false;
                    }
                }
            } else {


                SBDL::showTexture(backgroundgame, backgroundgamerect);
                if (score > highscore) {
                    if (fpsrecord < 600) {
                        Texture record = SBDL::createFontTexture(font, "New Record! ", 0, 0, 0);
                        SBDL::showTexture(record, 100, 200);
                        fpsrecord++;
                    }

                    highscore = score;
                    fstream file("highscore.txt", ios::out);
                    file << highscore << endl;
                    file.close();
                }
                losetexture = SBDL::createFontTexture(font, "YOU LOSE!", 0, 0, 0);
                scoretexture = SBDL::createFontTexture(font, "Score: " + to_string(score), 0, 0, 0);
                Texture highscoretexture = SBDL::createFontTexture(font, "highScore: " + to_string(highscore), 0, 0, 0);
                SBDL::showTexture(scoretexture, 150, 30);
                SBDL::showTexture(losetexture, 130, 90);
                SBDL::showTexture(highscoretexture, 100, 150);
                SBDL::showTexture(playagain, playagainrect);
                SBDL::showTexture(main, mainrect);
                if (counterf >= 3) {
                    SBDL::showTexture(continueb, chancerect);
                }
                if (SBDL::mouseInRect(playagainrect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        fpsrecord=0;
                        counterf = 0;
                        velocity = 1;
                        score = 0;
                        game = true;
                        arrowrect = {250, 250, 20, 20};
                        for (int k = 0; k < 10; ++k) {
                            blockrectright1[k] = {0, -500, 50, 50};
                            blockrectright2[k] = {0, -1000, 50, 50};
                            blockrectleft1[k] = {280, -500, 280, 50};
                            blockrectleft2[k] = {280, -1000, 280, 50};

                        }
                        for (int i = 0; i < 5; ++i) {
                            gem_purple[i] = {240, -200, 10, 10};
                        }
                        initialize1 = false;
                        initialize2 = false;
                        initialize3 = false;
                    }
                }
                if (SBDL::mouseInRect(mainrect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        counterf = 0;
                        initialize5 = false;
                        initialize4 = false;
                        firstmenu = true;
                    }
                }
                if (SBDL::mouseInRect(chancerect)) {
                    if (SBDL::Mouse.clicked(1)) {
                        counterf -= 3;
                        velocity = 1;
                        game = true;
                        arrowrect = {220, 200, 20, 20};
                    }

                }

            }
        }


        ////////////////////gem\\\\\\\\\\\\\\\\\\?
        if (game == true) {

            if (score > 0) {
                if (score % 100 == 0 || score % 110 == 0) {
                    score += 10;
                    velocity++;
                }
            }

            firstmenu = false;
            SBDL::showTexture(backgroundgame, backgroundgamerect);

            if (SBDL::keyHeld(SDL_SCANCODE_SPACE)) {
                arrowrect.x += 2;

                if (arrowangle < 45) {
                    if (bluearrow == true)
                        SBDL::showTexture(arrowb, arrowangle, arrowrect);
                    else
                        SBDL::showTexture(arrowy, arrowangle, arrowrect);
                    arrowangle += 5;
                } else {
                    if (bluearrow == true)
                        SBDL::showTexture(arrowb, arrowangle, arrowrect);
                    else
                        SBDL::showTexture(arrowy, arrowangle, arrowrect);
                }
                if (counterf >= 1) {
                    follow[0].x = arrowrect.x - 17;
                    follow[0].y = arrowrect.y + 12;
                    SBDL::showTexture(gemy, 45, follow[0]);
                }
                if (counterf > 1) {
                    for (int i = 1; i < counterf; ++i) {
                        follow[i].x = follow[i - 1].x - 17;
                        follow[i].y = follow[i - 1].y + 12;
                        SBDL::showTexture(gemy, 45, follow[i]);
                    }
                }

            } else {
                arrowrect.x -= 2;
                if (arrowangle > -45) {
                    if (bluearrow == true)
                        SBDL::showTexture(arrowb, arrowangle, arrowrect);
                    else
                        SBDL::showTexture(arrowy, arrowangle, arrowrect);
                    arrowangle -= 5;
                } else {
                    if (bluearrow == true)
                        SBDL::showTexture(arrowb, arrowangle, arrowrect);
                    else
                        SBDL::showTexture(arrowy, arrowangle, arrowrect);
                }
                if (counterf >= 1) {
                    follow[0].x = arrowrect.x + 17;
                    follow[0].y = arrowrect.y + 12;
                    SBDL::showTexture(gemy, arrowangle, follow[0]);
                }
                if (counterf > 1) {
                    for (int i = 1; i < counterf; ++i) {
                        follow[i].x = follow[i - 1].x + 17;
                        follow[i].y = follow[i - 1].y + 12;
                        SBDL::showTexture(gemy, arrowangle, follow[i]);
                    }
                }
            }

            if (initialize3 == false) {
                for (int j = 0; j < 5; ++j) {
                    gem_purple[j].y = (-1 * 100 * (rand() % 10));
                    gem_purple[j].x = 100 + (rand() % 200);

                }
                initialize3 = true;
            }
            if (gem_yellow.y >= 500) {
                gem_yellow.x = 140 + (rand() % 200);
                gem_yellow.y = (-1 * 10 * (rand() % 30)) - 200;
            }
            for (int k = 0; k < 5; ++k) {

                if (gem_purple[k].y >= 500) {
                    gem_purple[k].y = 100 * (-1 * (rand() % 10));
                    gem_purple[k].x = (rand() % 300);
                }

            }
            for (int l = 0; l < 5; ++l) {
                for (int i = 0; i < 10; ++i) {
                    if (SBDL::hasIntersectionRect(gem_purple[l], blockrectleft1[i]))
                        gem_purple[l].x = 600;

                    if
                            (SBDL::hasIntersectionRect(gem_purple[l], blockrectleft2[i]))
                        gem_purple[l].x = 600;
                    if
                            (SBDL::hasIntersectionRect(gem_purple[l], blockrectright1[i]))
                        gem_purple[l].x = 600;
                    if (SBDL::hasIntersectionRect(gem_purple[l], blockrectright2[i]))
                        gem_purple[l].x = 600;
                }
            }
            for (int i = 0; i < 10; ++i) {
                if (SBDL::hasIntersectionRect(gem_yellow, blockrectleft1[i]))
                    gem_yellow.x = 500;

                if
                        (SBDL::hasIntersectionRect(gem_yellow, blockrectleft2[i]))
                    gem_yellow.x = 500;
                if
                        (SBDL::hasIntersectionRect(gem_yellow, blockrectright1[i]))
                    gem_yellow.x = 500;
                if (SBDL::hasIntersectionRect(gem_yellow, blockrectright2[i]))
                    gem_yellow.x = 500;
            }

            for (int j = 0; j < 5; ++j) {
                SBDL::showTexture(gemp, gem_purple[j]);
                SBDL::showTexture(gemy, gem_yellow);
                gem_purple[j].y += velocity;
            }
            SBDL::showTexture(gemy, gem_yellow);
            gem_yellow.y += velocity;
            ///////////////////left and right 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\?
            if (blockrectleft1[0].y >= 500) {
                initialize1 = false;
                blockrectleft1[0].y = -500;
                blockrectright1[0].y = -500;
            }
            blockrectleft1[0].y += velocity;
            blockrectright1[0].y += velocity;

            if (initialize1 == false) {
                for (int i = 0; i < 10; ++i) {
                    blockrectright1[i].w = (rand() % 160);
                    blockrectleft1[i].x = 240 + (rand() % 150);
                }
                initialize1 = true;
            }
            if (initialize1 == true) {
                for (int i = 0; i < 10; ++i) {
                    blockrectright1[i].y = blockrectright1[0].y + (50 * i);
                    SBDL::showTexture(block, blockrectright1[i]);
                    blockrectleft1[i].y = blockrectleft1[0].y + (50 * i);
                    SBDL::showTexture(block, blockrectleft1[i]);
                }
            }
            ///////////////////////right and left 2\\\\\\\\\\\\\\\\?
            srand(time(NULL));
            if (blockrectleft2[0].y >= 500) {
                initialize2 = false;
                blockrectleft2[0].y = -500;
                blockrectright2[0].y = -500;
            }
            blockrectright2[0].y += velocity;
            blockrectleft2[0].y += velocity;


            if (initialize2 == false) {
                for (int i = 0; i < 10; ++i) {
                    blockrectright2[i].w = (rand() % 200);
                    blockrectleft2[i].x = 240 + (rand() % 200);

                }
                initialize2 = true;
            }
            if (initialize2 == true) {


                for (int i = 0; i < 10; ++i) {
                    blockrectright2[i].y = blockrectright2[0].y + (50 * i);
                    SBDL::showTexture(block, blockrectright2[i]);
                    blockrectleft2[i].y = blockrectleft2[0].y + (50 * i);
                    SBDL::showTexture(block, blockrectleft2[i]);
                }


            }
            /////////////////////////////////arrow\\\\\\\\\\\\\\\\\\\\\\\\\\?

            for (int n = 0; n < 5; ++n) {
                if (SBDL::hasIntersectionRect(arrowrect, gem_purple[n])) {
                    SBDL::playSound(catchsound, 1);
                    gem_purple[n].x = 500;
                    score += 10;
                }
            }
            if (SBDL::hasIntersectionRect(arrowrect, gem_yellow)) {
                SBDL::playSound(catchsound, 1);
                gem_yellow.x = 500;
                counterf++;
                score += 20;
            }
            for (int m = 0; m < 10; ++m) {
                if (SBDL::pointInRect(arrowrect.x + 10, arrowrect.y + 10, blockrectright1[m])) {
                    SBDL::playSound(catchsound, 1);
                    game = false;
                } else if (SBDL::pointInRect(arrowrect.x + 10, arrowrect.y + 10, blockrectright2[m])) {
                    SBDL::playSound(crash, 1);
                    game = false;
                } else if (SBDL::pointInRect(arrowrect.x + 10, arrowrect.y, blockrectleft1[m])) {
                    SBDL::playSound(crash, 1);
                    game = false;
                } else if (SBDL::pointInRect(arrowrect.x + 10, arrowrect.y, blockrectleft2[m])) {
                    SBDL::playSound(crash, 1);
                    game = false;
                }

            }
            if(arrowrect.x>500||arrowrect.x<0)
                game= false;

            //////////////////////////////////////////////////score\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\?

            scoretexture = SBDL::createFontTexture(font, "Score: " + to_string(score), 0, 0, 0);
            SBDL::showTexture(scoretexture, 240, 0);
            SBDL::showTexture(pause, pauserect);
            if (SBDL::mouseInRect(pauserect)) {
                if (SBDL::Mouse.clicked(1)) {
                    game = false;
                    pauseb = true;
                }
            }
            if (counterf % 3 == 0 && counterf != 0) {
                if (fps < 60) {
                    Texture chancetexture = SBDL::createFontTexture(font, "New Chance! ", 0, 0, 0);
                    SBDL::showTexture(chancetexture, 100, 100);
                    fps++;
                }
                fps=0;
            }
            if (score > highscore) {
                if (fpsrecord < 300) {
                    Texture record = SBDL::createFontTexture(font, "New Record! ", 0, 0, 0);
                    SBDL::showTexture(record, 100, 400);
                    fpsrecord++;
                }
            }



        }
        SBDL::updateRenderScreen();

        int elapsedTime = SBDL::getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - elapsedTime);

    }
}