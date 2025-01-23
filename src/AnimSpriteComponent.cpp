#include "AnimSpriteComponent.h"
#include "Maths.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(8.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0)
	{
		// Update the current frame based on frame rate
		// and delta time
		mCurrFrame += mAnimFPS * deltaTime;

        if (animType == AnimType::LOOPING)
        {
            // Looping Animation
            // Wrap current frame if needed
            while (mCurrFrame >= mAnimTextures.size())
            {
                mCurrFrame -= mAnimTextures.size();
            }
        }
        else
        {
            // Single Animation
            mCurrFrame = mAnimTextures.size() - 1;
        }
	}
    // Set the current texture
    SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures, AnimType type)
{
	mAnimTextures = textures;
    animType = type;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}
