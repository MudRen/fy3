// Room: /d/suzhou/guandao3.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接中州与苏州的官道。由于此处远离城镇，所以路上行人渐稀。偶
而也会有一两骑从你身边飞驰而过，但大都是匆匆过客。道路两旁除了荒丘之外
再也看不见什么了。西面是中州方向，东面则往苏州。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" :__DIR__"guandao4",
  "eastup" : __DIR__"huangqiu3",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
