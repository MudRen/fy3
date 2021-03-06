// Room: /d/zhongzhou/nanmeng.c

inherit ROOM;

void create()
{
	set("short", "南城门");
	set("long", @LONG
到了中州的南城门了。出了城不远就是一大片的树林。听说南城门外
一带经常有土匪出没。可在这里把守的官兵比较多，所以城里倒也太平无
事。南边是苏州、杭州、武当等方向。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing.c" : 2,
]));
	set("outdoors", "/d/zhongzhou");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wendingnan4",
  "south" : __DIR__"nroad",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
