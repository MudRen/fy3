// Room: /u/oldsix/room1/yuemen.c

inherit ROOM;

void create()
{
	set("short", "月洞门");
	set("long", @LONG
一个小巧精致的月门，透出江南水乡的淡淡清雅。耳边传来草丛中昆虫的低
语声，一阵幽香随风而至，让你暂时忘却了江湖的恩怨。
    西面是客厅，东边通向厨房。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west":__DIR__"keting2",
		"east" :__DIR__"huatan",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
