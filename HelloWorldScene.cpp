#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using std::string;

 string words;
 int i = 204;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
	
	

	auto pEditBox_name = EditBox::create(CCSizeMake(250,50), Scale9Sprite::create("text2.png"));
	pEditBox_name->setPosition(ccp(visibleSize.width *1/ 3, visibleSize.height * 1/ 5));
	pEditBox_name->setFontColor(Color3B(0, 0, 0));//设置字体颜色  
	pEditBox_name->setFont("Arial", 20);
	pEditBox_name->setPlaceHolder("Input: ");//设置预置文本    
	pEditBox_name->setMaxLength(16);//设置最大长度    
	pEditBox_name->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);//可以输入任何，但是不包括换行   
	pEditBox_name->setInputFlag(cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);//设置输入标志位    
	pEditBox_name->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);//设置返回类型    
	pEditBox_name->setDelegate(this);//当前类继承CCEditBoxDelegate类    
	pEditBox_name->setTag(101);
	this->addChild(pEditBox_name,2);

	

    return true;
}


void HelloWorld::editBoxEditingDidBegin(EditBox *editBox)
{
	CCLOG("start edit");
}
void HelloWorld::editBoxEditingDidEnd(EditBox *editBox)
{
	CCLOG("end edit");
	
}
void HelloWorld::editBoxReturn(EditBox *editBox)
{
	CCLOG("editbox return");
	auto editbox = (EditBox*)editBox;

	if (editBox->getTag() == 101)
	{
		
		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		auto label = Label::createWithTTF(words, "fonts/Marker Felt.ttf", 24);
		if (label == nullptr)
		{
			problemLoading("'fonts/Marker Felt.ttf'");
		}
		else
		{
			// position the label on the center of the screen
			label->setPosition(ccp(visibleSize.width * 1 / 5, visibleSize.height *  5/6  - label->getContentSize().height*(i % 6)));

			// add the label as a child to this layer
			this->addChild(label, 1,i);
			this->removeChildByTag(i - 6);
		}
		editBox->setText("");
		i = i + 1;
	}
	if (editBox->getTag() == 102)
	{
		editBox->setText("you recieved a letter");
	}
}
void HelloWorld::editBoxTextChanged(EditBox *editBox, const std::string &text)
{
	CCLOG("EditBox_password changed");
	auto editbox = (EditBox*)editBox;
	if (editBox->getTag() == 101)
	{
		words = text;
	}
	if (editbox->getTag() == 102)
	{
		editBox->setText("");
		
	}
	
	}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

   


}
