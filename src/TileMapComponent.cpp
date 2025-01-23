#include "TileMapComponent.h"

void TileMapComponent::LoadTileSet(std::string filePath)
{
    SDL_RWFromFile(filePath.c_str(), "r+b");
}
