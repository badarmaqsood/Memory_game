
//
//  grid.cpp
//  MemoryGame
//
//  Created by Tin on 6/16/16.
//
//

#include <stdio.h>
#include "grid.h"


#include "ui/CocosGUI.h"
USING_NS_CC;

#include "cocos2d.h"

cocos2d::Scene* grid::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = grid::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool grid::init()
{
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
  
    
    auto background = LayerColor::create(Color4B(153,153,153,255));
    this->addChild(background);
    
    
    
   
    drawGrid();
    
    return true;
    
    
}



/*

 
 */

void grid::drawGrid()
{
    
    auto layer1 = LayerGradient::create(Color4B(163, 0, 0, 255), Color4B(163, 0, 0, 255));
    layer1->setContentSize(Size(210, 220));
    layer1->setPosition(Vec2(160, 10));
    addChild(layer1,2);
    
    auto layer2 = LayerGradient::create(Color4B(163, 0, 0, 163), Color4B(163, 0, 0, 163));
    layer2->setContentSize(Size(210, 220));
    layer2->setPosition(Vec2(160, 10));
    addChild(layer2,1);
    
    
    
    int x1=10,y1=10,x2=50,y2=50;
    
    
    Vec2 start = Vec2(x1,y1);
    Vec2 end = Vec2(x2,y2);
    
    
    
    
    
    // add the label as a child to this layer
    
    
    
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            tile* block = tile::create();
            Label* label = Label::create();
            int num= (row * 4) + col +1;
            block->init(start,end , label, num);
            block->setPosition(10 + (block->getContentSize().width + 10) * col, 7 + (block->getContentSize().width + 15) * row);
            label->setPosition(29 + (block->getContentSize().width + 10) * col, 21 + (block->getContentSize().width + 15) * row);
            
            layer2->addChild(label,1);
            layer1->addChild(block,10);
            
            
            x1+=50;
            
            x2+=50;
            

        }
        y1+=50;
        x1=10;
        y2+=50;
        x2=50;
    }
    
    
    }



