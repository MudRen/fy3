// thd:rock.c
// 97.7.18 by Aug

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "独孤岩");
	set("long", @LONG
你跳上这块岩石，才发现在上面有人用剑划这三个字“独孤岩”，原
来这里就是黄药师当年修炼内功、定力之所。在瀑布旁你已经能感受到那
水石向击之声的巨大，在这里更是不用说了。巨大的水注压在你身上，你
不得不静下心来运功向抗，你的气力消耗极快，你最好在气力消耗光之前
跳到岸上。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

//      set("exits", ([ /* sizeof() == 1 */
//          "west" : __DIR__"table",
//  	]));
      
	set("outdoors", "thd");

	setup();
//	replace_program(ROOM);
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
	if((arg!="back")&&(arg!="回去")) return 0;
	
	remove_call_out("setup_obj");	
	remove_call_out("in_rock");	

	message_vision("$N飞身一跃，跳会岸上。\n",this_player());	
	this_player()->move(__DIR__"fall");
	

	return 1;
}

void setup_obj(object ob)
{
	write("这里千百吨重的水柱不断的向你压来，你不得不消耗气来抵御水柱的强大冲力。\n");

	if(ob->query("combat_exp")>=200000)  // 200k
		write("这点水流对你这样的高手来说根本算不了什么，当然你在这里也得不到潜能了。\n");		

	call_out("in_rock", 3,ob);
}

int step=0;

void in_rock(object ob)
{
	int i,j;

	j=15+random(15);
	ob->set("kee", ob->query("kee")-j);	
	write("你的气正在不断的消耗。\n");

	if(ob->query("combat_exp")<200000)  // 200k
	{
		if( (int)ob->query("potential")>=100)
			write("你的潜能已经积累的很多了，可以去学习学习了。\n");
		else
		{
			step++;

			if(step>=3)
			{
				ob->set("potential",ob->query("potential")+1);
				write("你的潜能增加了。\n");

				step=0;
			}
		}
	}

	if(ob->query("kee")<=90)	
		write(RED"你的气快要消耗完了，最好赶快上岸！\n"NOR);

	if(ob->query("kee")<=0)		
	{
		message_vision(
"$N的气消耗完了，$N再也支持不住了，$N被水柱冲下独孤岩。
\n",ob);		
		ob->move(__DIR__"nebeach1");	

		ob->die();		
	}
	else 	call_out("in_rock", 3,ob);
}

