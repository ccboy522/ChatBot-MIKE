#include<iostream>
#include<string>
#include<sstream>
#include<ctime> 
#include<cstdlib>
#define M 5
using namespace std;
string greet[M]={"你好少年",
		 "地球人你好",
		 "有啥吩咐？",
		 "请问我问题",
		 "呵呵"}; 				 
string joke[M]={"小明买了一本教人如何快速睡着的书，天天看到天亮。"
	        "内蒙古的海军总司令",
		"法官：你为什么要印假钞？\n被告无辜地说：因为我不会印真钞。",
		"贼甲：快数数今天一共抢了多少钱？\n贼乙：不用，明天看看报纸就知道了。",
		"病人：医生，你把剪刀留在我肚子里了。\n医生：没关系，我还有一把。 "};
string story[M]={"从前有座山，山里有座庙……"
	         "很久很久以前，有一个叫Mike的机器人，他就站在你的面前。"
	         "我喜欢听故事。"
	         "#$@&&@!!*$%^^&%^#^&^&#@U*&^%$%#$%^&*……"
		 "预知后事如何，且听下回分解。"};
string sorry[M]={"不好意思，我的智商太低听不懂",
		 "让我想想",
		 "这个问题我不准备回答",
		 "无可奉告",
		 "下次再告诉你"};
bool allDigits(string s){
	for(int i=0;i<s.size();i++)
		if(s[i]<'0'||s[i]>'9') return 0;
	return 1;
}

void decompose(string s){
	stringstream ss;
	int n,c=0;
	ss<<s; ss>>n;
	if(n<=1) {cout<<n<<"不是质数"<<endl;return;} 
	for(int i=2;i*i<=n;i++)
		while(n%i==0){
			if(c==0) {cout<<i; c++;} 
			else cout<<"*"<<i;
			n/=i;
		}
	if(c==0) cout<<n<<"是个质数"<<endl;
	else if(n>1) cout<<"*"<<n<<endl;
	else cout<<endl;
}

int main(){
	cout<<"你好，我是聊天机器人，你可以问我各种问题"<<endl; 
	while(1){
		string s;
		getline(cin,s);
		if(s=="") continue;
		if(s=="88") 
			break; 
		else if(s.find("名")!=-1||s.find("谁")!=-1) 
			cout<<"我的名字叫MIKE，你是我主人"<<endl; 
		else if(s.find("岁")!=-1||s.find("多大")!=-1)
			cout<<"我今年100岁了，我永远不会死"<<endl;	
		else if(s.find("哪")!=-1)	
			cout<<"无处不在"<<endl; 
		else if(s.find("会")!=-1)
			cout<<"我什么都不会，只会聊天"<<endl;
		else if(s.find("生")!=-1)
			cout<<"我生日是2月30日，请送我生日礼物吧"<<endl;
		else if(s.find("智")!=-1)
			cout<<"我的智商为59，还没有及格"<<endl;
		else if(s.find("球")!=-1||s.find("兴")!=-1||s.find("爱")!=-1)
			cout<<"我爱看足球，但是不能踢足球，因为我没有腿"<<endl;
		else if(s.find("笑")!=-1)
			cout<<"我来给你说个笑话吧："<<endl<<joke[rand()%M]<<endl;
		else if(s.find("事")!=-1)
			cout<<"我来给你讲个故事吧："<<endl<<story[rand()%M]<<endl;
		else if(s.find("你好")!=-1)
			cout<<greet[rand()%M]<<endl;
		else if(allDigits(s)){
			cout<<s<<"是个好数字"<<endl;
			decompose(s);
    else if(s.find("再见")!=-1)
			cout<<"再见！期待下次的见面"<<endl;
		}
		else 
			cout<<sorry[rand()%M]<<endl;	
	}
	cout<<"再见！期待下次的见面"<<endl;
	return 0;
}
