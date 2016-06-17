//
//  tile.cpp
//  MemoryGame
//
//  Created by Tin on 6/16/16.
//
//

#include "ui/CocosGUI.h"
#include "tile.h"
#include "grid.h"
USING_NS_CC;
#include "GameController.h"

#define kTileWidth 40



tile* tile::create()
{
    tile* t = new tile();
    t->autorelease();
    
    return t;
}


bool tile::init(Vec2 start, Vec2 end, Label* label, int num)
{
    
    value =2;
    block = DrawNode::create();
    block->drawSolidRect(Vec2::ZERO, Vec2(kTileWidth,kTileWidth), Color4F(0.8,0.8,0.8,1.0));
    this->setContentSize(Size(kTileWidth,kTileWidth));
    
    
    
    this->addChild(block,10);
    __String* number= __String::create(std::to_string(num));
    __Dictionary* dic = __Dictionary::createWithContentsOfFile("data.plist");
    number = (__String*)dic->objectForKey(std::to_string(num));
    int val = number->intValue();
    label = Label::createWithTTF(std::to_string(val),  "fonts/Marker Felt.ttf", 20);
    label->setPosition(Vec2(20 , 20));
  //  label->setAnchorPoint(Vec2(0.5, 0.5));
    
    this->addChild(label, 4);

    
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->onTouchBegan = CC_CALLBACK_2(tile::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

    this->set_index(num);
    this->setvalue(val);

   
    return true;
}

void tile::setvalue(int val)
{
    this->value=val;
}

int tile::getvalue()
{
    return value;
}

void tile::set_index(int val)
{
    this->index = val;
}

int tile::get_index()
{
    return index;
}

DrawNode* tile::get_block()
{
    return block;
}

bool tile::onTouchBegan(Touch *touch, Event* event)
{
    Vec2 locationInNode = event->getCurrentTarget()->convertToNodeSpace(touch->getLocation());
    Size s = event->getCurrentTarget()->getContentSize();
    Rect rect = Rect(0,0, s.width, s.height);
    
    Vec2 screenPos = this->getParent()->convertToWorldSpace(this->getPosition());
    
    Rect b = this->getBoundingBox();
    if (rect.containsPoint(locationInNode)) {
        int num = this->getvalue();
        std::string s = std::to_string(num);
       // log(s.c_str());

            GameController::get_instance()->tile_pressed(this);
        
        
        
        
        //this->addChild(block);
        
        
        return true;
    }
    
    return true;
}

