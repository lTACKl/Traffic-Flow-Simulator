#pragma once
class Drawable
{
public:
	Drawable(void);
	Drawable(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h);
	~Drawable(void);

	void Draw();

	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

private:
	SDL_Renderer *main_Renderer;

	// vairables that need to be shared with sub classes
protected:
	SDL_Rect rect;
	SDL_Texture *image;

	
};

