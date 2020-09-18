#pragma once
class BaseState
{
public:
	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
};