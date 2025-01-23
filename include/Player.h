#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"
#include <cstdint>

class Player : public Actor
{
public:
    Player(class Game* game);
    void UpdateActor(float deltaTime) override;
    void ProcessKeyboard(const std::uint8_t* state);
    float GetRightSpeed() const { return mRightSpeed; }
    float GetDownSpeed() const { return mDownSpeed; }
private:
    float mRightSpeed;
    float mDownSpeed;
    AnimSpriteComponent* animSpriteComponent;
    std::vector<std::vector<SDL_Texture*>> animations;
};