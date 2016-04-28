/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <SFML/Graphics.hpp>
#include "movableelement.h"
#include "clock.h"

//!
//! \brief Player's character's class.
//! Inherit from MovableElement
//!
class Character : public MovableElement
{
private:

    ///Character's speed
    int m_speed;
    ///Character's direction
    int m_dir;

    ///Character's maximum life rate
    int m_maxLife;
    ///Character's actual life rate
    int m_actualLife;

	///Character's score
    int m_score;
	
	///Character's coin's number
    int m_coin;

	///Jump's Clock
    Clock jumpTime;
	///Character's jump state boolean
    bool m_jumping;

	///Invincibility bonus timer
    Clock m_InvicibleTimer;

	///Double Jump Bonus Timer
    Clock m_DoubleJumpTimer;

	///Score Multiplayer Bonus Timer
    Clock m_ScoreMultiplierTimer;

public:

    //// CONSTRUCTORS /////
    Character(float x, float y, int w, int h, float dx, float dy, int maxLife=100);
    //~Character() override;


    void addLife(int const& x);
    void subLife(int const& x);
    void damage(int const& damage);
    void move(int screen_w);
    void startInvicibility(int const& countdown);
    void startDoubleJump(int const& countdown);
    void startScoreMultiplier(const int &countdown);
    void addScore(int &x);
    void addCoin(int &x);
    void isJumping();
    void jump();

    void setDX(float d);

	//// Getter ////
	
    bool isInvicible();	
    int getGold() const;
    int getScore() const;
    int getMaxLife() const;
    int getLife() const;

};

#endif // CHARACTER_H
