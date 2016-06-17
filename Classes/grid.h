//
//  grid.h
//  MemoryGame
//
//  Created by Tin on 6/16/16.
//
//

#ifndef grid_h
#define grid_h


#include "cocos2d.h"
#include "tile.h"


class grid : public cocos2d::Layer
{
    
    
private:
    // cocos2d::Sprite* block;
    
    
public:
    
    
    
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void drawGrid();
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(grid);
};


#endif /* tile_h */