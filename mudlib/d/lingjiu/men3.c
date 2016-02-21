// Room: /d/lingjiu/men3.c

inherit ROOM;

void create()
{
	set("short", "闭关室大门");
	set("long", @LONG
这是闭关室南边，北面有一扇大门。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/lingjiu/tbzhu.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xiaodao2",
  "north" : __DIR__"biguan",
]));
	set("outdoors", "lingjiu");

	setup();
}

int valid_leave(object me,string dir)
{
	string family;
	object ob;

	family=(string)me->query("family/family_name");
	ob=present("shi sao",this_object());
	if(family!="灵鹫宫" && objectp(ob) && dir=="north")
	return notify_fail("石嫂拦住了你道：天山童姥正在练功，任何人不得打扰她老人家。\n");
	return ::valid_leave(me,dir);
}

