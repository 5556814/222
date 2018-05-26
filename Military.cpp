
#include <iostream>
#include <string>
#include "Military.h"
#include "cocos2d.h"


USING_NS_CC;
using namespace std;


bool Military::init() {
	
	//��ȡ��Ļ��С
	size = Director::getInstance()->getVisibleSize();
	//auto size = Director::getInstance()->getWinSize();
	//���һ��ͼƬ����
	sprite1 = Sprite::create("CloseNormal.png");
	sprite1->setPosition(Vec2(size.width / 100, size.height / 100));
	this->addChild(sprite1);


						  //���������¼�����
	auto listener = EventListenerTouchOneByOne::create();

	//��������¼��Ļص�����
	listener->onTouchBegan = CC_CALLBACK_2(Military::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Military::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Military::onTouchEnded, this);

	//���¼��ַ�����ע��
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

//����ƶ����¼��ص�����
bool Military::onTouchBegan(Touch *touch, Event *unused_event)
{
	//��ȡ����λ�ã����꣩
	Point pos = touch->getLocation();

	sprite1->setPosition(pos);//�ѵ����Ļ�Ĵ����㣨���꣩����ֵ������2

	log("TouchBegan");

	return true;
}
//�϶�����ִ���¼�����


void Military::onTouchMoved(Touch *touch, Event *unused_event)
{
	//��ȡ��ǰ�϶����Ƶ�������λ��
	Point pos = touch->getLocation();

	sprite1->setPosition(pos);//�þ�������϶����ƶ�


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


void Military::sethp(Sprite*sprite1,Sprite *sprite2)//���������
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

		log("TouchMoved");//ע������
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

	// �ж��Ƿ��н���  
	if (r1.intersectsRect(r2)) 
	{
		sethp(sprite1, sprite2);
	}
		
}
//����ͬһ�����µ�����
	void Military::collisionDetection(Node* node_1, Node* node_2, Sprite*sprite1, Sprite*sprite2)
	{
		//��ת��Ϊ��������  
		Point worldPoint1 = node_1->convertToWorldSpace(node_1->getAnchorPointInPoints());
		Point worldPoint2 = node_2->convertToWorldSpace(node_2->getAnchorPointInPoints());
		//��ȡ���ǵĴ�С  
		Size contentSize1 = node_1->getContentSize();
		Size contentSize2 = node_2->getContentSize();
		//������ǵ�ê��,��ΪҪ������ת��Ϊ���½ǵ�����  
		Point anchorPoint1 = node_1->getAnchorPoint();
		Point anchorPoint2 = node_2->getAnchorPoint();
		//�������ǵ�Rect  
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
