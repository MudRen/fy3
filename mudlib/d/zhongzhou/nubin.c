//nubin
  

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "女浴室");
	set("long", @LONG
这里是女浴室，这里水气蒙蒙。靠墙一排木桶里好几个人正在沐浴。
洗完可以在旁边的躺椅上小酣一下。
LONG
	);

	set("bath_room",1);
	set("exits", ([
		"south" : __DIR__"xiuxian",
]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

	setup();
}

void init()
{
        object ob;

        if( interactive(ob = this_player())) 
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
        if( !ob || environment(ob) !=this_object()) return;
        if(ob->query("gender")=="男性")
        {
                write(RED
"你一走进来才发觉这是个女浴室，一片迷茫的水气中朦朦胧胧的粉腿玉臂看的你两眼发直，疑是到了仙界一般。突然一股热气上涌，眼前一黑你就什么都不知道了！\n"NOR);
		ob->set("sen" ,-1);
		ob->move(__DIR__"wendingnan3");
		return;
        }
}
