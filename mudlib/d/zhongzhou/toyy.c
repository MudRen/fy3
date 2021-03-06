// Room: /d/zhongzhou/toyy.c

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
由于离中州渐远，路上见不到多少行人。听说南下要经过「野羊寨」，
你心里不由紧张起来。北面不远就是「中州府」，南边是南下之路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/yeyangzai/nroad",
  "north" : __DIR__"nroad",
]));
set("outdoors","/d/zhongzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
