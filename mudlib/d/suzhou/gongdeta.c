// Room: /d/suzhou/shelita.c

inherit ROOM;

void create()
{
	set("short" ,"功德塔");
	set("long", @LONG
这是座八角七层楼阁式仿木结构的砖塔，高约三十多米。你抬起头来，注意
到塔刹乃为铁制，挺拔秀丽，真不知是如何立于塔顶的。只见塔身黑瓦黄墙与赭
色额斗拱相映成趣。再往东是舍利塔。
LONG
	);
	set("objects",([
		__DIR__"npc/hutaseng" :1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"shuangta",
		"east" :__DIR__"shelita",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump()
{
	object me;
	me=this_player();
	if(living(me)==0)	return 0;
	if(me->query_skill("dodge",1)<10)	{
		tell_object(me,"你的基本轻功还没练到家吧。\n");
		return 1;
	}
	message_vision("只见$N一个“旱地拔葱”，飞身直窜塔顶。\n",me);
	tell_room("/d/suzhou/gongdetading",me->query("name")+"从塔下跃了上来。\n");
	me->move("/d/suzhou/gongdetading");
	me->start_busy(3);
	return 1;
}
