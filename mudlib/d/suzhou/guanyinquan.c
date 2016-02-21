// Room: /d/suzhou/guanyinquan.c

inherit ROOM;

void create()
{
	set("short", "观音泉");
	set("long", @LONG
你信步走进观音殿后院，只见院内四周种着些青竹，正冒着嫩芽。院中一张
石桌上摆着副残局，想是殿内和尚们闲时留下的。院角一口泉井，泉水清洌洁莹。
想必是天下第三泉了。院内清静幽雅，你真想住下不走了。
LONG
	);
	set("objects",([
	__DIR__"npc/xinnan":1,
	__DIR__"npc/xinnu"	:1,
]));
	set("exits", ([ /* sizeof() == 1 */
		"south" :__DIR__"guanyindian",
		"westup" :__DIR__"huqiuta",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
