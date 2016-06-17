//
//  GameController.h
//  MemoryGame
//
//  Created by Tin on 6/17/16.
//
//

#ifndef GameController_h
#define GameController_h



#include "cocos2d.h"
#include "tile.h"

USING_NS_CC;



class GameController : public cocos2d::Node
{
private:
    GameController();
    static GameController* instance;
    __Array* tiles;
    
public:
   static GameController* get_instance();
    
    void tile_pressed(tile* tile,Node * block);
    void add_tile(tile * tile);
    
    
    
};

#endif /* GameController_h */
