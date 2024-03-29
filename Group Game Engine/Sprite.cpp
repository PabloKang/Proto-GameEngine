#include "Sprite.h"
#include "Camera.h"
#include "SoundManager.h"
#include "SoundPlayer.h"

Sprite::Sprite() 
{
	sequenceIndex = 0;
	angle = 0;
	scaleX = 1;
	scaleY = 1;
	flip = SDL_FLIP_NONE;
	facing = DOWN;
}


// Sprite object constructors
Sprite::Sprite(float sID, float lvl, SDL_Rect rect, SDL_Renderer* ren, SoundManager* smr) : renderer(ren), sp(smr), sm(smr)
{
	id = sID;
	layer = lvl;
	spriteRect = rect;
	center.x = rect.w / 2.0;
	center.y = rect.h / 2.0;

	sequenceIndex = 0;
	angle = 0;
	scaleX = 1;
	scaleY = 1;
	flip = SDL_FLIP_NONE;
	facing = DOWN;

	type = SPRITE;
}

Sprite::~Sprite()
{

}


void Sprite::update()
{

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
	center.y = spriteRect.h / 2;

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


void Sprite::draw()
{
	draw("default");
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

	SDL_RenderCopyEx(renderer, frames[frameIndex].texture, &clip, &dst, angle, &center, flip);
}


// show(string) cycles through all frames in the specified sequence, one per call
void Sprite::draw(std::string sequence)
{
	if (sequence == "default"){
		draw(frameSequenceMap[sequence].at(0));// .at(facing));
	}
	else {
		if (sequenceIndex >= frameSequenceMap[sequence].size() - 1) {
			sequenceIndex = 0;
		}
		draw(frameSequenceMap[sequence].at(sequenceIndex));
		sequenceIndex++;
	}
}


void Sprite::addToCamera(Camera* cam)
{
	cam->queueSprite(*this);
}


bool Sprite::operator == (const Sprite& rhs) const{
	return id == rhs.id;
}
bool Sprite::operator != (const Sprite& rhs) const{
	return !(*this == rhs);
}
bool Sprite::operator <= (const Sprite& rhs) const{
	return layer <= -rhs.layer;
}
bool Sprite::operator < (const Sprite& rhs) const{
	return layer < -rhs.layer;
}
bool Sprite::operator >= (const Sprite& rhs) const{
	return rhs <= *this;
}
bool Sprite::operator >(const Sprite& rhs) const{
	return rhs < *this;
}


void Sprite::playSound(std::string soundstring, int repeat)
{
	sp.playSound(soundstring, repeat);

}