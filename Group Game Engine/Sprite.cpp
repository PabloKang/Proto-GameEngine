#include "Star Hornet.h"
#include "Sprite.h"

// Sprite object constructors
Sprite::Sprite()
{
	SDL_Rect sRect;
	sRect.h = 0;
	sRect.w = 0;
	sRect.x = 0;
	sRect.y = 0;

	Sprite(NULL, sRect);
}
Sprite::Sprite(Hardware* hrd, SDL_Rect rect)
{
	spriteRect.h = rect.h;
	spriteRect.w = rect.w;
	spriteRect.x = rect.x;
	spriteRect.y = rect.y;

	hardware = hrd;

	sequenceIndex = 0;
	center.x = rect.w / 2;
	center.y = rect.h / 2;
	angle = 0;
	scaleX = 1;
	scaleY = 1;
	flip = SDL_FLIP_NONE;
	facing = DOWN;
}


void Sprite::setPos(double x, double y)
{
	spriteRect.x = (int) x;
	spriteRect.y = (int) y;
}


// Sprite position functions
void Sprite::moveX(double delta)
{
	spriteRect.x += (int) delta;
}

void Sprite::moveY(double delta)
{
	spriteRect.y += (int) delta;
}

int Sprite::getX()
{
	return spriteRect.x;
}

int Sprite::getY()
{
	return spriteRect.y;
}


// Sprite rotation //////////////////////////////////////
void Sprite::autoCenter()
{
	center.x = spriteRect.w / 2;
	center.y = spriteRect.w / 2;

}

void Sprite::setCenter(SDL_Point centerPoint)
{
	center = centerPoint;
}

SDL_Point Sprite::getCenter()
{
	return center;
}

void Sprite::rotate(double deltaAngle)
{
	angle += deltaAngle;
}

void Sprite::setAngle(double specificAngle)
{
	angle = specificAngle;
}

double Sprite::getAngle()
{
	return angle;
}


// Sprite scaling ///////////////////////////////////////
void Sprite::changeScale(double deltaScaleX, double deltaScaleY)
{
	scaleX += deltaScaleX;
	scaleY += deltaScaleY;
}

void Sprite::setScale(double specificScaleX, double specificScaleY)
{
	scaleX = specificScaleX;
	scaleY = specificScaleY;
}

double Sprite::getScaleX() 
{
	return scaleX;
}

double Sprite::getScaleY()
{
	return scaleY;
}


// Sprite flipping //////////////////////////////////////
void Sprite::setFlip(SDL_RendererFlip flipType)
{
	flip = flipType;
}

SDL_RendererFlip Sprite::getFlip()
{
	return flip;
}


// makeFrame returns the unique index of the frame
int Sprite::makeFrame(SDL_Texture* tex, int x, int y)
{
	frame newFrame;
	newFrame.texture = tex;
	newFrame.x = x;
	newFrame.y = y;

	frames.push_back(newFrame);
	return frames.size() - 1;
}


// addFrameToSequence returns the number of frames in the sequence after the add
int Sprite::addFrameToSequence(std::string seqName, int frameIndex)
{
	if (frameSequenceMap.find(seqName) == frameSequenceMap.end()) {
		std::vector<int> indexes;
		frameSequenceMap.insert(std::pair<std::string,std::vector<int>>(seqName,indexes));
	}
	frameSequenceMap[seqName].push_back(frameIndex);

	return frameSequenceMap[seqName].size();
}


// show(int) renders the frame with the specified frameIndex
void Sprite::draw(int frameIndex)
{
	SDL_Rect dst;
	dst.h = (int) spriteRect.h * scaleY;
	dst.w = (int) spriteRect.w * scaleX;
	dst.x = spriteRect.x;
	dst.y = spriteRect.y;

	SDL_Rect clip;
	clip.h = spriteRect.h; 
	clip.w = spriteRect.w;
	clip.x = frames[frameIndex].x; 
	clip.y = frames[frameIndex].y;

	SDL_RenderCopyEx(hardware->renderer, frames[frameIndex].texture, &clip, &dst, angle, &center, flip);
}


// show(string) cycles through all frames in the specified sequence, one per call
void Sprite::draw(std::string sequence)
{
	if (sequence == "default"){
		draw(frameSequenceMap[sequence].at(facing));
	}
	else {
		if (sequenceIndex >= frameSequenceMap[sequence].size() - 1) {
			sequenceIndex = 0;
		}
		draw(frameSequenceMap[sequence].at(sequenceIndex));
		sequenceIndex++;
	}
}