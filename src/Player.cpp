
#include "Player.h"
#include "Game.h"

Player::Player(Game* game)
        :Actor(game)
        ,mRightSpeed(0.0f)
        ,mDownSpeed(0.0f)
{
    // Create an animated sprite component
//    auto* asc = new AnimSpriteComponent(this);
    animSpriteComponent = new AnimSpriteComponent(this);
    std::vector<SDL_Texture*> idle = {game->GetTexture(RESOURCES_PATH"Assets/Character06.png")};
    std::vector<SDL_Texture*> walk = {
            game->GetTexture(RESOURCES_PATH"Assets/Character01.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character02.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character03.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character04.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character05.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character06.png"),
    };
    std::vector<SDL_Texture*> jump = {
            game->GetTexture(RESOURCES_PATH"Assets/Character07.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character08.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character09.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character10.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character11.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character12.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character13.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character14.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character15.png"),
    };
    std::vector<SDL_Texture*> punch = {
            game->GetTexture(RESOURCES_PATH"Assets/Character17.png"),
            game->GetTexture(RESOURCES_PATH"Assets/Character18.png"),
    };

    
    animations.push_back(idle);
    animations.push_back(walk);
    animations.push_back(jump);
    animations.push_back(punch);

    animSpriteComponent->SetAnimTextures(animations[3], AnimType::LOOPING);
}

void Player::UpdateActor(float deltaTime)
{
    Actor::UpdateActor(deltaTime);
    // Update position based on speeds and delta time
    Vector2 pos = GetPosition();
    pos.x += mRightSpeed * deltaTime;
    pos.y += mDownSpeed * deltaTime;

    // Restrict position to left half of screen
    if (pos.x < 25.0f)
    {
        pos.x = 25.0f;
    }
    else if (pos.x > 500.0f)
    {
        pos.x = 500.0f;
    }
    if (pos.y < 25.0f)
    {
        pos.y = 25.0f;
    }
    else if (pos.y > 743.0f)
    {
        pos.y = 743.0f;
    }
    SetPosition(pos);
}

void Player::ProcessKeyboard(const Uint8* state)
{
    mRightSpeed = 0.0f;
    mDownSpeed = 0.0f;

    // right/left
    if (state[SDL_SCANCODE_D])
    {
        mRightSpeed += 250.0f;
    }
    if (state[SDL_SCANCODE_A])
    {
        mRightSpeed -= 250.0f;
    }
    // up/down
    if (state[SDL_SCANCODE_S])
    {
        mDownSpeed += 300.0f;
    }
    if (state[SDL_SCANCODE_W])
    {
        mDownSpeed -= 300.0f;
    }
}
