//zhangwuji.c

#include <ansi.h>
inherit NPC;
#include <renwu.h>

string do_tisheng();
void do_jiangli(object player,int lv,int type);

void create()
{
         set_name("柳生英雄", ({ "liusheng yingxiong", "liusheng", "yingxiong" }));
	set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
      set("bh_rank","宗师");
        set("title","扶桑岛神户城");
        set("banghui","扶桑剑门");
	set("gender", "男性");
    set("age", 20);
	set("shen_type",1);
    set("attitude", "friendly");

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

	set("kee",3050);
	set("max_kee",3050);
	set("gin",1500);
	set("max_gin",1500);
	set("force",5000);
	set("max_force",5000);
	set("force_factor",120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
	set_skill("force",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("sword",200);
	set_skill("blade",200);
	set_skill("jiuyang-shengong",200);
    set_skill("taiji-quan",200);
    set_skill("taiji-jian",200);
    set_skill("taiji-dao",200);
	set_skill("qiankundanuoyi",200);
	set_skill("tianlong-bu",200);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge","tianlong-bu");
	map_skill("unarmed","taiji-quan");
	map_skill("sword","taiji-jian");
	map_skill("blade","taiji-dao");
	map_skill("parry","qiankundanuoyi");


	set("inquiry",([
	"升职": (: do_tisheng :),
		]));
		setup();
		carry_object("/obj/weapon/sword")->wield();
		add_money("gold",1);
}

string do_tisheng()
{
	object me=this_player();
	string *lv11=({"巨","厚","锐","洪","烈"});
	string *lv12=({"金","木","水","火","土"});
	string *lv13=({"香","坛","旗","堂","舵"});
	string *lv21=({"紫","白","青","黄","红","黑","绿","兰","金"});
	string *lv22=({"衣","袍","冠","衫","甲"});
	string *lv31=({"紫","白","金","青","赤"});
	string *lv32=({"衫","眉","毛","翼","焰"});
	string *lv33=({"龙","鹰","狮","蝠","蛇"});
	string *lv41=({"狂","惊","烈"});
	string *lv42=({"风","云","雷","电"});
	string *lv43=({"左","右"});
	string banghui,str1,str2,str3;

	if(!stringp( banghui=me->query("banghui")) || banghui!=query("banghui"))
		return "你不是本教兄弟，张某如何提升你的职务？";
	if((int)me->query("combat_exp")<10000)	{
		if(! (int)me->query("rank_lv"))
		return "你的经验点不够，不能提升职位！";
		me->delete("bh_rank");
		me->delete("rank_lv");
		return "由于"+me->query("name")+"办事不力，降为帮众。";
	}
	else if(me->query("combat_exp")<100000)	{
		if((int)me->query("rank_lv")==1)
		return "你已经是本教"+(string)me->query("bh_rank")+
			"，要想升为散人至少得100000经验点。";
		str1=lv11[random(sizeof(lv11))];
		str2=lv12[random(sizeof(lv12))];
		str3=lv13[random(sizeof(lv13))];
		me->set("bh_rank",str1+str2+str3+str3+"主");
		if((int)me->query("rank_lv")>1)	{
		me->set("rank_lv",1);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
		me->set("rank_lv",1);
		return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
	}
	else if(me->query("combat_exp")<500000)	{
		if((int)me->query("rank_lv")==2)
		return "你已经是本教"+(string)me->query("bh_rank")+
			"，要想升为护法至少得500000经验点。";
		str1=lv21[random(sizeof(lv21))];
		str2=lv22[random(sizeof(lv22))];
		me->set("bh_rank",str1+str2+"散人");
		if((int)me->query("rank_lv")>2)	{
		me->set("rank_lv",2);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
		me->set("rank_lv",2);
		return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
	}
	else if(me->query("combat_exp")<1000000) {
		if((int)me->query("rank_lv")==3)
		return "你已经是本教"+(string)me->query("bh_rank")+
			"，要想升为使者至少得1000000经验点。";
		str1=lv31[random(sizeof(lv31))];
		str2=lv32[random(sizeof(lv32))];
		str3=lv33[random(sizeof(lv33))];
		me->set("bh_rank",str1+str2+str3+"王");
		if((int)me->query("rank_lv")>3)	{
		me->set("rank_lv",3);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
		me->set("rank_lv",3);
		return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
	}
	else	{
		if((int)me->query("rank_lv")==4)
		return "你已经是本教"+(string)me->query("bh_rank")+"了。";
		str1=lv41[random(sizeof(lv41))];
		str2=lv42[random(sizeof(lv42))];
		str3=lv43[random(sizeof(lv43))];
		me->set("bh_rank",str1+str2+str3+"使");
		me->set("rank_lv",4);
		return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
	}

}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
	add_action("do_renwu","renwu");
	add_action("do_jiaochai","jiaochai");
}

void greeting(object ob)
{
	string banghui;
	if(!ob || environment(ob)!=environment()) return;
	banghui=(string)ob->query("banghui");
	if(! banghui || banghui!=query("banghui"))
		command("say 光明正道任人走，劝君多加保重.");
	else	message_vision(HIC"张无忌说道：多为本教出力，我会为你"+
		YEL"升职"HIC"的。\n"NOR,this_object());
	return;
}




int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
        return 0;
    }
    message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
    return 1;
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
	if(! banghui || banghui!="明教")	{
		command("say 这位"+RANK_D->query_respect(player)+
		"非我明教中人，何以要向张某领取任务？\n");
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
         destruct(huowu);
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
		msg+="为本教招慕一位NPC帮众。";
	else	msg+="为本教抢夺一块地盘。";

	tell_object(player,"张无忌道："+msg+"\n");

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
	if(! banghui || banghui!="明教")	{
		command("say 这位"+RANK_D->query_respect(player)+
		"非我明教中人，何以要向张某交差？\n");
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
/*

	if(type==2)	{
		ob=present(id,player);
		if(!ob || (string)ob->query("name")!=name)	{
		over=0;
		}
		else	{
		over=1;
		}
	}
*/
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
	if(! stringp(banghui=ob->query("banghui")) ||
		banghui!=query("banghui"))
	return notify_fail(query("name")+"摇头道：你我非亲非故，"+
		RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<5000)
		return notify_fail(query("name")+"道：你还是多为本教做些实事吧。\n");
	return 1;
}

