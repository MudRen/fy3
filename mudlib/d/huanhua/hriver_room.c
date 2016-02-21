// Room: /d/new/huanhua/hriver_room.c

inherit ROOM;

void create()
{
	set("short", "观鱼阁");
	set("long", @LONG
一间小小的静轩,推开窗户就能看到外面的绿竹,靠窗一张竹榻朴实无华, 
但墙上的几副牧马图明显是古物.墙角的高几上一个兽纹毂散发一阵香烟. 
正对着竹榻的墙上挂了一把短剑,看上去没什么奇怪. 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/feidao-mo.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changlang5",
]));

	setup();
	replace_program(ROOM);
}
