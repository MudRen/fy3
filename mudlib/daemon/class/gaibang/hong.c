#include <ansi.h>
inherit NPC;
#include "/d/zhongzhou/npc/renwu.h"
string do_tisheng();
void do_jiangli(object player,int lv,int type);
void create()
{
	set_name("洪七公", ({"hong qigong","hong"}));
	set("nickname", "九指神丐");
        set("bh_rank","帮主");
	set("gender", "男性");
	set("age", 75);
	
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 30);
	set("int", 30);
	set("con", 30);
        set("banghui","丐帮");
	set("kee", 3000);
	set("shen_type",1);
	set("max_kee",3000);
	set("gin", 600);
	set("max_gin", 600);
	set("force", 3200);
	set("max_force", 3200);
	set("force_factor", 100);
	
	set("combat_exp", 2000000);
	set("score", 800000);
	
	set_skill("force", 200); // 基本内功
	set_skill("huntian-qigong", 200); // 混天气功
	set_skill("unarmed", 200); // 基本拳脚
	set_skill("xianglong-zhang", 200); // 降龙十八掌
	set_skill("dodge", 200); // 基本躲闪
	set_skill("xiaoyaoyou", 200); // 逍遥游
	set_skill("parry", 200); // 基本招架
	set_skill("staff", 200); // 基本棍杖
        set_skill("dagou-bang",200);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("parry","dagou-bang");
        map_skill("staff","dagou-bang");
	set("inquiry",([
        "加入丐帮":"老化子不再管这些闲事,你找我帮中其他人去.\n",
        "升职": (: do_tisheng :),
        ]));
	
	setup();
	carry_object(__DIR__"obj/dagoubang")->wield();
	carry_object("/obj/cloth")->wear();
}
void init()
{
	::init();
  add_action("do_renwu","renwu");
  add_action("do_jiaochai","jiaochai");
}
string do_tisheng()
{
	object me=this_player();
	string banghui;
        string *ranks=({"一袋弟子","二袋弟子","三袋弟子","四袋弟子","五袋弟子",
                        "六袋弟子","七袋弟子","八袋弟子","九袋长老"});
        int *lvl=({20000,50000,100000,200000,500000,800000,1200000,1500000,2000000});
        int i=0;
	if(!stringp( banghui=me->query("banghui")) || banghui!=query("banghui"))
		return "你不是丐帮弟子，呵呵,开老叫化玩笑来着!";
	if((int)me->query("combat_exp")<10000)	{
		if(! (int)me->query("rank_lv"))
		return "你的经验不够，不能提升职位！";
		me->delete("bh_rank");
		me->delete("rank_lv");
		return "由于"+me->query("name")+"办事不力，降为帮众。";
	}
	if((int)me->query("combat_exp")>2000000 &&
	(int)me->query("rank_lv")>=9)
         return "你已经是本帮九袋长老,不能再升了.";
if (me->query("combat_exp")>2000000)  {
me->set("ranl_lv",9);
me->set("bh_rank","九袋长老");
return me->query("name")+"升为本帮"+me->query("bh_rank")+"!";
}
       while (me->query("combat_exp")>lvl[i])  i++;
		if((int)me->query("rank_lv")==i)
		return "你已经是本帮"+(string)me->query("bh_rank")+
			"，要想升为"+ranks[i+1]+"至少得"+lvl[i]+"点经验值。";
		me->set("bh_rank",ranks[i]);
		if((int)me->query("rank_lv")>i)		{
		me->set("rank_lv",i);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
		me->set("rank_lv",i);
		return me->query("name")+"升为本帮"+me->query("bh_rank")+"！";
}
int do_renwu()
{
	object player,huowu;
	string banghui;
	mapping data;
	int long,sec,min;
	string msg;
	int time;

	player=this_player();
	banghui=(string)player->query("banghui");
	if(! banghui || banghui!="丐帮")	{
		command("say 这位"+RANK_D->query_respect(player)+
		"非我丐帮弟子，向老叫化要什么任务？\n");
		return 1;
	}
	if(!undefinedp(player->query("oldsix_quest")))   {
		command("say "+player->query("name")+"，你上次的任务还末曾交差(jiaochai)吧？。\n");
		return 1;
	}
//	if(intp(player->query("bad_quest"))
//	&& (int)player->query("mud_age")-(int)player->query("bad_quest")<600)	{
//		command("say 你还是好好反醒一下上次任务失败的原因吧。");
//		return 1;
//	}
//	if(intp(player->query("bad_quest")))	player->delete("bad_quest");
	huowu=present("huo wu",player);
	if(objectp(huowu))	{
		tell_object(player,"洪七公道：先把你身上的货物处理一下吧！\n");
		return 1;
	}
	if((int)player->query("combat_exp")<10000)
		data=renwu1[random(sizeof(renwu1))];
	else if((int)player->query("combat_exp")<100000)
		data=renwu2[random(sizeof(renwu2))];
	else if((int)player->query("combat_exp")<800000)
		data=renwu3[random(sizeof(renwu3))];
	else 	data=renwu4[random(sizeof(renwu4))];
	time=time();
	player->set("oldsix_quest/type",data["type"]);
	player->set("oldsix_quest/id",data["id"]);
	player->set("oldsix_quest/name",data["name"]);
	player->set("oldsix_quest/lv",data["lv"]);
	player->set("oldsix_quest/start",time);
	player->set("oldsix_quest/over",0);
	long=data["lv"]*60+random(60);
	long+=120;
	player->set("oldsix_quest/time",long);
	sec=long%60;	long/=60;
	min=long;
	msg="请在"+chinese_number(min)+"分"+chinese_number(sec)+
		"秒内，";
	if(data["type"]==1)	msg+="把"+data["name"]+"("+data["id"]+")杀了。";
	else if(data["type"]==2)
		msg+="把"+data["name"]+"("+data["id"]+")找来。";
	else if(data["type"]==3)	{
		huowu=new("/obj/huowu");
		huowu->set("start",time);
		huowu->move(player);
		msg+="把货物送到"+data["name"]+"后回来交差。";
		}
	else if(data["type"]==4)
		msg+="为本帮招慕一位NPC帮众。";
	else	msg+="为本帮抢夺一块地盘。";

	tell_object(player,"洪七公道："+msg+"\n");

	return 1;
}

int do_jiaochai()
{
	object player,ob;
	int type,start,time,over,lv;
	int now_time,score;
	string id,name,banghui;

	player=this_player();
	banghui=(string)player->query("banghui");
	if(! banghui || banghui!="丐帮")	{
		command("say 这位"+RANK_D->query_respect(player)+
		"非我丐帮弟子，向老化子交什么差？\n");
		return 1;
	}
	if(undefinedp(player->query("oldsix_quest")))    {
		command("say "+player->query("name")+"，你并末领取任何任务(renwu)，何来交差之说？\n");
		return 1;
	}
	type=(int)player->query("oldsix_quest/type");
	id=(string)player->query("oldsix_quest/id");
	name=(string)player->query("oldsix_quest/name");
	start=(int)player->query("oldsix_quest/start");
	time=(int)player->query("oldsix_quest/time");
	over=(int)player->query("oldsix_quest/over");
	lv=(int)player->query("oldsix_quest/lv");

	if(type==2)	{
		ob=present(id,player);
		if(!ob || (string)ob->query("name")!=name)	{
		over=0;
		}
		else	{
		over=1;
		}
	}
	if(over==0)	{
		now_time=time();
		if(now_time<(start+time))
		message_vision("$N对$n道：你还有点时间，快抓紧完成任务去吧。\n",this_object(),player);
		else	{
		message_vision("$N对$n叹道：你的任务已经过时了，好好反醒一下吧。\n",this_object(),player);
		player->delete("oldsix_quest");
		player->set("bad_quest",player->query("mud_age"));
		}
	}
	else if(over==1)	{
		if(time()<start+time)	{
		message_vision("$N拍了拍$n的肩膀道：这次任务完成的不错，休息一下再接新任务(renwu)吧。\n",this_object(),player);
		player->delete("oldsix_quest");
		if(objectp(ob))	destruct(ob);
		do_jiangli(player,lv,type);
		}
		else	{
		message_vision("$N安慰$n道：太可惜了，你应该早些来交差啊。\n",this_object(),player);
		player->delete("oldsix_quest");
		if(objectp(ob))	destruct(ob);
		}
	}
	return 1;
}

void do_jiangli(object player,int lv,int type)
{
	int exp,skl_exp;
	int score,db;

	if(type==4)	score=50;
	if(type==5)	score=100;
	if(type!=4&&type!=5)	{
	exp=(lv*50)+random(lv*50);
	skl_exp=exp+random(exp);
	if( player->query("combat_exp")<10000)	db=1;
	else if( player->query("combat_exp")<80000)	db=3;
	else if( player->query("combat_exp")<500000)	db=6;
	else db=10;
	skl_exp*=db;
	player->add("combat_exp",exp);
	player->add("wgjn",skl_exp);
	score=10;
	tell_object(player,"你的经验点增加了"+chinese_number(exp)+"点！\n");
	tell_object(player,"你的武功技能增加了"+chinese_number(skl_exp)+"点！\n");
	tell_object(player,"使用分配(fenpei)命令分配你的武功技能点数！\n");
	}
	player->add("score",score);
	tell_object(player,"你的评价上升了"+chinese_number(score)+"点！\n");
}

int recognize_apprentice(object ob)
{
  string banghui;
  banghui=ob->query("banghui");
  if (!banghui||banghui!="丐帮")  
   return notify_fail("洪七公摇头道:你并非我丐帮弟子,老化子不能传武功给你.\n");
	if(ob->query("score")<5000)
   return notify_fail("洪七公皱眉道:你如能为本帮再作些事情,老化子再考虑吧.\n");
  return 1;
}
   
