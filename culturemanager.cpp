#include "culturemanager.h"

CultureManager::CultureManager()
{
    //Our square object
    Culture culture;
	culture.birthPersonality();
	culture.birthPersonality();
	culture.birthPersonality();
}

void CultureManager::move()
{
    int numOfCultures = cultures.size();
    
    for(int i = 0; i < numOfCultures; i++)
    {
        cultures[i].move();   
    }
}

void CultureManager::draw()
{
    int numOfCultures = cultures.size();
    
    for(int i = 0; i < numOfCultures; i++)
    {
        cultures[i].draw();   
    }
}
