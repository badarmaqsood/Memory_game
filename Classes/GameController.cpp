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


GameController* GameController::instance = 0;

GameController::GameController()
{
    if(instance == NULL)
    {
        instance = new GameController;
    }
    tiles = __Array::create();
    tiles->retain();
}

 GameController*   GameController::get_instance()
{
    return instance;
}


void GameController::tile_pressed(tile* tile, Node * block)
{
    block->setVisible(false);
   
    
    
}

void GameController::add_tile(tile* tile)
{
    tiles->addObject(tile);
}
