#pragma once
#include <vector>
#include <easyx.h>
#include "Base.hpp"

class Block                                                 //�뿴����
{
protected:
	pos m_basepos;
	HitBox m_hbox;
	int m_life;
	int m_width;//����Ϊbasewid��������
	static int m_height;

public:
	Block(){};
	Block(pos basepos,HitBox hbox,int length);
	~Block();
	virtual int Draw();                                      //����cpp�ļ���ʵ��Draw����
	int Delete();
	int Update();
	HitBox GetHBox();
};
class MovingBlock:public Block                         //���������
{
private:
	int m_speed;
	pos m_beginpos;
	pos m_endpos;
	int m_dir;   //��ǰ�ƶ�����
	int m_totaldir;

public:
	MovingBlock(pos basepos,HitBox hbox,int speed,pos beginpos,pos endpos);
	~MovingBlock();
	int Paint();
	int Move();
};

class MapBase                                         //���ǵ�ͼ�࣬���԰���ͼ��·��д�� m_sourcepath.sourcepath ���ȥMaps.cpp���Mapbase���캯����д��
{
protected:
	int m_blocknum;
	vector<Block> m_blocklist;

public:
	MapBase();
	~MapBase();
	int Update();
	int Draw();                                  //����Maps.cpp��ʵ��Draw��������blockʱֱ�ӵ���block.draw()���У���ո�ʵ�ֵģ���
	int GetBlockNum();
	Block GetBlock(int num);
};




Block::Block(pos basepos, HitBox hbox, int width)
{
	m_hbox = hbox;
	m_width = width;

	m_basepos.x = basepos.x;
	m_basepos.y = basepos.y;

	m_life = alive;
	m_hbox = hbox;
}
int Block::m_height = 100;
Block::~Block() {}
int Block::Draw()                        //ʵ�ֺ���ֱ�ӷ��������濴MapBase�Ĺ��캯����MapBase::Draw()
{
	//��ⷽ���Ƿ���ã������ٻ���
	if (m_life == alive)
	{   //��������д
		IMAGE block;
		int num = m_width / basewid;

		loadimage(&block, L".\\resources\\block3.png", basewid, m_height);
		for (int i = 1; i <= num; i++)
		{
			putimage(m_basepos.x + basewid * (i - 1), m_basepos.y , &block);
		}
		m_hbox.DrawHbox();
	}
	return DONE;
}
int Block::Update()
{
	if (m_life == dead)
	{
		Delete();
	}
	return DONE;
}
int Block::Delete()
{
	m_life = dead;
	return DONE;
}
HitBox Block::GetHBox()
{
	return m_hbox;
}



MovingBlock::MovingBlock(pos basepos, HitBox hbox, int speed, pos beginpos, pos endpos)
{
	m_life = alive;

	m_basepos.x = basepos.x;
	m_basepos.y = basepos.y;

	m_hbox = hbox;
	m_speed = speed;

	m_beginpos.x = beginpos.x;
	m_beginpos.y = beginpos.y;

	m_endpos.x = endpos.x;
	m_endpos.y = endpos.y;

	if (m_beginpos.x == m_endpos.x)
		m_totaldir = Ydir;
	else if (m_beginpos.y == m_endpos.y)
		m_totaldir = Xdir;
}
MovingBlock::~MovingBlock() {}
int MovingBlock::Paint()
{
	//
}
int MovingBlock::Move()
{
	if (m_basepos.x == m_beginpos.x && m_basepos.y == m_beginpos.y)
	{

	}
	else if (m_basepos.x == m_endpos.x && m_basepos.y == m_endpos.y)
	{

	}
	else
	{

	}
}



MapBase::MapBase()
{
	pos posground, posflyblock1, posflyblock2;
	HitBox hboxg, hboxf1, hboxf2;

	m_blocknum = 3;

	posground.x = 0;                            //��������Ļ������꣨����������Ƿ�������½����꣩
	posground.y = 654;                          //�ذ巽��
	posflyblock1.x = 150;                       //���շ���1
	posflyblock1.y = 300;
	posflyblock2.x = 900;                       //���շ���2
	posflyblock2.y = 300;

	hboxg.Assignment(posground, 100, 1400);      //�����������ײ�䣬������������ǣ��������꣬�߶ȣ���ȣ�
	hboxf1.Assignment(posflyblock1, 100, 300);
	hboxf2.Assignment(posflyblock2, 100, 300);


	Block groundblock(posground, hboxg, 1400);     //�������������Ӧ��Block��������������ֱ�Ϊ����ͼ·�����������꣬��ײ�䣬block�ܳ��ȣ�
	Block Flyingblock(posflyblock1, hboxf1, 300);
	Block Flyingblock2(posflyblock2, hboxf2, 300);

	m_blocklist.push_back(groundblock);            //��MapBase�����vector<Block>���������Ԫ��
	m_blocklist.push_back(Flyingblock);
	m_blocklist.push_back(Flyingblock2);
}
MapBase::~MapBase() {};
int MapBase::Draw()
{
	//������д��ͼ�Ļ��ƺ���
	IMAGE p1, p2, p3, p4, p5, p6, p7, p8, p9;

	loadimage(&p1, L".\\resources\\p1.jpg", 448, 252);
	putimage(0, 0, &p1);

	loadimage(&p2, L".\\resources\\p2.jpg", 448, 252);
	putimage(448, 0, &p2);

	loadimage(&p3, L".\\resources\\p3.jpg", 448, 252);
	putimage(896, 0, &p3);

	loadimage(&p4, L".\\resources\\p4.jpg", 448, 252);
	putimage(0, 252, &p4);

	loadimage(&p5, L".\\resources\\p5.jpg", 448, 252);
	putimage(448, 252, &p5);

	loadimage(&p6, L".\\resources\\p6.jpg", 448, 252);
	putimage(896, 252, &p6);

	loadimage(&p7, L".\\resources\\p7.jpg", 448, 252);
	putimage(0, 504, &p7);

	loadimage(&p8, L".\\resources\\p8.jpg", 448, 252);
	putimage(448, 504, &p8);

	loadimage(&p9, L".\\resources\\p9.jpg", 448, 252);
	putimage(896, 504, &p9);

	for (vector<Block>::iterator it = m_blocklist.begin(); it != m_blocklist.end(); it++)
	{
		it->Draw();
	}
	return DONE;
}
int MapBase::GetBlockNum()
{
	return m_blocknum;
}
Block MapBase::GetBlock(int num)
{
	vector<Block>::iterator it = m_blocklist.begin();

	for (int i = 0; i < num; i++)
	{
		it++;
	}
	return *it;
}
int MapBase::Update()
{
	for (vector<Block>::iterator it = m_blocklist.begin(); it != m_blocklist.end(); it++)
	{
		it->Update();
		return DONE;
	}
}
