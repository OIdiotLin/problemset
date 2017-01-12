#include <iostream>
using namespace std;
typedef struct inf{
	int attack;
	int hp;
};
inf student;
inf teacher[70];
int n;

void input()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>teacher[i].hp>>teacher[i].attack;
	}
	cin>>student.attack>>student.hp;
}

bool fight(int hp,int att)
{
	while(1)
	{
		hp-=student.attack;
		if (hp<=0)
			return true;
		student.hp-=att;
		if (student.hp<=0)
			return false;
	}
}

void turn()
{
	for(int i=0;i<n;i++)
	{
		if(fight(teacher[i].hp,teacher[i].attack))
			continue;
		else
		{
			cout<<"oh shit!"<<endl;
			return;
		}
	}
	cout<<"yes!!very good"<<endl;
}

int main()
{
	input();
	turn();
	return 0;
}
