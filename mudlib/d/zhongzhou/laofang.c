//laofang
  

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
	这是一间阴暗潮湿的牢房，地上几只老鼠莫无旁人在那里找东西吃。就只有铁
门上的一个小窗户透一点光进来。这种地方多呆一刻你就要发疯。你不竟想大叫救命。
你如果有朋友的话可以叫他们来保你出去。
LONG
	);

	set("exits", ([
		"out" : __DIR__"xunbu",
		
	]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

	setup();
	replace_program(ROOM);
}

