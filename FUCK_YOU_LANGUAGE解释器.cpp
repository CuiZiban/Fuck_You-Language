#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int>bl;
map<string, vector<int> > lists;
struct num_to_do{bool type;string a;int b;}nums[10000][2000];
string s[1000000];
bool a[1000][2000];
int i2[10000],beg=0,nownum[10000],cntcode=0;
void donum(string x,int nowif)
{
	int ok=1,ret=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>'9'||x[i]<'0')
		{
			ok=0;
			break;
		}
		ret=ret*10+(x[i]-'0');
	}
	if(ok==0)nums[nowif][nownum[nowif]].type=0,nums[nowif][nownum[nowif]].a=x,nownum[nowif]++;
	if(ok==1)nums[nowif][nownum[nowif]].type=1,nums[nowif][nownum[nowif]].b=ret,nownum[nowif]++;
}
void error(int nowif)
{
	cout<<"error!you fucked ccf by a wrong way!\nfrom ";
	if(a[nowif][0]==1)cout<<"in ";
	if(a[nowif][1]==1)cout<<"out ";
	if(a[nowif][2]==1)cout<<"defnum ";
	if(a[nowif][3]==1)cout<<"changenum ";
	if(a[nowif][4]==1)cout<<"deflist ";
	if(a[nowif][5]==1)cout<<"changelist ";
	if(a[nowif][6]==1)cout<<"listtonum ";
	if(a[nowif][7]==1)cout<<"if ";
	if(a[nowif][8]==1)cout<<"for ";
	while(1);
}
void dosth(string x,int nowif)
{
	if(x=="in")a[nowif][0]=1;
	if(x=="out")a[nowif][1]=1;
	if(x=="defnum")a[nowif][2]=1;
	if(x=="changenum")a[nowif][3]=1;
	if(x=="deflist")a[nowif][4]=1;
	if(x=="changelist")a[nowif][5]=1;
	if(x=="listtonum")a[nowif][6]=1;
	if(x=="if")a[nowif][7]=1;
	if(x=="for")a[nowif][8]=1;
	if(x=="num")
	{
		int ok=0;
		for(int i=0;i<20;i++)
		{
			if(a[nowif][i]==1)
			{
				ok=1;
				break;
			}
		}
		if(ok==0)error(nowif);
		donum(s[i2[nowif-1]],nowif);
	}
	if(x=="end")
	{
		if(a[nowif][0]==1)
		{
			if(nums[nowif][0].type==1)error(nowif);
			if(nums[nowif][1].type==1)error(nowif);
			if(nums[nowif][0].a=="cnm")
			{
				char x;
				cin>>x;
				bl[nums[nowif][1].a]=x;
			}
			else if(nums[nowif][0].a=="CNM")
			{
				int x;
				cin>>x;
				bl[nums[nowif][1].a]=x;
			}
			else error(nowif);
		}
		else if(a[nowif][1]==1)
		{
			if(nums[nowif][0].type==1)error(nowif);
			if(nums[nowif][1].type==0)nums[nowif][1].b=bl[nums[nowif][1].a];
			if(nums[nowif][0].a=="cnm")cout<<((char) nums[nowif][1].b);
			else if(nums[nowif][0].a=="CNM")cout<<nums[nowif][1].b;
			else error(nowif);
		}
		else if(a[nowif][2]==1)
		{
			if(nums[nowif][0].type==1)error(nowif);
			if(nums[nowif][1].type==0)bl[nums[nowif][0].a]=bl[nums[nowif][1].a];
			else bl[nums[nowif][0].a]=nums[nowif][1].b;
		}
		else if(a[nowif][3]==1)
		{
			if(nums[nowif][0].type==1)error(nowif);
			if(nums[nowif][1].type==1)error(nowif);
			if(nums[nowif][2].type==0)nums[nowif][2].b=bl[nums[nowif][2].a];
			if(nums[nowif][1].a=="Fuck")bl[nums[nowif][0].a]+=nums[nowif][2].b;
			if(nums[nowif][1].a=="fUck")bl[nums[nowif][0].a]-=nums[nowif][2].b;
			if(nums[nowif][1].a=="fuCk")bl[nums[nowif][0].a]*=nums[nowif][2].b;
			if(nums[nowif][1].a=="fucK")bl[nums[nowif][0].a]/=nums[nowif][2].b;
			if(nums[nowif][1].a=="FUck")bl[nums[nowif][0].a]=(bl[nums[nowif][0].a]>nums[nowif][2].b);
			if(nums[nowif][1].a=="fuCK")bl[nums[nowif][0].a]=(bl[nums[nowif][0].a]==nums[nowif][2].b);
		}
		else if(a[nowif][4]==1)
		{
			if(nums[nowif][0].type==1)error(nowif);
			lists[nums[nowif][0].a] = vector<int>(100000, 0);
		}
		else if(a[nowif][5]==1)
		{
		    if(nums[nowif][0].type==1)error(nowif);
		    if(nums[nowif][1].type==0)nums[nowif][1].b=bl[nums[nowif][1].a];
		    if(nums[nowif][2].type==0)nums[nowif][2].b=bl[nums[nowif][2].a];
		    
		    vector<int>& vec = lists[nums[nowif][0].a];
		    if(nums[nowif][1].b >= 0 && nums[nowif][1].b < vec.size()) {
		        vec[nums[nowif][1].b] = nums[nowif][2].b;
		    } else {
		        error(nowif);
		    }
		}
		else if(a[nowif][6]==1)
		{
		    if(nums[nowif][0].type==1)error(nowif);
		    if(nums[nowif][1].type==1)error(nowif);
		    if(nums[nowif][2].type==0)nums[nowif][2].b=bl[nums[nowif][2].a];
		    
		    vector<int>& vec = lists[nums[nowif][1].a];
		    if(nums[nowif][2].b >= 0 && nums[nowif][2].b < vec.size()) {
		        bl[nums[nowif][0].a] = vec[nums[nowif][2].b];
		    } else {
		        error(nowif);
		    }
		}
		else if(a[nowif][7]==1)
		{
			if(nums[nowif][0].type==0)nums[nowif][0].b=bl[nums[nowif][0].a];
			if(nums[nowif][1].type==0)error(nowif);
			if(nums[nowif][2].type==0)error(nowif);
			if(nums[nowif][0].b!=0)
			{
				int cntend=0;
				for(i2[nowif]=0;cntend<nums[nowif][1].b-1&&i2[nowif]<cntcode;i2[nowif]++)
				{
					if(s[i2[nowif]]=="CCF!")cntend++;
				}
				for(;cntend<nums[nowif][2].b&&i2[nowif]<cntcode;i2[nowif]++)
				{
					if(s[i2[nowif]]=="CCF!")
					{
						dosth("end",nowif+1);
						cntend++;
						continue;
					}
					else if(s[i2[nowif]]=="FUCK")dosth("in",nowif+1);
					else if(s[i2[nowif]]=="fuck")dosth("out",nowif+1);
					else if(s[i2[nowif]]=="FuCk")dosth("defnum",nowif+1);
					else if(s[i2[nowif]]=="FUcK")dosth("deflist",nowif+1);
					else if(s[i2[nowif]]=="fUcK")dosth("changenum",nowif+1);
					else if(s[i2[nowif]]=="fUCK")dosth("changelist",nowif+1);
					else if(s[i2[nowif]]=="FUCk")dosth("listtonum",nowif+1);
					else if(s[i2[nowif]]=="FucK")dosth("if",nowif+1);
					else if(s[i2[nowif]]=="fUCk")dosth("for",nowif+1);
					else dosth("num",nowif+1);
				}	
			}
		}
		else if(a[nowif][8]==1)
		{
			if(nums[nowif][1].type==0)error(nowif);
			if(nums[nowif][2].type==0)error(nowif);	
			if(nums[nowif][0].type==0)nums[nowif][0].b=bl[nums[nowif][0].a];
			while(nums[nowif][0].b!=0)
			{
				int cntend=0;
				for(i2[nowif]=0;cntend<nums[nowif][1].b-1&&i2[nowif]<cntcode;i2[nowif]++)
				{
					if(s[i2[nowif]]=="CCF!")cntend++;
				}
				for(;cntend<nums[nowif][2].b&&i2[nowif]<cntcode;i2[nowif]++)
				{
					if(s[i2[nowif]]=="CCF!")
					{
						dosth("end",nowif+1);
						cntend++;
						continue;
					}
					else if(s[i2[nowif]]=="FUCK")dosth("in",nowif+1);
					else if(s[i2[nowif]]=="fuck")dosth("out",nowif+1);
					else if(s[i2[nowif]]=="FuCk")dosth("defnum",nowif+1);
					else if(s[i2[nowif]]=="FUcK")dosth("deflist",nowif+1);
					else if(s[i2[nowif]]=="fUcK")dosth("changenum",nowif+1);
					else if(s[i2[nowif]]=="fUCK")dosth("changelist",nowif+1);
					else if(s[i2[nowif]]=="FUCk")dosth("listtonum",nowif+1);
					else if(s[i2[nowif]]=="FucK")dosth("if",nowif+1);
					else if(s[i2[nowif]]=="fUCk")dosth("for",nowif+1);
					else dosth("num",nowif+1);
				}
				if(nums[nowif][0].type==0)nums[nowif][0].b=bl[nums[nowif][0].a];
			}
		}
		memset(a,0,sizeof(a));
		nownum[nowif]=0;		
	}
}
signed main()
{
	string p;
	while(1)
	{
		cin>>s[cntcode];
		cntcode++;
		if(s[cntcode-1]=="I_HAD_FUCK_CCF!")break;
	}
	for(i2[0]=0;i2[0]<cntcode-1;i2[0]++)
	{
		if(s[i2[0]]=="I_START_TO_FUCK_CCF!")
		{
			beg=1;
			continue;
		}
		if(beg==0)continue;
		else if(s[i2[0]]=="FUCK")dosth("in",1);
		else if(s[i2[0]]=="fuck")dosth("out",1);
		else if(s[i2[0]]=="FuCk")dosth("defnum",1);
		else if(s[i2[0]]=="FUcK")dosth("deflist",1);
		else if(s[i2[0]]=="fUcK")dosth("changenum",1);
		else if(s[i2[0]]=="fUCK")dosth("changelist",1);
		else if(s[i2[0]]=="FUCk")dosth("listtonum",1);
		else if(s[i2[0]]=="FucK")dosth("if",1);
		else if(s[i2[0]]=="fUCk")dosth("for",1);
		else if(s[i2[0]]=="CCF!")dosth("end",1);
		else dosth("num",1);
	}
}
