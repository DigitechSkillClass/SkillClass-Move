#pragma once
class cKeyManager
{
private:
	cKeyManager();
	~cKeyManager();
	
	cKeyManager(cKeyManager const&) = delete;            
	cKeyManager(cKeyManager&&) = delete;                 
	cKeyManager& operator=(cKeyManager const&) = delete; 
	cKeyManager& operator=(cKeyManager &&) = delete;     
public:
	static cKeyManager* GetInstance()
	{
		thread_local static cKeyManager instance;
		return &instance;
	}
};

