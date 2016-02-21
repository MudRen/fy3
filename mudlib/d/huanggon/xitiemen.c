// Room: /d/huanggon/xitiemen.c

inherit ROOM;

void create()
{
	set("short", "西铁门");
	set("long", @LONG
西铁门高高的铁灰色城墙的夕阳下十分威武.进出此门的多是到回疆
的生意人,出了此门,向西据说还能到天山,此处向东,是西长安街.几个士
兵无聊的打着盹.
LONG
	);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/huizhu/to_bj",
  "east" : __DIR__"wchangan1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chengweibin.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
