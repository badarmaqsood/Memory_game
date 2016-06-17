//
//  GameController.cpp
//  MemoryGame
//
//  Created by Tin on 6/17/16.
//
//

#include <stdio.h>
#include "GameController.h"

#include "cocos2d.h"
#include "tile.h"


GameController* GameController::instance = 0;

GameController::GameController()
{
    tiles = __Array::create();
    tiles->retain();
    count=0;
    
}

GameController*   GameController::get_instance()
{
    if(instance == NULL)
    {
        instance = new GameController();
    }
    return instance;
}


void GameController::tile_pressed(tile* tile_pressed)
{
    //this->count++;
    if(tiles->count() <2)
    {
        tiles->addObject(tile_pressed);
        tile_pressed->get_block()->setVisible(false);
        //block->setVisible(false);
        if(tiles->count() == 2)
        {
            tile* tile1 = (tile*)tiles->getObjectAtIndex(0);
            tile* tile2 = (tile*)tiles->getObjectAtIndex(1);
            if(tile1->getvalue() != tile2->getvalue()  || (tile1->get_index() == tile2->get_index()))
            {
                
                Director::getInstance()->getScheduler()->schedule(schedule_selector(GameController::wait_for_it), this, 1.0f,0,0, false);
                
            }
            else
            {
                tiles->removeAllObjects();
            }
        }
    }
    else
    {
        tile_pressed->get_block()->setVisible(true);
        
    }
    
    
    
    
    
}




void GameController::wait_for_it(float dt)
{
    tile* tile1 = (tile*)tiles->getObjectAtIndex(0);
    tile* tile2 = (tile*)tiles->getObjectAtIndex(1);
    tiles->removeAllObjects();
    tile1->get_block()->setVisible(true);
    tile2->get_block()->setVisible(true);
    
}
