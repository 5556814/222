#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos-ext.h"  
USING_NS_CC_EXT;
#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene, public EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
	virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
	virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string &text);
	virtual void editBoxReturn(cocos2d::extension::EditBox *editBox);

    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};


#endif // __HELLOWORLD_SCENE_H__
