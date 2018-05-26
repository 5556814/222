
#include <iostream>
#include <string>
#include "Military.h"
#include "cocos2d.h"


USING_NS_CC;
using namespace std;


bool Military::init() {
	
	//获取屏幕大小
	size = Director::getInstance()->getVisibleSize();
	//auto size = Director::getInstance()->getWinSize();
	//添加一个图片精灵
	sprite1 = Sprite::create("CloseNormal.png");
	sprite1->setPosition(Vec2(size.width / 100, size.height / 100));
	this->addChild(sprite1);


						  //创建监听事件对象
	auto listener = EventListenerTouchOneByOne::create();

	//定义监听事件的回调函数
	listener->onTouchBegan = CC_CALLBACK_2(Military::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Military::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Military::onTouchEnded, this);

	//在事件分发器中注册
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

//点击移动精事件回调方法
bool Military::onTouchBegan(Touch *touch, Event *unused_event)
{
	//获取触屏位置（坐标）
	Point pos = touch->getLocation();

	sprite1->setPosition(pos);//把点击屏幕的触摸点（坐标）给赋值给精灵2

	log("TouchBegan");

	return true;
}
//拖动手势执行事件方法


void Military::onTouchMoved(Touch *touch, Event *unused_event)
{
	//获取当前拖动手势的坐标与位置
	Point pos = touch->getLocation();

	sprite1->setPosition(pos);//让精灵跟着拖动点移动


}
 void Military::onTouchEnded(Touch*touch, Event*unused_event)
{
	Point pos = touch->getLocation();
	MoveTo*MoveTo = MoveTo::create(0.5f,pos);
	sprite1->runAction(MoveTo);

};

static Military* create(string & filename)
{
	CCSprite * sprite = CCSprite::create(filename);
}


static Military* create(const std::string & filename, const Rect & rect)
{
	CCSprite * sprite = CCSprite::create(filename, rect);
}


static Military* createWithTexture(Texture2D * texture)
{
	CCTexture2D*pTexture = CCTextureCache::sharedTextureCache()->addImage("pszFilename.png");
	CCSprite * sprite = CCSprite::createWithTexture(pTexture);
}


static Military* createwithTexture(Texture2D * texture, const Rect & rect, bool rotated = false)
{
	CCSpriteBatchNode* spriteTexture = CCSpriteBatchNode::create("iocn.png");
}


static Military* createWithSpritFrame(SpriteFrame* pSpriteFrame)
{
	CCSpriteFrameCache *pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	pCache->addSpriteFramesWithFile("spriteFrameName.plist");
}


static Military* createWithSpriteFrameName(const std::string & spriteFrameName)
{
	CCSpriteFrameCache *pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	pCache->addSpriteFramesWithFile("spriteFrameName.plist");
}

int Military::Getpower(Sprite*sprite)
{
	 Military*pstr = dynamic_cast<Military*>(this);
	 int Getpoint;
	 Getpoint = pstr->power;
	 return Getpoint;
}


void Military::sethp(Sprite*sprite1,Sprite *sprite2)//含死亡清除
{
	Military*pstr = dynamic_cast<Military*>(this);
	int Gethp;
	Gethp = pstr->health_point;
	while (Gethp > 0)
	{
		Gethp -= Getpower(sprite1);
		pstr->health_point=Gethp;
	}
	if (Gethp == 0)
	{
		this->removeChild(sprite2, true);
	}
}

void Military::setDestination(Vec2 destination, Sprite*sprite1, Sprite*sprite2)
{
	if (sprite2->getBoundingBox().intersectsRect(sprite1->getBoundingBox())) 
	{   
		void sethp(Sprite*sprite1, Sprite *sprite2);
	}
	else {
		MoveTo*MoveTo = MoveTo::create(0.5f, destination);
		sprite1->runAction(MoveTo);

		log("TouchMoved");//注册表调试
	}
	MoveTo*MoveTo = MoveTo::create(0.9f, destination);
	sprite1->runAction(MoveTo);
}


void Military::move(Vec2 Destination,Sprite*sprite1)
{

	MoveTo*MoveTo = MoveTo::create(0.5f,  Destination);
	sprite1->runAction(MoveTo);
}

void Military::attack(Sprite*sprite1,Sprite*sprite2)
{
	CCRect r1 = sprite1->boundingBox();
	CCRect r2 = sprite2->boundingBox();

	// 判断是否有交叉  
	if (r1.intersectsRect(r2)) 
	{
		sethp(sprite1, sprite2);
	}
		
}
//不在同一父类下的子类
	void Military::collisionDetection(Node* node_1, Node* node_2, Sprite*sprite1, Sprite*sprite2)
	{
		//先转换为世界坐标  
		Point worldPoint1 = node_1->convertToWorldSpace(node_1->getAnchorPointInPoints());
		Point worldPoint2 = node_2->convertToWorldSpace(node_2->getAnchorPointInPoints());
		//获取他们的大小  
		Size contentSize1 = node_1->getContentSize();
		Size contentSize2 = node_2->getContentSize();
		//获得他们的锚点,因为要把坐标转换为左下角的坐标  
		Point anchorPoint1 = node_1->getAnchorPoint();
		Point anchorPoint2 = node_2->getAnchorPoint();
		//构造他们的Rect  
		Rect r1 = Rect(worldPoint1.x - contentSize1.width * anchorPoint1.x, worldPoint1.y - contentSize1.height * anchorPoint1.y, contentSize1.width, contentSize1.height);
		Rect r2 = Rect(worldPoint2.x - contentSize2.width * anchorPoint2.x, worldPoint2.y - contentSize2.height * anchorPoint2.y, contentSize2.width, contentSize2.height);
		if (r1.intersectsRect(r2))
		{
			sethp(sprite1, sprite2);
		}
	}
	void Military::bindsprite(Sprite*sprite)
	{
		if (this->sprite1 != NULL)
		{
			sprite1->removeChild(sprite1,true);
		}
		this->sprite1 = sprite;
		this->addChild(sprite1);

		Size size = sprite1->getContentSize();
		this->setContentSize(size);
	
	}
