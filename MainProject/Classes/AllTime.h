//AllTime.h
#pragma once

#include "../HuEngine.h"




class AllTime : public HE::Scene
{
public:
	AllTime();
	virtual ~AllTime() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

	float GetElapsedTime() const { return elapsedTime_; }

private:
	float elapsedTime_ = 0.0f; // åoâﬂéûä‘Åi
};
