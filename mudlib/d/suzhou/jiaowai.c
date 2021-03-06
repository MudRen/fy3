// Room: /u/oldsix/room1/jiaowai.c

inherit ROOM;

void create()
{
	set("short", "苏州郊外");
	set("long", @LONG
三月天气，杏花夹径，绿柳垂湖，暖洋洋的春风吹在身上，当真是醺醺欲醉。
你不禁脱口吟道：[1;32m波渺渺，柳依依，孤村芳草远，斜日杏花飞。[2;37;0m西边水天一色，
荷香阵阵。东边依稀望见苏州城门。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"baigongti",
		"east" :__DIR__"xichengmen",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
