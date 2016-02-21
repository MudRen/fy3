// thd:spring.c
// 97.7.14 by Aug

inherit ROOM;

void create()
{
      set("short", "龙云泉");
	set("long", @LONG
这里是龙云泉，这里就是碧云涧的源头，也就是千丈瀑的发源的。这
一眼小小的泉水，慢慢的变成溪水，再慢慢边成瀑布，其实人生不也正象
这样吗？桃花岛虽到处大海之中，但这眼泉的泉水竟然是淡的，而且还带
着些甘甜，桃花岛真不愧是海天福地啊！往下看你能看到一个大瀑布。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"yun_jian",
  	]));
      
	set("outdoors", "thd");

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	int i;

	if(arg!="down") return 0;

	me=this_player();

	if(me->query_skill("dodge")<20)
	{
		write("你的轻功太差了，这样跳下去会送命的！\n");
		return 1;
	}

	i=10+random(10);
	if(me->query_stat("kee")<=i)
	{
		write("你太累了，这样子跳下去很危险的。\n");
		return 1;
	}

	me->consume_stat("kee", i);

	message_vision("$N顺着龙云泉跳了下去。\n",me);
	
	me->move(__DIR__"fall");

	if(me->query("class")=="taohua")
	{
		me->improve_skill("dodge", me->query_skill("dodge")/8+1);
		me->improve_skill("bagua-steps", me->query_skill("bagua-steps")/8+1);

		write("你的基本轻功进步了。\n");
		write("你的九宫八卦步进步了。\n");
	}
	else
	{
		me->improve_skill("dodge", me->query_skill("dodge")/8+1);
		write("你的基本轻功进步了。\n");
	}

	return 1;
}




