// Room: /d/kaifeng/yanqing.c

inherit ROOM;

void create()
{
	set("short", "延庆观");
	set("long", @LONG
延庆观飞檐挑拱，气势磅礴。始建于元太宗五年,原名重阳观,为纪
念道教中全真教创始人王吉在此传教并逝世于此而修建.明洪武六年,
改名延庆观。  
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sanqing",
  "east" : __DIR__"wroad2",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
