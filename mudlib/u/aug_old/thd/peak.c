// thd:peak.c
// 97.7.14 bu Aug

#include <ansi.h>

inherit ROOM;

void create()
{
      set("short", "弹指峰");
	set("long", @LONG
这里就是弹指峰的绝顶。这里的风终年不息，在暴风之日在这里根本
就站不住人，即使是平时在这里站稳也要消耗不少的内功。从这里向下望
去，就是一望无际的大海，在这里你才能真正体验大自然的气魄，才能真
正感受天下无敌的豪迈。从这里你也能清晰的看到桃花岛的全貌，连内阵
也能看的很真切，可惜你不一定进的去。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "southdown" : __DIR__"hill9",
  	]));
      
	set("outdoors", "thd");

	setup();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("setup_obj");
		call_out("setup_obj", 1, ob);
	}

	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me,ob;
	int i,j;

	if((arg!="in")&&(arg!="里面")) return 0;

	me=this_player();

	remove_call_out("in_peak");

	message_vision("$N发疯似的从弹指封上跳了下去。\n",me);

	me->move(__DIR__"in_air");

	message("vision",
"\n
你的身体在空中飞速下降，耳旁的风呼呼的响着。
你眼前只有一团团的粉红色，那些色团越来越大，越来越大……
\n",environment(me));

	ob = present("dou peng", me);
	if(objectp(ob))
		message("vision",YEL+"但你的斗篷被风吹的飘起来，你的下降速度减慢了。\n\n"NOR,environment(me));

	call_out("flying", 12, me);

	return 1;
}

void flying(object me)
{
	int i,j;
	object ob;

	message("vision","也不知过了多久，你耳听'碰'的一声，你重重的摔在了地上。\n",environment(me));

	me->move(__DIR__"in_road1");
	
	ob = present("dou peng", me);
	if(objectp(ob)) i=2; else i=1;

	j=me->query("max_kee");
	if(me->skill("dodge")<30)	
		me->set("kee", 0);	
	else
	{	
		j=j/2+random(180-me->query_skill("dodge")*i)/100*j;

		if(j>me->query("kee"))
			 j=me->query("kee");

	      me->set("kee", me->query("kee")-j);
	}

	if(me->query("kee")==0)		
	{
		me->die();		
		message("channel:rumor", YEL +"【谣言】"+ "某人："+me->query("name")+"跳下弹指峰摔死了。\n"NOR,users());
	}	
}

void setup_obj(object ob)
{
    call_out("in_peak", 5,ob);
}

void in_peak(object ob)
{
	object *all;
	int i,j;

	i=0;
	all = all_inventory(this_object()); 

	for (j=0; j<sizeof(all); j++) 
	{
		if( all[j]==ob) i=1;	
	}

	if(i==0) return;

	write(BLU+"这里的风太大了，你不得不消耗内力来抵御狂风。\n"NOR);

	i=50+random(100);

	if(i>ob->query("force")) 
	{
		ob->set("force",0);
		message_vision(YEL+
"$N的内力消耗完了，$N再也支持不住了！
$N被大风吹下了弹指峰。

\n"NOR,ob);			
		ob->move(__DIR__"hill9");
	}
	else
	{
		ob->set("force", ob->query("force")-i);	

		call_out("in_peak", 5,ob);
	}
}

int valid_leave(object me, string dir)
{
	if(dir=="southdown") remove_call_out("in_peak");

	return ::valid_leave(me, dir);
}
