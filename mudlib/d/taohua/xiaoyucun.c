// Room: /d/taohua/xiaoyucun.c

inherit ROOM;

void create()
{
	set("short", "小渔村");
	set("long", @LONG
你没有看见一个人影。很奇怪，这里是个小岛。各种不知
名的野花野草，遍地丛生。树丛后面只能隐约看见两间小草房
。向南有一条小土路，道路两旁种着许多桃树，一样看去，排
列整齐。显然有人刻意的安排。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"haitan.c",
  "north" : __DIR__"100.c",
"east" : __DIR__"shuli.c",
]));
	set("no_clean_up", 0);
    set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
