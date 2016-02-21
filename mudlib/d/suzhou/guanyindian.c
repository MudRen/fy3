// Room: /d/suzhou/guanyindian.c

inherit ROOM;

void create()
{
	set("short", "观音殿");
	set("long", @LONG
大殿正中央的龛台上是个泥塑金身的观音像，一脸的兹悲。似乎为沉浮于人
间欲海的凡人叹惜。由于慕名来虎丘的善男信女不少，因而此殿的香火到也旺盛。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" :__DIR__"huqiushanding",
		"north" :__DIR__"guanyinquan",
]));
	set("objects",([
	__DIR__"npc/xiaoshami":1,
	__DIR__"npc/xiaoheshang" :1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
