// Room: /d/huanggon/chaoyangmen.c

inherit ROOM;

void create()
{
	set("short", "朝阳门");
	set("long", @LONG
这里就是朝阳门，城墙上刻着“朝阳门”三个大字。东门就在东
南边，那里人来车往，是进出京城的要道，盘查十分严密。一条宽阔
的大道向西延伸，通往著名的王府井大街。从这里可到燕京长白.
LONG
	);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/yanjing/to_yj",
  "west" : __DIR__"echangan1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chengweibin.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
