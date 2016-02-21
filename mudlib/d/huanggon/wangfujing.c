// Room: /d/huanggon/wangfujing.c

inherit ROOM;

void create()
{
	set("short", "王府井");
	set("long", @LONG
王府井的店铺在京城最多,也是生意人最多的地方,全国各地的商贩
都把货物弄到此地交易,街道两边的招牌一个接一个,排得密密麻麻的.东
面就是全聚德酒楼.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"edajie1",
  "north" : __DIR__"wangfujing1",
  "east" : __DIR__"quanjude",
]));

	setup();
	replace_program(ROOM);
}
