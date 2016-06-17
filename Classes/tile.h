//
//  tile.h
//  MemoryGame
//
//  Created by Tin on 6/16/16.
//
//

#ifndef tile_h
#define tile_h

#include "cocos2d.h"


class tile : public cocos2d::Node
{
    
    
private:
    
    int index;
    //cocos2d::Sprite* block;
    
     cocos2d::DrawNode* block;
    int value;
    
    
public:
    
    
    cocos2d::DrawNode* get_block();
    void setvalue(int val);
    int getvalue();
    void set_index(int val);
    int get_index();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void myModification(float dt);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(cocos2d::Vec2 start, cocos2d::Vec2 end, cocos2d::Label* label, int num);
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    //CREATE_FUNC(tile);
    static tile* create();
};


#endif /* tile_h */
