// Room: /d/huanggon/wangfujing2.c

inherit ROOM;

void create()
{
	set("short", "王府井");
	set("long", @LONG
王府井的店铺在京城最多,也是生意人最多的地方,全国各地的商贩
都把货物弄到此地交易,街道两边的招牌一个接一个,排得密密麻麻的.东
边就是家珠宝店.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jubaoge",
  "south" : __DIR__"wangfujing1",
  "north" : __DIR__"ndajie",
]));
	set("objects",([
		"/npc/man5":1,
		"/npc/man6":1,
	]));
	setup();
	replace_program(ROOM);
}
