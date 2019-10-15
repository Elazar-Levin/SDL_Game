#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include "Object.h"
class Entity : public Object
{
	public:
		void setHealth(int h) {health =h;}
		void setMaxHealth(int h) {maxHealth =h;}
		int getMaxHealth(){return maxHealth;}
		int getHealth(){return health;}
		int createCycle(int r,int w,int h,int amount,int speed);
		void setCurAnimation(int c){begin=0;currAnim =c;}
		int getCurAnimation(){return currAnim;}
		void updateAnimation();
		void setMoving(bool b){moving = b;}
					
	private:
		int health,maxHealth;
	//	bool movingUp=false,movingLeft=false,movingDown=false,movingRight=false;
		bool moving=false;
		struct cycle
		{
			int row;
			int w;
			int h;
			int amount;
			int speed;
			int tick;
		};
		std::vector<cycle> animations;
		int currAnim;
		int begin;
};
#endif
