#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN=2002;

struct Point{
	double x,y;
	Point 
	bool operator < (Point t){
		return x==t.x ? y<t.y : x<t.x;
	}
	bool operator == (Point t){
		return x==t.x && y==t.y;
	}
	void read(){
		cin>>x>>y;
	}
};
Point P[MAXN];
vector<Point> Mid;
int N;
int ans=0,cnt=0;

inline Point midPoint(const Point A,const Point B){
	return Point((A.x+B.x)/2,(A.y+B.y)/2);
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		P[i].read();
	sort(P,P+N);
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			Mid.push_back(midPoint(P[i],P[j]));
	sort(Mid.begin(),Mid.end());
	for(vector<Point>::iterator *it1=Mid.begin();it1<=Mid.end()-1;it1++){
		vector<Point>::iterator *it2=it1+1;
		if(*it1==*it2) cnt++;
		else{
			ans+=cnt*(cnt-1)>>1;
			cnt=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}