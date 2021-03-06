// Room: /d/lingjiu/men1.c

inherit ROOM;

void create()
{
	set("short", "囚室大门");
	set("long", @LONG
这是囚室东边,西面有一扇紧闭的大门(door)。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "door" : (: look_door :),
]));
	set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/lingjiu/jujian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"changl11",
  "west" : __DIR__"qiushi",
]));
	set("outdoors", "lingjiu");

	setup();
}

int valid_leave(object me,string dir)
{
	string family;
	object ob;

	family=(string)me->query("family/family_name");
	ob=present("ju jian",this_object());
	if(family!="灵鹫宫" && objectp(ob) && dir=="west")
	return notify_fail("菊剑一伸手，把你给拦住了。\n");
	return ::valid_leave(me,dir);
}

