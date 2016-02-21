// Room: /d/huanggon/guangchang1.c

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这就是地安门广场,广场用麻石铺就,同皇宫前的天安门广场相呼应,
广场的两边是北大街,向北出了安定门可到漠北一带,南边是皇宫的后门
神武门,守卫森严.
LONG
	);
	set("no_clean_up", 0);
	set("objects",([
		"/npc/man4":3,
	]));
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"andingmen",
  "east" : __DIR__"ndajie1",
  "west" : __DIR__"ndajie2",
  "south" : __DIR__"shenwumen",
]));
	set("outdoors", "/d/huanggon");

	setup();
	replace_program(ROOM);
}
