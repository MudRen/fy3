// Room: /d/huanggon/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
跨入大厅,正面是幅巨大的猛虎下山图,下面题款是陈近南,图画下两
张枣木太师椅子并列,靠着墙壁两排是两排椅子,看来此处经常有人集会.
东面是厢房.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/yunlong/xuanzhen.c" : 1,
  __DIR__"npc/wuliuqi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wyshanzhuang",
  "east" : __DIR__"xiangfang1",
  "north" : __DIR__"houtang1",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	string bh;
	object npc;

	bh=(string)me->query("banghui");
	npc=present("xuan zhen",this_object());
	if(( !bh || bh!="天地会") && dir=="north"
	&& objectp(npc))
	return notify_fail("玄真道长一伸手拦住你道：总舵主正忙着呢。\n");
	return ::valid_leave(me,dir);
}

