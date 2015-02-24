#include "Scene.h"

class Camera{
public:
	Camera(int sceneX = 1, int sceneY = 1);
	~Camera();

	void renderEntities();
	bool isEntityOnScr(Entity entity);
	void changeScene(int sceneX, int sceneY);

private:
	std::pair<int, int> sceneIndex;
	Scene currentScene;
};
