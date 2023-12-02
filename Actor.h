#pragma once
#include "raylib.h"
#include "Components.h"
#include <vector>
#include <memory>

class Actor
{
public:
	Actor();
	~Actor();
	void Update();
	bool willCollide(float speed_xP, float speed_yP);
	
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* component(new T(std::forward<TArgs>(mArgs)...));
		std::unique_ptr<Components> uPtr{ component };
		components.emplace_back(std::move(uPtr));
		component->init();


		return *component;
	}

	template <typename T>
	T* getComponent()
	{
		if (this != NULL)
		{
			for (auto& component : components)
			{
				if (component && typeid(*component) == typeid(T))
				{
					return static_cast<T*>(component.get());
				}
			}
			return nullptr;
		}
	}

private:
	std::vector<std::unique_ptr<Components>> components;
	
};

