// thd:in_air.c
// 97.7.23 bu Aug

inherit ROOM;

void create()
{
      set("short", "空中");
	set("long", @LONG
你正在急速下降中，四周白茫茫的，都是云雾。风在你耳边呼呼的刮
着，使你的眼睛很难受，你只能模模糊糊的看见下面好象有一团红色。
LONG
);

	setup();

	replace_program(ROOM);
}

