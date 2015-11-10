#pragma once


class Scene
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
};

class SceneManager
{

	static Vector<std::unique_ptr<Scene>> scene;

public:

	static void Push(Scene *_scene)
	{

		scene.emplace_back(std::unique_ptr<Scene>(_scene));

	}

	static void Pop()
	{

		scene.pop_back();

		return;

		scene.back().release();

		scene.erase(scene.end());
	}

	static void Draw()
	{

		scene.back()->draw();

	}

	static void Update()
	{

		scene.back()->update();
	}

};

Vector<std::unique_ptr<Scene>> SceneManager::scene;

