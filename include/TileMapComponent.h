#pragma once
#include "SpriteComponent.h"
#include "string"

class TileMapComponent : public SpriteComponent
{
public:
    void Update(float deltaTime) override;
    void LoadTileSet(std::string filePath);
    void LoadLayoutFile(std::string filePath);

private:
    SDL_Texture* tileSet;

};