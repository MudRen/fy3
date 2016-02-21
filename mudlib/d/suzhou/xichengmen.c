// Room: /d/suzhou/dongchengmen.c

inherit ROOM;

void create()
{
	set("short", "西城门");
	set("long", @LONG
城门口冷冷清清，过路行人大都匆匆而过。谁要是在这里探头探脑的，非得
被守城官兵给揪了去。东边传来嘈杂的人声，你不由加快了步伐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"jiaowai",
		"east" :__DIR__"chengxijie1",
]));
	set("objects",([
	__DIR__"npc/bingyong":2,
]));
	set("outdoors","suzhou");

	setup();
}
int valid_leave(object who,string dir)
{
	if(who->query("suzhou")==1 && dir=="west") return 0;
	return 1;
}
